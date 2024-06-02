vector<ll>bitcnt(64, 0);
void cnt(ll num){
    if(num==0)
    return;
   
    ll bits=1LL * log2(num);
    ll clsbit = (1LL << bits);
    bitcnt[bits] += (num - clsbit + 1);

     for(int i = 0; i < bits; i++){
         bitcnt[i] += clsbit / 2;
     }

     cnt(num - clsbit);
}

// bitcnt[i] represents the total number of setbits of all the numbers from 1 to N at bitindex i.
