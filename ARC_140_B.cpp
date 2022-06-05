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

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N;
        cin >> N;
        string S; cin >> S;

        vec(ll) v;
        ll one = 0;
        rep(i,N){
            if(S[i]!='R') continue;
            ll l=0,r=0;
            for(ll j=i-1; j>=0; j--){
                if(S[j]=='A') l++;
                else break;
            }
            for(ll j=i+1; j<N ; j++){
                if(S[j]=='C') r++;
                else break;
            }
            chmin(l,r);
            if(l==1) one++;
            if(l>1) v.push_back(l);
        }

        sort(all(v),greater<ll>());

        ll ans = 0;
        while(1){
            // odd
            if(!v.empty()){
                v.back()--;
                ans++;
                if(v.back()==1){
                    v.pop_back();
                    one++;
                }
            }else{
                if(one==0) break;
                one--;
                ans++;
            }


            // even
            if(one>0){
                one--;
                ans++;
            }else{
                if(!v.empty()){
                    v.pop_back();
                    ans++;
                }else break;
            }
        }
        cout << ans << endl;


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
