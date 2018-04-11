#include "definitions.h"

/*
This function returns a gate which is specified through a line of string.
*/
Gate* parse_Gate(char* line);

/*
This function will change the input values of the circuit.
*/
void changeInputVals(Gate* gates, int** digits, int index);

/*
This function is used to "Run" the circuit by 
*/
void runCircuit(Gate* gates);

/*
This function checks if a gate is stable.
*/
bool isStable(Gate* gates, bool outExists);

/*
This function resets the values of each wire.
*/
void clearGates(Gate* gates);

/*
This function returns the previous value of a specified wire.
*/
int getValue(char* wireName, Gate* gates);

/*
This function is used to print a line of current values of each wire.
*/
void printLine(Gate* gates, bool isStable, bool outExists);

/*
This function carries out the operation specified of the current gate
and returns the value of the conducted operation.
*/
bool conductOperation(Gate* currentGate, bool* input1, bool* input2);
