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

int answer = 0;
for(int h,k,j,i = 1;i <= n;i++)
	for(j = 1;j <= m;j++)
		for(h = 0;h <= i;h++)
			for(k = 0;k <= j;k++)
				answer = max(answer , X[i][j] - X[i][k] - X[h][j] + X[h][k] == (i-h)*(j-k) ? (i-h)*(j-k) : 0);
