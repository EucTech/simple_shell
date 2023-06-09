#ifndef MAIN_H
#define MAIN_H

/**********          **********/
/******** HEADER FILES ********/
/**********          *********/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <dirent.h>


/****** ENVIRONMENT *******/
extern char **environ;

/********** MACRO **********/
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define BUFF 1024
#define MAX_COMMAND 100

/**********          **********/
/****** STRUCT BUILT_IN *******/
/**********          *********/

/**
 * struct han_builtin - This is a function that that will handle the builtins
 * @exe: This is the command
 * @check: This is a for execution
 */

typedef struct han_builtin
{
	char *exe;
	int (*check)(char **count, int sta);
} my_bit;


/**********          **********/
/******** STRING FUNCS ********/
/**********          *********/
int _atoi(char *s);
char *_itoa(int n);
int _isalpha(int c);
int count_num(int n);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(char *n);
void *_realloc(void *ptr, unsigned int size_a, unsigned int size_b);
char *_strtok(char *str, const char *d);
unsigned int is_delim(char ch, const char *str);

/**********          **********/
/****** SHELL FUNCTIONS  *******/
/**********          *********/

int main(int ac, char **av);
void prompt(void);
void sig_handle(int sig);
void _EOF(char *buff);
char **token(char *name);
void not_found(char *input, int line, char **av);
int execute_com(char **av, char *input, int line, char **cmd);
char *get_command_dir(char *token, char *dir);
int get_command(char **cmd);
ssize_t _getline(char **lptr, size_t *l, FILE *stream);
void allocate_lptr(char **lptr, size_t *l, char *buff, size_t b);
void my_exit(char **cmd, char *pointer, char **av, int line);
void print_er(char **av, int line, char **cmd);
int my_builtin(char **cmd);
void print_env(void);
int change_dir(char **cmd);
char *token2(char *pointer, size_t *n);

#endif
