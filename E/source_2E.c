void Nhap2(int *n, Sach2 **A){
    printf("Nhap so luong sach: "); 
    scanf("%d", n);
    while (*n <= 0) {
        printf("So luong sach phai lon hon 0! Nhap lai: ");
        scanf("%d", n);
    }
	getchar();
    printf("\n----------Nhap thong tin-----------\n");
    int i;
    for(i = 0; i < *n; i++){
        Sach2 *newNode2 = (Sach2*)malloc(sizeof(Sach2)); 
        
        printf("Cuon thu %d\n", i+1);
        printf("     Nhap ten cuon sach: "); 
        fgets(newNode2->title, 100, stdin); 
        newNode2->title[strcspn(newNode2->title, "\n")] = '\0';
        
        printf("     Nhap ten tac gia: "); 
        fgets(newNode2->author, 100, stdin); 
        newNode2->author[strcspn(newNode2->author, "\n")] = '\0';
        
        printf("     Nhap nam xuat ban: "); 
        scanf("%d", &newNode2->publication_year);
        while (newNode2->publication_year > 2025 || newNode2->publication_year < 0) {
            if (newNode2->publication_year > 2025) {
                printf("     Nam xuat ban khong duoc vuot qua 2025! Nhap lai: ");
            } else {
                printf("     Nam xuat ban khong duoc am! Nhap lai: ");
            }
            scanf("%d", &newNode2->publication_year);
        }
	    getchar();
        
        newNode2->next = NULL;
        
        if(*A == NULL) {
            *A = newNode2;
        } else {
            Sach2 *temp = *A;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newNode2;
        }
    }
}

void Xuat2(int n, Sach2 *A){
    int i = 1;
    Sach2 *temp = A;
    printf("\n----------In danh sach-----------\n");
    while (temp != NULL) {
        printf("Cuon thu %d\n   Ten cuon sach: %s\n   Ten tac gia: %s\n   Nam xuat ban: %d\n", 
               i++, temp->title, temp->author, temp->publication_year);
        temp = temp->next;
    }
}

int DemSach2(int n, Sach2 *A){
    int count = 0;
    char ten[100];
    printf("\nDem so luong sach theo tac gia\n");
    printf("Nhap ten tac gia: "); 
    getchar();
    fgets(ten, 100, stdin); 
    ten[strcspn(ten, "\n")] = '\0';
    Sach2 *temp = A;
    while(temp != NULL) {
        if(strcmp(temp->author, ten)==0) {
            count++;
        }
        temp = temp->next;
    }
    printf("Tac gia %s co %d cuon\n", ten, count);
    return count;
}

void ThongKe2(int n, Sach2 *A2){
    int nam[100], Dem[100];
    int check = 0;
    Sach2 *temp = A2;
    int i;
    while (temp != NULL) {
        int dem = 0;
        for(i = 0; i < check; i++){
            if(temp->publication_year == nam[i]){
                Dem[i]++;
                dem = 1; 
                break;
            }
        }
        if(!dem){
            nam[check] = temp->publication_year;
            Dem[check] = 1;
            check++;
        }
        temp = temp->next;
    }
    printf("\nThong ke sach theo nam:\n");
    for(i = 0; i < check; i++){
        printf("Nam %d co %d cuon sach.\n", nam[i], Dem[i]);
    }
}

void freeList2(struct Sach2 *A) {
    struct Sach2 *temp;
    while(A != NULL){
        temp = A;
        A = A->next;
        free(temp);
    }
}
