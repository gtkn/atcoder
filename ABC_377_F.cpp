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

struct S{
    ll l,r,u,b;
    S(ll l=0, ll r=0, ll u=0, ll b=0):l(l),r(r),u(u),b(b){}
};



void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) a(M),b(M);
    rep(i,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    set<Pll> s0,s1,s2,s3;
    rep(i,M){
        ll ai = a[i], bi = b[i];
        s0.emplace(ai,0);
        {
            ll h = max(0LL, ai-bi);
            ll w = max(0LL, bi-ai);
            s1.emplace(h,w);
        }
        s2.emplace(0,bi);
        {
            ll h = max(0LL, ai-(N-bi-1));
            ll w = min(N-1, bi+ai);
            s3.emplace(h,w);
        }    
    }


    map<Pll,ll> mp;
    
    for(auto [h0,w0]:s0)for(auto [h1,w1]:s1){
        if(h1>h0) continue;
        ll d = h0-h1;
        if(w1+d>=N) continue;
        mp[{h0,w1+d}]++;
    }

    for(auto [h0,w0]:s0)for(auto [h2,w2]:s2){
        mp[{h0,w2}]++;
    }

    for(auto [h0,w0]:s0)for(auto [h3,w3]:s3){
        if(h3>h0) continue;
        ll d = h0-h3;
        if(w3-d<0) continue;
        mp[{h0,w3-d}]++;
    }

    for(auto [h1,w1]:s1)for(auto [h2,w2]:s2){
        if(w1>w2) continue;
        ll d = w2-w1;
        if(h1+d>=N) continue;
        mp[{h1+d,w2}]++;
    }

    for(auto [h1,w1]:s1)for(auto [h3,w3]:s3){
        if(w1>w3) continue;
        ll d1 = h3+w3-h1-w1;
        if(d1&1) continue;
        d1/=2;

        ll d3 = w3-h3-w1+h1;
        if(d3&1) continue;
        d3/=2;

        if(h1+d1>=N || h1+d1<0) continue;
        if(w1+d1>=N || w1+d1<0) continue;

        mp[{h1+d1,w1+d1}]++;
    }

    for(auto [h2,w2]:s2)for(auto [h3,w3]:s3){
        if(w3<w2) continue;
        ll d = w3-w2;
        if(h3+d>=N) continue;
        mp[{h3+d,w2}]++;
    }   


    ll ans = N*N;
    // cerr << ans << endl;

    ans -= N*(ll)(s0.size());
    // cerr << ans << " , " << s0.size() << endl;


    for(auto [h,w]:s1){
        ll dh = N-h, dw = N-w;
        ans -= min(dh,dw);
        // cerr << h << " " << w << " " << min(dh,dw) << endl;
    }


    ans -= N*(ll)(s2.size());
    for(auto [h,w]:s3){
        ll dh = N-h, dw = w+1;
        ans -= min(dh,dw);
        // cerr << h << " " << w << " " << min(dh,dw) << endl;
    }
    

    // cerr << s0.size() << " " << s1.size() << " " << s2.size() << " " << s3.size() << endl;
    // cerr << ans << endl;

    // vvec(ll) xx(N,vec(ll)(N));

    for(auto [pos,cnt]:mp){
        auto [h,w] = pos;
        // cerr << h << " " << w << " " << cnt << endl;
        // xx[h][w] += cnt;

        if(cnt==1) ans+=1;
        else if(cnt==3) ans+=2;
        else if(cnt==6) ans+=3;
        else{
            cerr << "error" << cnt << endl;
        }
    }

    cout << ans << endl;

    // rep(i,N){
    //     rep(j,N) cerr << xx[i][j] << " "; cerr << endl;
    // }

    // for(auto [h,w]:s3) cerr << h << " " << w << endl;



    // ll ans = N*N;

    // ans -= N*s0.size();

    // for(auto [h,w]:s1){
    //     ll u = h, b = min(N,h+(N-w-1)+1);
    //     ans += b-u;
    //     auto itr1 = s0.lower_bound({u,0});
    //     auto itr2 = s0.upper_bound({b,0});
    //     ans -= distance(itr1,itr2);
    // }

    // for(auto [h,w]:s2){
    //     ans += N;
    //     ans -= s0.size();









    // }






    // vec(S) v0,v1,v2,v3;

    // rep(i,M){
    //     ll ai = a[i], bi = b[i];
    //     v0.emplace_back(bi, bi+1, 0, N);
    //     {
    //         ll l = max(0LL, bi-(N-ai-1));
    //         ll r = min(N, bi+ai+1);
    //         ll u = min(0LL, ai-(N-bi-1));
    //         ll b = max(N, ai+bi+1);
    //         v1.emplace_back(l, r, u, b);
    //     }
    //     v2.emplace_back(0,N,ai,ai+1);
    //     {
    //         ll l = min(0LL, bi-ai);
    //         ll r = max(N, bi+(N-ai-1)+1);
    //         ll u = max(0LL, ai-bi);
    //         ll b = min(N, ai+(N-bi-1)+1);
    //         v3.emplace_back(l, r, u, b);
    //     }
    // }

    // ll ans = N*N;







}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
