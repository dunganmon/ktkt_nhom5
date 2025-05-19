#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node3 {
    int heSo;
    int luyThua;
    struct Node3 *next;
} Node3;

Node3 *createNode3(int heSo, int luyThua);
void insert3(Node3 **daThuc, int heSo, int luyThua);
void inDaThuc3(Node3 *daThuc);
double tinhDaThuc3(Node3 *daThuc, double x);
Node3 *daoHamDaThuc3(Node3 *daThuc);
void freeDaThuc3(Node3 *daThuc);
double tinhDaoHam3(Node3 *daThuc, double x);
Node3 *tong2DaThuc3(Node3 *daThuc1, Node3 *daThuc2);
Node3 *nhapDaThuc3();
