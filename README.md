Unix Command Line Interpreter:
The Unix Command Line Interpreter is a simple command-line application that allows users to enter commands and execute them in a Unix-like environment. It provides a basic interface for interacting with the operating system, running various commands, and performing tasks efficiently.
This project has been developed under stringent measures for memory management

Getting Started:
To use the Unix CLI ,follow these steps;

1. Clone the repo to your local machine:

git clone https://github.com/obimbasmart/simple_shell.git

2. Change to the simple_shell directory:

cd simple_shell

3. Compile the C files in the simple_shell directory to generate an executable:

gcc -Wall -Wextra - Werror -pedantic -std=gnu89 *.c -o hsh

4. Run the executable 

./hsh

Usage:
Once the interpreter is running, you can type commands and press Enter to execute them. The interpreter will process the command and perform the appropriate actions.

Here are some examples of supported commands:

ls: List files and directories in the current directory.
cd <directory>: Change the current working directory to the specified directory.
mkdir <directory>: Create a new directory with the given name.
rm <file>: Remove a file.
rmdir <directory>: Remove a directory (only works if it's empty).
man <program> : Provide information about a command,function or a system call
exit: Exit the command line interpreter.

Contribution:
We welcome contributions to improve the Unix Command Line Interpreter. If you find any issues or have ideas for enhancements, please open an issue or submit a pull request on the project's GitHub repository.
