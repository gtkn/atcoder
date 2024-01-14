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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    int H,W;
    cin >> H >> W;

    vvec(int) S(H,vec(int)(W));
    rep(i,H)rep(j,W) cin >> S[i][j];
    rep(i,H)rep(j,W) S[i][j]--;


    vvec(int) sol(H,vec(int)(W));
    rep(i,H)rep(j,W) sol[i][j] = i*W+j;

    
    map<vvec(int),int> used;

    auto f1 = [&](auto f1, const vvec(int)& vv, int prev, int cnt)->void{
        if(used.find(vv) == used.end()){
            used[vv] = cnt;
        }else{
            chmin(used[vv],cnt);
        }
        if(cnt==10) return;

        // if(vv==sol) cout << "sol ; " << cnt << endl;

        // cout << cnt << " ---- " << prev << endl;
        // rep(i,H){
        //     rep(j,W) cout << vv[i][j] << " "; cout << endl;
        // }

        rep(t,4){
            if(prev==t) continue;

            int x,y;
            x = t%2; y = t/2;
            // cout << x << " ," << y << "!!!" << endl;

            vvec(int) zz = vv;
            rep(i,H-1)rep(j,W-1) zz[H-2-i+x][W-2-j+y] = vv[i+x][j+y];
            f1(f1,zz,t,cnt+1);
        }
    };

    f1(f1,S,-1,0);

    int ans = 100;


    auto f2 = [&](auto f2, const vvec(int)& vv, int prev, int cnt)->void{
        if(used.find(vv)!=used.end()){
            // cout << "found : " << used[vv] << " , " << cnt << endl;
            chmin(ans, used[vv]+cnt);
        }

        if(cnt==10) return;

        rep(t,4){
            if(prev==t) continue;

            int x,y;
            x = t%2; y = t/2;

            vvec(int) zz = vv;
            rep(i,H-1)rep(j,W-1){
                int xx = H-2+x-i, yy = W-2+y-j;
                // if(xx < 0 || xx>=H ) cout << xx << "," << i << " , " << x << endl;
                // if(yy < 0 || yy>=W ) cout << yy << "," << j << " , " << y << endl;

                zz[xx][yy] = vv[i+x][j+y];
            }
            f2(f2,zz,t,cnt+1);
        }
    };

    f2(f2,sol,-1,0);

    if(ans>20) ans = -1;
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
