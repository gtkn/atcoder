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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


vvec(bool) rotate(vvec(bool) a){
    ll h = a.size(), w = a[0].size();
    vvec(bool) res(w,vec(bool)(h));
    rep(i,h)rep(j,w){
        res[j][h-1-i] = a[i][j];
    }
    return res;
}

vvec(bool) trim(vvec(bool) a){
    vvec(bool) res;
    bool f1 = false;
    for(auto row: a){
        bool use = false;
        if(f1){
            use = true;
        }else{
            for(bool aij:row) if(aij) use = true;
        }
        if(use){
            res.push_back(row);
            f1 = true;
        }
    }

    while(!res.empty()){
        bool use = false;
        for(bool aij:res.back()) if(aij) use = true;
        if(use) break;
        res.pop_back();
    }


    return res;
}


bool issame(vvec(bool) a, vvec(bool) b){
    if(a.size()!=b.size()) return false;
    if(a[0].size()!=b[0].size()) return false;
    ll h = a.size(), w = a[0].size();
    rep(i,h)rep(j,w){
        if(a[i][j]!=b[i][j]) return false;
    }
    return true;
}


void solve(){
    ll N;
    cin >> N;

    vec(string) S(N), T(N);
    rep(i,N) cin >> S[i];
    rep(i,N) cin >> T[i];

    
    vvec(bool) svv(N,vec(bool)(N)), tvv(N,vec(bool)(N));
    rep(i,N)rep(j,N){
        svv[i][j] = (S[i][j]=='#');
        tvv[i][j] = (T[i][j]=='#');
    }

    svv = trim(svv);
    tvv = trim(tvv);

    svv = rotate(svv);
    tvv = rotate(tvv);

    svv = trim(svv);
    tvv = trim(tvv);

    rep(_,4){
        if(issame(svv,tvv)) sayyes;
        svv = rotate(svv);
    }
    sayno;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
