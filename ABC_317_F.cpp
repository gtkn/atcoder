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

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N, A1, A2, A3;
    cin >> N >> A1 >> A2 >> A3;

    ll ni=60, nj=(1<<3), nk=(A1*A2*A3);
    vvvec(mint) dp(ni+1,(vvec(mint)(nj,vec(mint)(nk))));
    dp[ni][0][0]=1;

    repr(i,ni)rep(j,nj)rep(k,nk){
        ll b1,b2,b3;
        b1 = bit(j,0);
        b2 = bit(j,1);
        b3 = bit(j,2);


        ll r1,r2,r3;
        ll rr = k;
        r1 = rr%A1; rr/=A1;
        r2 = rr%A2; rr/=A2;
        r3 = rr;


        rep(l,4){
            ll now1=0, now2=0, now3=0;
            if(l==1) now2=1, now3=1;
            if(l==2) now3=1, now1=1;
            if(l==3) now1=1, now2=1;

            ll nb = bit(N,i);

            ll c1=1,c2=1,c3=1;


            if(b1==0 && nb==0 && now1==1) continue;
            if(b2==0 && nb==0 && now2==1) continue;
            if(b3==0 && nb==0 && now3==1) continue;

            if(nb==now1 && b1==0) c1=0;
            if(nb==now2 && b2==0) c2=0;
            if(nb==now3 && b3==0) c3=0;

            ll jj = (c3<<2) + (c2<<1) + (c1);

            ll t1=r1,t2=r2,t3=r3;
            if(now1==1) t1 = (r1+(1LL<<i))%A1;
            if(now2==1) t2 = (r2+(1LL<<i))%A2;
            if(now3==1) t3 = (r3+(1LL<<i))%A3;

            ll kk = t3*A1*A2 + t2*A1 + t1;
            
            if(jj<0 || jj>=nj || kk < 0 ||  kk>=nk){
                cout << jj << " " << kk << endl;
                cout << t1 << " " << t2 << " " << t3 << endl;
            }

            dp[i][jj][kk] += dp[i+1][j][k];
        }

    }

    mint ans = 0;
    rep(j,nj) ans += dp[0][j][0];

    ans -= 1;
    ans -= N/( A1*A2/(__gcd(A1,A2)) );
    ans -= N/( A2*A3/(__gcd(A2,A3)) );
    ans -= N/( A3*A1/(__gcd(A3,A1)) );


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
