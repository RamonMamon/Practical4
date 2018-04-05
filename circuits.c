#include "parsing.h"

void testFunc(int* i){
    *i = 5;
}

int main(int argc, char* argv[]){
    //Don't forget to implement arguments.
    // if(argc != 3)

    FILE* file;
    int size = 30;
    char* line = malloc(sizeof(char)*size);

    file = fopen("./Input Files/srnandlatch.txt", "r");

    //Used to store a list of all the gates.
    Gates* gates = malloc(sizeof(Gates));
    Gates* last;
    //Segementation fault error here when last = gate->next;
    gates = last;
    while(fgets(line, size, (FILE*)file)){
        last = malloc(sizeof(Gates));
        last->gate = parse_Gate(line);
        last = last->next;
    }
    while(gates != NULL){
        printf("%s\n", gates->gate->operand);
        gates = gates->next;
    }

    //Implement printing of values here.
    return 0;
}