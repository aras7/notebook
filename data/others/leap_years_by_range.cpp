int numbersOfLeapYears(Date dates[2])
{
     if(dates[1] < dates[0])
         swap(dates[0],dates[1]);
     
     // first leap year >= dates[0]
     {    
         if(dates[0] > Date(29,2,dates[0].y))
             dates[0].y++;
            
         dates[0].d = 29;
         dates[0].m = 2;
                
         while(!dates[0].isLeapYear())
             dates[0].y++;
     }
     
     // first leap year <= dates[1]
     {
         if(dates[1] < Date(29,2,dates[1].y))
             dates[1].y--;
                
         dates[1].d = 29;
         dates[1].m = 2;
            
         while(!dates[1].isLeapYear())
                dates[1].y--;
     }
        
     if(dates[0] < dates[1])
         return 1 + ((dates[1].y - dates[0].y)/4) - ( (dates[1].y/100 - dates[1].y/400) - (dates[0].y/100 - dates[0].y/400) );
     
     if(dates[0] == dates[1])
         return 1;
     
     return 0;
}