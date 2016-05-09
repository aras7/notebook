// O(N ^ 3)
// Needs kadane, not tested for 0/1 zone but it should also work
int matrix[SIZE][SIZE];
int max_sum_rectangle(int n, int m) {

    int max_sum = 0;

    for(int i = 0; i < m; i++) {

    	for(int k = 0; k < n; k++)
    		aux[k] = 0;

        for(int j = i; j < m; j++) {

        	for(int k = 0; k < n; k++) {
	    		aux[k] += matrix[k][j];
	    	}

        	max_sum = max(max_sum, kadane(n));
        }
    }

	return max_sum;
}

// O(N ^ 4)
for(int j,i = 1;i <= n;i++)
	for(j = 1;j <= n;j++)
		X[i][j] += X[i-1][j] + X[i][j-1] - X[i-1][j-1];
               
 int answer = X[n][n];

 for(int h,k,j,i = 1;i <= n;i++)
 	for(j = 1;j <= n;j++)
 		for(h = 1;h < i;h++)
 			for(k = 1;k < j;k++)
 				answer = max(answer , X[i][j] - X[i][k] - X[h][j] + X[h][k]);


// Maximun area with values(ussume 1 means it has data 0 means no)
// O(N ^ 4)
int answer = 0;
for(int h,k,j,i = 1;i <= n;i++)
	for(j = 1;j <= m;j++)
		for(h = 0;h <= i;h++)
			for(k = 0;k <= j;k++)
				answer = max(answer , X[i][j] - X[i][k] - X[h][j] + X[h][k] == (i-h)*(j-k) ? (i-h)*(j-k) : 0);

