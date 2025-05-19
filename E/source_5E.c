Sach *createNode5(char ten[], int sl, char loai, int nam) {
    Sach *newNode = (Sach*)malloc(sizeof(Sach));
    strcpy(newNode->ten, ten);
    newNode->sl = sl;
    newNode->loai = loai;
    newNode->nam = nam;
    newNode->next = NULL;
    return newNode;
}

void themdau5(Sach **head, Sach *newNode) {
    newNode->next = *head;
    *head = newNode;
}

void themcuoi5(Sach **head, Sach *newNode) {
    if(*head == NULL) {
        *head = newNode;
    } else {
        Sach *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void Nhap5(int *n, Sach **head) {
    char ten[100];
    int sl;
    char loai;
    int nam, i;
    printf("Nhap so luong cuon sach:  ");
    scanf("%d", n);
    
   
    while (*n <= 0) {
        printf("So luong sach phai lon hon 0! Nhap lai:  ");
        scanf("%d", n);
    }
    
    for(i = 0; i < *n; i++) {
        printf("Nhap thong tin cua cuon sach thu %d:\n", i + 1);
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
        
        Sach *newNode = createNode5(ten, sl, loai, nam);
        themcuoi5(head, newNode);
    }
}

void Xuat5(int n, Sach *head) {
    Sach *temp = head;
    if(head == NULL) {
        printf("Danh sach rong\n");
        return;
    }
    int i = 1;
    printf("Danh sach cac cuon sach:\n");
    while (temp != NULL) {
        printf("| %-4d | Ten sach: %-20s | So luong: %-4d | Loai sach: %-4c | Nam xuat ban: %-5d |\n", 
        i++, temp->ten, temp->sl, temp->loai, temp->nam);
        temp = temp->next;
    }
}

void Xoasach20105(Sach **head) {
    int check = 0;
    while(*head && (*head)->nam == 2010) {
        Sach *def = *head;
        *head = (*head)->next;
        free(def);
        check = 1;
    }
    Sach *temp = *head;
    while(temp && temp->next) {
        if(temp->next->nam == 2010) {
            Sach *def = temp->next;
            temp->next = def->next;
            free(def);
            check = 1;
        } else {
            temp = temp->next;
        }
    }
    if(check == 0) printf("Khong co cuon sach nao xuat ban nam 2010\n");
    else printf("Da xoa het cuon sach xuat ban nam 2010\n");
}

void Thongketheoloai5(Sach *head) {
    int tongA = 0, tongB = 0, tongC = 0;
    Sach *temp = head;
    while(temp != NULL) {
        switch(temp->loai) {
            case 'A': tongA += temp->sl; break;
            case 'B': tongB += temp->sl; break;
            case 'C': tongC += temp->sl; break;
        }
        temp = temp->next;
    }
    printf("Loai A: %d | Loai B: %d | Loai C: %d |\n", tongA, tongB, tongC);
}

void Sapxeptangdan5(Sach **head) {
    Sach *temp = *head;
    Sach *i, *j;
    for(i = *head; i != NULL; i = i->next) {
        for(j = *head; j != NULL; j = j->next) {
            if(i->sl < j->sl) {
                char tempten[100];
                strcpy(tempten, i->ten);
                strcpy(i->ten, j->ten);
                strcpy(j->ten, tempten);
                int tempsl = i->sl;
                i->sl = j->sl;
                j->sl = tempsl;
                char temploai = i->loai;
                i->loai = j->loai;
                j->loai = temploai;
                int tempnam = i->nam;
                i->nam = j->nam;
                j->nam = tempnam;
            }
        }
    }
    printf("Danh sach cuon sach xep theo so luong tang dan:\n");
    int k = 1;
    while (temp != NULL) {
        printf("| %-4d | Ten sach: %-20s | So luong: %-4d | Loai sach: %-4c | Nam xuat ban: %-5d |\n", 
        k++, temp->ten, temp->sl, temp->loai, temp->nam);
        temp = temp->next;
    }
}

void giaiphongbonho5(Sach **head) {
    Sach *temp;
    while(*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
