# Simple_shell

Welcome. This project consists in replicate how a the Linux Shell works, in a simpler way.

## Introduction.
In the 1960s and 1970s Dennis Ritchie and Ken Thompson invented Unix.
The first Unix shell was the Thompson shell, sh, written by Ken Thompson at Bell Labs and distributed with Versions 1 through 6 of Unix, from 1971 to 1975.
In 1969, Thompson and colleague Dennis Ritchie created the UNIX operating system at Bell Telephone Laboratories.

The shell is a program where users can type commands that can be executable files or built-ins.
Bash is the default shell on most modern implementations of Unix.

## Evironment of our Simple_shell

- Language: C
- Editor: VIM
- Compile mode: gcc Wall -Werror -Wextra -pedantic -std=gnu89 -g
- Style rules: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## Built-in Commands implemented:

| Command    | Output          |
|------------|-----------------|
| `env`      | print env       |
| `exit`     | exit shell      |

## Install

To install and execute in your own terminal:

`git clone https://github.com/LeandroPintosChelli/holbertonschool-simple_shell.git`
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## To test with Valgrind, you can use this metod and flags:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh`

`valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all -s ./hsh`

## Examples of commands and built-ins, and what they do:

ls: List information about the FILEs (the current directory by default).

Input: 
`$ ls`

Output:

```



```
ls -l: helps the “ls” command to list the files in a long format, including the permissions, ownership, timestamps and file sizes.

Input: 
`$ ls -l`

```


```

Input:
`$ /bin/ls`

Output:
```



```
env: The env command allows you to display your current environment.

Input:
`$ env`

```


```

# Flowchart


