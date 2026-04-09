#include <stdio.h>
#include "headers/yigitfw_headers.h" // YigitFileManager Configs

#define BUFFER_SIZE 1024

void print_banner(FILE *banner_file) {
    char banner[BUFFER_SIZE * 2];
    
    while (fgets(banner, sizeof(banner), banner_file)) {
        printf(CYAN "%s", banner);
    }
    printf(RESET "\nUSAGE: yw <file> <content>\n");

    fclose(banner_file);
}

void get_banner() {
    FILE *banner_file;
    banner_file = fopen("/Users/yigit/Documents/YigitConfigs/yigitfilemanager/yigitFileWriter/banner.txt", "r");

    if (!banner_file) {
        fprintf(stderr, "Banner file error!");
        return;
    }

    print_banner(banner_file);
}