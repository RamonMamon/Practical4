#include "parsing.h"
#include <math.h>


/**
 * Function that converts an int to its binary representation using recursion.
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

//Create a funtion that prints the out value

int main(int argc, char* argv[]){
    //Don't forget to implement arguments.
    // if(argc != 3)

    FILE* file;
    int size = 30;
    char* line = malloc(sizeof(char)*size);
    file = fopen("./Input Files/srnandlatch.txt", "r");

    //Used to store a list of all the gates.
    Gates* head;
    Gates* last;

    int numInputs = 0;
    while(fgets(line, size, (FILE*)file)){
        Gates* node = malloc(sizeof(Gates*));;
        node->gate = parse_Gate(line);
        if(strcmp(node->gate->operand, operators[IN]))numInputs++;
        node->next = NULL;
        if(head == NULL)head = node;
        else last->next = node;
        last = node;
    }
    printf("\n");
    //Number of possible input states
    numInputs = pow(2,numInputs);
    for(int i = 0; i < numInputs; i++){
        int binary =binary_conversion(i);
        int** digits = malloc(sizeof(int)*binary);
        int index = 0;
        while(binary){
            digits[index] = binary % 10;
            // printf("%d\n", digits[index]);
            binary /= 10;
            index++;
        }
        if(index >1)index--;
        // printf("Repetition: %d\n", i);
        
        clearGates(head);
        changeInputVals(head, digits, index); 
        
        // printf("\n");s
        printLine(head,isStable(head,numInputs));
    }

    return 0;
}

