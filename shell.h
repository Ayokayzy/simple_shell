#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

extern char **environ;

void prompt();
char **get_argv(char *buffer, char *delim);
void free_tokens(char **av);
void handle_err(char *err, char *command);
ssize_t execute_command(char **av, char **argv);
int _strlen(char *str);
char *_concat(char *a, char *b, char *c);
char *_getenv(const char *name);
int has_path(char *command);
char *handle_path(char *command);
char *_which(char *filename);
char *_strdup(char *str);
void builtin_exit(int status, char **av, char *buff);
int is_builtin(char *command);
void handle_builtin(char *command, int status, char **av, char *buff);
void _printenv(void);
int printchar(char c);
char *concat2str(char *s1, char *s2);
void printstring(char *str);
void error_print(char *filename, char *command);

#endif
