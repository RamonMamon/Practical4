#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#define T true
#define F false

typedef struct wire Wire;
typedef struct gate Gate;
typedef struct gates Gates;


struct wire {
    char* name;
    int value;
    bool isWired;
    Gate* outputGate;
};

struct gate{
    char* operand;
    Wire* output;
    char* input1;
    char* input2;
    // Wire* input[];
};

struct gates{
    Gate* gate;
    Gates* next;
};
#endif
extern const int numberOfOps;
enum enumOps{IN,NOT, AND, NAND, OR, NOR, XOR,EQ};
extern const char* operators[];

//Define a zero and one wire for obvious reasons.
extern const Wire* one;
extern const Wire* zero;
extern const Wire* out;

//Gates Struct to form list of gates.

Wire* new_Wire(char* name, int val);

Gate* new_Gate(Wire* output, char* operand, char* inputWire1, char* inputWire2);

//Sets Wire Value.
void setValue(Wire* wire, int val);

/*
Gives a wire an output Gate.
*/
void setGate(Wire* wire, Gate* outputGate);