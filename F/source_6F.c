#include <stdio.h>
void Doc_file(const char *filename, int *a, int *n, int *b, int *m) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Khong the mo duoc file: %s\n", filename);
        exit(1);
    }
    fscanf(f, "%d %d", n, m);
    int i;
    for (i = 0; i <= *n; i++) {
        fscanf(f, "%d", &a[i]);
    }
    for (i = 0; i <= *m; i++) {
        fscanf(f, "%d", &b[i]);
    }
    fclose(f);
}
void In_da_thuc(int *heso, int bac) {
    int first = 1;
    int i;
    for (i = bac; i >= 0; i--) {
        if (heso[i] != 0) {
            if (!first) {
                if (heso[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                    printf("%d", abs(heso[i]));
                    if (i > 0) {
                        if (i == 1) printf("x");
                        else printf("x^%d", i);
                    }
                    continue;
                }
            }
            printf("%d", heso[i]);
            if (i > 0) {
                if (i == 1) printf("x");
                else printf("x^%d", i);
            }
            first = 0;
        }
    }
    if (first) printf("0");
    printf("\n");
}
int tinhGTDT(int *heso, int bac, int x) {
    int sum = 0;
    int i;
    for (i = 0; i <= bac; i++) {
        sum += heso[i] * pow(x, i);
    }
    return sum;
}
void cong_DT(int *a, int n, int *b, int m, int *s, int *bacs) {
    *bacs = (n > m) ? n : m;
    int i;
    for (i = 0; i <= *bacs; i++) {
        int ai = (i <= n) ? a[i] : 0;
        int bi = (i <= m) ? b[i] : 0;
        s[i] = ai + bi;
    }
}
