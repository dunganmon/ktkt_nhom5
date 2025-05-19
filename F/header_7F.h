#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char name[50];
    char room;
    int salary;
} NhanVien;

void readFile7(NhanVien** ds, int *n);
void print7(NhanVien *nv, int n);
void highestSalary7(NhanVien *nv, int n);
void countRoom7(NhanVien *nv, int n);
void w_out7(FILE* out, NhanVien* ds, int n);
void write_ans7(int n, NhanVien *ds);
