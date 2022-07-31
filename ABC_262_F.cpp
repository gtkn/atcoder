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
        ll N,K;
        cin >> N >> K;

        vec(ll) P(N);
        rep(i,N) cin >> P[i];

        if(K==0){
            rep(i,N) cout << P[i] << " ";
            cout << endl;
            return;
        }


        vec(ll) v(N+1);
        rep(i,N) v[P[i]] = i;

        ll x = 1;
        while( v[x]>=K && v[x]<N-K ) x++;

        cout << x<<" : " << v[x] << endl;

        vec(ll) ans;
        if(N-1-v[x] <= v[x]){
            ll now = 0;
            vec(ll) tmp;
            priority_queue<ll,vector<ll>,greater<ll>> q;
            rep(_,K-(N-v[x])) q.push(P[now++]);

            while(now<v[x] && q.top() < P[now]){
                tmp.push_back(q.top());
                q.pop();
                q.push(P[now++]);
            }
            while(now<v[x]) ans.push_back(P[now++]);

            while(!q.empty()) q.pop();
            for(ll i=v[x];i<N;i++) q.push(P[i]);
            for(ll i=v[x];i<N;i++){
                if(P[i]==q.top()){
                    ans.push_back(q.top());
                    q.pop();
                }
            }

            for(ll ai:tmp) ans.push_back(ai);

        }else{
            ll now = 0;
            priority_queue<ll,vector<ll>,greater<ll>> q;
            rep(_,K) q.push(P[now++]);

            while(now<N && q.top() < P[now]){
                ans.push_back(q.top());
                q.pop();
                q.push(P[now++]);
            }
            while(now<N) ans.push_back(P[now++]);
        }

        for(ll ai:ans ) cout << ai << " "; cout << endl;



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
