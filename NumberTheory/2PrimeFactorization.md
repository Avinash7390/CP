# Prime factorization
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
> - Overall Time Complexity of the prime factorization is $O(\sqrt{N})$
> - Why $\sqrt{N}$ ? Because we can list down all the factors of a number in $\sqrt{N}$ time. 

<hr/>

- If someone asks me to find out the prime factors of numbers from 1 to N
I mean some query type of question on prime factorization
if I calculate from the above method it is going to take $O(N*\sqrt{N})$
- Can I do better?

- Well Yes We can do better using the idea of smallestPrime factorization.
<h2>Below is the code for finding out the smallest prime factor of numbers from 1 - N</h2>

    void smallestPrimeFactor(int N){
    
        vector<int>smallestPrime(N + 1);
        for(int i = 2; i <= N; i++) smallestPrime[i] = i;
        
        for(int i = 2; i <= N; i++){
            if(smallestPrime[i] != i) continue;
            for(int j = i * i; j <= N; j += i){
                if(smallestPrime[j] == j)
                smallestPrime[j] = i;
            }
        }
    }
- Since I know that every No can be represented as $N = P1^k1 * P2^k2 * P3^k3 * ....... * Pm^km$
- Let's find out prime factorization for N = X;
  first, find out the smallest prime factors of x and that will be P1 = smallestPrime[x]
  Now remove  $P1^k1$ from x so now $x = x / P1^k1$
  and repeat the steps while x != 1

  <h4> Code for N queries </h4>
    
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

        void findSmallestPrimeFactorQueries(int N){
        
            vector<int>smallestPrime(N + 1);
            smallestPrimeFactor(smallestPrime);
        
            for(int i = 2; i <= N; i++){
        
                int count = 0;
        
                int num = i;
                int prime = smallestPrime[num];
        
                while(num != 1){
                    int prime = smallestPrime[num];
        
                    while(num % prime == 0){
                        num = num / prime;
                        count++;
                    }
                }
            }
        }

- Overall time complexity of the above code is $O(N*log(N))$
  
  



