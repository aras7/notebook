def my_gcd(a, b):
    if b == 0:
        return a
    else:
        return my_gcd(b, a % b)

from fractions import gcd

gcd(20, 8) == my_gcd(20, 8)


"""
C++

#include <algorithm>

cout << std::__gcd(100,24);


// Big gcd

char str[1000];
int a = 7, b = 0;
        for(int i = 0;i < strlen(str);i++)
           b *= 10,b += static_cast<int>(str[i]-48),b %= a;
           
int GCD = __gcd(a,b);

"""
