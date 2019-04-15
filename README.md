
The Own Shell Project
=====================

This is a shell project created by two students of Holberton School, how part of the challenges for become to enginner software developers.

This **Shell** allows run some basics commands of the shell linux, like to ls, pwd, cat, etc mostly contained path /bin.

## Getting Started

Make a copy of this project up and compile **C** files using *gcc* compiler see installing section.

### Prerequisites

You need the follow software to run the shell:

* Linux Ubuntu 14.04.3 LTS
* gcc 4.8.4

### Installing

Follow the next steps for installing this shell:

1 - Once you have downloaded the repository, run the following command to compile the files:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
2- Execute shell with the command:
```
./hsh
```

## Running the tests

You can try this shell by running the following commands.

### ls command

Run the shell and type command *ls* and press enter: 

```
> ./hsh
#cisfun$ls
#Makefile#  _strcat.c   exec.c         freelist.c       print_list.c
AUTHORS     _strcmp.c   getline.c      Makefile         _strdup.c   
handle_sigint.c         shell.c        README.md        _strncmp.c  
_getenv.c   commands.c  free.c         hsh              test
#cisfun$
```
### ls command executed from /bin path

Run the shell and type command */bin/ls* and press enter: 

```
> ./hsh
#cisfun$/bin/ls
#Makefile#  _strcat.c   exec.c         freelist.c       print_list.c
AUTHORS     _strcmp.c   getline.c      Makefile         _strdup.c   
handle_sigint.c         shell.c        README.md        _strncmp.c  
_getenv.c   commands.c  free.c         hsh              test
#cisfun$
```
### pwd command

Run the shell and type command *pwd* and press enter: 

```
> ./hsh
#cisfun$pwd
/home/vagrant/projects/simple_shell
#cisfun$
```
### cat command

Run the shell and type command *cat **namefile*** and press enter: 

```
> ./hsh
#cisfun$cat AUTHORS
# This file lists all individuals having contributed content to the repository.

Rodrigo Sierra <735@holbertonschool.com>
Yony Brinez <769@holbertonschool.com>
#cisfun$
```

### Other tests

You can contribute to do more test int those repositories [Holberton test shell](https://github.com/holbertonschool/0x15.c/) and [Holberton Colombia test shell](https://github.com/holberton-school-colombia/tests_simple_shell).

## Versioning

This repository is open source. 

## Authors

* **Rodrigo Sierra** - *Initial work* - [Git Hub Repository](https://github.com/RodrigoSierraV)
* **Yony Briñez** - *Initial work* - [Git Hub Repository](https://github.com/arleybri18/)

See also the list of [contributors](https://github.com/arleybri18/simple_shell/blob/master/AUTHORS) who participated in this project.

## Acknowledgments

* Holberton School thanks for this challenge that allows to put into practice all the acquired knowledge.

