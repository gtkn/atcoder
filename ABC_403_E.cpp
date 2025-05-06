//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (n); ++i)
#define repr(i,n) for (ll i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (ll i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目

#define vec(T) vector<T>
#define vvec(T) vector<vec(T)>
#define vvvec(T) vector<vvec(T)>
#define vvvvec(T) vector<vvvec(T)>

//typedef vector<mint>vi;
//typedef vector<vi>vvi;
//typedef vector<vvi>vvvi;
//typedef vector<vvvi>vvvvi;

#define all(x) x.begin(),x.end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


struct TrieTree{
    vector<map<char,ll>> g;
    TrieTree(): g(1){}

    ll add(const string& s){
        ll now = 0;
        for(char c:s){
            if(!g[now].count(c)){
                g[now][c] = g.size();
                g.push_back({});
            }
            now = g[now][c];
        }
        return now;
    }

    vec(ll) val;
    void val_init(){
        ll n = g.size();
        val = vec(ll)(n, llINF);
    }

    void val_set(const string& s, const ll& v){
        ll now = 0;
        for(char c:s){
            now = g[now][c];
        }
        chmin(val[now], v);
        return;
    }


    ll val_get(const string& s){
        ll res = llINF;
        ll now = 0;
        for(char c:s){
            if(!g[now].count(c)) return llINF;
            now = g[now][c];
            chmin(res, val[now]);
        }
        return res;
    }


};




void solve(){
    ll Q;
    cin >> Q;
    vec(ll) T(Q);
    vec(string) S(Q);
    rep(i,Q) cin >> T[i] >> S[i];


    TrieTree trie;
    rep(i,Q) trie.add(S[i]);


    trie.val_init();    
    rep(i,Q) if(T[i] == 1){
        trie.val_set(S[i], i);
    }


    vec(ll) d(Q+1);
    rep(l,Q){
        if(T[l] == 1) continue;
        ll r = trie.val_get(S[l]);
        chmin(r, Q);
        if(r<l) continue;
        d[l]++;
        d[r]--;
    }

    ll sum = 0;
    rep(i,Q){
        sum += d[i];
        cout<< sum << nl;
    }






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
