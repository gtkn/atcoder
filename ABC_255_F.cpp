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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    ll N;
    vec(ll) P,I;
    map<ll,ll> Iinv;
    vec(Pll) ans;
    bool isok = true;

    void f(ll now, ll l, ll r){
        ll p0 = P[now];
        ll x = Iinv[p0];
        if(x<l || x>r){
            isok=false;
            return;
        }

        ll nl,nr;
        nl = x-l;
        nr = r-x;

        if(nl>0){
            ans[p0].first = P[now+1];
            f(now+1, l, x-1);
        }

        if(nr>0){
            ans[p0].second = P[now+nl+1];
            f(now+nl+1, x+1, r);
        }

    }




    void solve(){
        cin >> N;

        rep(_,N){
            ll x; cin >> x;
            P.push_back(x);
        }
        rep(_,N){
            ll x; cin >> x;
            I.push_back(x);
        }

        rep(i,N) Iinv[I[i]] = i;
        ans.resize(N+1);

        if(P[0]!=1) isok=false;

        f(0,0,N-1);

        if(!isok) dame;

        rep1(i,N) cout << ans[i].first <<" " << ans[i].second << endl;

    }
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
