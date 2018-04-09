#include "definitions.h"

/*
This function returns a gate which is specified through a line of string.
*/
Gate* parse_Gate(char* line);

/*
This function will be used to wire the gates together to create working circuit.
*/
void runCircuit(Gates* gates);

int getValue(char* wireName, Gates* gates);

bool conductOperation(Gate* currentGate, bool* input1, bool* input2);
/*
This function checks if a specified string is an operator.
*/
bool isOperator(char* string);

bool isPredefined(char* string);

bool notGate(bool* val);

bool orGate(bool* val, bool* val2);

bool andGate(bool* val, bool* val2);

bool nandGate(bool* val, bool* val2);

bool norGate(bool* val, bool* val2);

bool xorGate(bool* val, bool* val2);