/*------------------------------------- Avinash MNNIT Allahabad, Prayagraj----------------------------------------*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using namespace chrono;
using ll = long long;
using ull = unsigned long long;
using lld = long double;
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, pair<int, int>>
#define lb "\n"
#define fr(i, a, b) for (int i = (a); i < (b); i++)
#define frr(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define pb(x) push_back(x)
#define SUM(x) accumulate(all(x), 0LL)
ll mod = 1e9 + 7;
/*---------------------------------------------------------------------------------------------------------------------------*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}

struct Interactor{
    vector<int> arr;
    Interactor(){
        arr.resize(1000);
        for(int i = 0; i < 501; i++){
            arr[i] = 10;
        }
        for(int i = 501; i < 1000; i++){
            arr[i] = getRandomNumber(1, 9);
        }
    }
    bool query(int index){
        return arr[index] == 10;
    }
    void isValidOutput(int index){
        if(arr[index] == 10){
            cout << "Passed";
        }else{
            cout << "Failed";
        }
        cout << endl;
    }
};

void solve(){
    int maxQueriesTaken = 0;
    map<int, int> queriesMap;
    for(int i = 0; i < 1000000; i++){
        int queries = 0;
        int ans = -1;
        Interactor it = Interactor();
        while(true){
            int x = getRandomNumber(0, 999);
            // cout << "? " << x << endl;
            queries++;
            if(it.query(x)){
                ans = x;
                break;
            }
        }
        queriesMap[queries]++;
        maxQueriesTaken = max(maxQueriesTaken, queries);
        // it.isValidOutput(ans);
        // cout << "queries: " << queries << endl;
    } 
    cout << "max queries " << maxQueriesTaken << endl;
    for(auto i : queriesMap){
        cout << "took " << i.first << " queries in " << double(i.second)/1000000 * 100 << "% test cases " << endl;
    }
    
    // what is the probability that you will take more than 20 queries
    // 1/2^(20) => < 1/1000000
}

int32_t main()
{
    init_code();
    int t;
    //cin>>t;
    t = 1;

    while(t--){
        solve();
    }
}




