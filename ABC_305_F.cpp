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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;

        set<ll> used;
        set<ll> checked;
        vvec(bool) g(N+1,vec(bool)(N+1));
        vvec(ll) dp(N+1, vec(ll)(N+1,llINF));


        auto update = [&](ll x){
            vec(ll) tmp(N+1,llINF);
            queue<ll> q;
            q.push(x);
            tmp[x]=0;

            while(!q.empty()){
                ll q0 = q.front();
                q.pop();
                rep1(to,N){
                    if(!g[q0][to]) continue;
                    if(chmin(tmp[to], tmp[q0]+1 )) q.push(to);
                }
            }

            rep1(i,N){
                dp[x][i] = tmp[i];
                dp[i][x] = tmp[i];
            }
        };


        ll now = 1;
        rep(_,2*N){
            ll k; cin >> k;

            vec(ll) v(k);
            rep(i,k) cin >> v[i];

            for(ll vi:v) g[now][vi] = true;

            if(!sfind(used,now)) update(now);
            used.insert(now);

            vec(ll) a,b;
            for(ll vi:v){
                if(sfind(used,vi)) a.push_back(vi);
                else b.push_back(vi);
            }
            if(b.empty()) checked.insert(now);

            ll nxt=-1;
            if(v.back()==N) nxt = N;
            else if(!b.empty()) nxt=b[0];
            else{
                ll tgt = -1, dmax = llINF;
                for(ll ui:used){
                    if(sfind(checked,ui)) continue;
                    if(chmin(dmax, dp[now][ui])) tgt = ui;
                }

                for(ll ai:a){
                    if(chmin(dmax, dp[ai][tgt])) nxt=ai;
                }
            }
            assert(nxt>=0);


            cout << nxt << endl << flush;
            now = nxt;
            if(nxt==N) break;
        }

        if(now==N){
            string ok; cin >> ok;
        }
        return;

    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
