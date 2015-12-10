vector<int> base10_to_base(int n,int base)
{
    vector<int>num;
    do num.push_back(n%base), n /= base; while(n);
    return num;
}

long long  to_base10(vector<int>s,int base)
{
    unsigned long long n = 0,i= s.size();
    while(i--)n = n*base + s[i];
    return n;
}