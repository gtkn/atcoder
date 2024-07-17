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
    ll N, M;
    cin >> N >> M;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vec(double) C(N);
    rep(i,N) C[i] = (A[i]+B[i])*0.5;

    set<Pll> xy;
    rep(_,M){
        ll x,y;
        cin >> x >> y;
        x--; y--;
        if(x==y){
            if(A[x]<B[x]) swap(A[x],B[x]);
        }else{
            xy.insert({x,y});
        }
    }


    set<ll> aok,bok;
    rep(i,N){
        if(A[i]>B[i]) aok.insert(i);
        else bok.insert(i);
    }
    ll aok_n = aok.size();
    ll bok_n = bok.size();

    vec(ll) aok_v(all(aok)), bok_v(all(bok));
    vec(ll) i2j_a(N,-1), i2j_b(N,-1);
    rep(j,aok_n) i2j_a[aok_v[j]] = j;
    rep(j,bok_n) i2j_b[bok_v[j]] = j;


    // rep(i,N) cerr << A[i] << " " << B[i] << " " << C[i] << endl;
    // for(ll x:aok) cerr << x << " "; cerr << " : aok" << endl; 


    vec(Pll) maa,mab,mbb;
    for(auto [x,y]:xy){
        bool xina = sfind(aok,x);
        bool yina = sfind(aok,y);
        if(xina && yina) maa.push_back({x,y});
        else if(xina && !yina) mab.push_back({x,y});
        else if(!xina && yina) mab.push_back({y,x});
        else mbb.push_back({x,y});    
    }


    // cerr << "--- maa " << endl;
    // for(auto [x,y]:maa) cerr << x << " " << y << endl;
    // cerr << "--- mab " << endl;
    // for(auto [x,y]:mab) cerr << x << " " << y << endl;
    // cerr << "--- mba " << endl;
    // for(auto [x,y]:mba) cerr << x << " " << y << endl;
    // cerr << "--- mbb " << endl;
    // for(auto [x,y]:mbb) cerr << x << " " << y << endl;


    auto sub_solve0 = [&]()->double{ // aok_n < bok_n
        double res = 0;

        rep(ptn,(1<<aok_n)){
            vec(bool) a_used(aok_n), b_used(bok_n);
            for(auto [x,y]:maa){
                ll j0 = i2j_a[x];
                ll j1 = i2j_a[y];
                if(!bit(ptn,j0)) continue;
                if(!bit(ptn,j1)) continue;
                a_used[j0] = true;
                a_used[j1] = true;
            }
            for(auto [x,y]:mab){
                ll j0 = i2j_a[x];
                ll j1 = i2j_b[y];
                if(!bit(ptn,j0)) continue;
                a_used[j0] = true;
                b_used[j1] = true;
            }
            for(auto [x,y]:mbb){
                ll j0 = i2j_b[x];
                ll j1 = i2j_b[y];
                b_used[j0] = true;
                b_used[j1] = true;
            }
            bool isok = true;
            rep(i,aok_n) if(a_used[i] != bit(ptn,i)) isok = false;
            if(!isok) continue;

            double tmpres = 0;
            rep(i,aok_n){
                if(a_used[i]) tmpres += C[aok_v[i]];
                else tmpres += A[aok_v[i]];
            }
            rep(i,bok_n){
                if(b_used[i]) tmpres += C[bok_v[i]];
                else tmpres += A[bok_v[i]];
            }
            chmax(res,tmpres);
        }

        return res;
    };



    auto sub_solve1 = [&]()->double{ // aok_n >= bok_n
        ll bok_nn = (1<<bok_n);
        vvec(double) dp(aok_n+1,vec(double)(bok_nn,-llINF));

        vec(bool) b_used(bok_n);
        for(auto [x,y]:mbb){
            ll j0 = i2j_b[x];
            ll j1 = i2j_b[y];
            // cerr << x << ", " << y << ", " << j0 << ", " << j1 << endl;
            b_used[j0] = true;
            b_used[j1] = true;
        }
        ll jj = 0;
        rep(i,bok_n) if(b_used[i]) jj += (1<<i);

        double& dp0 = dp[0][jj];
        dp0 = 0;
        for(ll i:aok_v) dp0 += A[i];
        rep(i,bok_n){
            if(b_used[i]) dp0 += C[bok_v[i]];
            else dp0 += A[bok_v[i]];
        }
        // cerr << dp0 << " " << jj << endl;


        vvec(ll) vv(aok_n);
        for(auto [x,y]:mab){
            vv[i2j_a[x]].push_back(i2j_b[y]);
        }

        rep(i,aok_n)rep(j,bok_nn){
            chmax(dp[i+1][j],dp[i][j]);
            if(vv[i].empty()) continue;
            double tmp = dp[i][j];
            tmp -= A[aok_v[i]];
            tmp += C[aok_v[i]];
            ll jj = j;
            for(ll k:vv[i]){
                if(bit(jj,k)) continue;
                tmp -= A[bok_v[k]];
                tmp += C[bok_v[k]];
                jj += (1<<k);
            }
            chmax(dp[i+1][jj], tmp);
        }

        // rep(i,aok_n+1){
        //     rep(j,bok_nn) cerr << dp[i][j] << " "; cerr << endl;
        // }
        
        double res = 0;
        rep(j,bok_nn) chmax(res,dp[aok_n][j]);
        return res;
    };


    double ans;
    cerr << aok_n << " " << bok_n << endl;
    if(aok_n < bok_n){
        ans = sub_solve0();
    }else{
        ans = sub_solve1();
    }

    printf("%.6f\n",ans);


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
