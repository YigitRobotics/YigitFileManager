#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h> // For options, Windows is not supported. Only POSIX !
#include "../configs.h" // YigitFileManager Configs

char* return_message(char *text) {
    return text;
}

// ----- Main Functions -----
void print_file_content(char *content) {
    printf("%s", content);
    free(content);
    content = NULL;
}

void read_file(char* file_name) {
    FILE *dosya;
    dosya = fopen(file_name, "r");
    if (fseek(dosya, 0, SEEK_END) != 0) { return_message("NULL"); }

    long file_size = ftell(dosya);
    if (file_size < 0) { perror("File size is under 0!"); exit(1); }

    rewind(dosya);

    char *content_buffer = malloc(file_size + 1);
    if (!content_buffer) {
        return_message("NULL");
    }

    size_t read_bytes = fread(content_buffer, 1, file_size, dosya);
    if (read_bytes != file_size) {
        free(content_buffer);
        content_buffer = NULL; // use-after-free önlendi.
        perror("Copy failed!");
        exit(1);
    }
    
    content_buffer[file_size] = '\0';
    print_file_content(content_buffer);
}

int main(int argc, char *argv[]) {
    char *file_name;
    int options;

    while ((options = getopt(argc, argv, "hf:")) != -1) { // h: help, f: argüman alır, dosya ismi.
        switch (options) {
            case 'h':
                get_banner();
                break;
            case 'f':
                read_file(optarg);
        }
    }

    return 0;
}