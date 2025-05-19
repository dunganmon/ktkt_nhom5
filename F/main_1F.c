#include "header_1F.h"
#include"source_1F.c"

int main_1F() {
    char filename[100];
    printf("Nhap ten file: ");
    scanf("%s", filename);
   return readFile(filename);
}