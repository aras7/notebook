typedef int NUM;
vector<vector<NUM> > RMQ(vector<NUM> X)
{
     int N = X.size();
     
     vector<vector<NUM> >M ( N, vector<NUM> (static_cast<int>(log2(N))+1,0 ));
     
     for(int i = 0;i < N;i++)
        M[i][0] = i;
        
     for(int h,i = 1; (1 << i) <= N; i++)
         for(h = 0;h + (1 << i) - 1 < N;h++)
             if( X[ M[h][i-1] ] >= X[ M[h + (1 << (i-1))][i-1] ])
                 M[h][i] = M[h][i-1];
             else
                 M[h][i] = M[h + (1 << (i-1))][i-1];
     
     return M;
}

// query(i, j)
k = static_cast<int>( log2 ( j - i + 1 ) );
pos = A[  M[ i ] [ k ]  ]  >=  A[  M[ j - (1 <<  k) + 1]  [ k ]  ] ? M[ i ]  [ k ] : M[ j - (1 << k) + 1 ] [ k ];
printf("%d",A[pos]);