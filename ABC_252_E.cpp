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

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c,id;
        edge(ll to=0, ll c=0, ll id=0):to(to),c(c),id(id){}
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

        vvec(edge) g(N);
        rep1(i,M){
            ll a,b,c;
            cin >> a >> b >> c;
            a--; b--;
            g[a].emplace_back(b,c,i);
            g[b].emplace_back(a,c,i);
        }

        vec(ll) dp(N,llINF);
        priority_queue<Pll, vector<Pll>, greater<Pll>> q;
        auto qpush = [&](ll to, ll c){
            if(chmin(dp[to], c)){
                q.emplace(c,to);
            }
        };
        qpush(0,0);

        while(!q.empty()){
            Pll q0 = q.top(); q.pop();
            ll now = q0.second;
            ll c0 = q0.first;
            if(dp[now] < c0) continue;
            for(edge nxt:g[now]){
                qpush(nxt.to, c0+nxt.c);
            }
        }

        set<ll> s;
        vec(bool) used(N);
        rep1(i,N-1){
            ll now = i;
            while(now!=0){
                if(used[now]) break;
                used[now] = true;
                for(edge nxt:g[now]){
                    if(dp[nxt.to] + nxt.c == dp[now]){
                        now = nxt.to;
                        s.insert(nxt.id);
                        break;
                    }
                }
            }
        }

        for(ll si:s) cout << si << " "; cout << endl;

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
