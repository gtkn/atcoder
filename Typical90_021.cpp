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
    struct SCC{
        ll n;
        vvec(ll) gf,gr;
        vec(bool) used;
        vec(ll) memo;

        SCC(ll _n, vvec(ll) _gf, vvec(ll) _gr){
            n = _n;
            gf = _gf;
            gr = _gr;
            assert(n==gf.size() && n==gr.size());
            used.resize(n);
        }

        void dfsf(ll now){
            used[now] = true;
            for(auto to:gf[now]) if(!used[to]) dfsf(to);
            memo.push_back(now);
            return;
        }

        vec(ll) tmp;

        void dfsr(ll now){
            tmp.push_back(now);
            used[now]=true;
            for(auto to:gr[now]) if(!used[to]) dfsr(to);
            return;
        }



        vvec(ll) get_group(){
            rep(i,n) used[i] = false;
            memo.clear();

            rep(st,n) if(!used[st]) dfsf(st);

            rep(i,n) used[i] = false;
            
            vvec(ll) res;
            reverse(all(memo));
            for(auto st:memo){
                if(used[st]) continue;
                tmp.clear();
                dfsr(st);
                res.push_back(tmp);
            }

            return res;
        }

    };



 
    void solve(){
        ll N,M;
        cin >> N >> M;

        vvec(ll) gf(N),gr(N);
        rep(_,M){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            gf[a].push_back(b);
            gr[b].push_back(a);
        }

        SCC scc(N,gf,gr);
        
        vvec(ll) vv = scc.get_group();
        ll ans = 0;
        for(vec(ll) v:vv){
            ll n = v.size();
            //for(ll vi:v)cout<<vi<<" ";cout<<endl;
            ans += n*(n-1)/2;
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
