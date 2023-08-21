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

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll H,W;
    cin >> H >> W;

    vvec(ll) vv(H,vec(ll)(W));
    rep(i,H){
        string S;
        cin >> S;
        rep(j,W) vv[i][j] = (S[j]-'a');
    }

    vvec(ll) hv(H,vec(ll)(26)),wv(W,vec(ll)(26));

    rep(i,H)rep(j,W) hv[i][vv[i][j]]++;
    rep(i,H)rep(j,W) wv[j][vv[i][j]]++;

    vec(ll) hrem(H,W),wrem(W,H);


    rep(_,5000){
        vec(Pll) hmemo,wmemo;

        rep(i,H){
            ll x = -1;
            rep(k,26){
                if(hv[i][k]==hrem[i] && hrem[i]>1) x=k;
            }
            if(x!=-1) hmemo.emplace_back(i,x);
        }



        rep(j,W){
            ll x = -1;
            rep(k,26){
                if(wv[j][k]==wrem[j] && wrem[j]>1) x=k;
            }
            if(x!=-1) wmemo.emplace_back(j,x);
        }


        // cout << "----" << _ << endl;
        // rep(i,H){
        //     cout << "at" << i <<" ;; ";
        //     rep(k,26) cout << hv[i][k] << " ";cout << endl;
        // }
        // rep(j,W){
        //     cout << "at" << j <<" ;; ";
        //     rep(k,26) cout << wv[j][k] << " ";cout << endl;
        // }

        // cout << "hmemo" << endl;
        // for(Pll hm:hmemo) cout << hm.first << " , " << hm.second << endl;

        // cout << "wmemo" << endl;
        // for(Pll wm:wmemo) cout << wm.first << " , " << wm.second << endl;



        if(hmemo.empty() && wmemo.empty()) break;

        for(Pll hm:hmemo){
            ll ii = hm.first, kk = hm.second;            
            hv[ii][kk]=0;
            hrem[ii]=0;
            rep(j,W){
                if(wv[j][kk]>0) wv[j][kk]--;
                if(wrem[j]>0) wrem[j]--;
            }
        }

        for(Pll wm:wmemo){
            ll jj = wm.first, kk = wm.second;            
            wv[jj][kk]=0;
            wrem[jj]=0;
            rep(i,H){
                if(hv[i][kk]>0) hv[i][kk]--;
                if(hrem[i]>0) hrem[i]--;
            }
        }
    }

    ll ans = 0;
    rep(i,H) ans+=hrem[i];
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
