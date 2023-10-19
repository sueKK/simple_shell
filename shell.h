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
void write_string(const char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
void execute(char **command);
void read_input(char *input, size_t input_size);

#endif
