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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
    string R,C;
    cin >> R >> C;

    vec(string) cand;

    rep(ptn,(1<<(2*N))){
        string s;
        ll tmp = ptn;
        vec(ll) cnt(4);
        rep(_,N){
            ll x = tmp%4;
            char c = 'A'+x;
            if(x==3) c='.';
            s += c;
            cnt[x]++;
            tmp /= 4;
        }
        bool isok = true;
        rep(i,3) if(cnt[i]!=1) isok = false;
        if(isok) cand.push_back(s);
    }

    // cerr << cand.size() << endl;

    ll M = 1<<(3*N);
    string xx = "xx";
    vvec(string) dp(N+1,vec(string)(M,xx));
    vvec(ll) g(N+1,vec(ll)(M,-1));
    dp[0][0] = "";

    rep(i,N)rep(j,M){
        if(dp[i][j] == xx) continue;
        for(string s:cand){
            char fst = '.';
            for(char c:s){
                if(c=='.') continue;
                fst = c;
                break;
            }
            if(fst != R[i]) continue;

            ll jj = j;
            rep(k,N){
                if(s[k]=='.') continue;
                vec(bool) used(3);
                used[0] = bit(j,3*k);
                used[1] = bit(j,3*k+1);
                used[2] = bit(j,3*k+2);
                if(!used[0] && !used[1] && !used[2]){
                    if(s[k]!=C[k]){
                        jj = -1;
                        break;
                    }
                }
                jj = jj | (1<<(3*k + (s[k]-'A')));
            }

            if(jj<0) continue;
            dp[i+1][jj] = s;
            g[i+1][jj] = j;
        }
    }

    if(dp[N][M-1] == xx) sayno;

    vec(string) ans;
    ll now = M-1;
    repr(i,N){
        ans.push_back(dp[i+1][now]);
        now = g[i+1][now];
    }
    reverse(all(ans));

    cout << "Yes" << endl;
    for(string s:ans) cout << s << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
