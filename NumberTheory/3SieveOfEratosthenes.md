# Sieve of Eratosthenes

    void sieve(int n){
    
        <-- 1 --> Prime -->
        <-- 0 --> nonPrime -->
        vector<int>prime(n + 1, 1);
        prime[1] = 0;
        for(int i = 2; i<= n; i++){
        
            if(prime[i] == 0) continue;
            for(int j = i * i; j<= n; j+=i){
                prime[j] = 0;
            }
        }
        
    }

<hr/>

> [!NOTE]
> - The idea is to mark all the numbers that have p as their factor
> - Time complexity is $O(N * log(log(N)))$
