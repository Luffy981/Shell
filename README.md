# project 0x16. C - Simple Shell
***

### Description
***

Creation of the command line interface of the Unix Shell project for Linux systems. This Shell can interpret instructions and perform Syscall.

### Learning Objectives
***

*Who designed and implemented the original Unix operating system
*Who wrote the first version of the UNIX shell
*Who invented the B programming language (the direct predecessor to the C programming language)
*Who is Ken Thompson
*How does a shell work.
*What is a pid and a ppid.
*How to manipulate the environment of the current process.
*What is the difference between a function and a system call.
*How to create processes.
*What are the three prototypes of `main`.
*How does the shell use the `PATH` to find the programs.
*How to execute another program with the `execve` system call.
*How to suspend the execution of a process until one of its children terminates.
*What is `EOF` / "end-of-file"?.

## Requirements
***

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to


### Compilation
***

Your shell will be compiled this way:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Testing
***

Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### files
***

| Files | Description |
| --- | --- |
| [simpleshell.h](https://github.com/CarolinaDCode/simple_shell/blob/master/simpleshell.h) | Header file. Contain all the prototype name of the functions. |
| [AUTHORS](https://github.com/CarolinaDCode/simple_shell/blob/master/AUTHORS) | Contains the authors of the project. |
| [man_1_simple_shell](https://github.com/CarolinaDCode/simple_shell/blob/master/man_1_simple_shell) | man page containing details about the usage of shell function.|

### List of allowed functions and system calls
`access` (man 2 access)
`chdir` (man 2 chdir)
`close` (man 2 close)
`closedir` (man 3 closedir)
`execve` (man 2 execve)
`exit` (man 3 exit)
`_exit` (man 2 _exit)
`fflush` (man 3 fflush)
`fork` (man 2 fork)
`free` (man 3 free)
`getcwd` (man 3 getcwd)
`getline` (man 3 getline)
`getpid` (man 2 getpid)
`isatty` (man 3 isatty)
`kill` (man 2 kill)
`malloc` (man 3 malloc)
`open` (man 2 open)
`opendir` (man 3 opendir)
`perror` (man 3 perror)
`read` (man 2 read)
`readdir` (man 3 readdir)
`signal` (man 2 signal)
`stat` (__xstat) (man 2 stat)
`lstat` (__lxstat) (man 2 lstat)
`fstat` (__fxstat) (man 2 fstat)
`strtok` (man 3 strtok)
`wait` (man 2 wait)
`waitpid` (man 2 waitpid)
`wait3` (man 2 wait3)
`wait4` (man 2 wait4)
`write` (man 2 write)

### Authors

Smith Flores - [GitHub](https://github.com/ChristianVaras)
Christian Varas - [GitHub](https://github.com/Luffy981)