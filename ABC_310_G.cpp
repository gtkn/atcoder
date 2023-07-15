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
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
using mint = modint998244353;


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

 
 
    vec(ll) dh = {1,0,-1,0};
    vec(ll) dw = {0,1,0,-1};
 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(ll) A(N),B(N);
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];
        rep(i,N) A[i]--;

        vec(mint) num(N);
        vec(bool) used(N);
        vec(ll) done(N);
        vec(ll) memo;

        auto f = [&](auto f,ll now, ll cnt, mint tot)->void{
            cout << now << " " << cnt << " " << tot.val() << endl;
            if(cnt>=K) return;
            if(used[now]){
                if(done[now]<0) return;
                else{
                    ll c = cnt-done[now];
                    ll x = (K-done[now])/c;
                    num[now] += tot*x;
                    done[now]=-1;
                }
            }else{
                done[now]=cnt;         
                used[now]=true;
                memo.push_back(now);
                tot += B[now];
                B[now]=0;
                num[now] += tot;
            }
            f(f,A[now],cnt+1,tot);
        };

        vec(ll) incnt(N);
        rep(i,N) incnt[A[i]]++;

        rep(st,N){
            if(incnt[st]>0 || used[st]) continue;
            f(f,st,0,0);
            for(ll x:memo) done[x]=false;
        }

        mint den = mint(K).inv();

        rep(i,N) cout << (num[i]*den).val() << " "; cout << endl;
        




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
