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

    vec(ll) dpu,dpv,rem;
    vvec(ll) g;

    ll dfsv(ll now, ll frm, ll d){
        ll res = d;
        dpv[now]=d;

        for(ll nxt:g[now]){
            if(nxt == frm) continue;
            chmax(res, dfsv(nxt,now,d+1));
        }

        rem[now] = res - d;
        return res;
    }


    void dfsu(ll now, ll frm, ll d){
        dpu[now]=d;

        for(ll nxt:g[now]){
            if(nxt == frm) continue;
            dfsu(nxt,now,d+1);
        }
    }



    void solve(){
        ll N, u, v;
        cin >> N >> u >> v;
        --u; --v;

        g.resize(N);
        dpu.resize(N);
        dpv.resize(N);
        rem.resize(N);


        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfsv(v,v,0);

        rep(i,N) dpu[i]=llINF;
        queue<ll> q;
        auto qpush = [&](ll _now, ll _d){
            if(chmin(dpu[_now],_d)){
                q.push(_now);
            }
        };
        qpush(u,0);

        ll ans = 0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();

            for(ll nxt:g[now]){
                if(dpv[nxt] > dpv[now]) continue;
                qpush(nxt,dpu[now]+1);

                rep(x,2){
                    if(dpv[nxt]==dpu[now]+x){
                        chmax(ans, dpu[now]+rem[now]+x);
                        // cout << now << " , " << x << " ; " << dpu[now] << ","<<rem[now] << endl;
                    }
                }

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
