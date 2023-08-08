#ifndef main_h
#define main_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024
#define WHITESPACE " \n\t\r"

extern char **environ;

void handle(int signals);
char **split_string(char *str, const char *delimiters, int *num_tokens);
char *find_command(char *command);
void free_tokens(char **tokens, int num_tokens);
void execute_input(char **argv);
void print_enviro(char **env);

#endif 
