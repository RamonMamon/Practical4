#include "parsing.h"
#include <math.h>

//Create a function that activates the gates

//Create a function that changes the value of the gates
void bin(unsigned n)
{
	/* step 1 */
	if (n > 1)
		bin(n/2);

	/* step 2 */
	printf("%d\n", n % 2);
}

//Create functions that act as Operators.

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
    //Segementation fault error here when last = gate->next;
    Gates* last;
    int numInputs = 0;
    while(fgets(line, size, (FILE*)file)){
        Gates* node = malloc(sizeof(Gates*));;
        node->gate = parse_Gate(line);
        // printf("%s\n", head.gate->output->name);
        if(strcmp(node->gate->operand, operators[IN]))numInputs++;
        node->next = NULL;
        node->previous = NULL;        
        if(head == NULL)head = node;
        else{
            last->next = node;
            node->previous = last;
        }
        last = node;
    }
    printf("Bruh %d \n", numInputs);
    for(int i = 0; i < pow(2,numInputs); i++){
        bin(i);
        runCircuit(head);
    }
    

    //Implement printing of values here.
    return 0;
}

