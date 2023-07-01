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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N, M;
        cin >> N >> M;

        vec(ll) P(N+1),L(M+1),D(M+1);
        rep1(i,N) cin >> P[i];
        rep1(i,M) cin >> L[i];
        rep1(i,M) cin >> D[i];


        vec(Pll) v;
        rep1(i,N) v.emplace_back(P[i],i);
        rep1(i,M) v.emplace_back(L[i],-i);
        v.emplace_back(llINF,0);

        sort(all(v));

        ll cnt = 0;
        priority_queue<ll> q;
        ll ans = 0;
        rep1(i,N) ans += P[i];

        for(Pll vi:v){
            // cout << vi.first << " , " << vi.second << endl;
            if(vi.second > 0) cnt++;
            else{      
                while(cnt){
                    if(!q.empty()){
                        ans -= q.top();
                        q.pop();
                    }
                    cnt--;
                }               
                q.push(D[-vi.second]);
            }
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
