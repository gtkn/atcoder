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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    struct mconb{
        ll nmax;
        vec(mint) fa,af;
        mconb(ll sz=200020){
            nmax = sz;
            fa.resize(nmax+1);
            fa[0]=1;
            rep1(i,nmax) fa[i]=fa[i-1]*i;
            af.resize(nmax+1);
            rep(i,nmax+1) af[i]=fa[i].inv();
        }
        mint c(ll n, ll k){
            if(n<k || k<0 || n>nmax) return 0;
            return fa[n]*af[k]*af[n-k];
        }
    };

    ll N;
    vvec(ll) g;
    vec(ll) ch;
    vec(mint) pt,ans;
    mconb mc;   


    void dfs0(ll now,ll frm){
        ch[now]=1;
        pt[now]=1;

        vec(ll) v;
        for(ll to:g[now]){
            if(to==frm) continue;
            dfs0(to,now);
            v.push_back(ch[to]);
            pt[now]*=pt[to];
        }

        ll tot=0;
        for(ll vi:v) tot+=vi;
        ch[now]+=tot;

        for(ll vi:v){
            pt[now] *= mc.c(tot,vi);
            tot-=vi;
        }
    }


    void dfs1(ll now,ll frm){
        ll chn,chf;
        mint ptn,ptf;
        chn = ch[now]; chf = ch[frm];
        ptn = pt[now]; ptf = pt[frm];

        vec(ll) v;
        ll tot = 0;

        /**
        pt[frm]=1;
        ch[frm]=1;
        for(ll to:g[frm]){
            if(to==now) continue;
            v.push_back(ch[to]);
            pt[frm]*=pt[to];
        }
        for(ll vi:v) tot+=vi;
        ch[frm]+=tot;
        for(ll vi:v){
            pt[frm]*=mc.c(tot,vi);
            tot-=vi;
        }
        **/
        if(now!=frm){
            pt[frm]/=(pt[now] * mc.c(ch[frm]-1,ch[now]) );
            ch[frm]-=ch[now];
        }
            
        ans[now]=1;
        v.clear();
        for(ll to:g[now]){
            v.push_back(ch[to]);
            ans[now]*=pt[to];
        }
        tot=0;
        for(ll vi:v) tot+=vi;
        for(ll vi:v){
            ans[now]*=mc.c(tot,vi);
            tot-=vi;
        }

        pt[now] = ans[now];
        ch[now] = N;


        for(ll to:g[now]) if(to!=frm) dfs1(to,now);


        ch[now] = chn; ch[frm] = chf;
        pt[now] = ptn; pt[frm] = ptf;

    }




 
    void solve(){
        cin >> N;
        g.resize(N);
        ans.resize(N);
        ch.resize(N);
        pt.resize(N);

        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        dfs0(0,0);
        dfs1(0,0);

        for(mint ai:ans) cout << ai.val() << endl;

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
