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

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
//using tri = array<ll,3>;

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
        ll H,W,T;
        cin >> H >> W >> T;


        vec(string) A(H);
        rep(i,H) cin >> A[i];

        ll sx,sy,gx,gy;
        vec(Pll) v;
        rep(i,H)rep(j,W){
            if(A[i][j]=='S'){
                sx = i; sy=j;
            }
            if(A[i][j]=='G'){
                gx = i; gy = j;
            }
            if(A[i][j]=='o'){
                v.emplace_back(i,j);
            }
        }

        ll M = v.size();
        v.emplace_back(sx,sy);
        v.emplace_back(gx,gy);

        ll N = M+2;



        vvec(ll) dist(N,vec(ll)(N));
        
        rep(st,N){
            queue<Pll> q;
            vvec(ll) dp(H,vec(ll)(W,llINF));
            auto qpush = [&](ll h,ll w, ll c){
                if(h<0 || h>=H || w<0 || w>=W) return;
                if(A[h][w]=='#') return;
                if(chmin(dp[h][w], c)) q.emplace(h,w);
            };

            qpush(v[st].first, v[st].second, 0);
            while(!q.empty()){
                ll h0,w0;
                tie(h0,w0) = q.front();
                q.pop();

                rep(di,4){
                    ll h1 = h0 + dh[di], w1 = w0 + dw[di];
                    qpush(h1,w1,dp[h0][w0]+1);
                }

            }

            rep(i,N){
                ll h,w; tie(h,w) = v[i];
                dist[st][i] = dp[h][w];
            }
        }

        if(dist[M][M+1] >  T) dame; 

        // rep(i,N){
        //     rep(j,N) cout << dist[i][j] << " "; cout << endl;
        // }



        vvec(ll) dpp(1<<M, vec(ll)(M,llINF) );
        rep(i,M) dpp[(1<<i)][i] = dist[M][i];
        rep(state, (1<<M))rep(now,M){
            if(dpp[state][now]>T) continue;
            rep(nxt,M){
                if(bit(state,nxt)) continue;
                chmin(dpp[state+(1<<nxt)][nxt], dpp[state][now]+dist[now][nxt]);
            }
        }

        ll ans = 0;
        rep(st,(1<<M))rep(now,M){
            if(dpp[st][now] + dist[now][M+1] <= T){
                // cout << st << " : " <<  dpp[st][now] << endl;
                chmax(ans, (ll)__builtin_popcount(st));
            }
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
