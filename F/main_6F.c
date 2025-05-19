#include "header_6F.h"
#include "source_6F.c"
int main_6F() {
    char filename[100];
    int *a, *b, *s;
    int n, m, bacs;
    int k, r;
    
   
    a = (int*)malloc(MAX_BAC * sizeof(int));
    b = (int*)malloc(MAX_BAC * sizeof(int));
    s = (int*)malloc(MAX_BAC * sizeof(int));
    

    if (a == NULL || b == NULL || s == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }
    
    int i;
    for (i = 0; i < MAX_BAC; i++) {
        a[i] = 0;
        b[i] = 0;
        s[i] = 0;
    }
   
    printf("Nhap ten tep lay du lieu: ");
    fflush(stdin);
    gets(filename);
  
    Doc_file(filename, a, &n, b, &m);
    printf("\nDa thuc A(x): "); 
    In_da_thuc(a, n);
    
    printf("Da thuc B(x): "); 
    In_da_thuc(b, m);
    
    
    printf("\nNhap gia tri cua k: ");
    scanf("%d", &k);
    
    printf("Nhap gia tri cua r: ");
    scanf("%d", &r);
    
    int valA = tinhGTDT(a, n, k);
    int valB = tinhGTDT(b, m, r);
    
    int S = valA + valB;
    printf("A(%d) = %d\n", k, valA);
    printf("B(%d) = %d\n", r, valB);
    printf("Tong S = A(%d) + B(%d) = %d\n", k, r, S);
    
   
    cong_DT(a, n, b, m, s, &bacs);
    printf("\nDa thuc S(x) = A(x) + B(x): ");
    In_da_thuc(s, bacs);
    

    free(a);
    free(b);
    free(s);
    
    return 0;
}
