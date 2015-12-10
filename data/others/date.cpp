struct Date
{
       int d,m,y;
       
       Date(){}
       Date(int _d,int _m,int _y): y(_y), d(_d), m(_m) {}
       Date(int _d,char _m[],int _y):y(_y), d(_d), m(numberOfMonth(_m)) {}
       
       int numberOfMonth(char s[])
       {
           if(strcmp(s,"January") == 0) return 1;
           if(strcmp(s,"February") == 0) return 2;
           if(strcmp(s,"March") == 0) return 3;
           if(strcmp(s,"April") == 0) return 4;
           if(strcmp(s,"May") == 0) return 5;
           if(strcmp(s,"June") == 0) return 6;
           if(strcmp(s,"July") == 0) return 7;
           if(strcmp(s,"August") == 0) return 8;
           if(strcmp(s,"September") == 0) return 9;
           if(strcmp(s,"October") == 0) return 10;
           if(strcmp(s,"November") == 0) return 11;
           if(strcmp(s,"December") == 0) return 12;
           
           return 0;
       }

       bool isLeapYear()
       {    
            if(!(y%100))return !(y%400);
            
            return !(y%4);
       }
       
       bool operator <(Date obj)
       {
            if(y != obj.y) return y < obj.y;
            
            if(m != obj.m) return m < obj.m;
            
            return d < obj.d;
       }
       bool operator >(Date obj)
       {
            if(y != obj.y) return y > obj.y;

            if(m != obj.m) return m > obj.m;

            return d > obj.d;
       }
       
       bool operator ==(Date obj)
       {
            return y == obj.y && m == obj.m && d == obj.d;
       }
       
       bool operator <=(Date obj)
       {
            if(y != obj.y) return y <= obj.y;
            
            if(m != obj.m) return m <= obj.m;
            
            return d <= obj.d;
       }
       bool operator >=(Date obj)
       {
            if(y != obj.y) return y >= obj.y;
            
            if(m != obj.m) return m >= obj.m;
            
            return d >= obj.d;
       }
};