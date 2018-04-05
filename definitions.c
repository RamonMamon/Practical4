#include "definitions.h"

const int numberOfOps = 8;
const char* operators[] = {"IN","NOT", "AND", "NAND", "OR", "NOR", "XOR","EQ"};

Wire* new_Wire(char* name, int val){
    Wire* newWire = malloc(sizeof(Wire));
    newWire->name = name;
    newWire->value = val;
    newWire->isWired = false;
    return newWire;
}

Gate* new_Gate(Wire* output, char* operand, char* inputWire1, char* inputWire2){
    Gate* newGate = malloc(sizeof(Gate));
    newGate->output = output;
    newGate->operand = operand;
    newGate->input1 = inputWire1;
    newGate->input2 = inputWire2;
    return newGate;
}

void setValue(Wire* wire, int val){
    wire->value = val;
}

void setGate(Wire* wire, Gate* outputGate){
    wire->outputGate = outputGate;
}