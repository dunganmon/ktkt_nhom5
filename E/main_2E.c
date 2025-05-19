#include "header_2E.h"
#include "source_2E.c"
int Menu2(){
    int choice;
    printf("\n----------MENU------------\n");
    printf("1 - Nhap n cuon sach\n");
    printf("2 - Xuat n cuon sach\n");
    printf("3 - Dem theo tac gia\n");
    printf("4 - Thong ke\n");
    printf("5 - Thoat\n");
    printf("Chon chuc nang: "); scanf("%d", &choice);
    return choice;
}

int main_2E(){
    Sach2* A = NULL;
    int choice;
    int n = 0;
    do {
        choice = Menu2();
        switch (choice) {
            case 1:
                Nhap2(&n, &A);
                break;
            case 2:
                if(A != NULL) {
                    Xuat2(n,A);
                } else {
                    printf("Chua co sach trong kho!");
                }
                break;
            case 3:
                if(A != NULL) {
                    DemSach2(n,A);
                } else {
                    printf("Chua co sach trong kho!");
                }
                break;
            case 4:
                if(A != NULL) {
                    ThongKe2(n,A);
                } else {
                    printf("Chua co sach trong kho!");
                }
                break;
            case 5:
                freeList2(A);
                break;
            default:
                printf("Khong hop le!");
        }
    } while (choice != 5);
    return 0;
}