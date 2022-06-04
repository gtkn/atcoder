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

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------


//---区間max,区間addのlazy_segtreeのテンプレート---
ll op(ll a, ll b){ return max(a,b);}
ll ee(){return 0;}
ll mapping(ll f, ll x){return f+x;}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}


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
        ll N,M,Q;
        cin >> N >> M >> Q;

        vvec(ll) vv(Q,vec(ll)(4,-1));
        rep(i,Q){
            cin >> vv[i][0];
            if(vv[i][0]==1) rep1(j,3) cin >> vv[i][j];
            else rep1(j,2) cin >> vv[i][j];
        }

        vec(ll) ans;
        vec(Pll) v(N+1);
        ll cnt=0;

        vvec(Pll) vq(Q);

        rep(i,Q){
            if(vv[i][0]==2){
                v[vv[i][1]] = {vv[i][2],i};
            }
            if(vv[i][0]==3){
                Pll vi = v[vv[i][1]];
                ans.push_back(vi.first);

                vq[vi.second].emplace_back(cnt,vv[i][2]);
                //vv[vi.second][4] = cnt;
                //vv[vi.second][5] = vv[i][2];
                cnt++;
            }
        }


        lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(M+1);
        cnt=0;
        rep(i,Q){

            for(Pll x:vq[i]) ans[x.first] -= ls.get(x.second); 

            if(vv[i][0]==1){
                ls.apply(vv[i][1],vv[i][2]+1,vv[i][3]);
            }
            if(vv[i][0]==3){
                ans[cnt] += ls.get(vv[i][2]);
                cnt++;
            }
        }

        for(ll ai:ans) cout << ai << endl;

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
