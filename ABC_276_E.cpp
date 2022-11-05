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
        ll H,W;
        cin >> H >> W;

        vvec(bool) C(H,vec(bool)(W));
        ll sh,sw;
        rep(i,H){
            string s;
            cin >> s;
            rep(j,W){
                if(s[j]=='S'){
                    sh=i;
                    sw=j;
                    C[i][j]=false;
                }
                if(s[j]=='.') C[i][j]=true;
                if(s[j]=='#') C[i][j]=false;
            }
        }

        


        auto chk=[&](Pll st,Pll gl){

            if(st.first<0 || st.first>=H) return false;
            if(st.second<0 || st.second>=W) return false;
            if(gl.first<0 || gl.first>=H) return false;
            if(gl.second<0 || gl.second>=W) return false;

            if(C[st.first][st.second]==false) return false;


            vvec(bool) used(H,vec(bool)(W));
            queue<Pll> q;
            q.emplace(st);
            while(!q.empty()){
                Pll q0=q.front(); q.pop();
                ll h0,w0;
                h0=q0.first; w0=q0.second;
                if(used[h0][w0]) continue;
                used[h0][w0]=true;
                rep(i,4){
                    ll h1=h0+dh[i], w1=w0+dw[i];
                    if(h1<0 || h1>=H || w1<0 || w1>=W) continue;
                    if(C[h1][w1]) q.emplace(h1,w1);
                }
            }



            //cout << used[gl.first][gl.second]<<"!" << endl;
            if(used[gl.first][gl.second]) return true;
            else return false;
        };



        string ans = "No";

        if(chk({sh-1,sw}, {sh,sw-1})) ans = "Yes";
        if(chk({sh-1,sw}, {sh,sw+1})) ans = "Yes";
        if(chk({sh,sw-1}, {sh,sw+1})) ans = "Yes";
        if(chk({sh-1,sw}, {sh+1,sw})) ans = "Yes";
        if(chk({sh,sw-1}, {sh+1,sw})) ans = "Yes";
        if(chk({sh,sw+1}, {sh+1,sw})) ans = "Yes";

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
