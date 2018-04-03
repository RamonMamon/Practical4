#include "parsing.h"

int main(int argc, char* argv[]){
    //Don't forget to implement arguments.
    // if(argc != 3)
    
    File* file;
    char* line = NULL;
    size_t size = 0;

    file = fopen("./Input Files/not.txt", "r");

    while(fgets(line, size, (FILE*)file)){
        process_line(line);
    }

    return 0;
}