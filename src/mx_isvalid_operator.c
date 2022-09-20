#include "../inc/part_of_the_matrix.h"


bool mx_isvalid_operator(const char *s){
    bool only_one = false;
    int index = 0;

    while(s[index] != '\0'){

        if((s[index] == '+' ||
            s[index] == '-' ||
            s[index] == '*' ||
            s[index] == '/' ||
            s[index] == '?') && !only_one){
            only_one = true;
        }else
             return false;

        index += 1;
    }

    return true;
}


