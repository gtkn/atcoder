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
//using mint = modint998244353;


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


void solve(){
    ll H,W,Q;
    cin >> H >> W >> Q;

    vector<set<ll>> rset(H),cset(W);
    {
        set<ll> tmp;
        tmp.insert(-1);
        rep(i,W) tmp.insert(i);
        rep(i,H) rset[i] = tmp;
    }
    {
        set<ll> tmp;
        tmp.insert(-1);
        rep(i,H) tmp.insert(i);
        rep(i,W) cset[i] = tmp;
    }


    while(Q--){
        ll r,c;
        cin >> r >> c;
        --r; --c;

        // cerr << "--- " << r << " " << c << endl;
        // rep(i,H){
        //     cerr << i << " : ";
        //     for(ll c:rset[i]) cerr << c << " "; cerr << endl;
        // }
        // cerr << endl;
        // rep(i,W){
        //     cerr << i << " : ";
        //     for(ll r:cset[i]) cerr << r << " "; cerr << endl;
        // }


        set<ll> &rs = rset[r], &cs = cset[c];

        if(rs.find(c)!=rs.end()){
            // cerr << "in" << endl;
            rs.erase(c);
            cs.erase(r);
            continue;
        }

        auto itr = rs.upper_bound(c);
        if(itr != rs.end()){
            rs.erase(itr);
            ll cc = *itr;
            cset[cc].erase(r);
        }
        auto itl = rs.upper_bound(c);
        itl--;
        if(itl != rs.begin()){
            rs.erase(itl);
            ll cc = *itl;
            cset[cc].erase(r);
        }

        auto itd = cs.upper_bound(r);
        if(itd != cs.end()){
            cs.erase(itd);
            ll rr = *itd;
            rset[rr].erase(c);
        }
        auto itu = cs.upper_bound(r);
        itu--;
        if(itu != cs.begin()){
            cs.erase(itu);
            ll rr = *itu;
            rset[rr].erase(c);
        }


    }

    // rep(i,H){
    //     cerr << i << " : ";
    //     for(ll c:rset[i]) cerr << c << " "; cerr << endl;
    // }
    // rep(i,W){
    //     cerr << i << " : ";
    //     for(ll r:cset[i]) cerr << r << " "; cerr << endl;
    // }




    ll ans = 0;
    rep(i,H) ans += rset[i].size()-1;
    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
