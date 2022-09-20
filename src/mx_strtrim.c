#include "../inc/part_of_the_matrix.h"


static int get_ffront_char(const char *str){
    int index = 0;
    int len = mx_strlen(str);

    if(len <= 0)
        return -1;

    while(mx_isspace(str[index])){
        index += 1;

        if(index > len - 1)
            return -1;
    }

    return index;
}

static int get_fback_char(const char *str){
    int index = mx_strlen(str) - 1;

    while(mx_isspace(str[index])){
        index -= 1;
        if(index <= -1)
            return -1;
    }

    return index;
}

char *mx_strtrim(const char *str){
   char *n_str;
   int f_index;
   int l_index;

    if(str == NULL)
        return NULL;
    f_index = get_ffront_char(str);
    l_index = get_fback_char(str);

    if(f_index == -1 || l_index == -1)
        return NULL;
    n_str = mx_strnew(l_index - f_index);
    n_str = mx_strncpy(n_str, str + f_index, l_index - f_index + 1);
    return n_str;
}



