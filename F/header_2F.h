#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Hang_hoa {
    char ten_hang[100];
    int so_luong;
    char loai_hang[50];
} Hang_hoa;
void nhap_ds(Hang_hoa **ds, int *n);
void xuat_ds_file(Hang_hoa *ds, int n, const char *filename);
int tong_sl_hang(Hang_hoa *ds, int n);
void tim_theo_ten(Hang_hoa *ds, int n, const char *ten_can_tim);
void sap_xep_ten(Hang_hoa *ds, int n);
void xuat_file_nhi_phan(Hang_hoa *ds, int n, const char *filename);
