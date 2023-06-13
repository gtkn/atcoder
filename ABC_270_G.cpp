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


    // x^n % mod を求める関数
    ll pow_mod(ll x, ll n, ll mod) {
        ll res = 1;
        while (n > 0) {
            if (n & 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
    }

    void solve(){
        ll P,A,B,S,G;
        cin >> P >> A >> B >> S >> G;

        if(A==0){
            if(S==G) cout << 0 << endl;
            else if(B==G) cout << 1 << endl;
            else cout << -1 << endl;
            return;
        }


        ll M = sqrt(P)+1;



        map<ll,ll> m;
        ll a=1,b=0,x=S;
        rep(i,M){
            if(x==G){
                cout << i << endl;
                return;
            }
            m[x]=i;
            a = (A*a)%P;
            b = (A*b + B)%P;
            x = (A*x+B)%P;
        }



        ll y = G;
        rep1(i,M){
            y = ((y-b+P)*pow_mod(a,P-2,P))%P;
            if(m.count(y)>0){
                cout << i*M+m[y] << endl;
                return;
            } 
        }

        cout << -1 << endl;
        return;



    }
};



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
