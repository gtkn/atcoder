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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N;
    cin >> N;
    vec(ll) P(N);
    rep(i,N) cin >> P[i];

    vec(Pll) ans;

    auto f = [&](vec(ll) v, ll ii, ll jj)->vec(ll){
        ans.emplace_back(ii+1,jj);
        // cout << ii+1 << ", " << jj << endl;

        ll nn = v.size();
        vec(ll) Q;
        rep(i,nn){
            if(i!=ii && i!=ii+1) Q.push_back(v[i]);
        }

        vec(ll) res;
        for(ll i=0; i<jj; i++) res.push_back(Q[i]);
        res.push_back(v[ii]);
        res.push_back(v[ii+1]);
        for(ll i=jj; i<nn-2; i++) res.push_back(Q[i]);

        return res;
    };


    for(ll x=N; x>2; x--){
        assert(P.size()==x);
        // cout << x << "----" << endl;
        // for(ll pi:P) cout << pi << " "; cout << endl;

        if(P.back()!=x){
            if(P[0]==x) P = f(P,1,0);
            rep(i,x){
                if(P[i]==x){
                    P = f(P,i-1,x-2);
                    break;
                }
            }
        }
        P.pop_back();

        // for(ll pi:P) cout << pi << " "; cout << endl;

    }

    if(P[0]==2) nodame;
    
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(Pll a:ans) cout << a.first <<" " << a.second << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
