#define N_Test (100)

long long MultiplyMod(long long A,long long B,long long MOD)
{

    // return A * B % MOD; if A <= 2^32

    if(!A || !B)return 0;
    
    long long x = 0,y = A %= MOD;
    B %= MOD;
    
    while(B)
    {
       if(B % 2)
          x = (x + y) % MOD;
       y = (y + y) % MOD;
       B /= 2; 
    }
    
    return x % MOD;
} 

long long PowMod(long long base,long long exp,long long mod)
{
    long long x = 1,y = base;
    
    while(exp)
    { 
        if(exp % 2)
            x = MultiplyMod(y,x,mod);
            
        y = MultiplyMod(y,y,mod);
        
        exp /= 2;
    }
    
    return x % mod;
}

bool MillerRabinPrimalityTest(long long N)
{
    if(N == 2)return true;
    
    if(!(N % 2) || N < 2)return false;
 
    long long a,temp,x,d=N-1;
    
    while(!(d % 2))
        d /= 2;
        
    for(int _i = 0;_i < N_Test;_i++)
    {
 
        a = rand() % (N-1) + 1,temp = d;
        x = PowMod(a,temp,N);
        
        while (temp != N-1 && x !=1 and x != N-1)
        {
            x = MultiplyMod(x,x,N);
            
            temp *= 2;
        }
        
        if (x != N-1 && !(temp % 2))
            return false;
    }
    
    return true;
}