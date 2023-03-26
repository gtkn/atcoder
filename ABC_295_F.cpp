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
    string S;
    ll sll;
    ll L,R;
    ll N,M;
    vec(ll) ten;


    ll cat(ll x, ll k){
        ll r = k+1-N;
        if(r<0) return -1;
        x--;
        if(S[0]=='0') x+=ten[r];

        ll a = x/ten[r];
        ll b = x%ten[r];

        return a*ten[k+1] + sll*ten[r] + b;
    }

 
    ll bs(ll th){        
        ll res = 0;
        rep(k,16){
            ll chk = cat(1,k);
            if(chk==-1) continue;
            if(chk>th) continue;
            ll l=1,r=ten[16-N];
            while(l<=r){
                ll m = (l+r)/2;
                if(cat(m,k) > th ) r=m-1;
                else l=m+1;
            }
            res += r;
        }
        return res;
    }


    void solve(){
        cin >> S;
        cin >> L >> R;
        N = S.size();
        sll = stoll(S);

        ten.push_back(1);
        rep(_,18) ten.push_back(ten.back()*10);

        cout << bs(R) - bs(L-1) << endl;


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
