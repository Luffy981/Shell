#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef struct variables
{
	char *buffer;
	char **arrays;
}vars_t;

typedef struct arguments
{
	char *n;
	void (*f)(vars_t *);
}arg_t;

char **tokenizer(char *buffer , char *delimiter);
int main (int argc , char **argv[] , char **enviroment);
void  (*match (vars_t *vars))(vars_t *vars);
void file_exit(vars_t *vars);
void file_number(vars_t  *vars);
#endif
