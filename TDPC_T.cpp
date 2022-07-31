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

using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{

    // https://qiita.com/hidekikangeki/items/716ff998732f43050164
    struct kitamasa{
        ll n;//次数
        vector<mint> a;//漸化式の係数
        vector<vector<mint>> mem;//a_n+i = \sum a_j mem[i][n-1-j]
        //kitamasa(漸化式の係数,次数)
        kitamasa(vector<mint> c,ll N) : a(c),n(N){
            vector<mint> r(2*n,0);
            rep(i,n)r[i]=c[i];
            mem.push_back(r);
            rep(i,n+1){
                mem.push_back(oneplass(mem[i]));
            }
        }
        //畳み込み
        vector<mint> closs(vector<mint> b){
            vector<mint> res(2*n,0);  
            repr(i,2*n-2+1){//? vrep(i,2*n-2+1){
                mint a=0;
                rep(j,i+1){
                    a+=b[j]*b[i-j];
                }
                res[i]=a;
            }
            return res;
        }
        //a_l の係数-> a_l+1 の係数
        vector<mint> oneplass(vector<mint> b){
            vector<mint> res(2*n,0);
            rep(i,n-1){
                res[i]=b[i+1]+b[0]*a[i];
            }
            res[n-1]=b[0]*a[n-1];
            return res;
        }
        //a_l の係数-> a_2*l の係数
        vector<mint> twotimes(vector<mint> b){
            vector<mint> res(2*n,0);
            auto bb=closs(b);
            rep(i,n-1){
                rep(j,n){
                    bb[2*n-2-j]+=bb[n-2-i]*mem[i][n-1-j];
                }
                bb[n-2-i]=0;
            }
            rep(i,n){
                res[n-1-i]=bb[2*n-2-i];
            }
            return res;
        }
        //calculate(n)=a_nの係数
        vector<mint> calculate(int m){
            vector<mint> res(2*n,0);
            if(m<n){
                res[m]=a[m];
                return res;
            }
            if(m<=2*n){
                return mem[m-n];
            }else{
                if(m%2==0){
                    auto b=calculate(m/2);
                    res=twotimes(b);
                }else{
                    auto b=calculate((m-1)/2);
                    res=twotimes(b);
                    res=oneplass(res);
                }
            }
            return res;
        }
    };


    //---ベクトルとか行列の掛け算---
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
        ll K,N;
        cin >> K >> N;

        if(N<=K){
            cout << 1 << endl;
            return;
        }


        vec(mint) b(K,1);
        kitamasa kita(b,K);

        auto res = kita.calculate(N-1);
        mint ans = 0;
        rep(i,K) ans += res[i];
        cout << ans.val() << endl;


        /*
        vvec(mint) a(K,vec(mint)(K));
        rep(i,K) a[0][i]=1;
        rep(i,K-1) a[i+1][i]=1;

        vec(mint) v(K,1);

        ll rem = N-K;
        while(rem){
            if(rem&1) v = vvxv(a,v);
            rem>>=1;
            a = vvxvv(a,a);
        }

        cout << v[0].val() << endl;
        */

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
