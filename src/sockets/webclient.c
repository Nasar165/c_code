#include <stdio.h>
#include <string.h>     // contains strlen function
#include <netinet/in.h> // all socket funtions
#include <arpa/inet.h>  // contains inet_pton functions
#include <unistd.h>     // contains write function
#include <errno.h>
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */

#define SERVER_PORT 80
#define BUFFERLENGTH 4096
#define SA struct sockaddr

void err_n_die(const char *fmt, ...);

int main(int argc, char **argv)
{
    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendLine[BUFFERLENGTH];
    char receiveLine[BUFFERLENGTH];

    if (argc != 2)
        err_n_die("usage: %s <server address>", argv[0]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_n_die("Error while createing the socket");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_n_die("inet_pton error for %s", argv[1]);

    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
        err_n_die("connection failed");

    sprintf(sendLine, "GET / HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendLine);

    if (write(sockfd, sendLine, sendbytes) != sendbytes)
        err_n_die("Write Error");

    memset(receiveLine, 0, BUFFERLENGTH);

    while ((n = read(sockfd, receiveLine, BUFFERLENGTH - 1)) > 0)
        printf("%s", receiveLine);

    if (n < 0)
        err_n_die("read error");

    return 0;
}

void err_n_die(const char *fmt, ...)
{
    int errno_save;
    va_list ap;

    errno_save = errno;

    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    fprintf(stdout, "\n");
    fflush(stdout);

    if (errno_save != 0)
    {
        fprintf(stdout, "(errno = %d) : %s\n", errno_save);
        strerror(errno_save);
        fprintf(stdout, "\n");
        fflush(stdout);
    }
    va_end(ap);
    _exit(1);
}