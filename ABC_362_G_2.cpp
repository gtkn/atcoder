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
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct Aho_Corasick{
    using MP = unordered_map<char,ll>;
    vector<MP> to;
    vector<ll> cnt,fail;

    Aho_Corasick():to(1),cnt(1){}

    ll add(const string& s){ // trieにsを追加
        ll now = 0;
        for(char c:s){ // 1文字ずつ見ていく
            if(!to[now].count(c)){ // まだないなら新しいノードを作る
                to[now][c] = to.size();
                to.emplace_back();
                cnt.push_back(0);
            }
            now = to[now][c];
        }
        cnt[now]++; // このノードがsの終端であることを示す
        return now;
    }

    void init(){ // fail関数を構築
        fail = vector<ll>(to.size(),-1);
        queue<ll> q;
        q.push(0);

        while(!q.empty()){
            ll now = q.front(); q.pop();
            for(auto& [c,nxt]:to[now]){
                fail[nxt] = (*this)(fail[now],c);
                q.push(nxt);
            }
        }
    }

    ll operator()(ll now, char c) const {
        while( now != -1 ){
            auto itr = to[now].find(c);
            if (itr != to[now].end()){
                return itr->second;
            }
            now = fail[now];
        }
        return 0;
    }

    ll operator[](ll pos) const {
        return cnt[pos];
    }
};



void solve(){
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vec(string) T(Q);
    rep(i,Q) cin >> T[i];

    Aho_Corasick ac;
    for(auto& t:T) ac.add(t);
    ac.add(S);
    ac.init();

    ll nn = ac.to.size();

    vvec(ll) g(nn);
    rep(i,nn){
        ll j = ac.fail[i];
        if(j!=-1) g[j].push_back(i);
    }

    vvec(ll) vv(nn);
    rep(i,Q){
        ll now = 0;
        for(char c:T[i]) now = ac(now,c);
        vv[now].push_back(i);
    }

    vec(ll) scnt(nn);
    {
        ll now = 0;
        for(char c:S){
            now = ac(now,c);
            scnt[now]++;
        }
    }

    vec(ll) ans(Q);

    auto f = [&](auto f,ll now)->ll{
        ll cnt = scnt[now];
        for(ll nxt:g[now]){
            cnt += f(f,nxt);
        }
        for(ll idx:vv[now]){
            ans[idx] += cnt;
        }
        return cnt;
    };


    f(f,0);

    rep(i,Q) cout << ans[i] << endl;





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
