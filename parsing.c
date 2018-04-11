#include "parsing.h"

/**
 * Parses a line of text and returns a gate based off the cdf specifications
 * in the line of text.
 */
Gate* parse_Gate(char* line){
    const char delim[] = " \n";
    int i = 0;
    char* string[4];
    char* token = strtok(line, delim);
    
    while(token != NULL){
        string[i] = malloc(strlen(token) + 1);
        strcpy(string[i], token);
        token = strtok(NULL, delim);
        i++;
    }
    if(strcmp(string[1],operators[IN]) == 0 || strcmp(string[0],"out") == 0)
        printf("%s ", string[0]);
    return new_Gate(string[0], string[1], string[2], string[3]);
}

/**
 * Changes the input values based off the digits of the binary representation
 * of a value. 
 */
void changeInputVals(Gate* gates, int** digits, int index){
    Gate* current = gates;
    if(current){
        if(strcmp(current->operand, operators[IN]) == 0 && index >= 0){
            current->previousState = digits[index];
            index--;
        }
        changeInputVals(current->next, digits, index);
    }
}

/**
 * Runs the circuit with the current values of the IN gates and changes 
 * the values of the rest of the gates by iterating through the list and
 * conducting the operation specified by the gate after taking the values
 * of it's inputs.
 */
void runCircuit(Gate* gates){
    Gate* current = gates;
    while(current){
        if(current->input1 != NULL){
            current->previousState = current->currentState;
            int val1 = getValue(current->input1, gates);
            int val2 = getValue(current->input2, gates);
            current->currentState = conductOperation(current,val1, val2);
        }
        current = current->next; 
    }
}

/**
 * Tests if the value of the output of the circuit is stable by testing
 * the current input value a set number of times, which in this case is 4,
 * and compares the nth value of out and the (n-1)th value of out. These 
 * are represented as currentState and previousState. If out does not exist,
 * the value of name will be equal to the name of the last gate of in the list
 * of gates, and stability will be checked from there.
 */
bool isStable(Gate* gates,bool outExists){
    bool previousState;
    bool currentState;
    int tests = 4;
    char* name = "out";
    for(int i = 0; i < tests ; i++){
        runCircuit(gates);
        Gate* current = gates;
        while(current){
            if(strcmp(current->name, "out") == 0)
                current->previousState = current->currentState;
            if (!outExists && strcmp(name, "out") == 0) name = current->name;
            current = current->next; 
            
        }
        if(i == tests-2) previousState = getValue(name, gates);
        
    }
    currentState = getValue(name, gates);
    if(previousState != currentState) return false;
    else return true;
}

/**
 * Resets the value of each gate that is not an Input by traversing
 * through the list and setting each state back to 0.
 */
void clearGates(Gate* gates){
    // Gates* node = gates;
    Gate* current = gates;
    while(current){
        if(strcmp(current->operand, operators[IN]) != 0){
            current->previousState = 0;
            current->currentState = 0;
        }
        current = current->next;
    }
}

/**
 * Gets the value of a specified input wire by searching the list of gates
 * and comparing the names.
 */
int getValue(char* wireName, Gate* gates){
    Gate* current = gates;
    while(current){
        if(strcmp(wireName, current->name) == 0)
            return current->previousState;
        current = current->next;
    }
    return 0;
}

/**
 * Prints the current values of each input and the current value of out
 * based off the current inputs by traversing through the list and checking
 * if the current gate is either input or output. In addition, if the value
 * of isStable is false, then the value of out will be represented by a "?"
 * instead of 1 or 0.
 */
void printLine(Gate* gates, bool isStable, bool outExists){
    Gate* current = gates;
    while(current){
        if(strcmp(current->operand, operators[IN]) == 0)
            printf("%d ", current->previousState);
        if(strcmp(current->name, "out") == 0)
            if(!isStable)
                printf("? ");
            else printf("%d ", current->previousState);
        if(!outExists && current->next == NULL){
            if(!isStable) printf("?");
            else printf("0");
        }
        current = current->next;
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

