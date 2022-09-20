#include "../inc/part_of_the_matrix.h"

bool mx_isvalid_operand(const char *s){

    int index = 0;
    
    if(mx_strlen(s) <= 0)
        return false;

    while(s[index] != '\0'){
        if(index == 0 && s[index] == '-'){
        //
        }else if(!mx_isdigit(s[index]))
            if(s[index] != '?')
                return false;
        index += 1;
    }

    return true;
}


