#include <stdio.h>

struct model
{
    int id;
    char name[75];
    struct model *classMate;
};

int main()
{
    struct model mate1 = {1, "Hamilton"};
    struct model mate2 = {1, "Peter", &mate1};
    struct model name = {1, "Mark", &mate2};
    struct model class[3] = {
        mate1,
        mate2,
        name,
    };

    printf("ID\t Name\t Class mate\n");
    for (int i = 0; i < 3; i++)
    {
        if (class[i].classMate != NULL)
            printf("%d\t %s\t %s\n", class[i].id, class[i].name, class[i].classMate->name);
        else
            printf("%d\t %s\n", class[i].id, class[i].name);
    }
    return 0;
}