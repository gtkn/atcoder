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

using mint = modint1000000007;
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
    string S,T;
    cin >> S >> T;

    vec(ll) a(N),b(N);

    // R
    rep(i,N){
        if(S[i]=='R') a[i]=0;
        if(S[i]=='G') a[i]=1;
        if(S[i]=='B') a[i]=2;
    }    

    rep(i,N){
        if(T[i]=='R') b[i]=0;
        if(T[i]=='G') b[i]=2;
        if(T[i]=='B') b[i]=1;
    }    

    mint const base = 3;

    vec(mint) ah(N+1),bh(N+1);
    rep(i,N) ah[i+1] = ah[i]*base + a[i];
    rep(i,N) bh[i+1] = bh[i]*base + b[i];

    auto fa = [&](ll l,ll r)->mint{
        mint res = ah[r]-ah[l]*base.pow(r-l);
        return res;
    };

    auto fb = [&](ll l,ll r)->mint{
        mint res = bh[r]-bh[l]*base.pow(r-l);
        return res;
    };


    // rep(i,N+1) cout << ah[i].val() <<" "; cout << endl;
    // rep(i,N+1) cout << bh[i].val() <<" "; cout << endl;

    // cout << fa(0,2).val() << endl;
    // // cout << (fa(0,3)*base.pow(2)).val() << endl;
    // cout << fb(3,5).val() << endl;

    // return;

    ll ans = 0;
    rep(i,N){
        if( fa(i,N) == fb(0,N-i) ) ans++;
        if( i>0 && fa(0,N-i) == fb(i,N) ) ans++;
    }


    // G
    rep(i,N){
        if(T[i]=='R') b[i]=2;
        if(T[i]=='G') b[i]=1;
        if(T[i]=='B') b[i]=0;
    }    
    rep(i,N) bh[i+1] = bh[i]*base + b[i];

    rep(i,N){
        if( fa(i,N) == fb(0,N-i) ) ans++;
        if( i>0 && fa(0,N-i) == fb(i,N) ) ans++;
    }


    // B
    rep(i,N){
        if(T[i]=='R') b[i]=1;
        if(T[i]=='G') b[i]=0;
        if(T[i]=='B') b[i]=2;
    }    
    rep(i,N) bh[i+1] = bh[i]*base + b[i];

    rep(i,N){
        if( fa(i,N) == fb(0,N-i) ) ans++;
        if( i>0 && fa(0,N-i) == fb(i,N) ) ans++;
    }

    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
