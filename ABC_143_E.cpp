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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N, M, L;
    cin >> N >> M >> L;

    vvec(Pll) g(N);
    rep(_,M){
        ll a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }


    // tri a,b;
    // a = {1,2,8};
    // b = {1,1,1};
    // // a[0]=1;a[1]=2;a[2]=0;
    // // b[0]=1;b[1]=1;b[2]=0;
    // auto [a0,a1,a2] = a;
    // auto [b0,b1,b2] = b;
    
    // cout << a0 << " "<< a1 << " " << a2 << endl;
    // cout << b0 << " "<< b1 << " " << b2 << endl;
    // cout << (a<b) << endl;


    // priority_queue<tri,vector<tri>, greater<tri>> q;



    vvec(Pll) memo(N);

    rep(st,N){
        vec(Pll) tmp(N,{llINF,0});
        priority_queue<tri,vector<tri>, greater<tri>> q;

        auto f = [](Pll a, ll cnt, ll rem)->bool{
            if( a.first < cnt) return false;
            if( a.first == cnt ){
                if( a.second > rem) return false;
            }
            return true;
        };

        auto qpush = [&](ll cnt,ll rem, ll nxt)->void{
            if(f(tmp[nxt], cnt, rem)){
                tmp[nxt] = {cnt,rem};
                q.emplace(cnt,-rem,nxt);
            }
        };


        qpush(0,L,st);

        while(!q.empty()){
            auto [cnt,rem,now] = q.top(); q.pop();
            rem = -rem;
            
            // cout << cnt << ", " << rem <<", " << now << endl;

            if(!f(tmp[now], cnt, rem)) continue;

            for(Pll gi:g[now]){
                ll r2=rem,c2=cnt;
                if(gi.second > r2){
                    r2 = L; c2++;
                }
                if(gi.second <= r2){
                    qpush(c2, r2-gi.second, gi.first);
                }
            }
        }
        swap(memo[st],tmp);
    }

    // rep(i,N){
    //     rep(j,N) cout << memo[i][j].first << " " << memo[i][j].second << " , "; cout << endl;
    // }

    
    ll Q;
    cin >> Q;
    while(Q--){
        ll s,t;
        cin >> s >> t;
        --s; --t;

        ll res = memo[s][t].first;
        if(res==llINF) res = -1;
        cout << res << endl;
    }



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
