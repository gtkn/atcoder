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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


using arr = array<ll,51>;
const ll NMAX = 50;


//---modintで組み合わせ扱う用の構造体---
struct mcomb{
    ll nmax;
    vec(mint) fa,af;
    mcomb(ll sz=200020){
        nmax = sz;
        fa.resize(nmax+1);
        fa[0]=1;
        rep1(i,nmax) fa[i]=fa[i-1]*i;
        af.resize(nmax+1);
        rep(i,nmax+1) af[i]=fa[i].inv();
    }
    mint c(ll n, ll k){
        if(n<k || k<0 || n>nmax) return 0;
        return fa[n]*af[k]*af[n-k];
    }
};

void solve(){
    ll N,K;
    cin >> N >> K;

    set<arr> dp_now;
    arr z;
    rep(i,NMAX+1) z[i] = 0;
    // rep(i,NMAX+1) cerr << z[i] << " "; cerr << endl;

    auto f = [&](auto f,ll tot, ll now)->void{
        // assert(tot<=N);

        if(now==1){
            z[1] = N - tot;
            dp_now.insert(z);
            z[1] = 0;
            return;
        }
        
        z[now] = 0;
        rep(_,N+1){
            if(tot>N) break;
            f(f, tot, now-1);
            z[now]++;
            tot += now;
        }
    };

    f(f,0,N);

    // vec(mint) fa(N+1);
    // fa[0] = 1;
    // rep1(i,N) fa[i] = fa[i-1]*i;
    mcomb mc(N+1);

    mint ans = 0;
    for(auto a:dp_now){

        mint cnt = 1;
        ll rem = N;
        rep1(i,N){
            rep(_,a[i]){
                cnt *= mc.c(rem,i);
                rem -= i;
            }
            cnt *= mc.fa[i-1].pow(a[i]);
            cnt *= mc.af[a[i]];
        }

        ll score = 1;
        rep1(i,N)if(a[i]>0){
            score = score*i/__gcd(score,i);
        }

        // mint score = 0;
        // rep1(i,N)if(a[i]>0) score = i;

        // rep(i,N+1) cerr << a[i] << " "; cerr << " : " << cnt.val() <<", "<< score.val() << ", " << rem << endl;

        ans += mint(score).pow(K) * cnt;
    }

    cout << ans.val() << endl;




    // map<arr,mint> dp_now;    
    // arr z;
    // rep(i,NMAX+1) z[i] = 0;
    // // rep(i,NMAX+1) cerr << z[i] << " "; cerr << endl;
    // dp_now[z] = 1;

    // rep(_,N){
    //     map<arr,mint> dp_nxt;
    //     for(auto [a,cnt]:dp_now){
    //         rep(i,N)if(a[i]>0){
    //             arr b = a;
    //             b[i]--; b[i+1]++;
    //             dp_nxt[b] += cnt*(b[i]+1);
    //         }
    //         {
    //             arr b = a;
    //             b[1]++;
    //             dp_nxt[b] += cnt;
    //         }
    //     }
    //     swap(dp_now,dp_nxt);        
    // }

    // vec(mint) fa(N+1);
    // fa[0] = 1;
    // rep1(i,N) fa[i] = fa[i-1]*i;

    // mint ans = 0;
    // for(auto [a,cnt]:dp_now){

    //     mint x = 1;
    //     rep1(i,N){
    //         x *= fa[i-1].pow(a[i]);
    //     }

    //     mint score = 0;
    //     rep1(i,N)if(a[i]>0) score = i;

    //     // rep(i,N+1) cerr << a[i] << " "; cerr << " : " << cnt.val() <<", "<< score.val() << endl;

    //     ans += score.pow(K) * cnt * x;
    // }

    // cout << ans.val() << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
