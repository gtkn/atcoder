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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


struct RollingHash {
    const mint base = 131;

    RollingHash() {}

    mint calcHash(const string& s) {
        mint hash = 0;
        for (char c : s) {
            hash = (hash * base + c);
        }
        return hash;
    }

    mint calcRepeatedHash(const string& s, ll N, ll nn) {
        mint hs = calcHash(s);

        mint ten = base.pow(nn);

        while(N){
            if(N&1) hs = hs*ten + hs;
            N>>=1;
            ten *= ten;
        }

        return hs;
    }
};



bool operator>(const mint& a, const mint& b){
    return (a.val() > b.val());
}

bool operator<(const mint& a, const mint& b){
    return (a.val() < b.val());
}

void solve(){
    ll N;
    cin >> N;


    RollingHash rh; // ローリングハッシュの初期化


    set<mint> used;

    rep(i,N){
        string s;
        cin >> s;

        ll l=0,r=N;
        while(r-l>1){
            ll mid = (l+r)/2;
            mint tmp = rh.calcRepeatedHash(s,mid,s.size());
            if(sfind(used,tmp)) l=mid;
            else r=mid;
        }

        used.insert(rh.calcRepeatedHash(s,r,s.size()));
        cout << r << " ";
    }

    cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
