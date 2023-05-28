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
 
    void solve(){
        ll N;
        cin >> N;

        vvec(ll) g(N);
        rep(_,N-1){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        string S;
        cin >> S;

        bool isok = true;
        vec(ll) ans(N,-1);
        vec(ll) vs(N);
        rep(i,N) vs[i] = (S[i]=='B'? 0 : 1);

        auto dfs = [&](auto dfs, ll now, ll frm) -> ll{
            ll res = -1; //mitei

            vec(ll) bw(2);

            for(ll nxt:g[now]){
                if(nxt==frm) continue;

                ll tmp = dfs(dfs, nxt, now);
                if(ans[now]==-1) ans[now]=tmp;
                else{
                    if(ans[now]!=tmp && tmp!=-1) isok=false;
                }

                if(ans[nxt]==-1){
                    ans[nxt] = vs[now];
                }
                bw[ans[nxt]]++;                
            }


            if(bw[0]==bw[1]){
                res = vs[now];
            }
            if(bw[vs[now]] < bw[1-vs[now]]) isok=false;

            // cout << now << " <- " << frm << " ; " << bw[0] <<" : " << bw[1] << ", " << res << endl;  

            return res;
        };

        dfs(dfs, 0, 0);

        if(!isok) dame;


        // rep(i,N) cout << ans[i] << " "; cout << endl;
        // rep(i,N){
        //     if(ans[i]!=vs[i]){
        //         cout << i << " : " << ans[i] << " , " << vs[i] << endl;
        //         if(ans[i]==-1) ans[i] = vs[i];
        //     }
        // }

        rep(i,N) cout << (ans[i]==0? 'B' : 'W'); cout << endl;





    }
};



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
