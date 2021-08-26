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
#include <stdarg.h>
#include <errno.h>
#include <signal.h>

#define UNUSED(x) (void)(x)

/*Global Variable*/
extern char **environ;

/*Structures*/
typedef struct variables
{
	char *buffer; /*Buffer to getline*/
	char **arrays; /*Array of pointers to strings*/
} vars_t;

typedef struct arguments
{
	char *n; /*String to do match*/
	char (*f)(vars_t *r); /*Pointer to function after do match*/
} arg_t;

typedef struct com_help
{
	char *name;
	char (*p)(vars_t *r);
} help_v;

/*Main*/
int main(int argc , char *argv[] , char **enviroment);
char **tokenizer(char *buffer , char *delimiter);
char *str_tok(char *buffer, char *d);
char (*match(vars_t *m))(vars_t *n);
char file_exit(vars_t *vars);
int signal_C(void);

/*Tools to strings*/
int _strncmp(const char *s1, const char *s2, size_t n);
char *str_cat(char *s1, char *s2);
size_t len_str(char *str);
char *str_dup(char *str);
void *fill_an_array(void *a, int el, unsigned int len);

/*Check path*/
void check_path(vars_t *vars, char **enviroment);
int check2_path(vars_t *vars, char **enviroment);
char *_getenv(char *path_name);
int _setenv(char *path_name);

/**/
void free_struct(vars_t *vars);
int iter_number(char *buffer);
void handle_sigint(int sig);
char change_directory(vars_t *vars);

/*memory*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

/*History command*/
void add_history(vars_t *vars);
char print_history(vars_t *vars);
char *file_read(char *namefile);
int write_file(char *namef, int n, ...);
int only_chars(char *str, char character , char until);
int _atoi(char *string_number);
unsigned int un_int_to_buffer(int number, char *buffer, int idx);
int sizeofnum(int number);
char *get_index(void);

/*Help command*/
char help_func(vars_t *vars);
char (*help_match(vars_t *vars))(vars_t *vars);

/*Print help arguments*/
char print_exit(vars_t *vars);
char print_cd(vars_t *vars);
char print_help(vars_t *vars);
char help_print_history(vars_t *vars);

#endif
