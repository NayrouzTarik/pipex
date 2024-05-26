## what is a pipe?

Its the output of a program "command" can be used as the input to another

They are used in CLI (command lines) to chain commands ,using the vertical bare we split the commands 

Pipex focuses on three main concepts: pipelines, child processes and execution of commands

### We have multiple allowed defined functions like : 

## dup2() :

It's allow to use an opened file descriptor & to use them without closing any of them by creating a copy of the first one , so basically i can use the same file in multiple parts of my program it can be used in redirecting input/output 

exemple : i have a file called "test.txt" that have an fd1 = 3 & i wanna do two things in this file "read" & "write" once per time , so instead of reopening it again we can use "dup2()". That will create a copy of our fd1 so basically we want a copy of fd1 called fd2 , so we use it like "dup2(fd1, fd2)" & now both fd1 & fd2 are connected to our file "test.txt"

____________________________________________________________________________________________

## access() : The security guard & checker for the fie

It checks if the process has the permission to acess a file or directory , it take two arguments , the path to the file & the mode (W_OK , R_OK , X_OK, F_OK), which stands respectevilly for write, read, execute , existing ok.

# exemple of use :

Here we are checking if we have the permission of reading in example.txt
int main()
{
	if (access("example.txt", R_OK) != -1)
		printf("I have permission\n");
	else
		printf("I don't have permission\n");
 
	return (0);
}
____________________________________________________________________________________________

## execve() :

its a functin that execute the command that we give to it , it take three arguments : the path to the command , 
the array of arguments & the array of environment variables

# exemple of use : 

int main() {
    // Define the command to execute
    char *args[] = { "/bin/echo", "Hello, World!", NULL };
    
    // Call execve to execute the command
    execve(args[0], args, NULL);

    // If execve returns, it means an error occurred
    perror("execve");
    return 1; // Exit with an error status
}

Where :
- program_path: This is a string representing the path to the program you want to execute. In this case, it's a variable holding the path to the program you want to run. It could be "/bin/ls" as in the example, or any other valid path to an executable file.

- args: This is an array of strings containing the arguments to be passed to the program being executed. In this case, it's the args array we declared earlier, which contains the path to the program ("/bin/ls") and a NULL pointer indicating the end of the array.

- NULL: This parameter is for specifying the environment variables to be used by the new program. In this case, we're passing NULL, which means the new program will inherit the current environment variables of the calling process.

___________________________________________________________________________________________

## fork() : 

its decalared & used as : 
pid_t id = fork() (that pid_t is an int so no worries)
it's a function that create a child process from a parent process like :

./pipex file1 cmd1  | cmd2   > file2
./pipex file1 child | parent > file2

knowing that the child PID is always 0 & the parent have the process ID	

Chart to understand more : 

./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)

Knowing that the id of the child is always 0 
The id of the parent is always > 0
____________________________________________________________________________________________

## pipe() : 

This function create an *Unidirectional* data chanel , where the data written to one end is being read from the other end of pipe (aka tuyeau)

Chart to undestand things more :

    infile                                               outfile
as stdin for cmd1                                 as stdout for cmd2            
       |                        PIPE                        ↑
       |           |---------------------------|            |
       ↓           |                           |            |
      cmd1   -->  end[1]       <->        end[0]   -->     cmd2           
                   |                           |
            cmd1   |---------------------------|  end[0]
           output                             reads end[1]
         is written                          and sends cmd1
          to end[1]                          output to cmd2
       (end[1] becomes                      (end[0] becomes 
        cmd1 stdout)                          cmd2 stdin)


so here we can see clearly that the output of the first command was stored in end[1] & from it end[0] read to send to cmd2 

____________________________________________________________________________________________

## unlink() : 

Function that remove a file from the file system , takes one single arg that is the path to file to remove

# exemple of usage :
int main()
{
	if (unlink("example.txt") == 0)
		printf("File successfully deleted");
	else
		printf("Error deleting file");
 
	return (0);
}

____________________________________________________________________________________________

## wait() : 

Suspends the execution of its calling process until a child process terminates.

____________________________________________________________________________________________

## dup() : 

It's like dup2() , the main difference is that dup2() gives you more control over where the duplicate descriptor goes, while dup() simply assigns the duplicate to the lowest available descriptor number.

To understand more : 

- dup() : always creates a new file descriptor that is one greater than the highest-numbered descriptor currently open by the process.

- dup2() : on the other hand, allows you to specify both the source and the destination file descriptors. It duplicates the source file descriptor to the destination file descriptor, closing the destination file descriptor if it was already open

________________________________________________________________________________________________________

### The Logic building :

main()
{
	ft_init_pipex()
	ft_check_args()
	ft_parse_cmds()
	ft_parse_args()
	while (cmds)
		ft_exec()
	ft_cleanup()
}

where : 

I - ft_init_pipex() :
    A function where we gonna start initialising our pipe that will be a struct with some data 

II - ft_check_args() : 
    A function where to open all files & handle 'here_doc' & '/dev/urandom' , maybe use gnl

III - ft_parse-cmds() : 
    

