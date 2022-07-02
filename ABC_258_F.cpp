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

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{


    vec(Pll) f(ll x,ll y,ll b){
        vec(Pll) res;
        ll x1,x2,y1,y2;

        ll xx=1,yy=1;
        if(x<0) xx=-1;
        if(y<0) yy=-1;

        x1 = (x/b) * b;
        x2 = x1 + b*xx;

        y1 = (y/b) * b;
        y2 = y1 + b*yy;

        res.emplace_back(x1,y);
        res.emplace_back(x2,y);
        res.emplace_back(x,y1);
        res.emplace_back(x,y2);
        return res;
    }

    ll ff(Pll s,Pll g){return abs(s.first-g.first) + abs(s.second-g.second);};

    void _solve(){
        
        ll B,K,sx,sy,gx,gy;
        cin >> B >> K >> sx >> sy >> gx >> gy;

        vec(Pll) vs,vg;
        vs = f(sx,sy,B);
        vg = f(gx,gy,B);

        Pll ss,gg;
        ss = {sx,sy};
        gg = {gx,gy};

        ll ans = ff(ss,gg) * K;
        for(Pll si:vs)for(Pll gi:vg){
            ll tmp = 0;
            tmp = ff(ss,si)*K + ff(si,gi) + ff(gi,gg)*K;
            chmin(ans,tmp);
            //cout << si.first << "," << si.second << " :" << gi.first <<" , " << gi.second << " : " << tmp << endl;
        }
        cout << ans << endl;
    }


    vec(ll) fa(ll x,ll b){
        ll x1,x2;

        ll xx=1;
        if(x<0) xx=-1;

        x1 = (x/b) * b;
        x2 = x1 + b*xx;
        return {x1,x2,x};
    }


    void solve(){      
        ll B,K,sx,sy,gx,gy;
        cin >> B >> K >> sx >> sy >> gx >> gy;

        set<ll> vx,vy;
        for(ll xi:fa(sx,B)) vx.insert(xi);
        for(ll xi:fa(gx,B)) vx.insert(xi);
        for(ll yi:fa(sy,B)) vy.insert(yi);
        for(ll yi:fa(gy,B)) vy.insert(yi);

        vec(Pll) v;
        map<Pll,ll> m;
        ll cnt=0;

        for(ll xi:vx)for(ll yi:vy){
            m[{xi,yi}] = cnt++;
            v.emplace_back(xi,yi);
        }

        vvec(Pll) g(cnt);
        ll nx,ny;
        nx = vx.size(); ny = vy.size();
        vec(ll) ax,ay;
        for(ll xi:vx) ax.push_back(xi);
        for(ll yi:vy) ay.push_back(yi);

        for(ll xi:ax){
            ll c = K;
            if(xi%B==0) c=1;
            rep(i,ny-1){
                ll d = abs(ay[i+1]-ay[i])*c;
                ll aa,bb;
                aa = m[{xi,ay[i+1]}];
                bb = m[{xi,ay[i]}];
                g[aa].emplace_back(bb,d);
                g[bb].emplace_back(aa,d);
            }
        }

        for(ll yi:ay){
            ll c = K;
            if(yi%B==0) c=1;
            rep(i,nx-1){
                ll d = abs(ax[i+1]-ax[i])*c;
                ll aa,bb;
                aa = m[{ax[i+1],yi}];
                bb = m[{ax[i],yi}];
                g[aa].emplace_back(bb,d);
                g[bb].emplace_back(aa,d);
            }
        }

        vec(ll) dp(cnt,llINF);
        queue<Pll> q;
        auto qpush = [&](ll now,ll c){
            if(chmin(dp[now],c)){
                q.emplace(now,c);
            }
        };
        qpush(m[{sx,sy}],0);

        while(!q.empty()){
            Pll q0 = q.front();
            q.pop();
            if(dp[q0.first]<q0.second) continue;

            for(Pll gi:g[q0.first]){
                qpush(gi.first, q0.second+gi.second);
            }
        }

        cout << dp[m[{gx,gy}]] << endl;

    }


};



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
