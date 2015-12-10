#define TAM 7500

int x;
long long T[TAM],coins[] = {100, 50, 20, 10, 5 , 1};
    
memset(T,0,sizeof T);
T[0] = 1;
    
 for(size_t j,i = 0;i < 5;i++)
    for(j = coins[i];j < TAM;j++)
       T[j] += T[j - coins[i]];

 /*for(int h,i = coins.size()-1;i >= 0;i--)
      for(h = coins[i];h < TAM;h++)
         T[h] += T[h - coins[i]];*/
    
scanf("%d",&x);
printf("%lld\n",T[x]);