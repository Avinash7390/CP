# Total factors of a given Numbers

> [!NOTE]
> - If we want to find out the total no of factors for a single number then we can do it in $O(\sqrt{N})$ time
> - But when there is some query type of question something like - find out Total no of factors of all numbers from 1 - N
> - Then their comes the idea of smallest prime. We can do it in $O(N*log(N))$


<h2>Here is the code.</h2>

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
    
    void TotalNoOfFactors(int N){
    
        vector<int>smallestPrime(N + 1);
        smallestPrimeFactor(smallestPrime);
        vector<int>ans(N + 1);
    
        for(int i = 2; i <= N; i++){
            int num = i;
    
            int totalfactors = 1;
    
            while(num != 1){
                int prime = smallestPrime[num];
    
                int ct = 0;
    
                while(num % prime){
                    num = num / prime;
                    ct++;
                }
    
                totalfactors = totalfactors * (ct + 1);
            }
    
            ans[num] = totalfactors;
        }
    }

- Since No can be represented as $N = P1^k1 * P2^k2 * P3^k3 ....... * Pm^km$
- Total no of factors: $(k1 + 1)*(k2 + 1)*(k3 + 1).......(km + 1)$
