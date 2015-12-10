bool is_prime[tam];
vector<int>Primos;
memset(is_prime,true,sizeof is_prime);
is_prime[0] = is_prime[1] = false;
    
for(int i = 2;i < tam;i++)
 if(is_prime[i])
 {
    Primos.push_back(i);
    for(int k = i+i;k < tam;k += i)
      is_prime[k] = false;
 }