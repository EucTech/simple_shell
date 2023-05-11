#ifndef MAIN_H
#define MAIN_H

/**********          **********/
/******** HEADER FILES ********/
/**********          *********/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/****** ENVIRONMENT *******/
extern char **environ;


/**********          **********/
/******** STRING FUNCS ********/
/**********          *********/



/**********          **********/
/****** SHELL FUNCTIONS  *******/
/**********          *********/

int main(int ac, char **av);
void prompt(void);
void sig_handle(int sig);
void _EOF(char *buff);

#endif
