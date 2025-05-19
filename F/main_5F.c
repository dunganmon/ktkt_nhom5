#include "header_5F.h"
#include "source_5F.c"



int main_5F() {
 
	Diem3D *diem = NULL;
    int n = 0, luaChon;
   
    do {
        printf("\n--- CHUONG TRINH QUAN LY DIEM 3D ---\n");
        printf("1. Nhap diem tu ban phim\n");
        printf("2. Xuat diem ra file van ban\n");
        printf("3. Nhap diem tu file van ban\n");
        printf("4. Xuat diem ra file nhi phan\n");
        printf("5. Nhap diem tu file nhi phan\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                if (diem != NULL) {
                    free(diem);
                }
                printf("Nhap so luong diem: ");
                scanf("%d", &n);
                while (n <= 0) {
                    printf("So luong diem khong hop le!\nNhap lai: ");
                    scanf("%d", &n);
                 }

				diem = (Diem3D*)malloc(n * sizeof(Diem3D));
                if (diem == NULL) {
                    printf("Khong cap phat duoc bo nho!\n");
                    break;
                }
                nhapDiem(diem, n);
                break;
                
            case 2:
                if (diem == NULL || n == 0) {
                    printf("Chua co du lieu diem!\n");
                    break;
                }
                xuatDiemVanBan(diem, n);
                break;
                
            case 3:
                if (diem != NULL) {
                    free(diem);
                    diem = NULL;
                }
                nhapDiemVanBan(&diem, &n);
                break;
                
            case 4:
                if (diem == NULL || n == 0) {
                    printf("Chua co du lieu diem!\n");
                    break;
                }
                xuatDiemNhiPhan(diem, n);
                break;
                
            case 5:
                if (diem != NULL) {
                    free(diem);
                    diem = NULL;
                }
                nhapDiemNhiPhan(&diem, &n);
                break;
                
                
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
                
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);
    
    if (diem != NULL) {
        free(diem);
    }
    
    return 0;
}
