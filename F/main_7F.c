#include "header_7F.h"
#include "soucre_7F.c"

int main_7F() {
    NhanVien* ds;
    int n;
    readFile7(&ds, &n);
    print7(ds, n);
    highestSalary7(ds, n);
    countRoom7(ds, n);
    write_ans7(n, ds);
    free(ds);
    return 0;
}

