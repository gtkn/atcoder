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

ll solve(string S,ll K){
    // string S;
    // cin >> S;
    // ll K; cin >> K;
    ll N = S.size();

    vvec(ll) dp(N+1,vec(ll)(N+1,llINF));

    // rep(r,N+1)rep(l,r+1) dp[l][r] = r-l;

    // vvec(bool) used(N+1,vec(bool)(N+1));


    auto f = [&](auto f, ll l, ll r)->ll{
        // cout << l << " , " << r << endl;
        if(dp[l][r]<llINF) return dp[l][r];
        dp[l][r] = r-l;


        if(S[l]=='o'){
            for(ll m=l; m<r; m++){
                if(S[m]!='f') continue;
                if(f(f,l+1, m)!=0) continue;
                chmin(dp[l][r], max(f(f,m+1,r)- K,0LL) );
            }
        }

        for(ll m=l+1; m<r; m++){
            if(S[m]!='o') continue;
            chmin(dp[l][r],  f(f, l, m) + f(f, m, r)  );
        }

        return dp[l][r];            
    };

    // cout << f(f,0,N) << endl;
    


    ll ans = f(f,0,N);

    rep(l,N+1){
        rep(r,N+1) cout << (dp[l][r]>=2*N? -1 : dp[l][r]) << " "; cout << endl;
    }



    return ans;

}

ll solve_botu(string S,ll K){

    // string S;
    // cin >> S;
    // ll K;
    // cin >> K;

    ll N = S.size();

    vvec(ll) dp(N+1,vec(ll)(N+2,llINF));
    dp[0][0]=0;

    rep(i,N)rep(j,N+1){

        if(S[i]=='o'){
            chmin(dp[i+1][j+1], dp[i][j]+1);
        }else if(S[i]=='f'){
            if(j==0){
                chmin(dp[i+1][0], dp[i][j]+1);
            }else{
                rep(k,K+1){
                    if(i+1+k>N) break;
                    chmin(dp[i+1+k][j-1], dp[i][j]-1);
                }
            }
        }else{
            chmin(dp[i+1][0], dp[i][j]+1);
        }
    }


    ll ans = N;
    for(ll x:dp[N]) chmin(ans,x);

    // cout << ans << endl;

    rep(l,N+1){
        rep(r,N+1) cout << (dp[l][r]>=2*N? -1 : dp[l][r]) << " "; cout << endl;
    }

    return  ans;

}

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}

int main(){
    int testcasenum=100;

    string S;
    ll K,N;

    auto f = [&](){
        N = RandInt(1,51);
        K = RandInt(0,N-1);

        S = "";
        rep(_,N){
            ll x = RandInt(0,2);
            if(x==0) S += 'o';
            if(x==1) S += 'f';
            if(x==2) S += 'x';
        }
    };


    rep1(ti,testcasenum){
        // f();
        S = "xxoxxofoffxxfo";
        K = 4;
        cout << "--- 0" << endl;
        ll a0 = solve(S,K);
        cout << "--- 1" << endl;
        ll a1 = solve_botu(S,K);

        // cout << S << " , " << K << endl;
        if(a0!=a1){
            cout <<"ng : "<< a0 << " , " << a1 << endl;
            cout << S << " , " << K << endl;
            break;
        }
    }
    return 0;
}
