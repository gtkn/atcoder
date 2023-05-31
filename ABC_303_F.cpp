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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a, ll b){return max(a,b);}
ll ee(){return 0LL;}


struct Solver{

    void solve(){
        ll N, H;
        cin >> N >> H;

        vec(Pll) v(N);
        rep(i,N) cin >> v[i].first >> v[i].second;

        map<ll,vector<ll>> m;
        rep(i,N) m[v[i].first].push_back(i);

        vec(ll) va(N),vb(N); // vaが残りターンずっとのほう
        rep(i,N) va[i] = v[i].second;

        segtree<ll,op,ee> sega(va),segb(vb);


        auto f = [&](ll d,ll a, ll t){
            ll x = t*(t+1)/2 + a*t;
            chmin(x, (H+d-1)/d);
            return d*x;
        };

        ll ans = 0;
        for(auto mi:m){
            ll th = mi.first-ans;

            ll da = sega.all_prod();
            ll db = segb.all_prod();

            ll tab = db/da - ans;
            chmax(tab, 0LL);
            chmin(tab, th);

            // cout << "--now ;" <<ans <<" , " << th << ", " <<tab << " : " << H << endl;

            ll tb = tab;
            if(db>0 ) chmin(tb,  (H+db-1)/db );

            H -= db*tb;
            ans += tb;
            if(H<=0) break;

            // cout << tb << " , " << db << endl;

            assert(tab==tb);

            ll l=0,r=th-tab;
            while(r-l>1){
                ll mid = (l+r)/2;
                // cout <<"        "<< l << " , " << r << " , " << mid <<"  , "<<da<<" , " << f(da,ans,mid) << endl;
                if( f(da,ans,mid) < H) l=mid;
                else r=mid;
            }
            ll ta = r;

            // cout << ta << " , " << da << endl;


            H -= f(da,ans,ta);
            ans += ta;

            if(H<=0) break;

            assert(tb+ta==th);

            for(ll i:mi.second){
                sega.set(i, 0LL);
                segb.set(i, v[i].first*v[i].second );
            }

        }


        if(H>0){
            ll db = segb.all_prod();
            ll tb = (H+db-1)/db;

            // cout << "--now ;" <<ans <<" , "  << H << endl;
            // cout << db << " , " << tb << " , " << db*tb << endl;

            H -= db*tb;
            assert(H<=0);
            ans += tb;
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
