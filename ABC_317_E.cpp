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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(char) vv(H,vec(char)(W));
    rep(i,H){
        string s;
        cin >> s;
        rep(j,W) vv[i][j] = s[j];
    }


    ll sh,sw,gh,gw;
    rep(i,H)rep(j,W){
        if(vv[i][j]=='S'){
            sh = i; sw = j;
            vv[i][j]='.';
        }
        if(vv[i][j]=='G'){
            gh = i; gw = j;
            vv[i][j]='.';
        }
    }


    auto chk = [&](ll ii,ll jj){
        if(ii<0 || ii>=H || jj<0 || jj>=W) return false;

        char c = vv[ii][jj];
        if(c=='>') return false;
        if(c=='v') return false;
        if(c=='<') return false;
        if(c=='^') return false;
        if(c=='#') return false;
        return true;
    };



    rep(i,H)rep(j,W){
        ll dh=0,dw=0;
        if(vv[i][j]=='>') dw=1;
        if(vv[i][j]=='v') dh=1;
        if(vv[i][j]=='<') dw=-1;
        if(vv[i][j]=='^') dh=-1;

        if(dh==0 && dw==0) continue;

        ll h=i+dh,w=j+dw;
        while(chk(h,w)){
            vv[h][w] = '!';
            h += dh;
            w += dw;
        }
    }


    vvec(ll) dp(H,vec(ll)(W,llINF));
    queue<Pll> q;
    auto qpush = [&](ll ii,ll jj, ll dd){
        if(ii<0 || ii>=H || jj<0 || jj>=W) return;
        if(vv[ii][jj] == '.'){
            if(chmin(dp[ii][jj], dd)) q.emplace(ii,jj);
        }
    };

    qpush(sh,sw,0);
    while(!q.empty()){
        auto [h,w] = q.front(); q.pop();
        qpush(h+1, w, dp[h][w]+1);
        qpush(h, w+1, dp[h][w]+1);
        qpush(h-1, w, dp[h][w]+1);
        qpush(h, w-1, dp[h][w]+1);
    }

    ll ans = dp[gh][gw];
    if(ans>=llINF) ans = -1;
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
