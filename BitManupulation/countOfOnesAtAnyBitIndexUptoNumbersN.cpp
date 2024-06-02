void cnt(ll num, vector<ll>&bitcnt){
    if(num == 0)
    return;

    ll x = leading_zeroes(num);

    ll bits = 63 - x;
   
    ll clsbit = (1LL << bits);
    bitcnt[bits] += (num - clsbit + 1);

    for(int i = 0; i < bits; i++){
       bitcnt[i] += clsbit / 2;
    }

    cnt(num - clsbit, bitcnt);
}


// bitcnt[i] represents the total number of setbits of all the numbers from 1 to N at bitindex i.
