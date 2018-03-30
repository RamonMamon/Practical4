#include <stdbool.h>
#define true T
#define false F

typedef char* Wire;

typedef struct gate{
    char* operand;
    Wire output;
    Wire input[];
}Gate;

//Gates Struct to form list of gates.

Gate* new_Gate(Wire output, char* operand, Wire input[]);