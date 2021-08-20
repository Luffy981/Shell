#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>

typedef struct variables
{
	char *buffer; /*Buffer to getline*/
	char **arrays; /*Array of pointers to strings*/
}vars_t;

typedef struct arguments
{
	char *n; /*String to do match*/
	char (*f)(vars_t *r); /*Pointer to function after do match*/
}arg_t;

int main (int argc , char *argv[] , char **enviroment);
char **tokenizer(char *buffer , char *delimiter);
char (*match (vars_t *m))(vars_t *n);
char file_exit(vars_t *vars);
char file_number(vars_t  *vars);
char list_files(vars_t *env);
char current_directory(vars_t *pwd);
char delete_file_or_directory(vars_t *rm);
char clean_trash(vars_t *clean);
int _strncmp(const char *s1, const char *s2, size_t n);
char *str_cat(char *s1, char *s2);
int _strlen(char *s);
void check_path(vars_t *vars, char **enviroment);
int check2_path(vars_t *vars, char **enviroment);
void free_struct(vars_t *vars);
#endif
