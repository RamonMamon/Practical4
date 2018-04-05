#include <string.h>
#include "parsing.h"

Gate* parse_Gate(char* line){
    const Wire* one = new_Wire("one", 1);
    const Wire* zero = new_Wire("zero", 0);
    const Wire* out = new_Wire("out", 0);
    const char delim[2] = " \n";
    char* string[4];
    int i = 0;
    string[i] = strtok(line, delim);
    while(string[i] != NULL){
        //Check if 2nd index is an operator
        // printf("%s\n", string[i]);
        i++;
        string[i] = strtok(NULL, delim); 
        printf("%s\n", string[i]);
        if(i > 3 || (!isOperator(string[1]) && i == 1)){
            printf("Invalid specification.\n");
            exit(0);
        }
    }
    Wire* outputWire;
    if(strcmp(string[0], out->name) == 0) outputWire = out;
    else outputWire  = new_Wire(string[0], 0);
    return new_Gate(outputWire, string[1], string[2], string[3]);
}

void createCircuit(){
    
}

/*
Checks if the string is an operator.
*/
bool isOperator(char* string){
    for(int i = 0; i < numberOfOps; i++)
        if(strcmp(string, operators[i]) == 0) return true;
    return false;
}

//Create a function that can calculate the output value of a gate (based off the input values and the number of IN gates).
//This function can then be called based of the factorial of the number of IN gates to get all of the possible combinations.