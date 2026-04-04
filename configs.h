#include <stdio.h> // for file_declarations (neden bilmiom :D)
#ifndef CONFIGS_H
#define CONFIGS_H


// ---- Define'lar ----
#define BUFFER_SIZE 1024

// ---- Fonksiyonlar ----
void print_banner();
void get_banner();
void print_file_content(char *content);
void read_file(FILE *file);
void print_banner(FILE *banner_file);
void get_banner();

// ---- RENKLER -----
#define CYAN "\e[0;36m"
#define GREEN "\e[0;32m"
#define BLUE "\e[0;34m"
#define RESET "\e[0m"

#endif