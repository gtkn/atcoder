//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

vec(ll) dh = {1,0,-1,0,1,1,-1,-1};
vec(ll) dw = {0,1,0,-1,1,-1,1,-1};

void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(bool) vv(H,vec(bool)(W));
    rep(i,H){
        string S;
        cin >> S;
        rep(j,W) vv[i][j] = (S[j]=='#');
    }


    vvec(ll) a(H,vec(ll)(W,-1));
    ll cnt = 0;

    rep(i,H)rep(j,W){
        if(!vv[i][j]) continue;
        if(a[i][j]>=0) continue;

        queue<Pll> q;
        q.emplace(i,j);


        while(!q.empty()){
            auto [h,w] = q.front();
            q.pop();

            if(a[h][w]!=-1) continue;
            a[h][w] = cnt;

            rep(k,8){
                ll hh,ww;
                hh = h+dh[k];
                ww = w+dw[k];

                if(hh<0 || hh>=H || ww<0 || ww>=W) continue;
                if(vv[hh][ww] && a[hh][ww]==-1) q.emplace(hh,ww);
            }
        }

        cnt++;
    }

    cout << cnt << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
