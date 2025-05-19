#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct {
    char HoTen[50];
    float DToan;
    float DLy;
    float DHoa;
}ThiSinh;

struct Node{
    ThiSinh data;
    struct Node* next;
};

typedef struct Node* LinkedList;

LinkedList createNode(ThiSinh data);

void appendNode(LinkedList *head, ThiSinh data);
void insertAtHead(LinkedList *head, ThiSinh data);
void inputThiSinh(LinkedList *head, int *n);
void outputThiSinh(LinkedList head);
void XuatDanhSachThiSinhVaoFileNhiPhan(LinkedList head);
void XuatDanhSachThiSinhVaoFileVanBan(LinkedList head);
LinkedList NhapDanhSachThiSinhTuFileNhiPhan();
void NhapDanhSachThiSinhTuFileVanBan(LinkedList *head);
void ThiSinhCoDiemToanCaoNhat(LinkedList head);
float DiemLyThapNhat(LinkedList head);
void XoaDiemLyThapNhat(LinkedList *head, float DLyMin);
void freeLinkedList(LinkedList head);
void menu(LinkedList *head, int *choice, int *n);
