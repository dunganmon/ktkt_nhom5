void nhapDiem(Diem3D *diem, int n) {
    printf("Nhap %d diem trong khong gian 3D:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        printf("Diem %d (x y z): ", i + 1);
        scanf("%f %f %f", &diem[i].x, &diem[i].y, &diem[i].z);
    }
}

void xuatDiemVanBan(Diem3D *diem, int n) {
    FILE *f = fopen("output_5F.txt", "w");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi.\n");
        return;
    } 
    fprintf(f, "%d\n", n);
    int i;
    for (i = 0; i < n; i++) 
        fprintf(f, "%.2f %.2f %.2f\n", diem[i].x, diem[i].y, diem[i].z);
    fclose(f);
    printf("Da xuat du lieu vao file output_5F.txt.\n");
}

void nhapDiemVanBan(Diem3D **diem, int *n) {
    FILE *f = fopen("input_5F.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc file de doc.\n");
        return;
    } 
    fscanf(f, "%d", n);
    *diem = (Diem3D*)malloc((*n) * sizeof(Diem3D));
    if (*diem == NULL) {
        printf("Khong cap phat duoc bo nho.\n");
        fclose(f);
        return;
    }
    int i;
    for (i = 0; i < *n; i++) {
        fscanf(f, "%f %f %f", &(*diem)[i].x, &(*diem)[i].y, &(*diem)[i].z);
    }
    fclose(f);
    printf("Da nhap du lieu tu file input_5F.txt: %d diem.\n", *n);
}

void xuatDiemNhiPhan(Diem3D *diem, int n) {
    FILE *f = fopen("output_5F.dat", "wb");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, f);
    int i;
    for (i = 0; i < n; i++) {
        fwrite(&diem[i], sizeof(Diem3D), 1, f);
    }
    fclose(f);
    printf("Da xuat du lieu vao file nhi phan output_5F.dat.\n");
}

void nhapDiemNhiPhan(Diem3D **diem, int *n) {
    FILE *f = fopen("input_5F.dat", "rb");
    if (f == NULL) {
        printf("Khong mo duoc file de doc.\n");
        return;
    }
    fread(n, sizeof(int), 1, f);
    *diem = (Diem3D*)malloc((*n) * sizeof(Diem3D));
    if (*diem == NULL) {
        printf("Khong cap phat duoc bo nho.\n");
        fclose(f);
        return;
    }
    fread(*diem, sizeof(Diem3D), *n, f);
    fclose(f);
    printf("Da nhap du lieu tu file nhi phan bai5_input.bin: %d diem.\n", *n);
}
