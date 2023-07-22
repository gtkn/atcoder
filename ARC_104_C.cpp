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
using l3 = __int128;

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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

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
    ll N;
    cin >> N;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    ll nn = 2*N;
    vec(ll) v(nn);
    rep(i,N){
        if(A[i]==-1) continue;
        if(v[A[i]-1]!=0) nodame;
        v[A[i]-1] = i+1;
    }
    rep(i,N){
        if(B[i]==-1) continue;
        if(v[B[i]-1]!=0) nodame;
        v[B[i]-1] = -i-1;
    }

    rep(i,N){
        if(A[i]>0 && B[i]>0 && A[i]>B[i]) nodame;
    }

    vec(bool) dp(nn+1);
    dp[0]=true;

    rep(i,nn){
        if(!dp[i]) continue;

        for(ll d=1; i+2*d<=nn; d++){
            bool isok=true;
            for(ll st=i; st<i+d; st++){
                ll gl = st+d;
                if(v[st]<0 || v[gl]>0){
                    isok=false;
                    continue;
                }
                
                if(v[st]>0 && v[gl]<0 && v[st]!=-v[gl]){
                    isok=false;
                    continue;
                }
                if(v[st] == -v[gl]) continue;

                
                if(v[st]>0){
                    if(B[ v[st]-1 ]!=-1) isok=false;
                    continue;
                }

                if(v[gl]<0){
                    if(A[ -v[gl]-1]!=-1) isok=false;
                    continue;
                }
            }
            if(isok) dp[i+2*d]=true;
        }
    }

    if(dp[nn]) yn;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
