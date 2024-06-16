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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    if(K<N) sayno;
    ll d = K-N;
    if(d%2==1) sayno;

    vec(Pll) p;
    ll h=0, w=M-1;
    // p.emplace_back(h,w);
    p.push_back({h,w});

    if(N&1){
        rep(_,N/2-1){
            ll x = min(d/2,M-1);
            rep(i,x){
                w--;
                p.push_back({h,w});
            }
            h++;
            p.push_back({h,w});
            rep(i,x){
                w++;
                p.push_back({h,w}); 
            }
            h++;
            p.push_back({h,w});
            d -= 2*x;
            //assert(w==M-1);
        }

        if(d/2 > M-1){
            ll x = M-1;
            rep(i,x){
                w--;
                p.push_back({h,w});
            }
            h++;
            p.push_back({h,w});

            ll y = d-2*x;

            rep(i,x){
                if(y>0){
                    if(i&1){
                        h--;
                        p.push_back({h,w});
                    }else{
                        h++;
                        p.push_back({h,w});
                    }
                    y--;
                }
                w++;
                p.push_back({h,w}); 
            }
            h++;
            p.push_back({h,w});
            h++;
            p.push_back({h,w});

            d -= 2*x;
            //assert(w==M-1);

        }else{
            ll x = d/2;
            rep(i,x){
                w--;
                p.push_back({h,w});
            }
            h++;
            p.push_back({h,w});
            rep(i,x){
                w++;
                p.push_back({h,w}); 
            }
            h++;
            p.push_back({h,w});
            h++;
            p.push_back({h,w});
            d -= 2*x;
            //assert(w==M-1);
        }

    }else{
        rep(_,N/2){
            ll x = min(d/2,M-1);
            rep(i,x){
                w--;
                p.push_back({h,w});
            }
            h++;
            p.push_back({h,w});
            rep(i,x){
                w++;
                p.push_back({h,w}); 
            }
            h++;
            p.push_back({h,w});
            d -= 2*x;
            //assert(w==M-1);
        }
    }

    // cerr << p.size() << "!" << endl;
    // for(auto pi:p){
    //     cout << pi.first << ' ' << pi.second << endl;
    // }
    // //assert(p.size()==K+1);


    p.pop_back();
    
    vvec(bool) hv(N,vec(bool)(M-1));
    vvec(bool) wv(N-1,vec(bool)(M));

    rep(i,K-1){
        ll h1 = p[i].first, w1 = p[i].second;
        ll h2 = p[i+1].first, w2 = p[i+1].second;
        if(h1==h2){
            hv[h1][min(w1,w2)] = true;
        }else{
            wv[min(h1,h2)][w1] = true;
        }
    }



    cout << "Yes" << endl;
    rep(_,2*M-1) cout << "+";
    cout << "S+" << endl;

    rep(i,N){
        cout << "+";
        rep(j,M-1){
            cout << "o";
            cout << (hv[i][j] ? "." : "|");
        }
        cout << "o+" << endl;

        if(i==N-1) break;
        cout << "+";
        rep(j,M){
            cout << (wv[i][j] ? "." : "-");
            cout << "+";
        }
        cout << endl;

    }


    rep(_,2*M-1) cout << "+";
    cout << "G+" << endl;






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
