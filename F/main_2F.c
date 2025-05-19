#include"header_2F.h"
#include"source_2F.c"
int main_2F() {
    Hang_hoa *ds;
    int n;
    nhap_ds(&ds, &n);
    xuat_ds_file(ds, n, "output_2F.txt");
    printf("\nDa ghi danh sach hang hoa vao file output_2F.txt\n");
    int tong = tong_sl_hang(ds, n);
    printf("\nTong tat ca hang hoa trong danh sach la: %d\n", tong);
    char ten_can_tim[100];
    printf("\nNhap ten hang hoa can tim: ");
    
    fflush(stdin); gets(ten_can_tim);
    tim_theo_ten(ds, n, ten_can_tim);
    sap_xep_ten(ds, n);
    xuat_file_nhi_phan(ds, n, "output_2F.dat");
    printf("\nDa ghi danh sach hang hoa da sap xep theo ten vao file output_2F.dat\n");
    
    free(ds);
    return 0;
}
