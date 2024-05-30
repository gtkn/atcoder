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
constexpr ll llINF = 1LL << 60;
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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
 
    set<Pll> st;
    st.insert({1,N+1});

    auto f = [&](auto f, ll l, ll r)->void{
        if(r-l<=1) return;

        ll mid = (l+r)/2;
        for(ll i=l; i<mid; ++i){
            st.emplace(i,mid);
        }
        for(ll i=mid+1; i<=r; ++i){
            st.emplace(mid,i);
        }
        f(f,l,mid);
        f(f,mid,r);
    };

    f(f,1,N+1);

    ll M = st.size();
    cout << M << endl << flush;
    // return;

    vec(Pll) lr;
    for(auto p: st){
        assert(p.first < p.second);
        cout << p.first << " " << p.second-1 << endl << flush;
        lr.emplace_back(p);
    }


    map<Pll,ll> mp;
    rep(i,M) mp[lr[i]] = i;


    auto ff = [&](auto ff, ll l, ll r, ll lq, ll rq)->Pll{
        ll mid = (l+r)/2;

        if(lq<mid && mid<rq){
            ll a = mp[{lq,mid}];
            ll b = mp[{mid,rq}];
            return {a,b};
        }

        if(rq<=mid) return ff(ff,l,mid,lq,rq);
        if(mid<=lq) return ff(ff,mid,r,lq,rq);
    };


    ll Q;
    cin >> Q;

    while(Q--){
        ll L,R;
        cin >> L >> R;

        Pll res;
        if( mp.find({L,R+1}) != mp.end() ){
            ll x = mp[{L,R+1}];
            res = {x,x};
        }else{
            res = ff(ff,1,N+1,L,R+1);
        }

        cout << res.first+1 << " " << res.second+1 << endl << flush;

        // cerr << "---" << endl;
        // cerr << "Q : " << L << " " << R << " " << endl;
        // cerr << lr[res.first].first << " " << lr[res.first].second << endl;
        // cerr << lr[res.second].first << " " << lr[res.second].second << endl;
        // cerr << endl;

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
