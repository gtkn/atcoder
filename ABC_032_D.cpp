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


// N<=30
ll solve1(ll N,ll W, const vec(ll)& v,const vec(ll)& w){
    ll a = N/2;
    ll b = N-a;

    vec(Pll) va,vb;

    rep(pt,(1<<a)){
        ll vtot=0, wtot=0;
        rep(i,a){
            if(bit(pt,i)){
                vtot += v[i];
                wtot += w[i];
            }
        }
        va.emplace_back(wtot, vtot);
    };


    rep(pt,(1<<b)){
        ll vtot=0, wtot=0;
        rep(i,b){
            if(bit(pt,i)){
                vtot += v[a+i];
                wtot += w[a+i];
            }
        }
        vb.emplace_back(wtot, vtot);
    };

    // vb.emplace_back(llINF,llINF);

    sort(all(va));
    sort(all(vb));

    ll bnn = (1<<b);
    vec(ll) vbmax(bnn+1);
    rep(i,bnn) vbmax[i+1] = max(vbmax[i], vb[i].second);

    // for(Pll x:va) cout << x.first << "," << x.second << " : "; cout << endl;
    // for(Pll x:vb) cout << x.first << "," << x.second << " : "; cout << endl;
    // rep(i,bnn+1) cout << vbmax[i] << " "; cout << endl;

    ll res = 0;
    for(Pll ai:va){
        while(!vb.empty() && vb.back().first + ai.first > W) vb.pop_back();
        if(vb.empty()) break;
        chmax(res, ai.second + vbmax[vb.size()]);
        // if(!vb.empty()) cout << ai.first << "," << ai.second << " and " << vb.back().first << " , " << vbmax[vb.size()] << ", " << vb.size()<< endl;
    }

    return res;
};


ll solve11(ll N,ll W, const vec(ll)& v,const vec(ll)& w){
    ll res = 0;
    ll respt = 0;
    rep(pt,(1<<N)){
        ll vtot=0, wtot=0;
        rep(i,N){
            if(bit(pt,i)){
                vtot += v[i];
                wtot += w[i];
            }
        }
        if(wtot<=W) if(chmax(res,vtot)) respt = pt;
    };

    rep(i,N) cout << bit(respt,i) << " "; cout << endl; 

    return res;
}



// sum(w) <= 200*1000
ll solve2(ll N,ll W, const vec(ll)& v,const vec(ll)& w){
    vec(ll) dp(W+1,-1);
    dp[0] = 0;

    rep(i,N){
        repr(j,W+1){
            if(dp[j]<0) continue;
            ll jj = j+w[i];
            if(jj<=W) chmax(dp[jj], dp[j]+v[i]);
        }
    }

    ll res = 0;
    rep(i,W+1) chmax(res,dp[i]);
    return res;

}


// sum(v) <= 200*1000
ll solve3(ll N,ll W, const vec(ll)& v,const vec(ll)& w){

    ll vmax = 0;
    rep(i,N) vmax += v[i];


    vec(ll) dp(vmax+1,llINF);
    dp[0]=0;

    rep(i,N){
        repr(j,vmax+1){
            if(dp[j]>=llINF) continue;
            ll jj = j + v[i];
            if(jj<=vmax) chmin(dp[jj], dp[j]+w[i]);
        }
    }

    ll res = 0;
    rep(i,vmax+1) if(dp[i]<=W) chmax(res,i);

    return res;

}



void solve(){
    ll N,W;
    cin >> N >> W;

    vec(ll) v(N),w(N);
    rep(i,N) cin >> v[i] >> w[i];

    ll ans;
    if(N<=30) ans = solve1(N,W,v,w);
    else if(W<=200000) ans = solve2(N,W,v,w);
    else ans = solve3(N,W,v,w);

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
