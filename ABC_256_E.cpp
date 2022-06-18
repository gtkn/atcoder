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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
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
        ll N;
        cin >> N;
        vec(ll) X(N),C(N);
        rep(i,N) cin >> X[i];
        rep(i,N) X[i]--;
        rep(i,N) cin >> C[i];

        vvec(ll) g(N);
        rep(i,N){
            g[i].push_back(X[i]);
            g[X[i]].push_back(i);
        }


        vec(bool) used(N);
        vec(bool) used2(N);
        ll ans = 0;

        rep(i,N){
            if(used[i]) continue;

            ll st = -1;
            ll now = i;
            while(1){
                if(used2[now]){
                    st = now;
                    break;
                }
                used2[now]=true;
                now = X[now];
            }

            ll x = C[st];
            now = X[st];
            while(now!=st){
                chmin(x,C[now]);
                now = X[now];
            }

            ans += x;

            queue<ll> q;
            q.push(st);
            while(!q.empty()){
                ll now = q.front(); q.pop();
                used[now]=true;
                for(ll to:g[now]) if(!used[to]) q.push(to);
            }
        }
        cout << ans << endl;


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
