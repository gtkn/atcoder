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
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


ll dp[60][60][60][60];

vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

using arr = array<ll,5>;

void solve(){
    ll N;
    cin >> N;

    vvec(bool) vv(N,vec(bool)(N));
    Pll p0 = {-1,-1},p1;

    rep(i,N){
        string S;
        cin >> S;

        rep(j,N){
            if(S[j]=='#') vv[i][j]=false;
            if(S[j]=='.') vv[i][j]=true;
            if(S[j]=='P'){
                if(p0.first==-1){
                    p0 = {i,j};
                }else{
                    p1 = {i,j};
                }
                vv[i][j] = true;
            }
        }
    }

    rep(i0,60)rep(i1,60)rep(i2,60)rep(i3,60) dp[i0][i1][i2][i3] = llINF;
    ll ans = llINF;

    queue<arr> q;
    // priority_queue<arr> q;
    auto qpush = [&](ll c, Pll a, Pll b)->void{
        // cerr << c << " : " << a.first << " , " << a.second << " ,, " << b.first << ", " << b.second << nl;
        if(chmin(dp[a.first][a.second][b.first][b.second], c)){
            // q.emplace(c, a.first, a.second, b.first, b.second);
            q.push( {c, a.first, a.second, b.first, b.second} );
            if(a==b) chmin(ans,c);
        }
    };
    qpush(0,p0,p1);


    while(!q.empty()){
        auto [c0, ah, aw, bh, bw] = q.front();
        q.pop();

        if(c0 > dp[ah][aw][bh][bw]) continue;
        rep(k,4){
            ll ahh = ah + dh[k];
            ll aww = aw + dw[k];
            ll bhh = bh + dh[k];
            ll bww = bw + dw[k];

            // cerr <<k << "! " << ahh << ", " << aww << " ,, " << bhh << " , " << bww << nl;

            if(ahh<0 || ahh>=N  || aww<0 || aww>=N){
                ahh = ah;
                aww = aw;
            }else if(!vv[ahh][aww]){
                ahh = ah;
                aww = aw;
            }


            if(bhh<0 || bhh>=N || bww<0 || bww>=N){
                bhh = bh;
                bww = bw;
            }else if(!vv[bhh][bww]){
                bhh = bh;
                bww = bw;
            }

            qpush(c0+1, {ahh,aww}, {bhh,bww});
        }
    }

    if(ans>=llINF) ans = -1;
    cout << ans << nl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
