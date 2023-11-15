//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;
using ull = unsigned long long;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------
struct TrieTree{
    vvec(ll) g; // 子への辺
    vector<ll> cnt; // そのノードに該当する文字列が追加された数
    ll al = 26; // アルファベットの数
    ll maxsize; // ノード数の最大
    ll gcnt = 1; // すでに使ったノードの数

    TrieTree(ll maxsize):maxsize(maxsize){
        g = vvec(ll)(maxsize,vec(ll)(al));
        cnt = vec(ll)(maxsize);
    }

    vec(ll) add(const string& s){
        vec(ll) path;
        ll now = 0;
        for(char c:s){
            ll x = c-'a';
            path.push_back(now);
            if(g[now][x]==0) g[now][x] = gcnt++;
            now = g[now][x];
        }
        cnt[now]++;
        return path;
    }


};

void solve(){
    ll N;
    cin >> N;

    vec(string) S(N);
    rep(i,N) cin >> S[i];
    for(string& si:S) reverse(all(si));


    ll nn = 1000010;
    TrieTree tt(nn);
    vvec(ll) paths(N);
    rep(i,N) paths[i] = tt.add(S[i]);


    ll ans = 0;
    rep(i,N){
        set<ll> used;
        repr(j, S[i].size()){
            used.insert(S[i][j]);
            ll now = paths[i][j];
            for(char c:used) ans += tt.cnt[  tt.g[now][c-'a'] ];
        }
    }
    ans -= N;



    cout << ans << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
