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
        ll N,Q;
        cin >> N >> Q;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        vec(abc) q(Q);
        rep(i,Q){
            cin >> q[i].a >> q[i].b;
            q[i].a--;
            q[i].c = i;
        }

        ll nn = sqrt(N);
        sort(all(q),[&](abc const& x, abc const& y){
            if(x.a/nn != y.a/nn) return x.a/nn < y.a/nn;
            if(x.b/nn != y.b/nn) return x.b/nn < y.b/nn;
            if(x.a != y.a) return x.a < y.a;
            return x.b < y.b;
        });

        vec(ll) ans(Q);
        ll l=0,r=0;
        vec(ll) cnt(200020);
        ll tmp = 0;

        auto update = [&](ll x,bool add){
            if(add){
                tmp += cnt[x]*(cnt[x]-1)/2;
                cnt[x]++;
            }else{
                cnt[x]--;
                tmp -= cnt[x]*(cnt[x]-1)/2;
            }
        };


        for(abc qi:q){
            // cout << qi.a << " , " << qi.b << " : " << qi.c << endl;

            while(r<qi.b) update(A[r++],true);
            while(r>qi.b) update(A[--r],false);
            while(l<qi.a) update(A[l++],false);
            while(l>qi.a) update(A[--l],true);

            ans[qi.c] = tmp;
        }

        rep(i,Q) cout << ans[i] << endl;



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
