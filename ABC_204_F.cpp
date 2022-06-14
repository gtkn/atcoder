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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{

    vvec(mint) vvxvv(vvec(mint) const& vv1, vvec(mint) const& vv2){
        ll h,w,d;
        h = vv1.size(); w=vv1[0].size(); d=vv2[0].size();
        assert(w==vv2.size());

        vvec(mint) res(h,vec(mint)(d));
        rep(i,h)rep(j,d)rep(k,w) res[i][j]+=vv1[i][k]*vv2[k][j];
        return res;
    }


    vec(mint) vvxv(vvec(mint) const& vv, vec(mint) const& v){
        ll h,w;
        h = vv.size(); w=vv[0].size();
        assert(w==v.size());

        vec(mint) res(h);
        rep(i,h)rep(j,w) res[i]+=vv[i][j]*v[j];
        return res;
    }

    mint vxv(vec(mint) const& v1, vec(mint) const& v2){
        ll h;
        h = v1.size();
        assert(h==v2.size());

        mint res=0;
        rep(i,h) res+=v1[i]*v2[i];
        return res;
    }




    void solve(){
        ll H,W;
        cin >> H >> W;

        ll h2=1<<H;
        vvec(mint) vv(h2,vec(mint)(h2));

        rep(s,h2){
            queue<Pll> q;
            q.emplace(s,0);
            
            while(!q.empty()){
                Pll q0 = q.front();
                q.pop();
                ll s0,t0;
                s0 = q0.first; t0 = q0.second;

                if(s0 == h2-1){
                    vv[t0][s] ++;
                    continue;
                }

                rep(i,H){
                    if(bit(s0,i)) continue;
                    ll x = 1<<i;
                    q.emplace(s0|x,t0|x);
                    q.emplace(s0|x,t0);
                    if(i<H-1 && !bit(s0,i+1)){
                        x |= (x<<1);
                        q.emplace(s0|x,t0);
                    }
                    break;
                }
            }
        }

        rep(i,h2){
            //rep(j,h2) cout << vv[i][j].val() << " "; cout << endl;
        }

        vec(mint) v(h2);
        v[h2-1]=1;

        W++;
        while(W){
            if(W&1) v = vvxv(vv,v);
            vv = vvxvv(vv,vv);
            W>>=1;
        }

        mint ans = v[0];
        cout << ans.val() << endl;

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
