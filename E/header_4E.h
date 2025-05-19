#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct giangVien {
    char hoTen[20];
    char hocVi[10];
    double soTietDay;
    double donGia;
    struct giangVien *next;
} GV;

GV *createNode4(char *hoTen, char *hocVi, double soTietDay, double donGia);
void insertFirst4(GV **head, GV *newGV);
void insertEnd4(GV **head, GV *newGV);
GV *nhapGiangVien4();
void inDanhSach4(GV *head);
void search4(GV *head);
double heSo4(char *hocVi);
void tinhTien4(GV *head);
void sortSoTietDay4(GV **head);
void freeList4(GV **head);
