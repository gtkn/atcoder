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

    ll Q;
    vec(ll) qq,xx;
    vector<set<ll>> g;

    vec(ll) A;
    vec(ll) ans;

    void dfs(ll now){
        //cout << now << " ;";
        //for(ll ai:A) cout << ai << " "; cout << endl;

        ll memo=-100;
        if(qq[now]==1) A.push_back(xx[now]);
        if(qq[now]==2 && !A.empty()){
            memo = A.back();
            A.pop_back();
        }

        if(!A.empty()) ans[now]=A.back();
        else ans[now]=-1;

        if(now<Q && qq[now+1]!=4) dfs(now+1);
        if(qq[now]==3) for(ll to:g[now]) dfs(to);

        if(qq[now]==1) A.pop_back();
        if(qq[now]==2 && memo>0) A.push_back(memo);

    }


    void solve(){
        cin >> Q;

        ans.resize(Q+1);
        qq.push_back(3);
        xx.push_back(0);

        rep(_,Q){
            string s;
            cin >> s;
            ll x=-1;
            if(s!="DELETE") cin >> x;

            if(s=="ADD") qq.push_back(1);
            if(s=="DELETE") qq.push_back(2);
            if(s=="SAVE") qq.push_back(3);
            if(s=="LOAD") qq.push_back(4);
            xx.push_back(x);        
        }

        g.resize(Q+1);
        //rep(i,Q) g[i].insert(i+1);

        map<ll,vec(ll)> m;
        rep1(i,Q){
            if(qq[i]==3) m[xx[i]].push_back(-i);
            if(qq[i]==4) m[xx[i]].push_back(i);
        }

        for(auto mi:m){
            ll wr = 0;
            for(ll a:mi.second){
                if(a<0) wr = -a;
                else{
                    g[wr].insert(a);
                    //g[a-1].erase(a);
                }
            }
        }


        dfs(0);
        /*
        rep(i,Q){
            cout << i << " : ";
            for(ll to:g[i]) cout << to << " "; cout << endl;
        }
        */

        rep1(i,Q) cout << ans[i] << " ";
        cout << endl;



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
