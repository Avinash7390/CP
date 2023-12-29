/*------------------------------------- Avinash MNNIT Allahabad, Prayagraj----------------------------------------*/
#include <bits/stdc++.h>
#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
/*-----------------------------------------------------------------------------------------------------------------*/

using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

/*------------------------------------------------------------------------------------------------------------------*/

using ll = long long;
using ull = unsigned long long;
using lld = long double;
ll mod = 1e9 + 7;

/*-------------------------------------------------------------------------------------------------------------------*/

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, pair<int, int>>
#define PI 3.141592653589793238462
#define lb "\n"

/*---------------------------------------------------------------------------------------------------------------------*/

#define set_bits(x) __builtin_popcountll(x)
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
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

/*-----------------------------------------------------------------------------------------------------------------------------*/
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}
/*-------------------------------------------------------------------------------------------------------------------------------*/
struct Interactor{

    vector<int>arr;
    Interactor(){
        arr = {5,1,4,2,3};
    }

    int  query(int l, int r){
        set<pi>st;
        st.clear();
        fr(i, l, r + 1){
            st.insert({arr[i], i});
        }
        auto it = st.rbegin();
        --it;
        int idx = (*it).second;
        int x = (*it).first;

        if(l + 1 == r){
            if(arr[l] > arr[r]) return r;
            else return l;
        }
        return idx;
    }
};

void solve(){
    int n; 
    cin>>n;
    int l = 1, r = n;
    // Interactor it = Interactor();
    int ans = -1;

    while(l <= r){
        // cout<<"left: "<<l<<" right: "<<r<<lb;
        int mid = (l + r) / 2;
        cout<<"? "<<l<<" "<<r<<endl;
        int smax;
        cin>>smax;
        // cout<<smax<<lb;
        if(r == l){
            cout<<"! "<<r<<endl;
            ans = l;
            break;
        }
        if(r - l == 1){
            cout<<"! "<<(smax ^ l ^ r)<<endl;
            ans = smax ^ l ^ r;
            break;
        }

        if(smax <= mid){
            cout<<"? "<<l<<" "<<mid<<endl;
            int smax2;
            // cout<<smax2<<lb;
            cin>>smax2;
            if(smax == smax2){
                r = mid;
            }else{
                l = mid;
            }
        }else{
            cout<<"? "<<mid<<" "<<r<<endl;
            int smax2;
            // cout<<smax2<<lb;
            cin>>smax2;
            if(smax == smax2){
                l = mid;
            }else{
                r = mid;
            }
        }
    }
    // cout<<"ans is: "<<ans<<lb;

    
}
/***********************************************************************************************************************************/

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

/************************************************************************************************************************************/

