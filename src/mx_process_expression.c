#include "../inc/part_of_the_matrix.h"

static void brute_force_with_op(t_expression *ex, char operation){
    t_expression copy;
    copy.operand1 = mx_strdup(ex->operand1);
    copy.operand2 = mx_strdup(ex->operand2);
    copy.result = mx_strdup(ex->result);
    copy.operation = operation;

    mx_brute_force(&copy);

    free(copy.operand1);
    free(copy.operand2);
    free(copy.result);
}

void mx_process_expression(t_expression *ex){
    if(ex->operation != '?')
        mx_brute_force(ex);
    else{
        brute_force_with_op(ex, '+');
        brute_force_with_op(ex, '-');
        brute_force_with_op(ex, '*');
        brute_force_with_op(ex, '/');
    }
}


