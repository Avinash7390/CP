# Sum of all factors of a number.

> [!NOTE]
> - if N is represented as $N = P1^k1 * P2^k2 * P3^k3 * ....... *Pm^km$.
> - Then sum of all factors is given by $P1^(^k1 ^+ ^1) ^- ^1^)/(p1 - 1) + P2^(k2 + 1) - 1)/(p2 - 1) + ....... Pm^(km + 1) - 1)/(pm - 1)$
> - we have calculated this using the idea of smallest prime.

<h3> Here is the code </h3>

    void smallestPrimeFactor(vetor<int>&smallestPrime){
    
        for(int i = 2; i <= N; i++) smallestPrime[i] = i;
    
        for(int i = 2; i <= N; i++){
            if(smallestPrime[i] != i) continue;
    
            for(int j = i * i; j <= N; j += i){
                if(smallestPrime[j] == j)
                smallestPrime[j] = i;
            }
        }
    }
    
    void sumOfFactors(int N){
        vector<int>smallestPrime(N + 1);
        smallestPrimeFactor(smallestPrime);
    
        vector<int>ans(N + 1);
    
        for(int i = 2; i <= N; i++){
            int num = i;
    
            int res = 0;
    
            while(num != 1){
                int pi = 1;
    
                int prime = smallestPrime[num];
    
                while(num % prime == 0){
                    pi = pi * prime;
                    num = num / prime;
                }
    
                res = res + (pi - 1) / (prime - 1);
            }
            ans[i] = res;
        }
    }