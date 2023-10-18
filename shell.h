#ifndef SHELL_H
#define SHELL_H
#define MAX_INPUT_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

size_t _strlen(const char *str);
char *_strdup(const char *str);
void write_string(int fd, const char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
void execute_command(char **command_and_args);
void handle_command_not_found(const char *command);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
void free_command_args(char **command_and_args);
char **tokenize_input(char *input);
char *_getenv(const char *name, char **env);
char **get_environment_variables();
char **retrieve_environment_variables();
void free_environment_variables(char **env);

#endif
