#include "../inc/part_of_the_matrix.h"

int mx_strlen(const char *s){
    int len = 0;

    while(s[len] != '\0')
        len += 1;

    return len;
}


