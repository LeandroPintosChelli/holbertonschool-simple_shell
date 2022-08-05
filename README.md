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

## What is the PATH

The PATH variable is in summary a list of directories that your computer looks through to find a requested an executable command or built-ins.

## What are built-ins:

A shell built-in is a command or a function called, that is executed directly in the shell itself.

### Built-ins Commands implemented:

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

AUTHORS  check-builtin.c  main.h  man_1_simple_shell  more_aux_functions.c  README.md  simple_shell.c  string-functions.c  tests  which.c

```
ls -l: helps the “ls” command to list the files in a long format, including the permissions, ownership, timestamps and file sizes.

Input: 
`$ ls -l`

```

total 36
-rw-r--r-- 1 root root  212 Aug  4 12:18 AUTHORS
-rw-r--r-- 1 root root  417 Aug  4 12:29 check-builtin.c
-rw-r--r-- 1 root root  774 Aug  4 12:18 main.h
-rw-r--r-- 1 root root  831 Aug  4 12:18 man_1_simple_shell
-rw-r--r-- 1 root root 1598 Aug  4 12:18 more_aux_functions.c
-rw-r--r-- 1 root root 3040 Aug  4 12:32 README.md
-rw-r--r-- 1 root root 1115 Aug  4 12:29 simple_shell.c
-rw-r--r-- 1 root root 1493 Aug  4 12:18 string-functions.c
drwxr-xr-x 2 root root   88 Aug  4 12:18 tests
-rw-r--r-- 1 root root  869 Aug  4 12:29 which.c

```

Input:
`$ /bin/ls`

Output:
```

$ AUTHORS  check-builtin.c  main.h  man_1_simple_shell  more_aux_functions.c  README.md  simple_shell.c  string-functions.c  tests  which.c

```
env: The env command allows you to display your current environment.

Input:
`$ env`

```

HOSTNAME=cc608fbf1511
LANGUAGE=en_US:en
PWD=/root/holbertonschool-simple_shell
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
LC_ALL=en_US.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
OLDPWD=/root/holbertonschool-simple_shell/funciona
_=./a.out

```

## In files check-builtin.c, fill_buff.c, string-functions.c, more_aux_functions.c and which.c there are functions we use as help us:

```
_env: Prints enviroment variables.
_salir: Exit built-in function.
p_error: Print error to stderr.
fill_buff: Fills array of strings with tokens.
check_builtin: Checks for builtin function.
_getenv: searches the environment variable dynamically.
_putchar: writes a character to stdout.
_strlen: calculates the string lenght.
str_concat: concatenate two strings.
_strcmp: compare two strings.
_strdup: duplicate a string.
_which: search a path.
_strchr: locates a character in a string.
```
# Flowchart
![Flowcharts](https://user-images.githubusercontent.com/68179343/182882207-5b02a521-218d-4baa-a97e-b8734ab4c086.png)


Created by [Leandro Pintos](https://github.com/LeandroPintosChelli) & [Santiago Fernández](https://github.com/TotiFlame) & [Blas Hernandez](https://github.com/blashernandez98)
