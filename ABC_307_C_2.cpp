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
    ll ha,wa;
    cin >> ha >> wa;
    vec(string) A(ha);
    rep(i,ha) cin >> A[i];

    ll hb,wb;
    cin >> hb >> wb;
    vec(string) B(hb);
    rep(i,hb) cin >> B[i];

    ll hx,wx;
    cin >> hx >> wx;
    vec(string) X(hx);
    rep(i,hx) cin >> X[i];


    auto trim = [](vec(string) v)->vec(string){
        vec(string) res;
        ll n = v.size();
        ll m = v[0].size();
        string emp = string(m,'.');

        for(auto s:v){
            if(s != emp || !res.empty()){
                res.push_back(s);
            }
        }
        while(res.back()==emp) res.pop_back();

        ll l = 0, r = m-1;
        while(l<n){
            bool isok = false;
            rep(i,n) if(v[i][l] == '#') isok = true;
            if(isok) break;
            l++;
        }

        while(r>=0){
            bool isok = false;
            rep(i,n) if(v[i][r] == '#') isok = true;
            if(isok) break;
            r--;
        }

        ll sz = r-l+1;
        for(auto &s:res){
            s = s.substr(l,sz);
        }
        return res;
    };


    vec(string) aa = trim(A);
    vec(string) bb = trim(B);

    ll haa = aa.size(), waa = aa[0].size();
    ll hbb = bb.size(), wbb = bb[0].size();

    // cerr << "aa : " << haa << " , " << waa << endl;
    // for(auto s:aa) cerr << s << endl;
    // cerr << "bb : " << hbb << " , " << wbb << endl;
    // for(auto s:bb) cerr << s << endl;
    


    rep(ia,hx-haa+1)rep(ja,wx-waa+1)rep(ib,hx-hbb+1)rep(jb,wx-wbb+1){
        vec(string) Y(hx,string(wx,'.'));
        rep(i,haa)rep(j,waa) if(aa[i][j]=='#') Y[ia+i][ja+j] = '#';
        rep(i,hbb)rep(j,wbb) if(bb[i][j]=='#') Y[ib+i][jb+j] = '#';
        // if(ia==0 && ja==0 && ib==0 && jb==0){
        //     cerr << "Y : " << endl;
        //     for(auto s:Y) cerr << s << endl;
        // }
        if(Y == X) sayyes;
    }
    sayno;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
