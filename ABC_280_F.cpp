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

    vvec(Pll) g;
    vec(bool) used;
    vec(ll) maxp;
    vec(ll) lastp;
    
    bool dfs(ll now, ll c){
        if(used[now]){
            return lastp[now] != c;
        }
        
        used[now] = true;
        lastp[now] = c;

        for(Pll gi:g[now]){
            if( dfs(gi.first, c+gi.second) ) return true;
        }

        lastp[now] = -llINF;
        used[now] = false;

        return false;
    }




    void solve(){
        ll N,M,Q;
        cin >> N >> M >> Q;

        g.resize(N+1);
        used.resize(N+1);
        maxp.resize(N+1, -llINF);
        lastp.resize(N+1, -llINF);

        rep(_,M){
            ll a,b,c;
            cin >> a >> b >> c;
            g[a].emplace_back(b,c);
            g[b].emplace_back(a,-c);
        }



        rep(i,N+1) used[i]=false;
        vec(ll) gidx(N+1,-1);
        ll cnt = 0;
        vec(ll) gl;
        rep1(st,N){
            if(used[st]) continue;

            queue<ll> q;
            q.push(st);
            while(!q.empty()){
                ll q0 = q.front();
                q.pop();
                if(used[q0]) continue;

                used[q0] = true;
                gidx[q0] = cnt;
                for(Pll gi:g[q0]){
                    q.push(gi.first);                    
                }
            }
            cnt++;
            gl.push_back(st);
        }

        //rep(i,N+1) cout << gidx[i] <<"  "; cout <<" ;" << cnt << endl;

        ll GN = cnt;
        vec(bool) isinf(GN);

        queue<Pll> qq;
        auto qqpush = [&](ll to,ll c){
            if(maxp[to]==-llINF){
                maxp[to]=c;
                qq.emplace(to,c);
            }else{
                if(maxp[to]!=c) isinf[gidx[to]]=true;
            }
        };
        for(ll st:gl) qqpush(st,0);

        while(!qq.empty()){
            Pll qq0 = qq.front();
            qq.pop();

            for(Pll gi:g[qq0.first]) qqpush(gi.first, qq0.second+gi.second);
        }


        while(Q--){
            ll x,y;
            cin >> x >> y;
            if(gidx[x]!=gidx[y]){
                cout << "nan" << endl;
                continue;
            }
            if(isinf[gidx[x]]){
                cout << "inf" << endl;
                continue;
            }

            cout << maxp[y]-maxp[x] << endl;
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
