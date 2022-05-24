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
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(Pll) v(N);
        rep(i,N) cin >> v[i].first >> v[i].second;

        if(K==1){
            cout << "Infinity" << endl;
            return;
        }


        ll ans = 0;
        set<tri> used;
        for(ll i=0; i<N; i++)for(ll j=i+1; j<N; j++){
            ll a,b,c;
            a = v[j].second - v[i].second;
            b = v[i].first - v[j].first;
            c = v[j].first*v[i].second - v[i].first*v[j].second;
            if(a<0 || (a==0 && b<0)){
                a=-a;
                b=-b;
                c=-c;
            }

            ll x;
            if(a==0) x=abs(b);
            else if(b==0) x=abs(a);
            else x = __gcd(abs(a),abs(b));

            if(c!=0) x = __gcd(x,abs(c));

            //cout << i << "," << j << ";" << a << " ," << b << " , " << c << " : " << x << endl;

            a/=x;
            b/=x;
            c/=x;

            tri now={a,b,c};
            if(used.find(now)!=used.end()) continue;
            used.insert(now);

            ll cnt=0;
            for(Pll vi:v) if(a*vi.first+b*vi.second+c==0) cnt++;
            if(cnt>=K) ans++;

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
