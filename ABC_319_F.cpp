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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

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

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    vvec(ll) tr(N);
    vec(ll) t(N),s(N),g(N);
    rep1(i,N-1){
        ll pi;
        cin >> pi >> t[i] >> s[i] >> g[i];
        pi--;
        tr[pi].push_back(i);
    }


    map<set<ll>, ll> memo;

    auto f = [&](auto f, ll a, priority_queue<Pll, vector<Pll>, greater<Pll>> q, vec(ll) med, set<ll> used_med)->bool{
        if(q.empty() && med.empty()) return true;

        // cout << "now" << a << endl;

        while(!q.empty()){
            Pll q0 = q.top();
            if( a >= q0.first){
                q.pop();
                a = min(a+g[q0.second], llINF);
                for(ll b:tr[q0.second]){
                    if(s[b]==0) med.push_back(b);
                    else q.emplace( s[b], b );
                }
            }else{
                break;
            }
        }

        if(q.empty() && med.empty()) return true;
        
        // for(ll xx:used_med) cout << xx << " , ";
        // cout <<";;"<< memo[used_med] <<" " << a << endl;
        if(!chmax(memo[used_med],a )) return false;


        bool res = false;
        for(ll used:med){
            priority_queue<Pll, vector<Pll>, greater<Pll>> q2 = q;
            vec(ll) med2;

            for(ll b:tr[used]){
                if(s[b]==0) med2.push_back(b);
                else q2.emplace(s[b],b);
            }
            for(ll m:med) if(m!=used) med2.push_back(m);

            ll aa;
            if(llINF/g[used] < a) aa = llINF;
            else aa = a*g[used];

            used_med.insert(used);
            res |= f(f, aa, q2, med2, used_med);
            used_med.erase(used);
        }

        return res;
    };


    priority_queue<Pll, vector<Pll>, greater<Pll>> q0;
    vec(ll) med0;
    for(ll b:tr[0]){
        if(s[b]==0) med0.push_back(b);
        else q0.emplace(s[b],b);
    }

    if(f(f,1,q0,med0,{})) yn;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
