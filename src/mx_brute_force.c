#include "../inc/part_of_the_matrix.h"

#include <stdio.h>


static void set_start_state(t_expression *ex, bool *c_opr1, bool *c_opr2, bool *c_res){
    for(int i = 0; i< mx_strlen(ex->operand1); i++)
        if(ex->operand1[i] == '?'){
            ex->operand1[i] = '0';
            c_opr1[i] = true;
        }else
            c_opr1[i] = false;

    for(int i = 0; i < mx_strlen(ex->operand2); i++)
        if(ex->operand2[i] == '?'){
            ex->operand2[i] = '0';
            c_opr2[i] = true;
        }else
            c_opr2[i] = false;

    for(int i = 0; i < mx_strlen(ex->result); i++)
        if(ex->result[i] == '?'){
            ex->result[i] = '0';
            c_res[i] = true;
        }else
            c_res[i] = false;
}

static char next_num(char c){
    if(c == '9'){
        return 48;
    }
    return (char)((int)c + 1);
}

//return true if should increment next string
static bool increment(char *operand, int index, bool *can_inc){

    if(can_inc[index])
        operand[index] = next_num(operand[index]);
    else{
        if(index - 1 >= 0)
            return increment(operand, index - 1, can_inc);
        else
            return true;
    }

    if(operand[index] == '0'){
        if(index - 1 < 0)
            return true;
        return increment(operand, index - 1, can_inc);    
    }

    return false;
}

static void print_if_equal(t_expression *ex){
    int opr1 = mx_atoi(ex->operand1);
    int opr2 = mx_atoi(ex->operand2);
    int res = mx_atoi(ex->result);

    switch(ex->operation){
        case '+':
            if(opr1 + opr2 == res)
                mx_printexpression(ex);
            break;
        case '-':
            if(opr1 - opr2 == res)
                mx_printexpression(ex);
            break;
        case '*':
            if(opr1 * opr2 == res)
                mx_printexpression(ex);
            break;
        case '/':
            if(opr2 != 0 && opr1 / opr2 == res)
                mx_printexpression(ex);
            break;
        default:
            break;
    }
}

void mx_brute_force(t_expression *ex){
    bool c_opr1[mx_strlen(ex->operand1)];
    bool c_opr2[mx_strlen(ex->operand2)];
    bool c_res[mx_strlen(ex->result)];
    bool can_process_next = true;

    set_start_state(ex, c_opr1, c_opr2, c_res);
    print_if_equal(ex);

    while(can_process_next){
        if(increment(ex->result, mx_strlen(ex->result) - 1, c_res)){
            if(increment(ex->operand2, mx_strlen(ex->operand2) - 1, c_opr2)){
                if(increment(ex->operand1, mx_strlen(ex->operand1) - 1, c_opr1)){
                    can_process_next = false;
                }
            }
        }
        if(can_process_next){
            print_if_equal(ex);       
        }
    }
}


