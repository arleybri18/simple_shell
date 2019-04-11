#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<signal.h>
/**
 * struct paths - singly linked list
 * @next: pointer to the next node
 * @str: string with a path from environment
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct paths
{
	char *str;
	struct paths *next;
} path;
void handle_sigint(int sig);
void fun_getline(void);
void fun_exec(char **);
path **_extractpath(path **head, char *);
void print_list(const path *h);
extern char **environ;
char *_getenv(char *);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
#endif /*_HOLBERTON_H_*/
