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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;


    if(N==3){
        cout << "2 5 63" << endl;
        return;
    }
    

    vec(ll) v2,v3,v6;
    rep1(i,30000){
        if(i%6==0) v6.push_back(i);
        else if(i%3==0) v3.push_back(i);
        else if(i%2==0) v2.push_back(i);
    }

    // ll n2,n3,n6;
    // n2 = v2.size();
    // n3 = v3.size();
    // n6 = v6.size();

    reverse(all(v2));
    reverse(all(v3));
    reverse(all(v6));

    vec(ll) ans;
    rep(_,2){
        ans.push_back(v2.back());
        v2.pop_back();
    }
    rep(_,2){
        ans.push_back(v3.back());
        v3.pop_back();
    }


    while(ans.size() <= N-3 && v2.size() >= 2){
        rep(_,2){
            ans.push_back(v2.back());
            v2.pop_back();
        }
    }

    while(ans.size() <= N-2 && v3.size() >= 2){
        rep(_,2){
            ans.push_back(v3.back());
            v3.pop_back();
        }
    }

    while(ans.size()<N){
        ans.push_back(v6.back());
        v6.pop_back();
    }

    sort(all(ans));
    for(ll ai:ans) cout << ai << " "; cout << endl;


    // ll g = ans[0];
    // for(ll ai:ans) g = __gcd(ai,g);
    // if(g!=1){
    //     cerr << "all gcd : " << g << endl;
    // }

    // ll tot = 0;
    // for(ll ai:ans) tot += ai;
    // for(ll ai:ans)if(__gcd(tot-ai,ai)==1){
    //     cerr << "gcd : " << ai << " , " << tot << endl;
    // }



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
