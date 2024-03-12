## How to calculate nCr efficiently
    
         int MOD = 1e9 + 7
         ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
         ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
         ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);} /* multiplicative inverse prime */
         ll nCr(ll n, ll r, ll m, vector<ll>& fact, vector<ll>& ifact){return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);}
  
- first calculate factorial and inverse factorial
  
          vector<ll> fact(n + 1);
          vector<ll> ifact(n + 1);
          fact[0] = 1;
          for(int i = 1; i <= n; i++){
              fact[i] = mod_mul(fact[i - 1], i, MOD);
          }
          ifact[n] = mminvprime(fact[n], MOD);
          for(int i = n - 1; i >= 0; i--){
              ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
          }
  
  - then you can directly use the function nCr defined above

    <h3>Lets Analise how these have been implemented</h3>
  - We know that $nCr$ can be written as $(n!)/((r!) * (n - r)!)$
  - And this further can be written as $(n!) * (r!)^-1 * ((n - r)!)^-1$
  - Now we have to calculate $n!$ inverse of $r!$ and $(n - r)!$ then multiply them.
  - to calculate $n!$ we can use $f(n) = n * f(n - 1)$
  <h3>To calculate inverse factorial of a number we need to know some things prior</h3>
  
  - from Fermat's theorem we know that $_a(m-1) = 1 (mod) m$ where m is a prime number.
  - so $_a _{*}_a(m-2) = 1 (mod) m$, and so $_a(-1) = _a(m-2) (mod) m$
  
  
    
    
