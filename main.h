#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
void getEnvCmd(void);
char *get_ln(void);
void freememory(char **string);
char **split_token(char *line_str);
int custom_exec(char **cmd, char **argv, int num);
char *my_getenv(char *glbl_var);
char *find_cmd(char *cmd);
char *my_strdup(const char *input);
int my_strcmp(char *string1, char *string2);
int my_strlen(char *string);
char *my_strcat(char *destin, char *source);
char *my_strcpy(char *copied, char *source);
char *my_itoa(int num);
void my_reverse(char *string, int len);
void output_error(char *prog_name, char *cmd, int num);
#endif
