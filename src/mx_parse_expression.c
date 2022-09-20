#include "../inc/part_of_the_matrix.h"

void mx_parse_expression(char **argv, t_expression *ex){
    ex->operand1 = argv[1];
    ex->operation = argv[2][0];
    ex->operand2 = argv[3];
    ex->result = argv[4];
}


