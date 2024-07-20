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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N;
    cin >> N;

    auto inzero = [](ll n)->bool{
        while(n){
            if(n%10 == 0) return true;
            n/=10;
        }
        return false;
    };

    auto nrev = [](ll n)->ll{
        ll res = 0;
        while(n){
            res = res*10 + (n%10);
            n/=10;
        }
        return res;
    };

    auto keta = [](ll n)->ll{
        ll res = 0;
        while(n){
            res++;
            n/=10;
        }
        return res;
    };


    // N単体のとき
    if(N==nrev(N) && !inzero(N)){
        cout << N << endl;
        return;
    }


    set<Pll> cand2;
    set<ll> cand1;
    for(ll x=2; x*x<=N; x++){
        if(N%x!=0) continue;

        for(ll y:{x,N/x}){
            if(inzero(y)) continue;
            ll ry = nrev(y);
            if(N%ry!=0) continue;
            cand2.emplace(y,ry);
            if(y==ry) cand1.insert(y);
        }
    }

    ll M = 1000;
    vector<map<ll,string>> dp(M+1); // 全体長さ、全体積、左半分の文字列
    
    dp[0][1] = "";

    rep(sz,1000)for(auto [pr,s]:dp[sz]){
        for(auto [y,ry]:cand2){
            ll sz2 = sz + 2*(keta(y)+1);
            if(sz==0) sz2 = 2*keta(y)+1;
            if(sz2>M) continue; 
            ll pr2 = pr*y*ry;
            if(N%pr2 != 0) continue;
            
            string s2 = s + "*" + to_string(y);
            if(sz==0) s2 = to_string(y);

            if(pr2==N && sz2<=M){
                string rs2 = s2;
                reverse(all(rs2));
                string ans = s2 + "*" + rs2;
                cout << ans << endl;
                return;
            }

            dp[sz2][pr2] = s2;
        }

        for(auto y:cand1){
            ll sz2 = sz + keta(y)+1;
            if(sz==0) sz2 = keta(y);
            if(sz2>M) continue; 
            ll pr2 = pr*y;
            if(N%pr2 != 0) continue;
            
            if(pr2==N && sz2<=M){
                string rs = s;
                reverse(all(rs));
                // cerr << s << " , " << y << " " << rs << endl;
                string ans = s + "*" + to_string(y) + "*" + rs;
                if(sz==0) ans = to_string(y);
                cout << ans << endl;
                return;
            }

        }
    }

    cout << -1 << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
