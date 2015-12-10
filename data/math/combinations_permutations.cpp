/*
Binomial coefficient, pascal triangle
numbers of sub-set of k elements in a set of n elements. k <= n
*/
long long BinomialCoefficient(int a,int b)
{
     long long total = 1;
     int i = a,j = 2,limit = a-b;
     if(b < limit)b = limit,limit = a-b;
     while(i > b)
     {
         total *= i--;
         while(!(total % j) && j <= limit)total /= j++;
     }
     return total;
}

// Pascal triangle
vector<vector<long long> > pascal_triangle(int n)
{
     vector<vector<long long> > pascal = vector<vector<long long> >(n+1);
    
     pascal[0].push_back(1);
     
     for(int i = 1; i <= n;i++) {
         pascal[i].push_back(1);
         for(int j = 0; j < pascal[i-1].size()-1;j++)
             pascal[i].push_back(pascal[i-1][j] + pascal[i-1][j+1]);
         
         pascal[i].push_back(1);
     }
    
     return pascal;
}