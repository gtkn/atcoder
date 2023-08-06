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

using Plm = pair<ll,mint>;



vector<pair<char,ll>> RunLengthEncoding(string& S){
    vector<pair<char,ll>> res;
    if(S.empty()) return res;

    char now = S[0];
    ll cnt=0;
    for(char si:S){
        if(si!=now){
            res.emplace_back(now,cnt);
            now = si;
            cnt = 0;
        }
        cnt++;
    }
    res.emplace_back(now,cnt);
    return res;
}





void solve(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    rep(i,N-1){
        if(S[i]!='1' && S[i+1]!='1') dame;
    }


    auto rle = RunLengthEncoding(S);

    ll pre = 0;
    mint ans = 0;
    while(!rle.empty()){
        auto now = rle.back();
        rle.pop_back();

        mint n = now.second;
        if(now.first == '1'){
            n += (pre-1)*ans;
            ans += n;
        }else{
            ans++;
        }
        pre = now.first-'0';
    }
    ans--;

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
