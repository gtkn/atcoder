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
    ll N;
    cin >> N;
    vec(ll) m(N);
    vvec(ll) p(N),e(N);
    rep(i,N){
        cin >> m[i];
        p[i].resize(m[i]);
        e[i].resize(m[i]);
        rep(j,m[i]){
            cin >> p[i][j] >> e[i][j];
        }
    }

    set<ll> st;
    for(auto pi:p){
        for(auto pj:pi){
            st.insert(pj);
        }
    }
    map<ll,ll> mp;
    ll nn = 0;
    for(auto si:st){
        mp[si] = nn;
        ++nn;
    }

    vvec(ll) p2 = p;
    rep(i,N)rep(j,m[i]){
        p2[i][j] = mp[p2[i][j]];
    }


    vvec(ll) cnt(nn);
    rep(i,N)rep(j,m[i]){
        cnt[p2[i][j]].push_back(e[i][j]);
    }
    rep(i,nn) sort(all(cnt[i]),greater<ll>());
    rep(i,nn) cnt[i].push_back(0);

    vec(bool) isone(nn);
    rep(i,nn){
        if(cnt[i][0] != cnt[i][1]) isone[i] = true;
    }

    // set<ll> ss;
    // rep(i,N){
    //     ll x = 1;
    //     rep(j,m[i]){
    //         ll pj = p2[i][j];
    //         if(isone[pj] && e[i][j]==cnt[pj][0]){
    //             x*=p[i][j];
    //         }
    //     }
    //     ss.insert(x);
    // }

    // cout << ss.size() << endl;



    vvec(ll) b(N);
    rep(i,N){
        rep(j,m[i]){
            ll pj = p2[i][j];
            if(isone[pj] && e[i][j]==cnt[pj][0]){
                b[i].push_back(pj);
            }
        }
    }

    ll ans = 0;
    ll MOD = (1LL<<61)-1;
    rep(_,3){
        set<ll> hs;
        while(hs.size()<nn){
            hs.insert(rand()%(MOD-1)+1);
        }
        vec(ll) h(all(hs));

        // vec(ll) h(nn);
        // rep(i,nn) h[i] = rand()%(MOD-1)+1;

        set<ll> ss;
        // cerr << "--" << endl;
        rep(i,N){
            ll hash = 0;
            for(auto bi:b[i]){
                hash ^= h[bi];
            }
            // cerr << hash << endl;
            ss.insert(hash);
        }
        chmax(ans,(ll)ss.size());
    }

    cout << ans << endl;



    // for(auto [k,v]:mp){
    //     cerr << k << " " << v << endl;
    // }

    // rep(i,nn){
    //     cerr << i << " : ";
    //     for(auto c:cnt[i]){
    //         cerr << c << " ";
    //     }
    //     cerr << " : " << isone[i] << endl;
    // }


    // rep(i,N){
    //     cerr << "i = " << i << "----" << endl;
    //     for(auto bi:b[i]){
    //         cerr << bi << " ";
    //     }
    //     cerr << endl;
    // }

    // rep(i,N){
    //     cerr << "i = " << i << "----" << endl;
    //     rep(j,m[i]){
    //         cerr << p2[i][j] << " ";
    //     }
    //     cerr << endl;
    //     rep(j,m[i]){
    //         cerr << p[i][j] << " ";
    //     }
    //     cerr << endl;
        
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
