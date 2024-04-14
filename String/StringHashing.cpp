#include <bits/stdc++.h>
#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
/*---------------------------------------------------------------------------------------------------------------------------*/

using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

/*---------------------------------------------------------------------------------------------------------------------------*/

using ll = long long;
using ull = unsigned long long;
using lld = long double;
const ll MOD =1e9+7;
const ll m = 1000000007;
ll INF = 1000000000000000000;

/*---------------------------------------------------------------------------------------------------------------------------*/

typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, pair<int, int>>
#define PI 3.141592653589793238462
#define lb "\n"

/*---------------------------------------------------------------------------------------------------------------------------*/

#define set_bits(x) __builtin_popcountll(x)
#define leading_zeroes(x) __builtin_clz(x);
#define fr(i, a, b) for (int i = (a); i < (b); i++)
#define frr(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define pb(x) push_back(x)
#define SUM(x) accumulate(all(x), 0LL)

/*---------------------------------------------------------------------------------------------------------------------------*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll nCr(ll n, ll r, ll m, vector<ll>& fact, vector<ll>& ifact){return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

/*---------------------------------------------------------------------------------------------------------------------------*/
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}
void FAStIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);                     
    cout.tie(NULL);
}
void debug(vector<ll> &arr){
    cerr<<"* Debug start *"<<lb;
    fr(i, 0, size(arr)) cerr<<arr[i]<<" ";
    cerr<<lb;
    cerr<<"* Debug end *"<<lb;
    cerr<<lb;
}
/*----------------------------------------------------------------------------------------------------------------------------*/

struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = size(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = size(s); 
        for(int i = 0; i < size(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < size(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};


void Solve(){
    string str, pattern;
    cin >> str >> pattern;

    Hashing H1 = Hashing(str);
    Hashing H2 = Hashing(pattern);

    int sz = size(pattern);
    int n = size(str);
    vector<ll>sec = H2.substringHash(0, sz - 1);

    for(int i = 0; i <= n - sz; i++){
        vector<ll>f = H1.substringHash(i, i + sz - 1);
        if(f == sec){
            cout << "String matches at idx : " << i << lb;
        }
    }

    
}


/************************************************************************************************************************************/

int32_t main()
{
    FAStIO();
    init_code();
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
}

/************************************************************************************************************************************/



