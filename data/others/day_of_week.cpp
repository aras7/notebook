char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int d,m,y,x;

scanf("%d%d%d",&d,&m,&y); // day, month and year
        
x = ((14 - m) / 12);
y = y - x;
m = m + 12 * x - 2;

printf("%s\n",days[(d + y + y/4 - y/100 + y/400 + (31*m)/12) % 7 ] );