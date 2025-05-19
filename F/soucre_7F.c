void readFile7(NhanVien** ds, int *n) {
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        printf("Khong the mo file");
        exit(1);
    }
    fscanf(f, "%d", n);
    *ds = (NhanVien*)malloc((*n) * sizeof(NhanVien));
    if (*ds == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    int i;
    for (i = 0; i < *n; i++) {
        fscanf(f, "%d", &(*ds)[i].id);
        fgetc(f); 
        fgets((*ds)[i].name, 50, f);
        (*ds)[i].name[strcspn((*ds)[i].name, "\n")] = '\0'; 
        fscanf(f, " %c", &(*ds)[i].room);
        fscanf(f, "%d", &(*ds)[i].salary);
    }
    fclose(f);
}

void print7(NhanVien *nv, int n) {
    printf("DANH SACH NHAN VIEN:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d - %s - Phong %c - Luong: %d\n", nv[i].id, nv[i].name, nv[i].room, nv[i].salary);
    }
}

void highestSalary7(NhanVien *nv, int n) {
    int max = nv[0].salary;
    int i;
    for (i = 1; i < n; i++) {
        if (nv[i].salary > max) max = nv[i].salary;
    }
    printf("\nNHAN VIEN CO LUONG CAO NHAT:\n");
    for (i = 0; i < n; i++) {
        if (nv[i].salary == max) {
            printf("%d - %s - Phong %c - Luong: %d\n", nv[i].id, nv[i].name, nv[i].room, nv[i].salary);
        }
    }
}

void countRoom7(NhanVien *nv, int n) {
    int a = 0, b = 0, c = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (nv[i].room == 'A') a++;
        else if (nv[i].room == 'B') b++;
        else if (nv[i].room == 'C') c++;
    }
    printf("\nSO LUONG NHAN VIEN THEO PHONG:\n");
    printf("Phong A: %d\n", a);
    printf("Phong B: %d\n", b);
    printf("Phong C: %d\n", c);
}

void w_out7(FILE* out, NhanVien* ds, int n) {
    fprintf(out, "DANH SACH NHAN VIEN:\n");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(out, "%d - %s - Phong %c - Luong: %d\n", ds[i].id, ds[i].name, ds[i].room, ds[i].salary);
    }
    int max = ds[0].salary;
    for (i = 1; i < n; i++) {
        if (ds[i].salary > max) max = ds[i].salary;
    }
    fprintf(out, "\nNHAN VIEN CO LUONG CAO NHAT:\n");
    for (i = 0; i < n; i++) {
        if (ds[i].salary == max) {
            fprintf(out, "%d - %s - Phong %c - Luong: %d\n", ds[i].id, ds[i].name, ds[i].room, ds[i].salary);
        }
    }
    int a = 0, b = 0, c = 0;
    for (i = 0; i < n; i++) {
        if (ds[i].room == 'A') a++;
        else if (ds[i].room == 'B') b++;
        else if (ds[i].room == 'C') c++;
    }
    fprintf(out, "\nSO LUONG NHAN VIEN THEO PHONG:\n");
    fprintf(out, "Phong A: %d\n", a);
    fprintf(out, "Phong B: %d\n", b);
    fprintf(out, "Phong C: %d\n", c);
}

void write_ans7(int n, NhanVien *ds) {
    FILE* f = fopen("output.txt", "w");
    if (f != NULL) {
        w_out7(f, ds, n);
    }
    fclose(f);
}
