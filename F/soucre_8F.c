void Docvain(FILE **f, int *n, int *m, int ***a){
	*f = fopen("input_8F.txt", "r");
	if(*f == NULL){
		printf("Khong the mo file\n");
		exit(0);
	}
	fscanf(*f, "%d%d", n, m);
	*a = (int **)malloc(*n * sizeof(int*));

	int i, j;
	for(i = 0; i < *n; i++){
		(*a)[i] = (int *)malloc(*m * sizeof(int));
	}
	printf("Ma tran duoc nhap tu file la:\n");
	for(i = 0; i < *n; i++){
		for(j = 0; j < *m; j++){
			fscanf(*f, "%d", &(*a)[i][j]);
			printf("%5d ", (*a)[i][j]);
		}
		printf("\n");
	}
	fclose(*f);
}

long long tichphantule(int n, int m, int **a, int *ok){
	long long tich = 1;
	*ok = 0;

	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(a[i][j] % 2 != 0){
				tich *= a[i][j];
				*ok = 1;
			}
		}
	}
	return tich;
}

void phantuchanmax(int n, int m, int **a){
	int max = a[0][0];
	int x, y, check = 0;

	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(a[i][j] % 2 == 0){
				if(a[i][j] > max){
					max = a[i][j];
					x = i;
					y = j;
					check = 1;
				}
			}
		}
	}
	if(check == 0) printf("Ma tran toan phan tu le\n");
	else{
		printf("Phan tu chan lon nhat la: %d\n", max);
		printf("Thuoc o vi tri hang so %d va cot so %d\n", x, y);
	}
}

void sum_hang_chia_het7(int n, int m, int **a){
	printf("Tong phan tu moi hang chia het cho 7 la:\n");

	int i, j;
	for(i = 0; i < n; i++){
		int sum = 0;
		for(j = 0; j < m; j++){
			if(a[i][j] % 7 == 0){
				sum += a[i][j];
			}
		}
		printf("Hang %d: %d\n", i, sum);
	}
}

