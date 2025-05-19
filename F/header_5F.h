#include <stdio.h>
#include <stdlib.h>

   typedef struct {
    float x, y, z;
} Diem3D;
void nhapDiem(Diem3D *diem, int n);
void xuatDiemVanBan(Diem3D *diem, int n);
void nhapDiemVanBan(Diem3D **diem, int *n);
void xuatDiemNhiPhan(Diem3D *diem, int n);
void nhapDiemNhiPhan(Diem3D **diem, int *n);