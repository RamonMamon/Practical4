#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define true T
#define false F
//Define a zero and one wire for obvious reasons.
const Wire one;
const Wire zero;

typedef struct wire{
    char* name;
    int value;
}Wire;

typedef struct gate{
    char* operand;
    Wire output;
    Wire input[];
    //Possibly put next gate to link the gates together.
}Gate;

//Gates Struct to form list of gates.

Wire* new_Wire(char* name, int val);

Gate* new_Gate(Wire* output, char* operand, Wire* input[], int numInputs);

//Sets Wire Value
void setValue(Wire* wire, int val);