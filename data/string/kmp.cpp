char str[MAX];
void KMP(int N,char to_search[])
{
    int comp[N+7];
    memset(comp,0,sizeof comp);
    comp[0] = -1;
    
    for(int i = 1;i < N;i++)  
        for(int x = comp[i];true;)
            if(to_search[i] != to_search[x])
            {                 
                x = comp[x];
                if(x == -1)
                {
                   comp[i+1] = 0;
                   break;
                }
            }
            else
            {
                comp[i+1] = x+1;
                break;
            }
    
    int _i = 0,i = 0,size = strlen(str);
        
    while(i < size)
    {
        if(to_search[_i] == str[i])
        {
             if(_i == (N-1))
             {
                 printf("%d\n",i-N+1);
                 _i = comp[N];
             }
             else 
                 _i++;
                      
             i++;         
        }
        else
        {
            _i = comp[_i];
            if(_i == -1)
                _i++,i++;
        }
    }
}