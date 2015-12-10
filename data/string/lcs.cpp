#define TAM 1007
char a[TAM],b[TAM];
int X[TAM][TAM];

int LCS_Length()
{
    int n = strlen(a),m = strlen(b);
    memset(X,0,sizeof X);
    
    for(int j,i = 0;i < n;i++)
       for(j = 0;j < m;j++)
          if(a[i] == b[j])
              X[i+1][j+1] = X[i][j] + 1;
          else
              X[i+1][j+1] = max(X[i+1][j] , X[i][j+1]);
          
    return X[n][m];
}