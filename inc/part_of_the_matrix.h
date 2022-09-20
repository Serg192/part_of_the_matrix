#ifndef PART_OF_THE_MATRIX_H
#define PART_OF_THE_MATRIX_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>


int mx_strlen(const char *str);

bool mx_isspace(char c);

bool mx_isdigit(int c);

void mx_printchar(char c);

void mx_printstr(const char *s);

int mx_atoi(const char *str);

bool mx_isvalid_operator(const char *s);

bool mx_isvalid_operand(const char *s);

bool mx_isvalid_result(const char *s);

void mx_printerror(int error, const char *arg);

char *mx_strtrim(const char *str);

char *mx_strnew(const int size);

char *mx_strdup(const char *str);

char *mx_strncpy(char *dst, const char *src, int len);

char *mx_strcpy(char *dst, const char *scr);

enum e_status {
    INCORRECT_OPERAND,
    INCORRECT_OPERATION,
    INVALID_RESULT,
    RESULT_OK
};

typedef struct s_expression
{
    char *operand1;
    char *operand2;
    char operation;
    char *result;
}              t_expression;

typedef struct s_evresult
{
    int res;
    char *arg;
}              t_evresult;

void mx_printexpression(t_expression *ex);

void  mx_evaluate_expression(char *argv[], t_evresult* res);

void mx_parse_expression(char *argv[], t_expression *ex);

void mx_brute_force(t_expression *ex);

void mx_process_expression(t_expression *ex);


#endif


