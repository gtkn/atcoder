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

struct Solver{

    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll H,W;
        cin >> H >> W;

        vvec(bool) vv(H,vec(bool)(W));
        rep(i,H){
            string s;
            cin >> s;
            rep(j,W) vv[i][j] = (s[j]=='.');
        }



        ll ans = 0;
        rep(h0,H)rep(w0,W){
            vvec(ll) dp(H,vec(ll)(W,llINF));

            queue<Pll> q;
            auto qpush = [&](ll h,ll w,ll c){
                if(h<0 || h>=H || w<0 || w>=W) return;
                if(!vv[h][w]) return;
                if(chmin(dp[h][w],c)){
                    q.emplace(h,w);
                    chmax(ans,c);
                }
            };

            qpush(h0,w0,0);
            while(!q.empty()){
                Pll q0 = q.front();
                q.pop();
                ll cc = dp[q0.first][q0.second]+1;
                rep(di,4) qpush(q0.first+dh[di], q0.second+dw[di],cc);
            }

            // cout << "----" << h0 <<" ," <<w0 << endl;
            // rep(i,H){
            //     rep(j,W) cout << (dp[i][j]==llINF? 0 : dp[i][j]) << " "; cout << endl;
            // }

        }

        cout << ans << endl;

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
