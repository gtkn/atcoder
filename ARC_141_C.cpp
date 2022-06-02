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
        ll N;
        cin >> N;

        ll N2 = N*2;
        vec(ll) P(N2),Q(N2);
        rep(i,N2) cin >> P[i];
        rep(i,N2) cin >> Q[i];
        rep(i,N2) P[i]--;
        rep(i,N2) Q[i]--;

        vec(char) ans(N2,'?');
        rep(i,N2-1){
            if(P[i]>P[i+1]){
                ans[P[i]]='(';
                ans[P[i+1]]=')';
            }
        }
        rep(i,N2-1){
            if(Q[i]<Q[i+1]){
                ans[Q[i]]='(';
                ans[Q[i+1]]=')';
            }
        }

        bool isok=true;

        ll cnt=0;
        queue<ll> q;
        vec(ll) v;
        rep(i,N2){
            if(ans[i]=='('){
                v.push_back(i);
                cnt++;
            }else{
                q.push(i);
            }
            while(cnt>0 && !q.empty()){
                cnt--;
                v.push_back(q.front());
                q.pop();
            }
        }
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        //rep(i,N2) cout << v[i] << " "; cout << endl;
        rep(i,N2) if(P[i]!=v[i]) isok=false;
        if(cnt!=0) isok=false;

        

        cnt=0;
        v.clear();
        repr(i,N2){
            if(ans[i]=='('){
                v.push_back(i);
                cnt++;
            }else{
                q.push(i);
            }
            while(cnt>0 && !q.empty()){
                cnt--;
                v.push_back(q.front());
                q.pop();
            }
        }
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        //rep(i,N2) cout << v[i] << " "; cout << endl;
        //for(char ai:ans) cout << ai; cout << endl;

        rep(i,N2) if(Q[i]!=v[i]) isok=false;
        if(cnt!=0) isok=false;

        if(isok) for(char ai:ans) cout << ai;
        else cout << -1;
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
