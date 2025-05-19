#include <stdio.h>
#include <stdlib.h>
#include "menu.h"  

void displayMenu() {
    printf("\n===== MENU CHUONG TRINH =====\n");
    printf("1. Chay bai 1F\n");
    printf("2. Chay bai 2F\n");
    printf("3. Chay bai 3F\n");
    printf("4. Chay bai 4F\n");
    printf("5. Chay bai 5F\n");
    printf("6. Chay bai 6F\n");
    printf("7. Chay bai 7F\n");
    printf("8. Chay bai 8F\n");
	printf("0. Thoat\n");
    printf("============================\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: main_1F(); break;
            case 2: main_2F(); break;
            case 3: main_3F(); break;
            case 4: main_4F(); break;
            case 5: main_5F(); break;
            case 6: main_6F(); break;
            case 7: main_7F(); break;
            case 8: main_8F(); break;
			case 0: printf("Cam on ban da su dung chuong trinh!\n"); break;
            default: printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
        
        if (choice != 0) {
            printf("\nNhan Enter de tiep tuc...");
            getchar(); 
            getchar(); 
        }
        
    } while (choice != 0);
    
    return 0;
}
