#include "definitions.h"

/*
This function returns a gate which is specified through a line of string.
*/
Gate* parse_Gate(char* line)

/*
This function will be used to wire the gates together to create working circuit.
*/
void createCircuit(Gates* gates);

/*
This function checks if a specified string is an operator.
*/
bool isOperator(char* string);