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
using mint = modint998244353;


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

vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};


void solve(){
    ll H,W;
    cin >> H >> W;

    vec(string) S(H);
    rep(i,H) cin >> S[i];

    vvec(ll) vv(H,vec(ll)(W,-1));
    ll cnt = 0;

    rep(i,H)rep(j,W){
        if(S[i][j]=='.') continue;
        if(vv[i][j]>=0) continue;

        queue<Pll> q;
        q.emplace(i,j);

        while(!q.empty()){
            auto [h0,w0] = q.front();
            q.pop();
            if(vv[h0][w0]>=0) continue;
            vv[h0][w0] = cnt;

            rep(k,4){
                ll h1=h0+dh[k], w1=w0+dw[k];
                if(h1<0 || h1>=H || w1<0 || w1>=W) continue;
                if(S[h1][w1]=='.') continue;
                q.emplace(h1,w1);
            }
        }
        cnt++;
    }


    // rep(i,H){
    //     rep(j,W) cout << vv[i][j] << " ";
    //     cout << endl;
    // }


    mint ans = 0, rcnt=0;

    rep(h0,H)rep(w0,W){
        if(S[h0][w0]=='#') continue;
        rcnt++;

        set<ll> s;
        
        rep(k,4){
            ll h1=h0+dh[k], w1=w0+dw[k];
            if(h1<0 || h1>=H || w1<0 || w1>=W) continue;
            if(vv[h1][w1]==-1) continue;
            s.insert(vv[h1][w1]);
        }
    
        ans += (cnt - s.size()+1);
    }
    ans /= rcnt;

    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
