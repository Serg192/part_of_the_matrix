#include "../inc/part_of_the_matrix.h"

void mx_printstr(const char *s){
    int index = 0;

    while(s[index] != '\0'){
        write(1, &s[index], 1);
        index += 1;
    }
}


