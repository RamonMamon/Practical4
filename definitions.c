#include "definitions.h"

const Wire one = new_Wire("one", 1);
const Wire zero = new_Wire("zero", 0);

Wire* new_Wire(char* name, int val){
    Wire* newWire = malloc(sizeof(Wire));
    newWire->name = name;
    newWire->value = val;
    return newWire;
}

Gate* new_Gate(Wire output, char* operand, Wire input[], int numInputs){
    Gate* newGate = malloc(sizeof(Gate) + (sizeof(Wire)*numInputs));
    newGate->output = output;
    newGate->operand = operand;
    newGate->input = input;
    return newGate;
}

void setValue(Wire* wire, int val){
    wire->value = val;
}