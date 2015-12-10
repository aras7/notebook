bool CMP(pair<int,int> a,pair<int,int> b)
{
     return a.first != b.first ? a.first < b.first : a.second < b.second;
}

vector<int> PRE(vector<char>to_search)
{
    int N = to_search.size();
    vector<int> comp(N + 7,0);

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
            
    return comp;
}

void KMP_2D(vector<vector<char> >to_search , vector<vector<char> >__MAP,int N1,int N2,int M1,int M2)
{
     vector<vector<int> > VAL(M1 + 7 , vector<int>(M2 + 7 , 0));
     
     vector<pair<int,int> >answer;
     
     for(int k = 0;k < N1;k++)
     {
         vector<int> comp = PRE(to_search[k]);

         for(int p = M1 - N1 + k;p >= k;p--)
         {
             int _i = 0,i = 0,size = __MAP[p].size();
             
             vector<char> str = __MAP[p];
               
             while(i < size)
             {
                 if(to_search[k][_i] == str[i])
                 {
                      if(_i == (N2 -1))
                      {
                          if(VAL[max(0,p - 1)][i - N2 + 1] == k)
                          {   
                              if(k != N1 - 1)
                                  VAL[p][i - N2 + 1] = k + 1;
                              else
                                  answer.push_back(pair<int,int>( p - N1 + 2 , i - N2 + 2 ));
                          }
                          
                          _i = comp[N2 ];
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
     }
     
     sort(answer.begin(),answer.end(),CMP);
     for(int j = 0;j < answer.size();j++)
         printf("(%d,%d)\n",answer[j].first,answer[j].second);
         
     if(!answer.size())
         puts("NO MATCH FOUND...");
}