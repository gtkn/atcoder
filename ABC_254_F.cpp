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

ll op(ll a,ll b){return min(a,b);};
ll ee(){return llINF;};

ll opp(ll a,ll b){
    if(a==llINF || b==llINF) return min(a,b);
    return __gcd(a,b);
    };
ll eee(){return llINF;};


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
        ll N,Q;
        cin >> N >> Q;

        vec(ll) A(N),B(N);
        rep(i,N) cin >> A[i];
        rep(i,N) cin >> B[i];

        vec(ll) aa(N-1),bb(N-1);
        rep(i,N-1) aa[i] = abs(A[i+1]-A[i]);
        rep(i,N-1) bb[i] = abs(B[i+1]-B[i]);

        segtree<ll,op,ee> sa(A),sb(B);
        segtree<ll, opp, eee> saa(aa), sbb(bb);

        while(Q--){
            ll h1,h2,w1,w2;
            cin >> h1 >> h2 >> w1 >> w2;
            h1--;h2--;w1--;w2--;


            ll xab,xaa,xbb;
            xab = A[h1]+B[w1];
            if(h1!=h2) xaa = saa.prod(h1,h2);
            else xaa = xab;
            if(w1!=w2) xbb = sbb.prod(w1,w2);
            else xbb = xab;
            cout << __gcd(xab,__gcd(xaa,xbb)) << endl;;
            continue;




            ll amin,bmin;
            amin = sa.prod(h1,h2+1);
            bmin = sb.prod(w1,w2+1);

            ll xmin = amin+bmin;
            vec(ll) v;
            for(ll i=1; i*i<=xmin; i++){
                if(xmin%i==0){
                    ll vi = i;
                    v.push_back(vi);
                    vi = xmin/i;
                    v.push_back(vi);
                }
            }

            ll res = 1;
            for(ll vi:v){
                bool isok = true;
                if(h1<h2){
                    ll x = saa.prod(h1,h2);
                    if(x%vi || x<vi) isok=false;
                }            
                if(w1<w2){
                    ll x = sbb.prod(w1,w2);
                    if(x%vi || x<vi) isok=false;
                }
                if(isok) chmax(res, vi);
            }
            //cout << " -- " << xmin << ", " << A[h1]<< endl;
            cout << res << endl;
        }



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
