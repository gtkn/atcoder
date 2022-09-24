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
        ll N,M;
        cin >> N >> M;

        vec(string) S(N);
        rep(i,N) cin >> S[i];
        set<string> T;
        rep(_,M){
            string ti;
            cin >> ti;
            T.insert(ti);
        }

        ll cnt = N-1;
        rep(i,N) cnt += S[i].size();

        if(cnt>16 || cnt<3) dame;

        ll umax = 16 - (cnt - (N-1));

        set<vector<ll>> sv;
        vec(ll) tmp(N-1,1);
        sv.insert(tmp);

        queue<vector<ll>> q;
        q.push(tmp);

        while(!q.empty()){
            vec(ll) q0 = q.front();
            q.pop();

            ll tot = 0;
            rep(i,N-1) tot += q0[i];
            if(tot==umax) continue;

            rep(i,N-1){
                vec(ll) to = q0;
                to[i]++;
                if(sfind(sv,to)) continue;
                q.push(to);
                sv.insert(to);
            }
        }

        vec(ll) v;
        rep(i,N) v.push_back(i);

        do{
            for(vec(ll) si:sv){
                string now = "";
                rep(i,N-1){
                    now += S[v[i]];
                    rep(_,si[i]) now += "_";
                }
                now += S[v[N-1]];

                if(sfind(T,now)) continue;

                cout << now << endl;
                return;

            }

        }while(next_permutation(v.begin(),v.end()));

        cout << -1 << endl;








        



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
