#include "header_1E.h"
#include "source_1E.c"
int main_1E(){
    struct Node1* head1 = NULL;
    int lua_chon1;
    while(1){
        printf("\n---- MENU----\n");
        printf("1) Nhap day:\n");
        printf("2) Xuat day:\n");
        printf("3) Tim max duong:\n");
        printf("4) Kiem tra day so fibonacci:\n");
        printf("5) Thoat\n");
        printf("chon chuc nang:");
        scanf("%d",&lua_chon1);
        switch(lua_chon1){
            case 1:
                giai_phong_bo_nho1(head1);
                head1 = NULL;
                nhap1(&head1);
                break;
            case 2:
                in1(head1);
                break;
            case 3:
            {
                float max1;
                if(max_duong1(head1,&max1)){
                    printf("\nso duong lon nhat trong day so la:%.2f\n",max1);
                }
                else{
                    printf("\nday so khong co so duong\n");
                }    
            }
            break;
            case 4:
                if(la_day_fibonacci1(head1)){
                    printf("Day so co tinh chay fibonacci.\n");
                }else{
                    printf("day so khong co tinh chat fibonacci\n");
                }
                break;
            case 5:
                giai_phong_bo_nho1(head1);
                printf("thoat chuong trinh\n");
                return 0;
            default:
                printf("lua chon khong hop le!!!");
        }
    }
}