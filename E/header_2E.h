
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sach2{
    char title[100];
    char author[100];
    int publication_year;
    struct Sach2 *next;
} Sach2;

void Nhap2(int *n, Sach2 **A);
void Xuat2(int n, Sach2 *A);
int DemSach2(int n, Sach2 *A);
void ThongKe2(int n, Sach2 *A);
void freeList2(struct Sach2 *A);
