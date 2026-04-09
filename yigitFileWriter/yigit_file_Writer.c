#include <stdio.h>
#include <stdlib.h>
#include "headers/yigitfw_headers.h"
#include <string.h>

void open_file_and_write_data(char *file_path, char *content) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error while opening the file");
        return;
    }
    fprintf(file, "%s", content);
    return;
}

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "-h") == 0) {
        get_banner();
    }
    else {
        if (argv[1] && argv[2]) {
            open_file_and_write_data(argv[1], argv[2]);
        }
        else {
            perror("Usage: yw -h \n");
            return 1;
        }
    }
}