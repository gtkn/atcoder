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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    ll H,W;

    ll f(ll a,ll b){
        return (a>>(2*b)) & 3;
    }


    // nowの次にbwが来たらどのindexに対応するか
    ll chk(ll now,ll bw){
        if(now==0) return -1;
        rep(i,W-1) if(f(now,i)>0 && f(now,i+1)>0 && f(now,i)!=f(now,i+1)) return -1;
        //bool isok = false;
        //rep(i)


        dsu d(2*H);
        rep(i,H){
            if(i && f(now,i) && f(now,i-1)) d.merge(i,i-1);
            if(i) if(bit(bw,i) && bit(bw,i-1)) d.merge(i+H, i+H-1);
            if(f(now,i)>0 && bit(bw,i)) d.merge(i,i+H);
        }
        rep(i,H)rep(j,i) if( f(now,i) && f(now,i)==f(now,j) ) d.merge(i,j);

        vec(ll) v(H);

        auto iswhilte = [&](ll n){
            if(n<H) return (f(now,n)==0); 
            else return !bit(bw,n);
        };


        for(auto gi:d.groups()){
            if(gi.size()==1 && iswhilte(gi[0])) continue;
            ll idx = llINF;
            for(ll x:gi) if(x<H) chmin(idx,f(now,x));

            if(idx==llINF || idx==0) continue;
            //if(idx>3) cout << idx << "???" << endl;
            
            for(ll x:gi) if(x>=H) v[x-H] = idx;
        }

        vec(bool) used(4);
        for(ll vi:v) used[vi]=true;
        if(!used[1]) return -1;
        ll aaa = 3;
        if(!used[2]) aaa = 2;


        for(auto gi:d.groups()){
            if(gi.size()==1 && iswhilte(gi[0])) continue;
            bool isnow = true;
            for(ll x:gi) if(x<H) isnow=false;

            if(!isnow) continue;
            
            for(ll x:gi) if(x>=H) v[x-H] = aaa;
            aaa++;
        }


        ll res = 0;
        repr(i,H) res = (res<<2) + v[i];


        return res;
    }


    //---ベクトルとか行列の掛け算---
    vec(mint) vvxv(vvec(mint) const& vv, vec(mint) const& v){
        ll h,w;
        h = vv.size(); w=vv[0].size();
        assert(w==v.size());

        vec(mint) res(h);
        rep(i,h)rep(j,w) res[i]+=vv[i][j]*v[j];
        return res;
    }





    void solve(){
        cin >> H >> W;

        map<ll,ll> m;
        ll cnt = 0;

        ll h2 = 1<<(2*H);
        ll h1 = 1<<H;
        vvec(ll) vv(h2,vec(ll)(h1));


        rep(i,h2){
            rep(j,h1){
                vv[i][j] = chk(i,j);
            }
        }

        vvec(mint) dp(W+1,vec(mint)(h2));
        dp[0][1]=1;

        rep(n,W){
            rep(i,h2)rep(j,h1){
                if(vv[i][j]>=0) dp[n+1][vv[i][j]] += dp[n][i];
            }
        }

        mint ans = 0;
        rep(i,h2) if(f(i,H-1)==1) ans += dp[W][i];

        cout << ans.val() << endl;




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
