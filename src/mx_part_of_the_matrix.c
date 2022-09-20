#include "../inc/part_of_the_matrix.h"

static void print_usage(){
    const char *usage = "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n";
    mx_printstr(usage);
}

static void trim_args(char **argv){
    argv[1] = mx_strtrim(argv[1]);
    argv[2] = mx_strtrim(argv[2]);
    argv[3] = mx_strtrim(argv[3]);
    argv[4] = mx_strtrim(argv[4]);
}

static void free_targs(char **argv){
    free(argv[1]);
    free(argv[2]);
    free(argv[3]);
    free(argv[4]);
}

int main(int argc, char *argv[]){
    t_expression ex;
    t_evresult evr;

    if(argc != 5)
       print_usage();
    else{
        trim_args(argv);
        mx_evaluate_expression(argv, &evr);
        if(evr.res != RESULT_OK){
            mx_printerror(evr.res, evr.arg);
            exit(0);
        }
        mx_parse_expression(argv, &ex);
        mx_process_expression(&ex); 
        free_targs(argv);       
    } 
    return 0;
}


