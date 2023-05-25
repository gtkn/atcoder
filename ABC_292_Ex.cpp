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


ll op(ll a, ll b){ return max(a,b);}
ll ee(){return -llINF;}
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
        ll N,B,Q;
        cin >> N >> B >> Q;

        vec(ll) a(N);
        rep(i,N) cin >> a[i];


        // ll tot = 0;
        // rep(i,N) tot += a[i];

        vec(ll) v(N+1);
        rep(i,N) v[i+1] = v[i] + a[i]-B;
        v[0] = -llINF;

        lazy_segtree<ll, op, ee, ll, mapping, composition, id> ls(v);

        while(Q--){
            ll c,x;
            cin >> c >> x;
            c--;
            ls.apply(c+1, N+1, -a[c]+x);
            // tot -= a[c];
            // tot += x;
            a[c] = x;



            ll l=1, r=N+1;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(ls.prod(0,mid)>=0) r = mid;
                else l = mid;
            }

            // cout << "---" << Q << "---"<< l << endl;
            // rep(i,N+1) cout << ls.get(i) << " "; cout << endl;

            // if(ls.all_prod()<0) ok = N;

            double res = 1.*ls.get(l)/l + B;
            printf("%.10f\r\n", res);

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
