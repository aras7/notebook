for(int i,j,h = 1;h <= N;h++)
	for(i = 1;i <= N;i++)
		for(j = 0;j <= N;j++)
			if(i != j)
				F[i][j] = min(F[i][j], F[i][h] + F[h][j]);
			else
				F[i][j] = 0;