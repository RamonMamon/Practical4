#include "parsing.h"
#include <math.h>

/**
 * Function that converts an int to its binary reprentation using recursion.
 * Taken from Sanfoundry.
 */
int binary_conversion(int num){
    if (num == 0){
        return 0;
    }
    else{
        return (num % 2) + 10 * binary_conversion(num / 2);
    }
}

/**
 * Free list of Gates and it's fields.
 */
void freeGates(Gate* gates) {
	if (gates) {
		freeGates(gates->next);
		free(gates);
	}
}

int main(){
    Gate* head = NULL;
    Gate* last = NULL;
    bool outExists = false;
    size_t len = 0;
    int size = 30;
    char* line = malloc(sizeof(char)*size);
    int numInputs = 0;
    
    while(getline(&line, &len, stdin) != -1){
        Gate* node = malloc(sizeof(Gate*));;
        node = parse_Gate(line);
        if(strcmp(node->name,"out") == 0)outExists = true;
        if(strcmp(node->operand, operators[IN]) == 0)numInputs++;
        node->next = NULL;
        if(head == NULL)head = node;
        else last->next = node;
        last = node;
        line = realloc(line, len);
        
    }
    printf("\n");
    
    //Number of possible input states
    numInputs = pow(2,numInputs);
    for(int i = 0; i < numInputs; i++){
        int binary = binary_conversion(i);
        int** digits= malloc(sizeof(int)*binary);
        int index = 0;
        while(binary){
            digits[index] = binary % 10;
            binary /= 10;
            index++;
        }
        
        if(index >1)index--;
        clearGates(head);
        changeInputVals(head, digits, index); 
        printLine(head,isStable(head, outExists), outExists);
        free(digits);
    }
    
    freeGates(head);
    free(line);
    return 0;
}

