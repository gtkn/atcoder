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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    struct TrieTree{
        vector<map<char,ll>> g;
        vector<ll> cnt;

        TrieTree(): g(1),cnt(1){}

        ll add(const string& s){
            ll now = 0;
            for(char c:s){
                if(!g[now].count(c)){
                    g[now][c] = g.size();
                    g.push_back({});
                    cnt.push_back(0);
                }
                now = g[now][c];
            }
            cnt[now]++;
            return now;
        }



        vector<ll> A,B;

        ll dfs(ll now, ll num){
            num += cnt[now];
            A[now] = num;

            for(auto mi:g[now]){
                B[now] += dfs(mi.second, num);
            }

            return B[now]+cnt[now];
        }


        void calc_AB(){
            A = vector<ll>(g.size());
            B = vector<ll>(g.size());
            dfs(0, 0);
        }

    };


    void solve(){
        ll N;
        cin >> N;

        vec(string) S(N);
        rep(i,N) cin >> S[i];

        TrieTree t;

        vec(ll) memo(N);
        rep(i,N) memo[i] = t.add(S[i]);

        t.calc_AB();

        vec(mint) ans(N);
        rep(i,N){
            // cout << i << " ; " << S[i] <<" , " << t.A[memo[i]] << " , " << t.B[memo[i]] << endl;
            ans[i] = (mint)(N+t.A[memo[i]]-t.B[memo[i]])/2;
        }

        for(mint ai:ans) cout << ai.val() << endl;

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
