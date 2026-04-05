#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h> // For options, Windows is not supported. Only POSIX !
#include "configs.h" // YigitFileManager/YigitFileCopier Configs

void write_file_content(char *content, char *destination) {
    FILE *dest = fopen(destination, "w");
    if (!dest) {
        perror(destination);
        free(content);
        exit(1);
    }

    fwrite(content, 1, strlen(content), dest);
    fclose(dest);

    printf(BLUE "Success!!\n");

    free(content);
}

void read_file(char* source_file_name, char *destination_file_name) {
    FILE *dosya = fopen(source_file_name, "r");
    if (!dosya) {
        perror(source_file_name);
        exit(1);
    }

    if (fseek(dosya, 0, SEEK_END) != 0) {
        perror("fseek");
        fclose(dosya);
        exit(1);
    }

    long file_size = ftell(dosya);
    if (file_size < 0) {
        perror("ftell");
        fclose(dosya);
        exit(1);
    }

    rewind(dosya);

    char *content_buffer = malloc(file_size + 1);
    if (!content_buffer) {
        perror("malloc");
        fclose(dosya);
        exit(1);
    }

    size_t read_bytes = fread(content_buffer, 1, file_size, dosya);
    if (read_bytes != file_size) {
        perror("fread");
        free(content_buffer);
        fclose(dosya);
        exit(1);
    }

    content_buffer[file_size] = '\0';

    fclose(dosya);

    write_file_content(content_buffer, destination_file_name);
}

int main(int argc, char *argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                get_banner();
                return 0;
            default:
                fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
                return 1;
        }
    }
    if (argc - optind != 2) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    char *file1 = argv[optind];
    char *file2 = argv[optind + 1];

    read_file(file1, file2);

    return 0;
}