#include "../inc/part_of_the_matrix.h"

bool mx_isspace(char c){
    if(c == 32 || c == 10 ||
       c == 9 || c == 12 ||
       c == 11 || c == 13)
        return true;
    return false;
}



