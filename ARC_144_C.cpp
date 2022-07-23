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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return min(a,b);};
ll ee(){return llINF;};


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
        ll N,K;
        cin >> N >> K;

        if(N<2*K) dame;

        vec(ll) ans;



        vec(ll) v(N+1);
        rep(i,N+1) v[i]=i;
        v[0]=llINF;
        segtree<ll,op,ee> seg(v);



        rep1(i,N){
            ll x;
            if(i+K>N-K && i+K<=N){
                x = i+K;
            }else{
                ll a=llINF,b=llINF;
                if(i-K>0) a = seg.prod(0,i-K+1);
                if(i+K<=N) b = seg.prod(i+K,N+1);
                x = min(a,b);
            }
            ans.push_back(x);
            seg.set(x,llINF);
        }

        for(ll ai:ans) cout << ai << " ";cout<<endl;


        /*
        assert(ans.size()==N);

        vec(bool) used(N+1);
        rep(i,N){
            if(abs(ans[i]-i-1)<K) cout << i+1 <<" : " << ans[i]  <<" over " << endl;
            if(used[ans[i]]) cout << "used " << ans[i] << endl;
            used[ans[i]]=true;
        }
        rep1(i,N) if(!used[i]) cout << "not used " << i << endl;
        */

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
