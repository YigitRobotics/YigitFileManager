#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h> // For options, Windows is not supported. Only POSIX !
#include "configs.h" // YigitFileManager Configs

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
    char *file_name = NULL;
    int opt;

    while ((opt = getopt(argc, argv, "hf:")) != -1) {
        switch (opt) {
            case 'h':
                get_banner(); 
                return 0;
            case 'f':
                file_name = optarg; 
                break;
            default:
                fprintf(stderr, "Usage: %s [-f filename] [-h]\n", argv[0]);
                return 1;
        }
    }
    if (file_name == NULL && optind < argc) {
        file_name = argv[optind];
    }
    if (file_name == NULL) {
        fprintf(stderr, "Error: No file specified.\n");
        return 1;
    }

    read_file(file_name);
    return 0;
}