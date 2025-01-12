#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fclose(file);

    if (file_size < 0) {
        fprintf(stderr, "Error determining file size.\n");
        return -1;
    }

    printf("File size: %ld bytes\n", file_size);

    return 0;
}

