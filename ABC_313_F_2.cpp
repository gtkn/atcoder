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
constexpr ll llINF = 1LL << 60;
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
    ll N,M;
    cin >> N >> M;

    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vec(ll) X(M),Y(M);
    rep(i,M) cin >> X[i] >> Y[i];

    rep(i,M) X[i]--;
    rep(i,M) Y[i]--;


    vvec(bool) vv(N,vec(bool)(N));
    rep(i,M){
        vv[ X[i] ][ Y[i] ] = true;
        vv[ Y[i] ][ X[i] ] = true;
    }

    rep(i,N){
        if(vv[i][i] && A[i] < B[i]){
            swap(A[i],B[i]);
        }
    }

    rep(i,N) A[i]*=2;
    rep(i,N) B[i]*=2;

    vec(ll) C(N);
    rep(i,N) C[i] = (A[i]+B[i])/2;



    vec(ll) abig,cbig;
    rep(i,N){
        if(A[i] > C[i]) abig.push_back(i);
        else cbig.push_back(i);
    }



    vec(bool) isabig(N);
    rep(i,abig.size()) isabig[ abig[i] ] = true;
    
    vec(bool) usec(N);
    vvec(ll) memo(N);

    rep(i,N)rep(j,i){
        if(!vv[i][j]) continue;
        if(isabig[i] && isabig[j]){
            continue;
        }else if(!isabig[i] && !isabig[j]){
            usec[i] = true;
            usec[j] = true;
        }else if(isabig[i]){
            memo[i].push_back(j);
        }else{
            memo[j].push_back(i);
        }
    }


    // cerr << "memo:" << endl;
    // for (int i = 0; i < N; i++) {
    //     cerr << "memo[" << i << "]: ";
    //     for (int j = 0; j < memo[i].size(); j++) {
    //         cerr << memo[i][j] << " ";
    //     }
    //     cerr << endl;
    // }


    ll nab = abig.size();
    ll ncb = cbig.size();


    ll ans = -llINF;
    // cerr << "nab:" << nab << " ncb:" << ncb << endl;    
    if(nab < ncb){
        // cerr << "nab < ncb" << endl;

        rep(ptn,(1<<nab)){
            vec(bool) uc = usec;
            rep(j,nab){
                if(bit(ptn,j)){
                    uc[ abig[j] ] = true;
                    for(ll k:memo[ abig[j] ]) uc[k] = true;
                }
            }
            ll tmp = 0;
            rep(i,N) tmp += (uc[i]? C[i]:A[i]);
            chmax(ans,tmp);
        }

    }else{
        // cerr << "nab >= ncb" << endl;
        ll nn = (1<<ncb);   
        vvec(ll) dp(nab+1,vec(ll)(nn,-llINF));

        // map<ll,ll> mp;
        vec(ll) mp(N,-1);
        rep(i,ncb) mp[cbig[i]] = i;

        ll st0 = 0;
        for(ll i:cbig){
            if(usec[i]) st0 |= (1<<mp[i]);
        }
        dp[0][st0] = 0;
        rep(i,N) dp[0][st0] += (usec[i]? C[i]:A[i]);


        rep(i,nab){
            rep(j,nn){
                chmax(dp[i+1][j],dp[i][j]);
                if(memo[abig[i]].empty()) continue;

                ll jj = j;
                ll diff = -A[ abig[i] ] + C[ abig[i] ];
                for(ll k:memo[abig[i]]){
                    if(bit(jj,mp[k])) continue;
                    jj |= (1<<mp[k]);
                    diff += C[k] - A[k];
                }
                chmax(dp[i+1][jj],dp[i][j]+diff);
            }
        }

        // cerr << "dp:" << endl;
        // for (int i = 0; i <= nab; i++) {
        //     for (int j = 0; j < nn; j++) {
        //         cerr << dp[i][j] << " ";
        //     }
        //     cerr << endl;
        // }

        // cerr << ans << endl;
        rep(i,nab+1)rep(j,nn) chmax(ans,dp[i][j]);
    }

    printf("%.1f\n",ans/2.0);






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
