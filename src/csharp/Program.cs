using System.Runtime.InteropServices;

namespace csharp
{
    class Program
    {
        // make sure to add the file to ItemGroup in csproj
        [DllImport("hello.dll", EntryPoint = "printMessage")]
        static extern void printMessage(char[] message);

        static void Main(string[] args)
        {
            var message = "Hey there it's me World!";
            printMessage(message.ToCharArray());
        }
    }
}
