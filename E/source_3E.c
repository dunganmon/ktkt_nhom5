Node3 *createNode3(int heSo, int luyThua) {
    Node3 *newNode = (Node3*)malloc(sizeof(Node3));
    if(newNode != NULL) {
        newNode->heSo = heSo;
        newNode->luyThua = luyThua;
        newNode->next = NULL;
    }
    return newNode;
}

void insert3(Node3 **daThuc, int heSo, int luyThua) {
    if(heSo == 0) return;
    Node3 *newNode = createNode3(heSo, luyThua);
    if(*daThuc == NULL || luyThua > (*daThuc)->luyThua) {
        newNode->next = *daThuc;
        *daThuc = newNode;
        return;
    }

    Node3 *current = *daThuc;
    while(current->next != NULL && current->next->luyThua > luyThua) {
        current = current->next;
    }

    if(current->next != NULL && current->next->luyThua == luyThua) {
        current->next->heSo += heSo;
        if(current->next->heSo == 0) {
            Node3 *tmp = current->next;
            current->next = tmp->next;
            free(tmp);
        }
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void inDaThuc3(Node3 *daThuc) {
    if(daThuc == NULL) {
        printf("0\n");
        return;
    }

    Node3 *current = daThuc;
    int firstPoint = 1;

    while(current != NULL) {
        if(current->heSo != 0) {
            if(firstPoint) {
                if(current->heSo < 0) {
                    printf("-");
                    current->heSo = -current->heSo;
                }
                firstPoint = 0;
            } else {
                printf(" %s ", (current->heSo > 0) ? "+" : "-");
                if(current->heSo < 0) current->heSo = -current->heSo;
            }
            if(current->heSo != 1 || current->luyThua == 0) {
                printf("%d", current->heSo);
            }
            if(current->luyThua != 0) {
                printf("x");
                if(current->luyThua != 1) {
                    printf("^%d", current->luyThua);
                }
            }
        }
        current = current->next;
    }
}

double tinhDaThuc3(Node3 *daThuc, double x) {
    double result = 0.0;
    Node3 *current = daThuc;

    while(current != NULL) {
        result += current->heSo * pow(x, current->luyThua);
        current = current->next;
    }
    return result;
}

Node3 *daoHamDaThuc3(Node3 *daThuc) {
    Node3 *daoHam = NULL;
    Node3 *current = daThuc;

    while(current != NULL) {
        if(current->luyThua > 0) {
            int heSoMoi = current->heSo * current->luyThua;
            int luyThuaMoi = current->luyThua - 1;
            insert3(&daoHam, heSoMoi, luyThuaMoi);
        }
        current = current->next;
    }
    return daoHam;
}

void freeDaThuc3(Node3 *daThuc) {
    Node3 *current = daThuc;
    Node3 *next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

double tinhDaoHam3(Node3 *daThuc, double x) {
    Node3 *daoHam = daoHamDaThuc3(daThuc);
    double result = tinhDaThuc3(daoHam, x);
    freeDaThuc3(daoHam);
    return result;
}

Node3 *tong2DaThuc3(Node3 *daThuc1, Node3 *daThuc2) {
    Node3 *result = NULL;
    Node3 *current1 = daThuc1;
    Node3 *current2 = daThuc2;

    while(current1 != NULL) {
        insert3(&result, current1->heSo, current1->luyThua);
        current1 = current1->next;
    }

    while(current2 != NULL) {
        insert3(&result, current2->heSo, current2->luyThua);
        current2 = current2->next;
    }
    return result;
}

Node3 *nhapDaThuc3() {
    Node3 *daThuc = NULL;
    int n, heSo, luyThua;
    int i;

    printf("Nhap so luong so hang tu trong da thuc: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("So luong so hang tu phai lon hon 0!\nNhap lai: ");
        scanf("%d", &n);
    }
    for(i = 0; i < n; i++) {
        printf("Nhap he so thu %d: ", i + 1);
        scanf("%d", &heSo);
        printf("Nhap luy thua thu %d: ", i + 1);
        scanf("%d", &luyThua);
        insert3(&daThuc, heSo, luyThua);
    }
    return daThuc;
}
