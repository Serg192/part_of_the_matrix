#include "../inc/part_of_the_matrix.h"

void mx_evaluate_expression(char *argv[], t_evresult *res){

    if(!mx_isvalid_operator(argv[2])){
        //printf("Operator is invalid\n");
        res->arg = argv[2];
        res->res = INCORRECT_OPERATION;
    }
    else if(!mx_isvalid_operand(argv[1])){
        res->arg = argv[1];
        res->res = INCORRECT_OPERAND;
    }
    else if(!mx_isvalid_operand(argv[3])){
        //printf("Second operand is invalid\n");
        res->arg = argv[3];
        res->res = INCORRECT_OPERAND;
    }
    else if(!mx_isvalid_operand(argv[4])){
        //printf("Invalid result\n");
        res->arg = argv[4];
        res->res = INVALID_RESULT;
    }
    else
    {
        res->res = RESULT_OK;
    }
}




