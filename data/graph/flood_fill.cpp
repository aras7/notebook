#define tam 107
// mark -> value which break the condition
void Flood_Fill(char x[tam][tam],int i,int j,int n,int m,char mark)
{
     if(!i || !j || i > n || j > m || x[i][j] == mark)
         return ;
         
     x[i][j] = mark;
     
     Flood_Fill(x,i+1,j,n,m,mark);
     Flood_Fill(x,i,j+1,n,m,mark);
     
     Flood_Fill(x,i-1,j,n,m,mark);
     Flood_Fill(x,i,j-1,n,m,mark);
     
     //diagonals
     Flood_Fill(x,i+1,j+1,n,m,mark);
     Flood_Fill(x,i-1,j-1,n,m,mark);
     
     Flood_Fill(x,i-1,j+1,n,m,mark);
     Flood_Fill(x,i+1,j-1,n,m,mark);
}