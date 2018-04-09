#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef struct gate Gate;
typedef struct gates Gates;

struct gate{
    char* operand;
    char* input1;
    char* input2;
    char* name;
    bool* currentState;
    bool* previousState;
};

struct gates{
    Gate* gate;
    Gates* next;
    Gates* previous;
};
#endif
extern const int numberOfOps;
enum enumOps{IN,NOT, AND, NAND, OR, NOR, XOR,EQ};
extern const char* operators[];
extern const char* predefWires[];

//Gates Struct to form list of gates.
Gate* new_Gate(char* output, char* operand, char* inputWire1, char* inputWire2);

//Sets Wire Value.
void setValue(Gate* gate, int val);