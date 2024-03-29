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

        vvec(ll) g(N);
        rep(_,M){
            ll u,v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ll K;
        cin >> K;
        vec(ll) p(K),d(K);
        rep(i,K) cin >> p[i] >> d[i];

        vec(set<ll>) memo(K);
        vec(bool) used(N);

        rep(i,K){
            ll st = p[i]-1;

            vec(ll) dp(N,llINF);
            priority_queue<Pll, vector<Pll>, greater<Pll>> q;
            auto qpush = [&](ll c_,ll to_){
                if(chmin(dp[to_], c_)) q.emplace(c_,to_);
            };

            qpush(0,st);
            while(!q.empty()){
                Pll q0 = q.top();
                q.pop();

                ll now,c;
                tie(c,now) = q0;
                // cout << ";;" << now <<"," << c << endl;

                if(c==d[i]) memo[i].insert(now);
                if(c<d[i]) used[now]=true;
                if(c>=d[i]) continue;
                if(dp[now]<c) continue;

                for(ll nxt:g[now]) qpush(c+1,nxt);
            }

            // cout << "---" << st <<","<<d[i]<< endl;
            // rep(j,N) cout << j << " : " << dp[j] << endl;
            // for(ll x:memo[i]) cout << x << " "; cout << endl;
        }

        bool isok=true;
        rep(i,K){
            bool tmp = false;
            for(ll x:memo[i]) if(!used[x]) tmp=true;
            if(!tmp) isok=false;
        }

        if(isok) yn;
        if(isok){
            rep(i,N) cout << (used[i]? 0: 1); cout << endl;
        }


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
