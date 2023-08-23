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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N,M,Q;
    cin >> N >> M >> Q;

    vvec(Pll) es(N);
    rep(_,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        es[a].emplace_back(b,c);
    }


    // merge
    rep(i,N){
        if(es[i].empty()) continue;

        vec(Pll) pree;
        swap(pree, es[i]);
        vec(Pll)& newe=es[i];

        sort(all(pree));
        newe.push_back(pree[0]);
        for(Pll e:pree){
            if(newe.back().second >= e.first){
                chmax(newe.back().second, e.second);
            }else{
                newe.push_back(e);
            }
        }
    }



    // 1回で行ける範囲
    vec(Pll) ce;
    rep(i,N) ce.insert( ce.end(), all(es[i]) );
    {
        vec(Pll) pree;
        swap(pree, ce);
        sort(all(pree));
        ce.push_back(pree[0]);
        for(Pll e:pree){
            if(ce.back().second >= e.second) continue;
            ce.push_back(e);
        }
    }


    // xがceの何番目か
    auto get = [&](ll x)->ll{
        ll d = upper_bound(all(ce), Pll(x,llINF)) - ce.begin() - 1;
        if(d>=0 && ce[d].second >= x) return d;
        return -1;
    };



    ll nn = ce.size();
    const ll D = 20;
    vector db(D,vec(ll)(nn));
    rep(j,nn) db[0][j] = get(ce[j].second);
    rep(i,D-1){
        rep(j,nn) db[i+1][j] = db[i][ db[i][j] ];
    }


    // ビルiでx階から行ける最上階
    auto goUp = [&](ll i,ll x)->ll{
        ll j = upper_bound(all(es[i]), Pll(x,llINF)) - es[i].begin() -1;
        if(j>=0 && es[i][j].second >= x) return es[i][j].second;
        return x;
    };


    // ビルiでx階から行ける最下階
    auto goDown = [&](ll i,ll x)->ll{
        ll j = upper_bound(all(es[i]), Pll(x,llINF)) - es[i].begin() -1;
        if(j>=0 && es[i][j].second >= x) return es[i][j].first;
        return x;
    };


    // 何個のceで行けるか
    auto calc_cost = [&](ll y,ll w)->ll{
        ll ei = get(y);
        if(ei==-1) return llINF;
        if(ce[ei].second >= w) return 1;
        ll res = 1; // ?
        repr(i,D){
            ll nxt = db[i][ei];
            if( ce[nxt].second < w ){
                ei=nxt;
                res += (1<<i);
            }            
        }
        if(ce[db[0][ei]].second < w) return llINF;
        return res+1;
    };



    while(Q--){
        ll x,y,z,w;
        cin >> x >> y >> z >> w;
        --x; --z;
        if(y>w){
            swap(x,z);
            swap(y,w);
        }
        ll res = w-y;
        
        y = goUp(x,y);
        w = goDown(z,w);

        if(y>=w){
            if(x!=z) res++;
        }else{
            res++;
            res += calc_cost(y,w);
        }

        if(res>=llINF) res = -1;
        cout << res << endl;

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
