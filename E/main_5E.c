#include "header_5E.h"
#include "source_5E.c"
int main_5E(){
    int n, choice;
    Sach *head = NULL;
    do{
        printf("------MENU BOOK-----\n");
        printf("1. Them cuon sach vao dau danh sach\n");
        printf("2. Them cuon sach vao cuoi danh sach\n");
        printf("3. Nhap n cuon sach\n");
        printf("4. In danh sach cac cuon sach\n");
        printf("5. Xoa tat ca cac cuon sach xuat ban nam 2010\n");
        printf("6. Thong ke sach theo tung loai\n");
        printf("7. Sap xep theo so luong tang dan\n");
        printf("8. Thoat chuong trinh\n\n");
        printf("Choice:  ");
        scanf("%d", &choice);
        char ten[100];
        int sl;
        char loai;
        int nam;
        switch(choice){
            case 1:{
                printf("Nhap thong tin cua cuon sach can them:\n");
                printf("Ten sach:  ");
                while (getchar() != '\n');
                fgets(ten, 100, stdin);
                ten[strcspn(ten, "\n")] = '\0';
                
                printf("So luong cuon sach:  ");
                scanf("%d", &sl);
               
                while (sl < 0) {
                    printf("So luong sach khong duoc am! Nhap lai:  ");
                    scanf("%d", &sl);
                }
                
                printf("Loai sach (A, B, C):  ");
                getchar();
                scanf("%c", &loai);
               
                while (loai != 'A' && loai != 'B' && loai != 'C') {
                    printf("Loai sach chi co the la A, B hoac C! Nhap lai:  ");
                    getchar();
                    scanf("%c", &loai);
                }
                
                printf("Nam xuat ban:  ");
                scanf("%d", &nam);
               
                while (nam > 2025 || nam < 0) {
                    if (nam > 2025) {
                        printf("Nam xuat ban khong duoc vuot qua 2025! Nhap lai:  ");
                    } else {
                        printf("Nam xuat ban khong duoc am! Nhap lai:  ");
                    }
                    scanf("%d", &nam);
                }
                
                themdau5(&head, createNode5(ten, sl, loai, nam));
                break;
            }
            case 2:{
                printf("Nhap thong tin cua cuon sach can them:\n");
                printf("Ten sach:  ");
                while (getchar() != '\n');
                fgets(ten, 100, stdin);
                ten[strcspn(ten, "\n")] = '\0';
                
                printf("So luong cuon sach:  ");
                scanf("%d", &sl);
             
                while (sl < 0) {
                    printf("So luong sach khong duoc am! Nhap lai:  ");
                    scanf("%d", &sl);
                }
                
                printf("Loai sach (A, B, C):  ");
                getchar();
                scanf("%c", &loai);
            
                while (loai != 'A' && loai != 'B' && loai != 'C') {
                    printf("Loai sach chi co the la A, B hoac C! Nhap lai:  ");
                    getchar();
                    scanf("%c", &loai);
                }
                
                printf("Nam xuat ban:  ");
                scanf("%d", &nam);
               
                while (nam > 2025 || nam < 0) {
                    if (nam > 2025) {
                        printf("Nam xuat ban khong duoc vuot qua 2025! Nhap lai:  ");
                    } else {
                        printf("Nam xuat ban khong duoc am! Nhap lai:  ");
                    }
                    scanf("%d", &nam);
                }
                
                themcuoi5(&head, createNode5(ten, sl, loai, nam));
                break;
            }
            case 3:
                Nhap5(&n, &head);
                break;
            case 4:
                Xuat5(n, head);
                break;
            case 5:
                Xoasach20105(&head);
                break;
            case 6:
                Thongketheoloai5(head);
                break;
            case 7:
                Sapxeptangdan5(&head);
                break;
            case 8:
                giaiphongbonho5(&head);
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");            
        } 
    } while(choice != 8);
    return 0;
}
