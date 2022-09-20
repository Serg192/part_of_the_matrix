#include "../inc/part_of_the_matrix.h"

static int skip_whitespace(const char *str){
    int index = 0;
    while(str[index] == ' ')
        index += 1;
    return index;
}

int mx_atoi(const char *str){
    int int_max = 2147483647;
    int int_min = -2147483648;
    int index = skip_whitespace(str);
    int number_sign  = 1;
    int result = 0;
    
    if(str[index] == '-'){
        number_sign = -1;
        index += 1;
    }

    while(str[index] >= '0' && str[index] <= '9'){
        
        if(result > int_max / 10 || (result == int_max / 10
            && (str[index]  - '0' > 7)))
           return (number_sign == -1 ? int_min : int_max);
        result = result * 10 + str[index] - '0';
        index += 1;
    }
    return number_sign * result;
}


