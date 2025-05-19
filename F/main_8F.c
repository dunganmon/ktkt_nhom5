#include "header_8F.h"
#include "soucre_8F.c"

int main_8F(){
	int n, m;
	int **a;
	int ok = 0, i;
	FILE *f;
	Docvain(&f, &n, &m, &a);
	long long tich = tichphantule(n, m, a, &ok);
	if(ok == 0) printf("Ma tran toan phan tu chan\n");
	else{
		printf("Tich cac phan tu le cua ma tran la: %lld\n", tich);
	}
	phantuchanmax(n, m, a);
	sum_hang_chia_het7(n, m, a);
	for(i = 0; i < n; i++){
		free(a[i]);
	}
	free(a);
}
