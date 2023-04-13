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


    // void dfs(ll now){
    //     used[now] = true;

    //     for(ll nxt:g[now]){
    //         if(used[nxt]) ans = "No";
    //         else dfs(nxt);
    //     }

    //     used[now]=false;
    // }


    vec(ll) topological_sort(vvec(ll) &g, vec(ll) &incnt, ll vnum){
        vec(ll) res;

        queue<ll> q;
        rep(i,vnum) if(incnt[i]==0) q.push(i);

        while(!q.empty()){
            ll now = q.front();
            q.pop();

            for(ll nxt:g[now]){
                incnt[nxt]--;
                if(incnt[nxt]==0) q.push(nxt);
            }

            res.push_back(now);
        }

        return res;

    }



    void solve(){
        ll H,W;
        cin >> H >> W;

        vvec(ll) g(W+1);

        vvec(ll) A(H,vec(ll)(W));
        rep(i,H)rep(j,W) cin >> A[i][j];

        vec(Pll) aminmax;

        rep(i,H){
            vec(Pll) v;
            rep(j,W) if(A[i][j]>0) v.emplace_back(A[i][j],j+1);            

            sort(all(v));

            if(!v.empty()) aminmax.emplace_back(v.front().first, v.back().first);

            vvec(ll) memo;
            vec(ll) tmp = {0};
            ll last=0;

            for(Pll vi:v){
                ll now = vi.first;
                if(now!=last){
                    memo.push_back(tmp);
                    tmp.clear();
                }
                tmp.push_back(vi.second);
                last = now;
            }
            memo.push_back(tmp);

            ll n = memo.size();
            rep(j,n-1){
                ll x = g.size();
                g.push_back({});
                for(ll y:memo[j]) g[y].push_back(x);
                for(ll y:memo[j+1]) g[x].push_back(y);                
            }

        }


        sort(all(aminmax));

        rep(i, (ll)aminmax.size()-1){
            if(aminmax[i].second > aminmax[i+1].first){
                cout << "No" << endl;
                return;
            }
        }


        ll n = g.size();
        vec(ll) incnt(n);
        rep(i,n) for(ll j:g[i]) incnt[j]++;
        
        vec(ll) tvec = topological_sort(g, incnt, n);

        if(tvec.size()==n) yn;





        // used.resize(g.size());
        // dfs(0);

        // cout << ans << endl;



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
