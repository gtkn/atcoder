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

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll K;
    cin >> K;
    ll X,Y;
    cin >> X >> Y;
    
    ll U = (X+Y), V=(X-Y);


    if(abs(U)%2 != abs(V)%2) dame;
    if(K%2==0 && abs(U)%2==1) dame;

    auto f = [&](ll a)->vec(ll){
        bool isminus = false;
        if(a<0){
            isminus = true;
            a = -a;
        }

        ll p = a/K, q = a%K;

        vec(ll) res(p,K);
        if(q>0){                    
            if(K&1){
                if(q&1){
                    res.push_back(q);
                }else{
                    res.push_back(1);
                    res.push_back(q-1);
                }
            }else{
                assert(q%2==0);
                res.push_back(q);
            }
        }
        if(isminus) for(ll &r:res) r=-r;

        return res;
    };

    vec(ll) uu = f(U);
    vec(ll) vv = f(V);

    ll un = uu.size(), vn = vv.size();
    
    // for(ll x:uu) cout << x << ", "; cout << endl;
    // for(ll x:vv) cout << x << ", "; cout << endl;

    bool memo = false;
    if(un>vn){
        memo = true;
        swap(uu,vv);
    }

    ll d = abs(vn-un);
    if(d&1){
        if(K&1) dame;
        uu.push_back(0);
        d--;
    }
    reverse(all(uu));
    rep(_,d/2){
        uu.push_back(K);
        uu.push_back(-K);
    }

    if(memo) swap(uu,vv);

    ll nn = max(un,vn);
    vec(Pll) ans(nn);
    rep(i,nn){
        if(abs(uu[i])!=K && abs(vv[i])!=K) dame;
        ans[i] = { (uu[i]+vv[i])/2, (uu[i]-vv[i])/2  };
    }

    cout << nn << endl;
    for(Pll ai:ans) cout << ai.first << " " << ai.second << endl;
    





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
