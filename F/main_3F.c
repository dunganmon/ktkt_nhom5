#include"header_3F.h"
#include"source_3F.c"
int main_3F(){

    int dong = 0, cot = 0;
    float **matran = NULL;
    int da_cap_phat = 0;
    int lua_chon;
    
    do {
        printf("\n==== MENU ====\n");
        printf("1. Nhap ma tran tu ban phim\n");
        printf("2. Ghi ma tran ra file van ban (output_3F.txt)\n");
        printf("3. Ghi ma tran ra file nhi phan (output_3F.dat)\n");
        printf("4. Doc ma tran tu file van ban (input_3F.txt)\n");
        printf("5. Doc ma tran tu file nhi phan (input_3F.dat)\n");
        printf("6. Hien thi ma tran\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lua_chon);
        
        switch(lua_chon) {
            case 1: {
                printf("Nhap so dong: ");
                scanf("%d", &dong);
                printf("Nhap so cot: ");
                scanf("%d", &cot);
                
               
                if (da_cap_phat) {
                    giai_phong_ma_tran3(matran, dong);
                }
                
              
                matran = cap_phat_ma_tran3(dong, cot);
                if (!matran) {
                    printf("Khong the cap phat bo nho cho ma tran!\n");
                    break;
                }
                
                da_cap_phat = 1;
                nhap_ma_tran_tu_ban_phim3(matran, dong, cot);
                printf("Da nhap ma tran thanh cong!\n");
                break;
            }
                
            case 2: {
                if (!da_cap_phat) {
                    printf("Chua co ma tran nao duoc nhap!\n");
                    break;
                }
                
                ghi_ra_file_van_ban3(matran, "output_3F.txt", dong, cot);
                printf("Da ghi ma tran ra file van ban output_3F.txt\n");
                break;
            }
                
            case 3: {
                if (!da_cap_phat) {
                    printf("Chua co ma tran nao duoc nhap!\n");
                    break;
                }
                
                ghi_ra_file_nhi_phan3(matran, "output_3F.dat", dong, cot);
                printf("Da ghi ma tran ra file nhi phan output_3F.dat\n");
                break;
            }
                
            case 4: {
               
                FILE *f_temp = fopen("input_3F.txt", "r");
                int dong_moi = 0, cot_moi = 0;
                
                if (!f_temp) {
                    printf("Khong the mo file input_3F.txt\n");
                    break;
                }
                
                if (fscanf(f_temp, "%d %d", &dong_moi, &cot_moi) != 2) {
                    printf("Loi dinh dang file: khong the doc so dong va cot\n");
                    fclose(f_temp);
                    break;
                }
                
                fclose(f_temp);
               
                if (da_cap_phat) {
                    giai_phong_ma_tran3(matran, dong);
                }
                
            
                matran = cap_phat_ma_tran3(dong_moi, cot_moi);
                if (!matran) {
                    printf("Khong the cap phat bo nho cho ma tran!\n");
                    break;
                }
                
            
                nhap_ma_tran_tu_file_van_ban3(matran, "input_3F.txt", &dong, &cot);
                da_cap_phat = 1;
                printf("Da doc ma tran tu file van ban input_3F.txt\n");
                break;
            }
                
            case 5: {
               
                FILE *f_bin = fopen("input_3F.dat", "rb");
                int dong_moi = 0, cot_moi = 0;
                
                if (!f_bin) {
                    printf("Khong the mo file input_3F.dat\n");
                    break;
                }
                
                if (fread(&dong_moi, sizeof(int), 1, f_bin) != 1 || 
                    fread(&cot_moi, sizeof(int), 1, f_bin) != 1) {
                    printf("Loi doc so dong va cot\n");
                    fclose(f_bin);
                    break;
                }
                
                fclose(f_bin);
                
              
                if (da_cap_phat) {
                    giai_phong_ma_tran3(matran, dong);
                }
                
                 matran = cap_phat_ma_tran3(dong_moi, cot_moi);
                if (!matran) {
                    printf("Khong the cap phat bo nho cho ma tran!\n");
                    break;
                }
                
             
                nhap_tu_file_nhi_phan3(matran, "input_3F.dat", &dong, &cot);
                da_cap_phat = 1;
                printf("Da doc ma tran tu file nhi phan input_3F.dat\n");
                break;
            }
                
            case 6: {
                if (!da_cap_phat) {
                    printf("Chua co ma tran nao duoc nhap!\n");
                    break;
                }
                
                hien_thi_ma_tran3(matran, dong, cot);
                break;
            }
                
            case 0: {
                printf("Thoat chuong trinh.\n");
                break;
            }
                
            default: {
                printf("Lua chon khong hop le.\n");
            }
        }
    } while (lua_chon != 0);
    
   
    if (da_cap_phat) {
        giai_phong_ma_tran3(matran, dong);
    }
    
    return 0;
}

