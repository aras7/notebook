string decimal_to_n_base(long long n, int base)
{ 
  string s = "";
  if(base != 10)
  {
    const char* _t = "0123456789ABCDEF";
    do s = _t[n % base] + s, n /= base; while(n);
  }
  else
    s = Long_to_String(n);  
  return s; 
}

long long n_base_to_decimal(string s, int base)
{
  if(base == 10)
    return atol(s.c_str());
  int _p;
  long long n = 0;
  for(size_t i = 0, h = s.size(); i < s.size(); ++i)
  {
    '0' <= s[i] && s[i] <= '9' ? _p = s[i] - '0' : _p = s[i] - '7';
    n += pow(static_cast<double>(base), static_cast<double>(--h)) * _p;
  }
  return n;
}