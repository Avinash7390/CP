# Sum of all factors of a number.

> [!NOTE]
> - if N is represented as $N = (P_1)^k_1 * (P_2)^k_2 * (P_3)^k_3 * ....... *(P_m)^k_m$.
> - Then sum of all factors is given by $(P_1^(k_1 + 1) - 1)/(p_1 - 1) + (P_2^(k_2 + 1) - 1)/(p_2 - 1) + ....... (P_m^(k_m + 1) - 1)/(p_m - 1)$.
> - we have calculated this using the idea of the smallest prime.

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
