#include "definitions.h"
#include "parsing.h"


void process_line(char* line){
    const char delim[2] = " \n";

    char* string = strtok(line, delim);
    printf("%s", string);
}
//Implement a function that reads the lines of a file.

//Create a function that creates Wires and gates from read input.

//Create a function that can calculate the output value of a gate (based off the input values and the number of IN gates).
//This function can then be called based of the factorial of the number of IN gates to get all of the possible combinations.