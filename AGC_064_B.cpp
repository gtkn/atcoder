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
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


struct edge{
    ll to,idx;
    char c;
    edge(ll to=0, char c='B', ll idx=0):to(to),c(c),idx(idx){}
};


void solve(){
    ll N,M;
    cin >> N >> M;

    vec(ll) a(M),b(M);
    vec(char) c(M);
    rep(i,M) cin >> a[i] >> b[i] >> c[i];
    rep(i,M) a[i]--;
    rep(i,M) b[i]--;

    string S;
    cin >> S;

    vvec(edge) g(N);
    rep(i,M){
        g[a[i]].emplace_back(b[i],c[i],i);
        g[b[i]].emplace_back(a[i],c[i],i);
    }


    vvec(ll) es(3);
    rep(i,M){
        if(c[i]==S[a[i]] && c[i]==S[b[i]]) es[0].push_back(i);
        else if(c[i]==S[a[i]]) es[1].push_back(i);
        else if(c[i]==S[b[i]]){
            es[1].push_back(i);
            swap(a[i],b[i]);
        }
        else es[2].push_back(i);
    }

    dsu d(N);
    vec(bool) chk(N);
    vec(ll) ans;


    for(ll ii:es[0]){
        if(d.same(a[ii],b[ii])) continue;
        chk[a[ii]]=true;
        chk[b[ii]]=true;
        d.merge(a[ii],b[ii]);
        ans.push_back(ii);
    }


    queue<edge> q;
    auto f = [&](ll x){
        for(auto ei:g[x]){
            if(d.same(x,ei.to)) continue;
            if(ei.c != S[ei.to]) continue;
            q.push(ei);
        }
    };

    rep(i,N){
        if(!chk[i]) continue;
        f(i);
    }

    while(!q.empty()){
        edge ei = q.front(); q.pop();
        if(chk[ei.to]) continue;
        chk[ei.to]=true;
        d.merge(a[ei.idx],b[ei.idx]);
        f(ei.to);
        ans.push_back(ei.idx);
    }


    // for(ll ii:es[1]){
    //     if(d.same(a[ii],b[ii])) continue;
    //     if(chk[a[ii]]) continue;
    //     if(!chk[b[ii]]) continue;
    //     chk[a[ii]]=true;
    //     d.merge(a[ii],b[ii]);
    //     ans.push_back(ii);
    // }

    rep(ii,M){
        if(d.same(a[ii],b[ii])) continue;
        d.merge(a[ii],b[ii]);
        ans.push_back(ii);
    }



    if(d.groups().size()!=1) sayno;
    if(d.groups()[0].size()!=N) sayno;
    if(ans.size()!=N-1) sayno;
    rep(i,N) if(!chk[i]) sayno;

    cout << "Yes" << endl;
    for(ll ai:ans) cout << ai+1 << " "; cout << endl;






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
