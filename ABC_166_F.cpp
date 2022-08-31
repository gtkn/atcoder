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
        ll N,A,B,C;
        cin >> N >> A >> B >> C;
        vec(ll) v={A,B,C};

        ll D = A+B+C;

        vec(char) ans;
        bool isok = true;

        vec(string) vs(N);
        rep(i,N) cin >> vs[i];
        vs.push_back(vs.back());

        rep(i,N){
            string s = vs[i];
            ll x,y;
            if(s=="AB"){x=0,y=1;};
            if(s=="AC"){x=0,y=2;};
            if(s=="BC"){x=1,y=2;};
            //cout << v[0] << v[1] << v[2] << endl;

            if(v[x]==0 && v[y]==0){
                isok = false;
                break;
            }

            if(v[y]>1 ){
                v[y]--;
                v[x]++;
                ans.push_back(s[0]);
            }else if(v[x]>1){
                v[y]++;
                v[x]--;
                ans.push_back(s[1]);
            }else{
                if(v[x]==1 && v[y]==1 && D==2){
                    ll xx,yy;
                    if(vs[i+1]=="AB"){xx=0,yy=1;};
                    if(vs[i+1]=="AC"){xx=0,yy=2;};
                    if(vs[i+1]=="BC"){xx=1,yy=2;};
                    
                    v[x]--;
                    v[y]++;

                    if(v[xx]==0 && v[yy]==0){
                        v[x]+=2;
                        v[y]-=2;
                        ans.push_back(s[0]);
                    }else{
                        ans.push_back(s[1]);
                    }



                }else if(v[x]==0){
                    v[y]--;
                    v[x]++;
                    ans.push_back(s[0]);
                }else{
                    v[y]++;
                    v[x]--;
                    ans.push_back(s[1]);
                }
            }

        }


        if(isok) yn;
        if(isok) for(char ai:ans ) cout << ai << endl;
        

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
