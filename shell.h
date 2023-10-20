#ifndef SHELL_H
#define SHELL_H
#define MAX_INPUT_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;
size_t _strlen(const char *str);
char *_strdup(const char *str);
void write_string(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int execute(char **command, char **av, int idx);
char *read_input(void);
char **tokenize_input(char *input);
void free_command(char **array);
char *_getenv(char *var);
char *get_path(char *command);
void reverse_str(char *str, int length);
void error_message(char *shell_name, char *cmd, int idx);
char *int_to_char(int n);
void write_env(char **command, int *status);
void handle_builtins(char **command, char **av, int *status, int idx);
int _builtin(char *command);
int _positive(char *str);
void X_shell(char **command, char **av, int *status, int idx);
int char_to_int(char *str);

#endif
