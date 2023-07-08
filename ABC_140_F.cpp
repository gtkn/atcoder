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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


ll op(ll a,ll b){return a+b;}
ll ee(){return 0;}

struct Solver{

 
    void solve(){
        ll N;
        cin >> N;
        ll nn = 1<<N;
        vec(ll) S(nn);
        rep(i,nn) cin >> S[i];

        set<ll> ss;
        for(ll si:S) ss.insert(si);
        map<ll,ll> mm;
        ll cnt=0;
        for(ll si:ss) mm[si]=cnt++;

        vec(ll) v(nn);
        rep(i,nn) v[i] = mm[S[i]]; 


        priority_queue<ll> q;
        for(ll vi:v) q.push(vi);

        vec(ll) used(cnt);
        used[q.top()]++; q.pop();
        string ans = "Yes";

        for(ll two=1; two<nn; two<<=1){
            segtree<ll,op,ee> seg(used);

            vec(ll) rem;            
            while(seg.all_prod()>0 && !q.empty()){
                ll q0 = q.top(); q.pop();

                // cout << q0 << " ," << seg.all_prod()<< endl;

                if(seg.prod(q0+1,cnt)==0){
                    rem.push_back(q0);
                    continue;
                }

                ll l=q0+1,r=cnt;
                while(r-l>1){
                    ll mid = (l+r)/2;
                    if(seg.prod(q0+1,mid) > 0) r=mid;
                    else l=mid;
                }

                seg.set(l, seg.get(l)-1);
                used[q0]++;
            }

            if(seg.all_prod()>0) ans = "No";
            for(ll x:rem) q.push(x);


        }

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
