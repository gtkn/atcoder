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

struct slope_trick{
    ll C, fmin; // 定数項,関数fの最小値
    priority_queue<ll> L; // 傾き0以下で傾き変わる点の集合
    priority_queue<ll,vector<ll>,greater<ll>> R;

    slope_trick(){
        C=0; fmin=0;
        L.push(-llINF);
        R.push(llINF);
    }

    // LeRUの方
    void addr(ll a){
        fmin += max(L.top() - a, 0LL);

        L.push(a);
        R.push(L.top());
        L.pop();
    }

    void addl(ll a){
        fmin += max(a-R.top(), 0LL);

        R.push(a);
        L.push(R.top());
        R.pop();
    }

    void addc(ll b){
        C += b;
        fmin += b;
    }


};


void solve(){
    ll Q;
    cin >> Q;


    slope_trick st;

    while(Q--){
        ll t;
        cin >> t;
        if(t==1){
            ll a,b;
            cin >> a >> b;
            st.addl(a);
            st.addr(a);
            st.addc(b);
        }else{
            cout << st.L.top() << " " << st.fmin << endl;
        }
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
