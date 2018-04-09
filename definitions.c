#include "definitions.h"

const int numberOfOps = 8;
const char* operators[] = {"IN","NOT", "AND", "NAND", "OR", "NOR", "XOR","EQ"};
const char* predefWires[] = {"zero","one"};

Gate* new_Gate(char* output, char* operand, char* inputWire1, char* inputWire2){
    Gate* newGate = malloc(sizeof(Gate));
    newGate->name = output;
    newGate->operand = operand;
    newGate->input1 = inputWire1;
    newGate->input2 = inputWire2;
    bool val = false;
    if(strcmp(output, predefWires[1]) == 0) val = true;
    newGate->currentState = val;
    newGate->previousState = val;

    return newGate;
}

void setValue(Gate* gate, int val){
    gate->previousState = gate->currentState;
    gate->currentState = val;
}