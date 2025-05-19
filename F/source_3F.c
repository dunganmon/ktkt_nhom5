


void nhap_ma_tran_tu_ban_phim3(float **matran, int dong, int cot) {
    int i, j;
    for(i = 0; i < dong; i++) {
        for(j = 0; j < cot; j++) {
            printf("a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matran[i][j]);
        }
    }
}


void nhap_ma_tran_tu_file_van_ban3(float **matran, const char *filename, int *dong, int *cot) {
    FILE *f = fopen(filename, "r");
    if(!f) {
        printf("Khong the mo duoc file %s \n", filename);
        return;
    }
    
   
    if (fscanf(f, "%d %d", dong, cot) != 2) {
        printf("Loi: Khong doc duoc so dong va cot tu file %s\n", filename);
        fclose(f);
        return;
    }
    

    if (*dong <= 0 || *cot <= 0) {
        printf("Loi: So dong hoac so cot khong hop le trong file %s\n", filename);
        fclose(f);
        return;
    }
    

    int i, j;
    for(i = 0; i < *dong; i++) {
        for(j = 0; j < *cot; j++) {
            if (fscanf(f, "%f", &matran[i][j]) != 1) {
                printf("Loi: Khong doc duoc du lieu tai vi tri [%d][%d] tu file %s\n", i, j, filename);
                fclose(f);
                return;
            }
        }
    }
    fclose(f);
}


void ghi_ra_file_van_ban3(float **matran, const char *filename, int dong, int cot) {
    FILE *f = fopen(filename, "w");
    if(!f) {
        printf("Khong the mo file %s\n", filename);
        return;
    }
    
    int i, j;
    fprintf(f, "%d %d\n", dong, cot);
    for(i = 0; i < dong; i++) {
        for(j = 0; j < cot; j++) {
            fprintf(f, "%.2f ", matran[i][j]);
        }    
        fprintf(f, "\n");
    }
    fclose(f);
}


void ghi_ra_file_nhi_phan3(float **matran, const char *filename, int dong, int cot) {
    FILE *f = fopen(filename, "wb");
    if(!f) {
        printf("Khong the mo file %s\n", filename);
        return;
    }
    
   
    fwrite(&dong, sizeof(int), 1, f);
    fwrite(&cot, sizeof(int), 1, f);
    
   
    int i;
    for(i = 0; i < dong; i++) {
        fwrite(matran[i], sizeof(float), cot, f);
    }
    fclose(f);
}


void nhap_tu_file_nhi_phan3(float **matran, const char *filename, int *dong, int *cot) {
    FILE *f = fopen(filename, "rb");
    if(!f) {
        printf("Khong the mo file %s\n", filename);
        return;
    }
    
    if (fread(dong, sizeof(int), 1, f) != 1 || fread(cot, sizeof(int), 1, f) != 1) {
        printf("Loi: Khong doc duoc so dong va cot tu file %s\n", filename);
        fclose(f);
        return;
    }
    

    if (*dong <= 0 || *cot <= 0) {
        printf("Loi: So dong hoac so cot khong hop le trong file %s\n", filename);
        fclose(f);
        return;
    }
    
 
    int i;
    for(i = 0; i < *dong; i++) {
        if (fread(matran[i], sizeof(float), *cot, f) != *cot) {
            printf("Loi: Khong doc duoc du lieu tai dong %d tu file %s\n", i, filename);
            fclose(f);
            return;
        }
    }
    fclose(f);
}


void hien_thi_ma_tran3(float **matran, int dong, int cot) {
    printf("Ma tran: \n");
    int i, j;
    for(i = 0; i < dong; i++) {
        for(j = 0; j < cot; j++) {
            printf("%7.2f", matran[i][j]);
        }
        printf("\n");
    }
}


float** cap_phat_ma_tran3(int dong, int cot) {
    float **matran;
    int i;
    
    matran = (float**)malloc(dong * sizeof(float*));
    if (!matran) {
        printf("Loi cap phat bo nho!\n");
        return NULL;
    }
    
    for (i = 0; i < dong; i++) {
        matran[i] = (float*)malloc(cot * sizeof(float));
        if (!matran[i]) {
            printf("Loi cap phat bo nho!\n");
          
            int j;
            for (j = 0; j < i; j++) {
                free(matran[j]);
            }
            free(matran);
            return NULL;
        }
    }
    return matran;
}


void giai_phong_ma_tran3(float **matran, int dong) {
    int i;
    if (matran) {
        for (i = 0; i < dong; i++) {
            if (matran[i]) free(matran[i]);
        }
        free(matran);
    }
}

