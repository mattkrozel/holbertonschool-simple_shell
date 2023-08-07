# Simple Shell

SimpleShell is a basic Unix shell implementation written in C. It allows users to execute commands, manage processes, and interact with the operating system.

[Github Simple Shell Repository link](https://github.com/mattkrozel/holbertonschool-simple_shell)

# Requirements


- All your files will be compiled on Ubuntu 20.04 LTS
-   No more than 5 functions per file





## Installation

 1. `git clone https://github.com/aDENTinTIME/simple_shell.git`
2. `cd holberton-simple_shell`
 3.   `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`

## Testing
**Interative mode:**

Command:
```./a.out```
```$ ls```

Output:

    AUTHORS execute_arg.c path.c man_1_simple_shell 
    a.out take_input.c README.md simple_shell.c tokening.c

**Non-interactive mode:**

Command:
```
$ echo "/bin/ls" | ./a.out
```
Output:

     AUTHORS execute_arg.c path.c man_1_simple_shell 
     take_input.c README.md simple_shell.c tokening.c







## File Contents

|  |  |
|--|--|
|main.h|  |
| simpleshell.c |  |
|take_input.c
|tokening.c  |  |
|path.c||
|execute_arg.c|  |



## Flowchart 

[Flowchart link](Flowchart%20link)


## Authors
- Mathew Krozel <mattkrozel@gmail.com>
- Abrielle Perry <abrielleperry22@icloud.com>
