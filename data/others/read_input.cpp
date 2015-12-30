template<class number>

bool Faster_Input_For_Positive_Integers(number *N)
{
    char c;

    while((c = getchar_unlocked()) && !isdigit(c))
       if(c == EOF)
          return false;

    for(*N = c-'0'; (c = getchar_unlocked()) && isdigit(c) ;)
       *N = *N * 10 + c-'0';

    return true;
}

template<class number>
bool Faster_Input_For_Integers(number *N)
{
    char c,last;

    while((c = getchar_unlocked()) && !isdigit(c))
    {
       last = c;      

       if(c == EOF)
          return false;
    }

    for(*N = c-'0'; (c = getchar_unlocked()) && isdigit(c) ;)
       *N = *N * 10 + c-'0';

    if(last == '-')
    	*N *= -1;

    return true;

}

template<class number>
bool Faster_Input_For_Real_Number(number *N)
{
    char c,last;
    int n_decimal = 0;
    bool decimal = false;

    while((c = getchar_unlocked()) && !isdigit(c))
    {
       last = c;

       if(c == EOF)
          return false;
    }

    for(*N = c-'0'; (c = getchar_unlocked()) && (isdigit(c) || c == '.') ;)
    {
        if(decimal)
        	n_decimal++;

        if(c != '.')
            *N = *N * 10 + c-'0';
        else
            decimal = true;
    }

    *N /= __pow(10, n_decimal);

    if(last == '-')
    	*N *= -1;

    return true;
}
