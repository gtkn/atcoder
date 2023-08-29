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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



void solve(){
    ll L,R;
    cin >> L >> R;



    auto f = [](const ll a,const ll b)->mint{
        // x<a, y<b

        ll nn = 60;

        ll an=-1,bn=-1;
        repr(i,nn){
            if(bit(a,i)){
                an=i;
                break;
            }
        }
        repr(i,nn){
            if(bit(b,i)){
                bn=i;
                break;
            }
        }
        assert(an>=0);
        assert(bn>=0);

        // cout << "anbn : " << an << " " << bn<< " / " << a << " "<< b << endl;

        vvec(mint) dp(nn+1,vec(mint)(4));
        rep(i,min(an,bn)) dp[i][3]=1;
        if(an==bn) dp[an][0]=1;
        else if(an<bn) dp[an][2]=1;
        else if(an>bn) dp[bn][1]=1;


        repr(i,nn)rep(j,4)rep(k,3){
            ll aok=(bit(j,0)), bok=(bit(j,1));

            ll xadd,yadd;
            if(k==0) xadd=0, yadd=0;
            if(k==1) xadd=0, yadd=1;
            if(k==2) xadd=1, yadd=1;
            
            

            ll aok2,bok2;
            ll abit=bit(a,i), bbit=bit(b,i);

            if(aok==1) aok2=1;
            else{
                if(xadd==abit) aok2=0;
                else if(xadd==0 && abit==1) aok2=1;
                else continue;
            }
            if(bok==1) bok2=1;
            else{
                if(yadd==bbit) bok2=0;
                else if(yadd==0 && bbit==1) bok2=1;
                else continue;
            }

            // if(a==4 && b==4 && i==0){
            //     cout << aok << " " << bok << " " << xadd << " " << yadd << " " <<aok2 << " " << bok2 << endl;
            // }

            dp[i][bok2*2+aok2] += dp[i+1][j];
        }

        return dp[0][3];
    };

    R++;
    mint ans = f(R,R) - f(L,R) - f(R,L) + f(L,L);

    // cout << "=---" << endl;
    // cout << f(R,R).val() << endl;
    // cout << f(L,R).val() << endl;
    // cout << f(R,L).val() << endl;
    // cout << f(L,L).val() << endl;

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
