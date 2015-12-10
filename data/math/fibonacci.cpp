typedef long long type;
typedef vector<type> row_t;
typedef vector<row_t> matrix_t;

matrix_t _square_matrix(int size, int value)
{
    return matrix_t(size , row_t(size , value));
}

matrix_t multiply(matrix_t A,matrix_t B,type mod)
{
    int size = A.size();
    
    matrix_t C = _square_matrix(size,0);

    for(int k,j,t,i = 0;i < size;i++)
       for(int j = 0;j < size;j++)
       {
             for(t = k = 0;k < size;k++)
                 t = (t + A[i][k] * B[k][j] % mod) % mod;
                 
             C[i][j] = t;
       }
       
    return C;
}

matrix_t power(matrix_t A,int n,type mod)
{
    if(n == 0)return _square_matrix(2,1);
    if(n == 1)return A;
    
    matrix_t B = power(A,n/2,mod) , C = multiply(B,B,mod);
    
    return n%2 ? multiply(C,A,mod) : C;
}

type Fibonacci(int n)
{
     if(n <= 1)return type(n);
     
     matrix_t M = _square_matrix(2,1);
     M[0][0] = 0;
             
     M = power(M, n + 1 , MOD);
     
     return M[0][0];
}

type Sum_Fibonacci_0_to_n(int n)
{
     if(n <= 1)return type(n);
     
     matrix_t M = _square_matrix(3,1);
     
     M[0][0] = M[0][2] = M[1][2] = 0;
             
     M = power(M, n , MOD);
     
     return M[2][0];
}

scanf("%d%d",&n,&m);
        
_n = Sum_Fibonacci_0_to_n(max((n-1),0));
_m = Sum_Fibonacci_0_to_n(m);

_m -= _n;
        
if(_m < 0)_m += MOD;
printf("%lld\n",_m);