#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Função que le uma string de tamanho indefinido e a aloca na memória heap o espaço exato
char* readLine(FILE *input){
    char *str;
    str = (char*) malloc(32 * sizeof(char)); // Making an initial allocation
    int pos = 0, size = 32;

    do {
        // Reallocating heap memory if the word exceeds the maximum space
        if (pos == size) {
            str = realloc (str, 2 * size);
            size *= 2;
        }

        // Receiving characters
        str[pos] = (char) fgetc(input);
        if (str[pos] == '\r') pos--;
        pos++;

    } while (str[pos-1] != '\n' && !feof(input));

    str[pos-1] = '\0'; 
    str = realloc(str, pos);

    return str;
}

unsigned char getHexcode(char *code){
    char *ptr = strchr(code, '$');
    unsigned int value;
    sscanf(ptr + 1, "%x", &value);
    return value;
}

void checkInstruction(char *instruction, FILE *output){
    unsigned char bin_instruction[2];

    if (strncmp(instruction, "mov", 3) == 0){
        if (strncmp(instruction + 13, "%al", 3) == 0)
            bin_instruction[0] = 0xb0;

        if (strncmp(instruction + 13, "%ah", 3) == 0)
            bin_instruction[0] = 0xb4;

        bin_instruction[1] = getHexcode(instruction);
    }

    if (strncmp(instruction, "int", 3) == 0){
        bin_instruction[0] = 0xcd;
        bin_instruction[1] = getHexcode(instruction);
    }

    if (strncmp(instruction, "jmp", 3) == 0){
        bin_instruction[0] = 0xeb;
        bin_instruction[1] = 0xfd;
    }

    if (strncmp(instruction, "hlt", 3) == 0){
        bin_instruction[0] = 0x55;
        bin_instruction[1] = 0xaa;
    }

    fwrite(bin_instruction, sizeof(unsigned char), 2, output);
}

int main(){
    char *input_name, *output_name;
    input_name = readLine(stdin);
    output_name = readLine(stdin);

    //  Checking for the file integrity
    FILE *input = fopen(input_name, "r");
    if (input == NULL){
        printf("File %s couldn't be open with sucess", input_name);
        return 1;
    }

    FILE *output = fopen(output_name, "wb");
    if (output == NULL) {
        printf("File %s couldn't be open with sucess", output_name);
        return 1;
    }

    char *line = malloc(100 * sizeof(char));
    while (fgets(line, 100 * sizeof(char), input) != NULL) {
        if ((strncmp(line, ".code", 5) != 0) || (line[0] != '#')){
            // line + 4 makes the line start in the instruction (not dealing with the jumps and labels)
            checkInstruction(line + 4, output);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}