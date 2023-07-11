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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return a+b;}
ll ee(){return 0;}


struct Solver{
    void solve(){
        ll N;
        cin >> N;
        vec(ll) x(N),y(N);
        rep(i,N) cin >> x[i] >> y[i];


        vec(Pll) v(N);
        rep(i,N) v[i] = {x[i],y[i]};

        sort(all(x));
        sort(all(y));

        map<ll,ll> xr,yr;
        rep(i,N) xr[x[i]] = i;
        rep(i,N) yr[y[i]] = i;

        vec(mint) two(N+1);
        two[0]=1;
        rep(i,N) two[i+1] = two[i]*2;

        segtree<ll,op,ee> seg(N+1);
        sort(all(v));

        mint ans=two[N-1]*N;

        for(Pll vi:v){
            ll a = xr[vi.first];
            ll b = yr[vi.second];
            ll ab = seg.prod(0,yr[vi.second]);

            mint tmp = two[N-1];
            tmp -= two[a];
            tmp -= two[N-a-1];
            tmp -= two[b];
            tmp -= two[N-b-1];
            tmp += two[ab];
            tmp += two[a-ab];
            tmp += two[b-ab];
            tmp += two[N-1-a-b+ab];
            tmp -= 1;

            // cout <<a <<","<<b <<",,"<<ab<<"  :"<< ans.val() << ","<<tmp.val() <<endl;

            ans += tmp;


            seg.set(yr[vi.second],1);
        
        }

        cout << ans.val() << endl;



        // set<ll> s;
        // rep(i,N) s.insert(y[i]);
        // map<ll,ll> m;
        // ll nn = 0;
        // for(ll si:s) m[si]=nn++;

        // vec(Pll) v(N);
        // rep(i,N) v[i] = {x[i],m[y[i]]};
        // sort(all(v));

        // segtree<mint,op,ee> seg0(nn),segu(nn),segd(nn);
        // mint ans = 0;

        // for(Pll vi:v){
        //     ll yy=vi.second;

        //     ans += segu.prod(yy,nn);
        //     ans += segd.prod(0 ,yy);

        //     seg0.set(yy, 1);
        //     ans += seg0.all_prod();

        //     segu.set(yy, seg0.prod(yy,nn) );
        //     segd.set(yy, seg0.prod(0,yy+1) );
        //     cout << yy << " " << ans.val() << endl;

        // }

        // cout << ans.val() << endl;

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
