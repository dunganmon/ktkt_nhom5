
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node1{
    float data1;
    struct Node1* next1;
} Node1;

struct Node1 *createNode1(float data1);
void them_gia_tri_vao_cuoi_day_so1(Node1 **head1, float data1);
int nhap1(struct Node1 **head1);
void in1(struct Node1 *head1);
void giai_phong_bo_nho1(struct Node1* head1);
int max_duong1(struct Node1 *head1, float *max1);
int la_day_fibonacci1(struct Node1 *head1);
