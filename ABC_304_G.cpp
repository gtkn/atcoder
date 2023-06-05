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

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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


    pair<vec(ll),vec(ll)> split(vec(ll)& a,ll k){
        vec(ll) a0,a1;
        for(ll ai:a){
            if(bit(ai,k)) a1.push_back(ai);
            else a0.push_back(ai);
        }
        return {a0,a1};
    }

    ll fab(ll x,ll k, vec(ll) a,vec(ll) b){
        if(a.empty()) return 0;
        if(b.empty()) return 0;
        if(k==0) return min(a.size(),b.size());
        --k;

        auto [a0,a1] = split(a,k);
        auto [b0,b1] = split(b,k);

        if(bit(x,k)){
            return fab(x,k,a0,b1) + fab(x,k,a1,b0);
        }else{
            ll d0 = a0.size()-b1.size();
            ll d1 = b0.size()-a1.size();

            ll res = min(a0.size(), b1.size());
            res += min(a1.size(), b0.size());

            if(d0<0 && d1<0){
                ll r = fab(x,k,a1,b1);
                res += min(r, min(-d0,-d1));
            }else if(d0>0 && d1>0){
                ll r = fab(x,k,a0,b0);
                res += min(r, min(d0,d1));
            }
            return res;
        }

    }


    ll faa(ll x,ll k, vec(ll) a){
        if(a.empty()) return 0;
        if(k==0) return a.size()/2;
        --k;

        auto [a0,a1] = split(a,k);

        if(bit(x,k)){
            return fab(x,k,a0,a1);
        }else{
            if(a0.size() < a1.size()) swap(a0,a1);
            ll r = faa(x,k,a0);
            chmin(r, (ll)(a0.size()-a1.size())/2);
            return a1.size() + r;
        }
    }
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) A(2*N);
        rep(i,2*N) cin >> A[i];

        ll l=0, r=1<<30;
        ll th = N-N/2;
        while(r-l>1){
            ll mid = (l+r)/2;

            ll nn = faa(mid,30,A);
            // cout << mid << " " << nn << "/" << th << endl;
            if(nn>=th) l=mid;
            else r=mid;
        }

        cout << l << endl;


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
