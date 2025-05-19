void nhap_ds(Hang_hoa **ds, int *n) {
    printf("Nhap so luong hang hoa: ");
    scanf("%d", n);
    
     while (*n <= 0) {
                    printf("So luong hang hoa khong hop le\nNhap lai: ");
                    scanf("%d", n);
                 }

    getchar();
    
    *ds = (Hang_hoa*)malloc((*n) * sizeof(Hang_hoa));
    if (*ds == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    
    int i;
    for (i = 0; i < *n; i++) {
        printf("Nhap thong tin hang hoa thu %d\n", i + 1);
        printf("Ten hang hoa: ");
        fflush(stdin); gets((*ds)[i].ten_hang);
        
        printf("Nhap so luong loai hang: ");
        scanf("%d", &(*ds)[i].so_luong);
        while ((*ds)[i].so_luong <= 0) {
                    printf("So luong loai hang khong hop le\nNhap lai: ");
                    scanf("%d", &(*ds)[i].so_luong);
                 }
	
        getchar();
        printf("Nhap loai hang hoa: ");
        fflush(stdin); gets((*ds)[i].loai_hang);
    }
}

void xuat_ds_file(Hang_hoa *ds, int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    fprintf(f, "%-30s %-10s %-20s\n", "Ten hang", "So luong", "Loai hang");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(f, "%-30s %-10d %-20s\n", ds[i].ten_hang, ds[i].so_luong, ds[i].loai_hang);
    }
    fclose(f);
}

int tong_sl_hang(Hang_hoa *ds, int n) {
    int tong = 0, i;
    for (i = 0; i < n; i++) {
        tong += ds[i].so_luong;
    }
    return tong;
}

void tim_theo_ten(Hang_hoa *ds, int n, const char *ten_can_tim) {
    int tim_thay = 0, i;
    for (i = 0; i < n; i++) {
        if (strcmp(ds[i].ten_hang, ten_can_tim) == 0) {
            printf("\nTim thay hang hoa:\n");
            printf("Ten: %s\n", ds[i].ten_hang);
            printf("So luong hang hoa: %d\n", ds[i].so_luong);
            printf("Loai: %s\n", ds[i].loai_hang);
            tim_thay = 1;
            break;
        }
    }
    if (tim_thay == 0) {
        printf("\nKhong tim thay ten hang hoa do trong danh sach\n");
    }
}

void sap_xep_ten(Hang_hoa *ds, int n) {
    int i, j;
    Hang_hoa temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(ds[j].ten_hang, ds[j + 1].ten_hang) > 0) {
                temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

void xuat_file_nhi_phan(Hang_hoa *ds, int n, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Khong mo duoc file %s\n", filename);
        return;
    }
    fwrite(&n, sizeof(int), 1, f);
    int i;
    for (i = 0; i < n; i++) {
        fwrite(&ds[i], sizeof(Hang_hoa), 1, f);
    }
    
    fclose(f);
}
