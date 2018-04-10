#include "definitions.h"

/*
This function returns a gate which is specified through a line of string.
*/
Gate* parse_Gate(char* line);

/*
This function will change the input values of the circuit.
*/
void changeInputVals(Gates* gates, int** digits, int index);

/*
This function will be used to wire the gates together to create working circuit.
*/
void runCircuit(Gates* gates);

void update(Gates*gates);

bool isStable(Gates* gates,int index);

void clearGates(Gates* gates);

int getValue(char* wireName, Gates* gates);

void printLine(Gates* gates, bool isStable);

bool conductOperation(Gate* currentGate, bool* input1, bool* input2);
