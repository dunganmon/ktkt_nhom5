#include "header_4E.h"
#include "source_4E.c"

int main_4E() {
    GV *danhSach = NULL;
    int choice, n;

    do {
        printf("\n-------------------------------------\n");
        printf("1. Them giang vien vao dau danh sach\n");
        printf("2. Them giang vien vao cuoi danh sach\n");
        printf("3. Nhap danh sach giang vien tu ban phim\n");
        printf("4. In danh sach giang vien\n");
        printf("5. Tim va in giang vien co hoc vi \"ThS\"\n");
        printf("6. Tinh tien giang day theo he so\n");
        printf("7. Sap xep giang vien theo so tiet day giam dan\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                GV *newGV = nhapGiangVien4();
                insertFirst4(&danhSach, newGV);
                break;
            }
            case 2: {
                GV *newGV = nhapGiangVien4();
                insertEnd4(&danhSach, newGV);
                break;
            }
            case 3:
                printf("Nhap so giang vien can them: ");
                scanf("%d", &n);
                int i;
				for (i = 0; i < n; i++) {
                    printf("\nNhap thong tin giang vien thu %d:\n", i + 1);
                    GV *newGV = nhapGiangVien4();
                    insertEnd4(&danhSach, newGV);
                }
                break;
            case 4:
                inDanhSach4(danhSach);
                break;
            case 5:
                search4(danhSach);
                break;
            case 6:
                tinhTien4(danhSach);
                break;
            case 7:
                sortSoTietDay4(&danhSach);
                printf("\nDanh sach sau khi sap xep theo so tiet day giam dan:\n");
                inDanhSach4(danhSach);
                break;
            case 0:
                printf("Dang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 0);

    freeList4(&danhSach);
    return 0;
}

