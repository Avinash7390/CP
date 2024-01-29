-prime factorization
void PrimeFactorization(vector<ll> &factors, ll n){

    for(ll i = 2; i * i <= n; i++){

        if(n % i == 0){

            while(n % i == 0){
                factors.push_back(i);
                n = n / i;
            }
        }
    }

    if(n > 1){
        factors.push_back(n);
    }
}
