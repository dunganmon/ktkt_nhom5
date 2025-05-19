LinkedList createNode(ThiSinh data){
    LinkedList newNode = (LinkedList)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(LinkedList *head, ThiSinh data){
    LinkedList newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    LinkedList tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void insertAtHead(LinkedList *head, ThiSinh data){
    LinkedList newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void inputThiSinh(LinkedList *head, int *n){
    ThiSinh thongtinThiSinh;
    do{
        printf("\nNhap vao so luong thi sinh: ");
        scanf("%d", n);
        if(*n <= 0){
            printf("So luong thi sinh khong hop le!\n");
        }
    }while(*n <= 0);

    int i;
    for(i = 0; i < *n; i++){
        printf("\nThong tin cua sinh vien thu %d\n", i + 1);
        getchar();

        printf("Nhap vao ten thi sinh: ");
		fflush(stdin);gets(thongtinThiSinh.HoTen);
        printf("Nhap vao diem Toan: ");
        scanf("%f", &thongtinThiSinh.DToan);

        printf("Nhap vao diem Hoa: ");
        scanf("%f", &thongtinThiSinh.DHoa);

        printf("Nhap vao diem Ly: ");
        scanf("%f", &thongtinThiSinh.DLy);

        appendNode(head, thongtinThiSinh);
    }
}

void outputThiSinh(LinkedList head){
    LinkedList tmp = head;
    int i = 0;
    printf("STT %-30s %-15s %-15s %-15s\n", "Ho va ten", "Diem Toan", "Diem Hoa", "Diem Ly");
    while(tmp != NULL){
        printf("%3d %-30s %-.2f %-10s %-.2f %-10s %-.2f\n", i + 1, tmp->data.HoTen, tmp->data.DToan, " ", tmp->data.DHoa, " ", tmp->data.DLy);
        tmp = tmp->next;
        i++;
    }
}

void XuatDanhSachThiSinhVaoFileNhiPhan(LinkedList head){
    char filename[50];
    printf("Nhap vao ten file nhi phan ma ban muon in ra danh sach: ");
    scanf("%s", &filename);
    FILE *f = fopen(filename, "wb");
    if(f == NULL){
        printf("Mo file nhi phan khong thanh cong!\n");
        exit(1);
    }

    LinkedList tmp = head;
    while(tmp != NULL){
        fwrite(&tmp->data, sizeof(ThiSinh), 1, f);
        tmp = tmp->next;
    }

    fclose(f);
    printf("Da ghi danh sach thi sinh vao file: %s", filename);
}

void XuatDanhSachThiSinhVaoFileVanBan(LinkedList head){
    char filename[50];
    printf("Nhap vao ten file van ban ma ban muon in ra danh sach: ");
    scanf("%s", &filename);
    FILE *f = fopen(filename, "w");
    if(f == NULL){
        printf("Mo file van ban khong thanh cong!\n");
        exit(1);
    }
    int i = 1;
    LinkedList tmp = head;
    fprintf(f, "STT %-30s %-15s %-15s %-15s\n", "Ho va ten", "Diem Toan", "Diem Hoa", "Diem Ly");
    while(tmp != NULL){
        fprintf(f, "%3d %-30s %-15.2f %-15.2f %-15.2f\n", i, tmp->data.HoTen, tmp->data.DToan, tmp->data.DHoa, tmp->data.DLy);
        tmp = tmp->next;
        i++;
    }

    fclose(f);
    printf("\nDa ghi danh sach thi sinh vao file: %s", filename);
}

LinkedList NhapDanhSachThiSinhTuFileNhiPhan(){
    char filename[50];
    printf("Nhap vao ten file nhi phan ban muon lay danh sach thi sinh: ");
    scanf("%s", &filename);
    FILE *f = fopen(filename, "rb");
    if(f == NULL){
        printf("Khong mo duoc file nhi phan!\n");
        exit(1);
    }

    LinkedList head = NULL, tmp = NULL;
    ThiSinh ts;
    while(fread(&ts, sizeof(ThiSinh), 1, f) == 1){
        LinkedList newNode = createNode(ts);

        if(head == NULL){
            head = tmp = newNode;
        }

        else{
            tmp->next = newNode;
            tmp = newNode;
        }
    }
    
    fclose(f);
    printf("Da doc danh sach thi sinh tu file: %s", filename);
    return head;
}

void NhapDanhSachThiSinhTuFileVanBan(LinkedList *head){
    char filename[50];
    printf("Nhap vao ten file van ban ban muon lay danh sach thi sinh: ");
    scanf("%s", &filename);
        
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong mo duoc file van ban!\n");
        exit(1);
    }

    char hoTen[100];
    float toan, ly, hoa;

    while (fgets(hoTen, sizeof(hoTen), f)) {
        hoTen[strcspn(hoTen, "\n")] = '\0';

        if (fscanf(f, "%f %f %f\n", &toan, &hoa, &ly) == 3) {
            ThiSinh ts;
            strcpy(ts.HoTen, hoTen);
            ts.DToan = toan;
            ts.DLy = ly;
            ts.DHoa = hoa;

            appendNode(head, ts);
        }
    }
    fclose(f);
    printf("Da doc danh sach thi sinh tu file: %s\n", filename);
}
    
void ThiSinhCoDiemToanCaoNhat(LinkedList head){
    float DToanMax = head->data.DToan;

    LinkedList tmp = head;
    while(tmp != NULL){
        if(tmp->data.DToan >= DToanMax){
            DToanMax = tmp->data.DToan;
        }

        tmp = tmp->next;
    }

    printf("\nDiem toan cao nhat la: %.2f\n", DToanMax);
    tmp = head;
    while(tmp != NULL){
        if(tmp->data.DToan == DToanMax){
            printf("%-30s\n", tmp->data.HoTen);
        }

        tmp = tmp->next;
    }
}

float DiemLyThapNhat(LinkedList head){
    LinkedList tmp = head;
    float DLyMin = tmp->data.DLy;

    while(tmp != NULL){
        if(DLyMin >= tmp->data.DLy){
            DLyMin = tmp->data.DLy;
        }
        tmp = tmp->next;
    }

    return DLyMin;
}

void XoaDiemLyThapNhat(LinkedList *head, float DLyMin){
    if(*head == NULL){
        return;
    }

    LinkedList tmp = *head;

    if(tmp->data.DLy == DLyMin){
        *head = tmp->next;
        free(tmp);
        XoaDiemLyThapNhat(head, DLyMin);
    }
    else{
        XoaDiemLyThapNhat(&(tmp->next), DLyMin);
    }
}

void freeLinkedList(LinkedList head){
    LinkedList tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void menu(LinkedList *head, int *choice, int *n){
    ThiSinh ts;
    LinkedList tmp = *head;
    do{
        printf("\n-----Menu-----\n");
        printf("1: Bo Sung thi sinh vao dau danh sach\n");
        printf("2: Bo sung thi sinh vao cuoi danh sach\n");
        printf("3: Nhap thong tin n thi sinh\n");
        printf("4: In ra thong tin tung sinh vien\n");
        printf("5: Xuat danh sach thi sinh ra file Nhi Phan\n");
        printf("6: Xuat danh sach thi sinh ra file Van ban\n");
        printf("7: Nhap danh sach thi sinh tu file nhi phan\n");
        printf("8: Nhap danh sach thi sinh tu file Van ban\n");
        printf("9: In ra cac thi sinh co diem Toan cao nhat\n");
        printf("10: Xoa tat ca cac thi sinh co diem Ly Thap nhat\n");
        printf("11: Thoat khoi chuong trinh\n");

        printf("\nNhap vao lua chon: ");
        scanf("%d", choice);

        switch(*choice){
            case 1:
                getchar();
                printf("\nNhap vao ten thi sinh: ");
                fgets(ts.HoTen, sizeof(ts.HoTen), stdin);
                ts.HoTen[strcspn(ts.HoTen, "\n")] = '\0';

                printf("Nhap vao diem Toan: ");
                scanf("%f", &ts.DToan);

                printf("Nhap vao diem Hoa: ");
                scanf("%f", &ts.DHoa);

                printf("Nhap vao diem Ly: ");
                scanf("%f", &ts.DLy);

                insertAtHead(head, ts);
                break;

            case 2:
                getchar();
                printf("\nNhap vao ten thi sinh: ");
                fgets(ts.HoTen, sizeof(ts.HoTen), stdin);
                ts.HoTen[strcspn(ts.HoTen, "\n")] = '\0';

                printf("Nhap vao diem Toan: ");
                scanf("%f", &ts.DToan);

                printf("Nhap vao diem Hoa: ");
                scanf("%f", &ts.DHoa);

                printf("Nhap vao diem Ly: ");
                scanf("%f", &ts.DLy);

                appendNode(head, ts);
                break;

            case 3:
                inputThiSinh(head, n);
                break;

            case 4:
                outputThiSinh(*head);
                break;
            
            case 5:
                XuatDanhSachThiSinhVaoFileNhiPhan(*head);
                break;

            case 6:
                XuatDanhSachThiSinhVaoFileVanBan(*head);
                break;

            case 7:
                *head = NhapDanhSachThiSinhTuFileNhiPhan();
                printf("\n");
                outputThiSinh(*head);
                break;

            case 8:
                *head = NULL;
                NhapDanhSachThiSinhTuFileVanBan(head);
                printf("\n");
                outputThiSinh(*head);
                break;

            case 9:
                ThiSinhCoDiemToanCaoNhat(*head);
                break;
            
            case 10:
                XoaDiemLyThapNhat(head, DiemLyThapNhat(*head));
                printf("Da xoa thi cac thi sinh co diem Ly thap nhat!\n");
                break;

            case 11:
                freeLinkedList(*head);
                printf("Da Thoat khoi chuong trinh!");
                break;
            
            default:
                printf("\nLua chon khong co trong menu!");
                break;
        }
    }while(*choice != 11);
}
