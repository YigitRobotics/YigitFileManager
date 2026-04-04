#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h> // For options, Windows is not supported. Only POSIX !
#include "../configs.h" // YigitFileManager Configs


// ----- Main Functions -----
void print_file_content(char *content) {

}

void read_file(FILE *dosya, char* file_name) {
    // eklenecek

}

int main(int argc, char *argv[]) {
    char *file_name;
    int options;

    while ((options = getopt(argc, argv, "hf:")) != -1) { // h: help, f: argüman alır, dosya ismi.
        switch (options) {
            case 'h':
                get_banner();
            case 'f':

        }
    }

    return 0;
}