using System.Runtime.InteropServices;

namespace csharp
{
    class Program
    {
        // add the compiled dll into bin/Debug/netcoreapp3.1 to avoid DLLNotFoundException
        [DllImport("hello.dll", EntryPoint = "printMessage")]
        static extern void printMessage(char[] message);

        static void Main(string[] args)
        {
            var message = "Hey there it's me World!";
            printMessage(message.ToCharArray());
        }
    }
}
