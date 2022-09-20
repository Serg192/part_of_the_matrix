#include "../inc/part_of_the_matrix.h"

static char *pass_front_zeros(char *number){

    int index = 0;
    int last = mx_strlen(number) - 1;


    while((*(number + index) == '0') && index != last){
        index += 1;
    }

    return number + index;
}

void mx_printexpression(t_expression *ex){
    mx_printstr(pass_front_zeros(ex->operand1));
    mx_printstr(" ");
    mx_printstr(&ex->operation);
    mx_printstr(" ");
    mx_printstr(pass_front_zeros(ex->operand2));
    mx_printstr(" ");
    mx_printstr("=");
    mx_printstr(" ");
    mx_printstr(pass_front_zeros(ex->result));
    mx_printstr("\n");
}





