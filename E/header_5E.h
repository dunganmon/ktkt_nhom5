#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sach {
    char ten[100];
    int sl;
    char loai;
    int nam;
    struct Sach *next;
} Sach;

Sach *createNode5(char ten[], int sl, char loai, int nam);
void themdau5(Sach **head, Sach *newNode);
void themcuoi5(Sach **head, Sach *newNode);
void Nhap5(int *n, Sach **head);
void Xuat5(int n, Sach *head);
void Xoasach20105(Sach **head);
void Thongketheoloai5(Sach *head);
void Sapxeptangdan5(Sach **head);
void giaiphongbonho5(Sach **head);
