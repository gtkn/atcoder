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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

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


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll Q;
    cin >> Q;

    vec(ll) q(Q),v(Q);

    map<string,ll> qname;
    qname["ADD"] = 0;
    qname["DELETE"] = 1;
    qname["SAVE"] = 2;
    qname["LOAD"] = 3;

    rep(i,Q){
        string s;
        cin >> s;
        q[i] = qname[s];
        if(q[i]==1) v[i] = -1;
        else cin >> v[i];
    }

    set<ll> st;
    rep(i,Q) if(q[i]>=2) st.insert(v[i]);

    map<ll,ll> mp;
    ll nn = 0;
    for(ll x:st){
        mp[x] = nn;
        nn++;
    }


    vec(ll) pos(nn);
    vec(Pll) node; // {par,last}
    node.emplace_back(0,-1);
    ll now = 0;
    ll cnt = 1;

    vec(ll) ans;
    rep(i,Q){
        // cerr << "i: " << i << " now: " << now << " " << q[i] << " " << v[i] << endl;    
        if(q[i]==0){
            node.emplace_back(now,v[i]);
            now = cnt;
            cnt++;
        }
        if(q[i]==1){
            now = node[now].first;
        }
        if(q[i]==2){
            pos[mp[v[i]]] = now;
        }
        if(q[i]==3){
            now = pos[mp[v[i]]];
        }
        ans.push_back(node[now].second);
    }

    for(ll x:ans) cout << x << " "; cout << endl;






    // vvec(ll) vv(nn);
    // vec(ll) A;

    // rep(i,Q){
    //     if(q[i]==0){
    //         A.push_back(v[i]);
    //     }
    //     if(q[i]==1){
    //         if(!A.empty()) A.pop_back();
    //     }
    //     if(q[i]==2){
    //         vv[mp[v[i]]] = A;
    //     }
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
