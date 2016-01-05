string to_negabase(int num, int base) {
    if(!num)
        return "0";

    string neg_bas = "";

    int x;

    while(num) {

        x = num %-base,num /= -base;

        if(x < 0)
            num++, x+= base;

        neg_bas = char(x+'0') + neg_bas;
    }

    return neg_bas;
}

long to_decimal_from_negabase(string num, int base) {

    long T = 0, i = num.size()-1, exp = 0;

    while(i >= 0)
       T += static_cast<int>(num[i--]-'0') * potencia(-base, exp++);

    return T;
}

// BASE -2
string Binario_negativo(int num) {
    if(!num)
        return "0";

    string neg_bin = "";

    int x;

    while(num) {

       x = num %-2,num /= -2;

       if(x < 0)
          num++, x+= 2;

       neg_bin = char(x+'0') + neg_bin;
    }

    return neg_bin;
}
