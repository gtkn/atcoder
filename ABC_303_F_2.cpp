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


ll op(ll a,ll b){return max(a,b);}
ll ee(){return 0;}


ll mul(ll a, ll b){
    if(a==0 || b==0) return 0;
    if(llINF/a < b) return llINF;
    return a*b;
}


void solve(){
    ll N,H;
    cin >> N >> H;

    vec(ll) t(N),d(N);
    rep(i,N) cin >> t[i] >> d[i];


    set<ll> st;
    for(ll ti:t) st.insert(ti);
    st.insert(llINF);

    segtree<ll,op,ee> segin(N),segout(N);

    rep(i,N) segout.set(i,d[i]);

    vec(Pll) tmemo(N);
    rep(i,N) tmemo[i] = {t[i],i};
    sort(all(tmemo),greater<Pll>());

    
    ll pred = 0;
    ll hp = H;

    for(ll nowt:st){
        while (!tmemo.empty() && tmemo.back().first <= pred) {
            ll idx = tmemo.back().second;
            segin.set(idx, d[idx]*t[idx]);
            segout.set(idx,0);
            tmemo.pop_back();
        }

        // inoutの切り替わりを計算
        ll din = segin.all_prod();
        ll dout = segout.all_prod();
        ll l = pred, r = nowt+1;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(din>=dout*mid) l=mid;
            else r=mid;
        }

        ll th = r;        
        auto f = [&](ll tt)->ll{
            ll res = 0;
            {
                ll tmp = min(th-1-pred, tt-pred);
                res += mul(din, tmp);
            }
            if(tt>=th){
                ll tmp = mul(tt+th, tt-th+1)/2;
                res += mul(dout, tmp);
            }
            return res;
        };
        
        ll dtot = f(nowt);


        // cerr << "nowt: " << nowt << " , " << pred << " , " << th << " , " << dtot << endl;

        if(hp > dtot){
            hp -= dtot;
            pred = nowt;
            continue;
        }


        // hp=0のタイミングを計算
        l = pred; r = nowt+1;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(f(mid) >= hp) r=mid;
            else l=mid;
        }
        cout << r << endl;
        return;

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
