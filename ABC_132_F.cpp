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
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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
//---ベクトルとか行列の掛け算---
    vvec(mint) vvxvv(vvec(mint) const& vv1, vvec(mint) const& vv2){
        ll h,w,d;
        h = vv1.size(); w=vv1[0].size(); d=vv2[0].size();
        assert(w==vv2.size());

        vvec(mint) res(h,vec(mint)(d));
        rep(i,h)rep(j,d)rep(k,w) res[i][j]+=vv1[i][k]*vv2[k][j];
        return res;
    }


    vec(mint) vvxv(vvec(mint) const& vv, vec(mint) const& v){
        ll h,w;
        h = vv.size(); w=vv[0].size();
        assert(w==v.size());

        vec(mint) res(h);
        rep(i,h)rep(j,w) res[i]+=vv[i][j]*v[j];
        return res;
    }

    mint vxv(vec(mint) const& v1, vec(mint) const& v2){
        ll h;
        h = v1.size();
        assert(h==v2.size());

        mint res=0;
        rep(i,h) res+=v1[i]*v2[i];
        return res;
    }

    // lxlの2次元正方行列のn乗
    vvec(mint) vvpow(vvec(mint) vv, ll n){
        ll l = vv.size();
        assert(vv[0].size()==l);

        vvec(mint) res(l,vec(mint)(l));
        rep(i,l) res[i][i]=1;

        while(n){
            if(n&1) res = vvxvv(vv, res);
            vv = vvxvv(vv,vv);
            n >>= 1;
        }
        return res;

    };

 
    void solve(){
        ll N,K;
        cin >> N >> K;


        map<ll,ll> m;

        ll st = 1;
        while(st<=N){
            ll a = N/st;
            ll l = st, r=N+1;
            while(r-l>1){
                ll mid = (l+r)/2;
                if(N/mid!=a) r=mid;
                else l=mid;
            }
            m[a] = r-st;
            st = r;
        }

        vec(Pll) memo;
        for(auto mi:m){
            memo.push_back(mi);
        }
        // for(Pll mi:memo) cout << mi.first << " " << mi.second << endl;

        ll nn = memo.size();
        
        map<ll,ll> rev;
        rep(i,nn) rev[memo[i].first] = i;


        vvec(mint) dp(K+1,vec(mint)(nn));
        dp[0][rev[N]]=1;

        rep(i,K){
            vec(mint) cum(nn);
            rep(j,nn){
                // cout << j << " ; " << memo[j].first << " , " << N/memo[j].first << endl;
                cum[ rev[N/memo[j].first] ]+=dp[i][j];
            }
            mint tmp = 0;
            rep(j,nn){
                tmp += cum[j];
                dp[i+1][j] = tmp*memo[j].second;
            }
        }

        mint ans = 0;
        rep(j,nn) ans+=dp[K][j];
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
