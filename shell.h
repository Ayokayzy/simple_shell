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

void prompt(void);
char **get_argv(char *buffer, char *delim);
void free_tokens(char **av);
void handle_err(char *err, char *command);
ssize_t execute_command(char **av, char **argv, char *line);
int _strlen(char *str);
char *_concat(char *a, char *b, char *c);
char *_getenv(const char *name);
int has_path(char *command);
char *handle_path(char *command);
char *_which(char *filename);
char *_strdup(char *str);
int builtin_exit(char **av, char *line);
int is_builtin(char *command);
int handle_builtin(char *command, char **av, char *line);
int _printenv(void);
int printchar(char c);
char *concat2str(char *a, char *b);
void printstring(char *str);
void error_print(char *filename, char *command);
int _fork(char **av, char **argv, char *command, char *line);

#endif
