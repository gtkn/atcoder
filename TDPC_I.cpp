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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    string s;
    ll n;
    vvec(string) dp;

    string dfs(ll l,ll r){
        if(dp[l][r]!="x") return dp[l][r];
        string res = s.substr(l, r-l);

        for(ll m = l+1; m<r; m++){
            string a,b;
            a = dfs(l,m);
            b = dfs(m,r);



            reverse(all(b));
            while(a.size()>=1 && b.size()>=1){
                ll na = a.size();
                ll nb = b.size();



                if(na>=2){
                    if(a[na-2]=='i' && a[na-1]=='w' && b[nb-1]=='i'){
                        a.pop_back();a.pop_back();b.pop_back();
                        continue;
                    }
                }
                if(nb>=2){
                    if(b[nb-2]=='i' && b[nb-1]=='w' && a[na-1]=='i'){
                        a.pop_back();b.pop_back();b.pop_back();
                        continue;
                    }
                }
                break;
            }
            reverse(all(b));
            a+=b;
            if(res.size() >= a.size()) res = a;
            //cout << l <<" , "<< m << " , " << r << " : " << a <<", " << b << endl;
        }

        dp[l][r]=res;
        return res;
    }
        

    void solve(){
        cin >> s;
        n = s.size();

        dp = vvec(string)(n+1,vec(string)(n+1,"x"));
        rep(i,n) dp[i][i+1] = s[i];

        string ss = dfs(0,n);
        ll ans = (s.size()-ss.size())/3;
        cout << ans << endl;
        //cout << ss << endl;






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
