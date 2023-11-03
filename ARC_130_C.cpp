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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    string a,b;
    cin >> a >> b;

    vec(ll) acnt(10),bcnt(10);
    for(char c:a) acnt[c-'0']++;
    for(char c:b) bcnt[c-'0']++;


    vvec(ll) ans(2);
    for(char c:a) ans[0].push_back(c-'0');
    for(char c:b) ans[1].push_back(c-'0');
    ll totmin=llINF;

    auto f =[](vec(ll) va,vec(ll) vb, ll a0){
        vvec(ll) res = vvec(ll)(2);
        if(va[a0]==0) return res;

        for(ll bi=10-a0; bi<=9; bi++){
            if(vb[bi]==0) continue;
            res[0].push_back(a0);
            res[1].push_back(bi);
            va[a0]--;
            vb[bi]--;
            break;
        }
        if(res[0].empty()) return res;

        rep1(ai,9)rep1(bi,9){
            if(ai+bi<9) continue;
            while(va[ai]>0 && vb[bi]>0){
                res[0].push_back(ai);
                res[1].push_back(bi);
                va[ai]--;
                vb[bi]--;
            }
        }

        rep1r(x,9) rep(_,va[x]) res[0].push_back(x);
        rep1r(x,9) rep(_,vb[x]) res[1].push_back(x);

        return res;
    };

    auto f2 = [](vvec(ll) vv){
        if(vv[0].empty()) return llINF;

        ll n = max(vv[0].size(), vv[1].size());
        rep(i,2) vv[i].resize(n);
        // rep(i,2) while(vv[i].size()<n) vv[i].push_back(0);

        ll res = 0;
        ll isup = 0;
        rep(i,n){
            // cout << i << " ; " << vv[0][i] << " " << vv[1][i] << endl;
            ll wa = vv[0][i]+vv[1][i]+isup;
            res += wa%10;
            isup = wa/10;
        }
        return res;
    };

    rep1(a0,9){
        vvec(ll) tmp = f(acnt,bcnt,a0);
        if(chmin(totmin,f2(tmp))) ans = tmp;

        // cout << a0 << "---" << f2(tmp) << endl;
        // rep(i,2){
        //     reverse(all(tmp[i]));
        //     for(ll x:tmp[i]) cout << x; cout << endl;
        // }

    }

    rep(i,2){
        reverse(all(ans[i]));
        for(ll x:ans[i]) cout << x; cout << endl;
    }




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
