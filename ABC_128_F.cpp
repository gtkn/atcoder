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

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    vec(ll) s(N);
    rep(i,N) cin >> s[i];

    vvec(ll) vf(N);
    rep1(d,N-1){
        vec(ll) v;
        ll tmp = 0;
        for(ll i=0; i<N; i+=d){
            tmp += s[i];
            v.push_back(tmp);
        }
        swap(v, vf[d]);
    }


    vvec(ll) vr(N);
    rep1(d,N-1){
        vec(ll) v;
        ll tmp = 0;
        for(ll i=N-1; i>=0; i-=d){
            tmp += s[i];
            v.push_back(tmp);
        }
        swap(v, vr[d]);
    }


    auto f = [&](ll a,ll d){
        ll res = 0;        
        ll r=N-1-a;

        // cout << a << " " << d << " : " << vf[d][r/d] << ", " << vr[d][r/d] << endl;
        
        if(r<a || a%d!=0){
            res += vf[d][r/d];
            res += vr[d][r/d];
        }

        return res;
    };






    ll ans = 0;
    rep1(B,N-1){
        ll A = N-1+B;
        if(A&1) continue;
        A/=2;
        if(A<B) continue;
        chmax(ans, s[A]+s[A-B]);
    }

    rep1(A,N-1){
        ll rem = N-1-A;
        
        vec(ll) ds;
        for(ll d=1; d*d<=rem; d++){
            if(rem%d) continue;
            ds.push_back(d);
            ds.push_back(rem/d);
        }

        for(ll d:ds){
            ll B = A-d;
            if(A<B || B<=0) continue;
            chmax(ans, f(A,d));
        }

    }

    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
