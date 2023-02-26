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
        ll N, K;
        cin >> N >> K;
        string S;
        cin >> S;

        ll xcnt=0;
        rep(i,N) if(S[i]=='X') xcnt++;
        ll ycnt = N-xcnt;

        vec(ll) vx,vy;
        char now = S[0];
        ll cnt = 1;
        rep1(i,N){
            if(i==N || S[i]!=S[i-1]){
                if(now=='X') vx.push_back(cnt);
                else vy.push_back(cnt);
                cnt = 1;
                now = S[i];
            }else{
                cnt++;
            }
        }

        assert(xcnt+ycnt==N);

        ll ans;

        
        if(K==xcnt){
            ans = N-1;
        }else if(K==0){
            ans=0;
            rep(i,N-1) if(S[i]=='Y' && S[i+1]=='Y') ans++;
        }else if(xcnt==N){
            ans = K-1;
        }else if(ycnt==N){
            ans = (N-K);
            if(K<N) ans-=1;
        }else if(K<xcnt){
            ans=0;
            rep(i,N-1) if(S[i]=='Y' && S[i+1]=='Y') ans++;
        
            vec(ll) v;
            rep(i,vx.size()){
                if(i==0 && S[0]=='X') continue;
                if(i==vx.size()-1 && S[N-1]=='X') continue;
                v.push_back(vx[i]);
            }
            sort(all(v),greater<ll>());
        
            while(!v.empty()){
                ll b = v.back();
                v.pop_back();
                if(K>=b){
                    K-=b;
                    ans += b+1;
                }else{
                    break;
                }
            }
        
            ans += K;
        }else{
            ans = N-1;
            K -= xcnt;

            vec(ll) v;
            rep(i,vy.size()){
                if(i==0 && S[0]=='Y'){
                    ll tmp = min(vy[i],K);
                    ans -= tmp;
                    K -= tmp;
                    continue;
                }
                if(i==vy.size()-1 && S[N-1]=='Y'){
                    ll tmp = min(vy[i],K);
                    ans -= tmp;
                    K -= tmp;
                    continue;
                }
                v.push_back(vy[i]);
            }

            sort(all(v));
            while(!v.empty()){
                ll b = v.back();
                v.pop_back();
                if(K>=b){
                    K -= b;
                    ans -= (b+1);
                }else{
                    break;
                }
            }
            if(K>0) ans -= (K+1);

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
