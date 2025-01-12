#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == 0) {
        printf("File size: %lld bytes\n", (long long)file_stat.st_size);
    } else {
        perror("Error getting file information");
        return -1;
    }

    return 0;
}
