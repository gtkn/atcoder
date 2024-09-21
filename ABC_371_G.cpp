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
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

ll extGcd(ll a,ll b, ll &p, ll &q){
    if(b==0){
        p=1; q=0;
        return a;
    }

    ll d = extGcd(b, a%b, q, p);
    q -= a/b * p;
    return d;
}

// 解なしの場合は (0, -1) をリターン
Pll ChineseRem(ll b1, ll m1, ll b2, ll m2) {
  ll p, q;
  ll d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);

  ll m = m1 * (m2/d); // lcm of (m1, m2)
  ll tmp = (b2 - b1) / d * p % (m2/d);
  ll r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}




vec(ll) eratosthenes(ll n){
    vec(bool) isok(n+1,true);
    isok[0]=false; isok[1]=false;
    rep1(i,n){
        if(!isok[i]) continue;
        ll a=i*2;
        while(a<=n){
            isok[a]=false;
            a+=i;
        }
    }
    vec(ll) res;
    rep1(i,n) if(isok[i]) res.push_back(i);

    return res;
}



void solve(){
    ll N;
    cin >> N;

    vec(ll) P(N),A(N);
    rep(i,N) cin >> P[i];
    rep(i,N) cin >> A[i];

    rep(i,N) P[i]--;
    rep(i,N) A[i]--;

    vec(ll) ans(N,-1);
    vec(ll) dp(N+1,-1);


    rep(st,N){
        if(ans[st]>=0) continue;

        vec(Pll) v;
        vec(ll) memo;
        ll now = st;
        v.emplace_back(A[now],0);
        memo.push_back(now);

        now = P[now];
        ll cnt = 1;
        while(now!=st){
            v.emplace_back(A[now],cnt);
            memo.push_back(now);
            cnt++;
            now = P[now];
        }
        
        sort(all(v));
        ll L = v.size();

        map<ll,ll> pf = prime_factor(L);
        

        for(auto [_,x]:v){
            bool isok = true;
            for(auto [p,n]:pf){
                ll pp = 1;
                rep(_,n+1){
                    ll xi = mod(x, pp);
                    if(dp[pp]!=xi && dp[pp]!=-1)  isok = false;
                    pp *= p;
                }
            }

            if(!isok) continue;


            for(auto [p,n]:pf){
                ll pp = 1;
                rep(_,n+1){
                    ll xi = mod(x, pp);
                    dp[pp]=xi;
                    pp *= p;
                }
            }

            rep(i,L){
                ans[memo[i]] = A[memo[mod(i+x,L)]];
            }
            break;
        }
        assert(ans[st]!=-1);
    }

    rep(i,N) cout << ans[i]+1 << " "; cout << endl;







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
