prime factorization
<hr/>
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
<hr/>

> [!NOTE]
> - The smallest factor (f > 1) of any Number N is always a prime.
> - Every No can be represented as $N = P1^k1 * P2^k2 * P3^k3 ........ *Pm^km$
> - Overall time Complexity of the prime factorization is $O(sqrt(N))$
> - Why $sqrt(N)$ ? Because we can list down all the factors of a number in $sqrt(N)$ time. 
