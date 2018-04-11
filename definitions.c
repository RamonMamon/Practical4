#include "definitions.h"

const int numberOfOps = 8;
const char* operators[] = {"IN","NOT", "AND", "NAND", "OR", "NOR", "XOR","EQ"};
const char* predefWires[] = {"zero","one"};

Gate* new_Gate(char* output, char* operand, char* inputWire1, char* inputWire2){
    Gate* newGate = malloc(sizeof(Gate));
    newGate->name = output;
    newGate->operand = operand;
    if(strcmp(operand, operators[IN] )==0){
        newGate->input1 = NULL;
        newGate->input2 = NULL;
    }else{
        newGate->input1 = inputWire1;
        newGate->input2 = inputWire2;
    }
    if(!isOperator(operand)|| isPredefined(output)){
            printf("Invalid specification.\n");
            exit(0);
    }

    bool val = false;
    if(strcmp(output, predefWires[1]) == 0) val = true;
    newGate->currentState = val;
    newGate->previousState = val;
    return newGate;
}

/**
 * The definitions for each gate.
 */
bool notGate(bool* val){return !val;}

bool orGate(bool* val, bool* val2){return val||val2;}

bool andGate(bool* val, bool* val2){return val && val2;}

bool nandGate(bool* val, bool* val2){return notGate(andGate(val,val2));}

bool norGate(bool* val, bool* val2){return notGate(orGate(val,val2));}

bool xorGate(bool* val, bool* val2){return val != val2;}

/**
 * Checks if the string is an operator by traversing through the list
 * of valid operators.
 */
bool isOperator(char* string){
    for(int i = 0; i < numberOfOps; i++){
        if(strcmp(string, operators[i]) == 0) return true;
    }
    return false;
}

/**
 * Checks if the specified string is predefined by iterating through the array of 
 * predefined wires.
 */
bool isPredefined(char* string){
    for(int i = 0; i < 2; i++){
        if(strcmp(string, predefWires[i]) == 0) return true;
    }
    return false;
}