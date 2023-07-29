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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

Pll op(Pll a, Pll b){return {a.first+b.first, a.second+b.second};}
Pll ee(){return {0,0};}


void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(ll) vv(3);
    rep(_,N){
        ll t,x;
        cin >> t >> x;
        vv[t].push_back(x);
    }

    rep(i,3) sort(all(vv[i]));


    vec(Pll) kan; // {x, 0/1}
    rep(i,2)for(ll x:vv[i]) kan.emplace_back(x,i);

    sort(all(kan));


    ll nn = kan.size();
    segtree<Pll, op, ee> seg(nn); // {x, num}

    vec(Pll) memo; // {x, idx}

    rep(i,nn){
        if(kan[i].second==0) seg.set(i, {kan[i].first, 1});
        else memo.emplace_back( kan[i].first, i );
    }



    auto f = [&](){
        ll l = 0, r= nn;
        Pll tmp;
        while(r-l>1){
            ll mid = (l+r)/2;
            tmp = seg.prod(mid, nn);
            if(tmp.second < M) r=mid;
            else l=mid;
        }
        tmp = seg.prod(l, nn);
        // cout << l << " ;; " << tmp.first << " , " << tmp.second << endl;

        return tmp.first;
    };


    ll ans = f();
    while(!vv[2].empty()){
        ll x = vv[2].back(); vv[2].pop_back();
        M--;
        rep(_,x){
            if(memo.empty()) break;
            Pll tmp = memo.back(); memo.pop_back();
            seg.set( tmp.second, {tmp.first, 1} );
        }
        chmax(ans, f());
    }

    cout << ans << endl;








    // vec(ll) mr;
    // rep(i,2)for(ll x:vv[i]) mr.push_back(x);

    // sort(all(mr));
    // mr.erase(unique(all(mr)),mr.end());

    // ll nn = mr.size();
    // map<ll,ll> mf;
    // rep(i,nn) mf[ mr[i] ] = i;


    // segtree<Pll, op, ee> seg(nn);

    // auto myset = [&](ll x,)


    






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
