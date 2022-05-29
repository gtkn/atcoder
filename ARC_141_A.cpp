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
        ll N;
        cin >> N;
        
        vec(ll) v;
        ll NN = N;
        while(NN){
            v.push_back(NN%10);
            NN/=10;
        }
        reverse(all(v));

        ll nsize = v.size();

        ll ans = 1;
        rep(_,nsize-1) ans*=10;
        ans--;
        chmax(ans,ll(11));

        rep1(a,nsize){
            ll b = nsize/a;
            if(nsize%a>0 || b<2) continue;

            vec(ll) x(b);
            rep(i,b)rep(j,a) x[i] = x[i]*10 + v[i*a+j];

            bool chk = false;
            for(ll xi:x){
                if(xi>x[0]) break;
                if(xi<x[0]) chk=true;
            }
            if(chk) x[0]--;

            ll ten = 1;
            rep(_,a) ten*=10;
            ll tmp=0;
            rep(_,b) tmp = tmp*ten + x[0];


            //cout << x[0] << " , " << b << " , " << ten << ", " << tmp << endl;

            chmax(ans,tmp);
        }
        cout << ans << endl;


    
    
    }

    void _solve(){


        string S;
        cin >> S;

        ll N=0;
        for(char si:S) N =  N*10 + (si-'0');

        ll nn = S.size();
        ll ans = 0;
        rep(_,nn-1) ans = ans*10+9;
        chmax(ans, ll(11));

        rep1(a, nn/2){
            ll b = nn/a;
            if(nn%a>0) continue;

            vec(ll) v;
            rep(i,b){
                ll x = 0;
                rep(j,a) x = x*10 + (S[a*i+j]-'0');
                v.push_back(x);
            }

            bool chk=true;
            rep(i,b) if(v[i]<v[0]) chk=false;
            if(!chk) v[0]--;
            ll ten = 1;
            rep(_,a) ten*=10;
            ll tmp = 0;
            rep(_,b) tmp = tmp*ten + v[0];
            //cout << v[0] << " * " << b << " , " << tmp << " , " << ten << endl;

            chmax(ans,tmp); 
        }
        cout << ans << endl;

    }
};


int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
