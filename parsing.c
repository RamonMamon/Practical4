#include "parsing.h"

Gate* parse_Gate(char* line){
    const char delim[] = " \n";
    int i = 0;
    char* string[4];
    char* token = strtok(line, delim);
    while(token != NULL){
        if(i > 3 || (!isOperator(token) && i == 1)|| (isPredefined(token) && i == 0)){
            printf("Invalid specification.\n");
            exit(0);
        }
        string[i] = malloc(strlen(token) + 1);
        strcpy(string[i], token);
        token = strtok(NULL, delim);
        i++;
    }
    return new_Gate(string[0], string[1], string[2], string[3]);
}

void runCircuit(Gates* gates){
    Gates* node = gates;
    //Iterates through the list and gets the values of the input wires
    while(node != NULL){
        Gate* current = node->gate;
        //Check if the gate is an IN wire?
        if(current->input1 != NULL){
            current->previousState = current->currentState;
            current->currentState = conductOperation(current, getValue(current->input1, gates), getValue(current->input2, gates));
            printf("%s %d \n",current->name, current->currentState);
        }
        node = node->next;
    }
}

/**
 * Gets the value of a specified input wire by searching the list of gates
 * and comparing the names.
 */
int getValue(char* wireName, Gates* gates){
    Gates* node = gates;
    while(node != NULL){
        Gate* current = node->gate;
        if(strcmp(wireName, current->name) == 0){
            return current->previousState;
        }
        node = node->next;
    }
    //The wire does not exist.
    return 2;
}

bool conductOperation(Gate* gate, bool* input1, bool* input2){
    if(strcmp(gate->operand, operators[NAND]) == 0){
        printf("%d %d\n", input1, input2);
        return nandGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[NOT]) == 0){
        printf("%d\n", input1);
        return notGate(input1);
    }
    if(strcmp(gate->operand, operators[OR]) == 0){
        printf("%d %d\n", input1, input2);
        return orGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[XOR]) == 0){
        printf("%d %d\n", input1, input2);
        return xorGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[NOR]) == 0){
        printf("%d %d\n", input1, input2);
        return norGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[AND]) == 0){
        printf("%d %d\n", input1, input2);
        return andGate(input1, input2);
    }
}

bool notGate(bool* val){return !val;}

bool orGate(bool* val, bool* val2){return val||val2;}

bool andGate(bool* val, bool* val2){return val && val2;}

bool nandGate(bool* val, bool* val2){return notGate(andGate(val,val2));}

bool norGate(bool* val, bool* val2){return notGate(orGate(val,val2));}

bool xorGate(bool* val, bool* val2){return val != val2;}

/*
Checks if the string is an operator.
*/
bool isOperator(char* string){
    for(int i = 0; i < numberOfOps; i++){
        if(strcmp(string, operators[i]) == 0) return true;
    }
    return false;
}

bool isPredefined(char* string){
    for(int i = 0; i < 2; i++){
        if(strcmp(string, predefWires[i]) == 0) return true;
    }
    return false;
}