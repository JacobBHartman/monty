# monty

## Objectives
 * Learn about LIFO and FIFO using Stacks and Queues, respectively
 * Create a Monty file interpreter that takes in simple commands to manipulate a Stack data structure, from scratch

## Features
- [x] push
- [x] pall
- [x] pint
- [x] pop
- [x] swap
- [x] add
- [x] nop
- [] sub, div, mul, mod
- [] comments
- [] pchar, pstr
- [] rotl, rotr
- [] stack, queue

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
dot_m_files  monty.c      montyfile.m~  ops_adv.c    ops_math.c  README.md
monty        montyfile.m  monty.h       ops_basic.c  pick_op.c   stack.c
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


## styling guide
 * Betty
 * variables should be descriptive but not so long that they make the code unreadable
 * function names should usually follow the format of verbObject
 * loop-index variables and function pointers can be one letter

