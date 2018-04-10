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
    if(strcmp(string[1],operators[IN]) == 0 || strcmp(string[0],"out") == 0)
        printf("%s ", string[0]);
    return new_Gate(string[0], string[1], string[2], string[3]);
}

void changeInputVals(Gates* gates, int** digits, int index){
    Gates* node = gates;
    if(index == 0) printf("0 ");
    while(node != NULL){
        Gate* current = node->gate;
        if(strcmp(current->operand, operators[IN]) == 0 && index >=0){
            current->previousState = digits[index];
            index--;
        }
        node = node->next;
    }
}

void runCircuit(Gates* gates){
    Gates* node = gates;
    //Iterates through the list and gets the values of the input wires
    while(node != NULL){
        Gate* current = node->gate;
        if(current->input1 != NULL){
            current->previousState = current->currentState;
            int val1 = getValue(current->input1, gates);
            int val2 = getValue(current->input2, gates);
            current->currentState = conductOperation(current,val1, val2);
        }         
        node = node->next; 
    }
    // printf("End of Circuit\n");
}

bool isStable(Gates* gates, int index){
    bool previousState;
    bool currentState;
    for(int i = 0; i < index ; i++){
        runCircuit(gates);
        Gates* node = gates;
        while(node != NULL){
            Gate* current = node->gate;
            if(strcmp(current->name, "out") == 0){
                current->previousState = current->currentState;
            }
            node = node->next; 
        }
        if(i == index-2) previousState = getValue("out", gates);
    }
    currentState = getValue("out", gates);
    
    // printf("previousState %d currentState %d\n", previousState, currentState);
    if(previousState != currentState)
        return false;
    else
        return true;
    
}

void clearGates(Gates* gates){
    Gates* node = gates;
    while(node!= NULL){
        Gate* current = node->gate;
        if(strcmp(current->operand, operators[IN]) != 0){
            current->previousState = 0;
            current->currentState = 0;
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

void printLine(Gates* gates, bool isStable){
    Gates* node = gates;
    while(node != NULL){
        Gate* current = node->gate;
        if(strcmp(current->operand, operators[IN]) == 0)
            printf("%d ", current->previousState);
        if(strcmp(current->operand, "out") == 0)
            if(isStable)
                printf("? ");
            else printf("%d ", current->previousState);
        
        node = node->next;
    }
    printf("\n");
}

bool conductOperation(Gate* gate, bool* input1, bool* input2){
    if(strcmp(gate->operand, operators[NAND]) ==   0){
        return nandGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[NOT]) == 0){
        return notGate(input1);
    }
    if(strcmp(gate->operand, operators[OR]) == 0){
        return orGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[XOR]) == 0){
        return xorGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[NOR]) == 0){
        return norGate(input1, input2);
    }
    if(strcmp(gate->operand, operators[AND]) == 0){
        return andGate(input1, input2);
    }
}

