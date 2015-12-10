string toRoman(int n) // 1 <= n <= 4.999
{

    static char *tmp[4][10] = 
    {
       {"","I","II","III","IV","V","VI","VII","VIII","IX"} ,
       {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"} ,
       {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"} ,
       {"","M","MM","MMM","MMMM"}
    };
    
    string s = "";
    
    s += tmp[3][n/1000];
    n%= 1000;
    
    s += tmp[2][n/100];
    n%= 100;
    
    s += tmp[1][n/10];
    n%= 10;
    
    s += tmp[0][n];
    
    return s;
}

int toArabic(string roman)
{
    map<char,int>value;
  
    value['M'] = 1000,
    value['D'] = 500,
    value['C'] = 100,
    value['L'] = 50,
    value['X'] = 10,
    value['V'] = 5,
    value['I'] = 1;
    
    int arabic = value[roman[0]];

    for(int i = 1,size = roman.size();i < size;i++)
    	if(value[roman[i]] <= value[roman[i-1]])
    		arabic += value[roman[i]];
    	else
    		arabic = arabic + value[roman[i]] - 2 * value[roman[i-1]];
    
    return arabic;
}