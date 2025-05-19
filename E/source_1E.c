struct Node1 *createNode1(float data1){
    struct Node1 *newNode1 = (struct Node1*)malloc(sizeof(struct Node1));
    newNode1->data1 = data1;
    newNode1->next1 = NULL;
    return newNode1;
}

void them_gia_tri_vao_cuoi_day_so1(Node1 **head1, float data1){
    struct Node1 *newNode1 = createNode1(data1);
    if(*head1 == NULL){
        *head1 = newNode1;
        return;
    }
    struct Node1* temp1 = *head1;
    while(temp1->next1 != NULL){
        temp1 = temp1->next1;
    }
    temp1->next1 = newNode1;
}

int nhap1(struct Node1 **head1){
    int n;
    printf("nhap so luong phan tu: ");scanf("%d",&n);
    float data1;
    int i;
    for(i = 0; i < n; i++){
        printf("nhap gia tri thu%d trong day so:",i + 1);
        scanf("%f",&data1);
        them_gia_tri_vao_cuoi_day_so1(head1,data1);
    }
    return n;
}

void in1(struct Node1* head1){
    printf("cac phan tu trong danh sach: ");
    while(head1 != NULL){
        printf("%.2f\t",head1->data1);
        head1 = head1->next1;
    }
}

void giai_phong_bo_nho1(struct Node1* head1){
    struct Node1* temp1;
    while(head1 != NULL){
        temp1 = head1;
        head1 = head1->next1;
        free(temp1);
    }
}

int max_duong1(struct Node1 *head1, float *max1){
    float so_duong1 = 0;
    while(head1 != NULL){
        if(head1->data1 > 0){
            if(!so_duong1){
                *max1 = head1->data1;
                so_duong1 = 1;
            }else if(head1->data1 > *max1){
                *max1 = head1->data1;
            }
        }
        head1 = head1->next1;
    }
    return so_duong1;
}

int la_day_fibonacci1(struct Node1 *head1){
    if(head1 == NULL || head1->next1 == NULL || head1->next1->next1 == NULL){
        return 0;
    }
    struct Node1 *a = head1;
    struct Node1 *b = head1->next1;
    struct Node1 *c = head1->next1->next1;
    while(c != NULL){
        if(c->data1 != a->data1 + b->data1){
            return 0;
        }
        a = b;
        b = c;
        c = c->next1;
    }
    return 1;
}
