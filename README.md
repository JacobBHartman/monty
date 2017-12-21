# monty

## Objectives
 * Learn about LIFO and FIFO using Stacks and Queues, respectively
 * Create a Monty file interpreter that takes in simple commands to manipulate a Stack data structure, from scratch

## Features
- [x] push, pall, pint, pop
- [x] swap, nop
- [x] add
- [ ] sub, div, mul, mod
- [ ] comments
- [ ] pchar, pstr
- [ ] rotl, rotr
- [ ] stack, queue

## System and Environment
 * Compiler: `gcc 4.8.4`
 * Tested on Ubuntu 14.04 LTS using Vagrant in VirtualBox

## Installation
 * Clone the repository: `git clone https://github.com/JacobBHartman/monty.git`
 * Change into the proper directory: `cd monty`
 * Compile using `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
 * Usage: `$ ./monty <montyfile>`

## Usage example
```
vagrant@vagrant-ubuntu-trusty-64:~/monty$ ls
dot_m_files  monty.c      monty.h    ops_basic.c  pick_op.c  stack.c
monty        montyfile.m  ops_adv.c  ops_math.c   README.md
vagrant@vagrant-ubuntu-trusty-64:~/monty$ cat montyfile.m | cat -e
push 0$
push 1$
pall$
push 2$
push 3$
pall$
pint$
pop$
pint$
swap$
pall$
add$
pint$
pall$
nop$
pall$
pop$
pop$
pall$
pint$
vagrant@vagrant-ubuntu-trusty-64:~/monty$ ./monty montyfile.m
1
0
3
2
1
0
3
2
1
2
0
3
3
0
3
0
L20: can't pint, stack empty
vagrant@vagrant-ubuntu-trusty-64:~/monty$
```

## File Descriptions
---
File | Description
--- | ---
`dot_m_files` | a directory containing monty files
`README.md` | self-explanatory
`monty.c` | main program flow and execution
`monty.h` | header file for the program
`montyfile.m` | test file used in above usage example
`ops_adv.c` | relatively advanced operations: `swap`, `nop`
`ops_basic.c` | relatively basic operations: `push`, `pall`, `pint`, `pop`
`ops_math.c` | math-based operations: `add`
`pick_op.c` | picks which operations will be ran
`stack.c` | manipulates the stack

## styling guide
 * `Betty` [styling](https://github.com/holbertonschool/Betty/wiki)
 * variables should be descriptive but not so long that they make the code unreadable
 * function names should usually follow the format of verbObject
 * loop-index variables and function pointers can be one letter

## Author(s)
 * Jacob Hartman - github: `JacobBHartman`