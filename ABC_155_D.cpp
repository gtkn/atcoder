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
        ll N,K;
        cin >> N >> K;

        vec(ll) vm,vp;
        ll nm=0,nz=0,np=0;
        rep(_,N){
            ll a; cin >> a;
            if(a>0) vp.push_back(a);    
            if(a<0) vm.push_back(a);    
            if(a==0) nz++;    
        }

        nm = vm.size();
        np = vp.size();
        sort(all(vm));
        sort(all(vp));

        vec(ll) vmr;
        repr(i,nm) vmr.push_back(-vm[i]);


        ll al=-llINF, ar=llINF;

        auto cntp = [&](ll const& th){
            ll res = nm*np + nz*nm + nz*np + nz*(nz-1)/2;
            ll r = np-1;
            rep(l,np){
                while(r>l && vp[l]*vp[r]>th) r--;
                res += max(r-l,0LL);
            }
            r = nm-1;
            rep(l,nm){
                while(r>l && vmr[l]*vmr[r]>th) r--;
                res += max(r-l,0LL);
            }
            return res;
        };

        auto cntm = [&](ll const& th){
            ll res = 0;
            ll r = 0;
            for(ll x:vm){
                while(r<np && x*vp[r] > th) r++;
                res += np-r;
            }
            return res;
        };




        while(ar-al>1){
            ll am = (al+ar)/2;
            //cout << am << endl;
            ll cnt = ((am>=0)? cntp(am) : cntm(am) );
            if(cnt>=K) ar = am;
            else al = am;
        }
        cout << ar << endl;

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
