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
 
    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

    void solve(){
        ll N;
        cin >> N;

        vec(string) alp(26);
        rep(i,26) alp[i] = 'a'+i;




        map<string,ll> cost;
        set<string> s;
        rep(_,N){
            string t;
            ll p;
            cin >> t >> p;
            cost[t] = p;
            s.insert(t);
        }


        map<string,ll> m;
        ll cnt=0;
        m["$$"] = cnt++;
        rep(i,26) m["$"+alp[i]] = cnt++;
        rep(i,26)rep(j,26) m[alp[i]+alp[j]] = cnt++;


        auto getc = [&](string now, string x){
            vec(string) _v;
            _v.push_back(now+x);
            _v.push_back(now[1]+x);
            _v.push_back(x);

            ll res = 0;
            for(string _vi:_v){
                if(sfind(s,_vi)) res += cost[_vi];
            }
            return res;
        };



        vec(abc) edge;
        //vvec(Pll) g(cnt);
        for(auto mi:m){
            string now = mi.first;
            ll idx = mi.second;

            for(auto ai:alp){
                //g[idx].emplace_back( m[now[1]+ai], getc(now,ai) );
                edge.emplace_back(idx, m[now[1]+ai], getc(now,ai));
            }
        }

        vec(ll) dp(cnt,-llINF);
        dp[m["$$"]] = 0;
        
        bool chk = false;
        rep(nn,cnt+1){
            bool update = false;
            for(abc ei:edge){
                if(chmax( dp[ei.b] , dp[ei.a] + ei.c )) update = true;
            }
            if(nn==cnt && update) chk=true;
        }

        if(chk) cout << "Infinity" << endl;
        else{
            ll ans = -llINF;
            rep1(i,cnt-1) chmax(ans,dp[i]);
            cout << ans << endl;
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
