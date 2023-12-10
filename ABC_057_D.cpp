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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

void solve(){
    ll N,A,B;
    cin >> N >> A >> B;

    vec(ll) v(N);
    rep(i,N) cin >> v[i];


    vvec(ll) ws(3),cnts(3);

    ll n0 = 0;
    rep(di,3){
        ll n = N/3;
        if(di==2) n = N - n0;


        ws[di].resize(n+1); cnts[di].resize(n+1);

        rep(p, (1<<n)){
            ll w=0, b=0;
            rep(i,n){
                if(!bit(p,i)) continue;
                w += v[n0+i];
                b++;
            }

            if(chmax(ws[di][b], w)){
                cnts[di][b]=1;
            }else if(ws[di][b]==w){
                cnts[di][b]++;
            }
        }

        n0 += n;
    }


    vec(ll) wall(N+1),cntall(N+1);
    rep(b0,ws[0].size())rep(b1,ws[1].size())rep(b2,ws[2].size()){

        ll b = b0+b1+b2;
        ll w = ws[0][b0] + ws[1][b1] + ws[2][b2];
        ll c = cnts[0][b0] * cnts[1][b1] * cnts[2][b2];

        if(chmax(wall[b],w)){
            cntall[b] = c;
        }else if(wall[b]==w){
            cntall[b] += c;
        }
    }

    ll cntans = 0;
    ll num=0,den=1;

    for(ll b=A; b<=B; b++){
        if( num * b < wall[b] * den  ){
            num = wall[b]; den = b;
            cntans = cntall[b];
        }else if(num * b == wall[b] * den){
            cntans += cntall[b];
        }
    }

    double ans = 1.*num/den;

    printf("%.8f\r\n%lli\r\n",ans,cntans);




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
