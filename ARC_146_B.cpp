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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

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
        ll N,M,K;
        cin >> N >> M >> K;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        sort(all(A));

        vec(ll) B;

        ll two = (1LL<<32);
        while(B.empty() && two>0){
            vec(Pll) v;
            rep(i,N) v.emplace_back(max(two-A[i],0LL),i);
            sort(all(v));
            

            ll cnt = 0;
            rep(i,K) cnt+=v[i].first;


            if(cnt<=M){
                rep(i,K) B.push_back(A[v[i].second]); 
                break;
            }


            ll mask = two-1;
            rep(i,N) A[i] &= mask;
            two>>=1;

        }

        //for(ll x:B) cout << x << " "; cout << endl; 


        ll ans = 0;
        while(two>0){
            ll cnt = 0;
            for(ll x:B) cnt += max(two-x,0LL);
            if(cnt<=M){
                ans += two;
                M-=cnt;
                rep(i,K) chmax(B[i],two);// if(B[i]<two) B[i]=0;
            }

            ll mask = two-1;
            rep(i,K) B[i] &= mask;
            two>>=1;
        }

        cout << ans << endl;



        /*
        ll l=0, r=1e10;
        while(r-l>1){
            ll mid = (l+r)/2;
            vec(ll) v;
            for(ll ai:A){
                ll cnt = -1;
                rep(i,30){
                    if(bit(mid,i) && !bit(ai,i)) cnt=i;
                }
                if(cnt==-1){
                    v.push_back(0);
                    continue;
                }
                ll mask = (2<<cnt)-1;
                v.push_back( mid-(ai&mask) );
            }
            sort(all(v));
            ll tot = 0;
            rep(i,K) tot+=v[i];
            if(tot<=M) l=mid;
            else r=mid;

        }

        cout << l << endl;
        */





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
