#include <stdio.h>
#include <stdlib.h>


void nhap_ma_tran_tu_ban_phim3(float **matran, int dong, int cot);


void nhap_ma_tran_tu_file_van_ban3(float **matran, const char *filename, int *dong, int *cot);


void ghi_ra_file_van_ban3(float **matran, const char *filename, int dong, int cot);

void ghi_ra_file_nhi_phan3(float **matran, const char *filename, int dong, int cot);


void nhap_tu_file_nhi_phan3(float **matran, const char *filename, int *dong, int *cot);


void hien_thi_ma_tran3(float **matran, int dong, int cot);


float** cap_phat_ma_tran3(int dong, int cot);


void giai_phong_ma_tran3(float **matran, int dong);


