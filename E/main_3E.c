#include "header_3E.h"
#include "source_3E.c"

int main_3E() {
    Node3 *daThuc1 = NULL;
    Node3 *daThuc2 = NULL;
    Node3 *sum = NULL;
    double x;

    printf("\n--- Nhap da thuc thu nhat: ----\n");
    daThuc1 = nhapDaThuc3();

    printf("\n--- Nhap da thuc thu hai: ----\n");
    daThuc2 = nhapDaThuc3();

    printf("Da thuc 1: "); inDaThuc3(daThuc1);
    printf("\nDa thuc 2: "); inDaThuc3(daThuc2);

    printf("\nNhap gia tri x: "); scanf("%lf", &x);
    printf("\nGia tri cua da thuc 1 tai x = %.2f la: %.2f\n", x, tinhDaThuc3(daThuc1, x));
    printf("Gia tri cua da thuc 2 tai x = %.2f la: %.2f\n", x, tinhDaThuc3(daThuc2, x));

    printf("Dao ham cua da thuc 1 tai x = %.2f la %.2f\n", x, tinhDaoHam3(daThuc1, x));
    printf("Dao ham cua da thuc 2 tai x = %.2f la %.2f\n", x, tinhDaoHam3(daThuc2, x));

    sum = tong2DaThuc3(daThuc1, daThuc2);
    printf("Tong hai da thuc: "); inDaThuc3(sum);
    printf("\nGia tri cua tong hai da thuc tai x = %.2f la: %.2f\n", x, tinhDaThuc3(sum, x));

    freeDaThuc3(daThuc1);
    freeDaThuc3(daThuc2);
    freeDaThuc3(sum);
    return 0;
}
