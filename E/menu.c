#include <stdio.h>
#include <stdlib.h>
#include "menu.h"  

void displayMenu() {
    printf("\n===== MENU CHUONG TRINH =====\n");
    printf("1. Chay bai 1E\n");
    printf("2. Chay bai 2E\n");
    printf("3. Chay bai 3E\n");
    printf("4. Chay bai 4E\n");
    printf("5. Chay bai 5E\n");
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
            case 1: main_1E(); break;
            case 2: main_2E(); break;
            case 3: main_3E(); break;
            case 4: main_4E(); break;
            case 5: main_5E(); break;
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