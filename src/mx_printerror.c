#include "../inc/part_of_the_matrix.h"

void mx_printerror(int e, const char *arg){
    const char *inv_op_msg = "Invalid operation: ";
    const char *inv_opr_msg = "Invalid operand: ";
    const char *inv_res_msg = "Invalid result: ";
    char nline = '\n';

    switch(e){
        case INCORRECT_OPERAND:
            write(2, inv_opr_msg, mx_strlen(inv_opr_msg));
            break;
        case INCORRECT_OPERATION:
            write(2, inv_op_msg, mx_strlen(inv_op_msg));
            break;
        case INVALID_RESULT:
            write(2, inv_res_msg, mx_strlen(inv_res_msg));
            break;
        default:
            break;
            
    }
    write(2, arg, mx_strlen(arg));
    write(2, &nline, 1);
}

