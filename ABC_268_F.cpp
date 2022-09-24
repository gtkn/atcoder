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
        ll N;
        cin >> N;

        vec(string) S;
        vec(Pll) v;
        ll a0 = 0;

        rep(_,N){
            string si;
            cin >> si;
            S.push_back(si);

            Pll tmp={0,0};

            rep(i,si.size()){
                if(si[i]=='X') tmp.first++;
                else{
                    ll x = si[i]-'0';
                    tmp.second += x;
                    a0+=x*tmp.first;
                }
            }
            v.push_back(tmp);

        }

        sort(all(v),[](Pll const& a,Pll const& b){
            return a.first * b.second > b.first * a.second;
        });


        ll c0=0,cx=0;
        ll ans = 0;
        for(Pll vi:v){
            ans += c0*vi.second;
            c0 += vi.first;
            cx += vi.second;
        }

        ans += a0;
        cout << ans << endl;





        /*
        sort(all(vv),[](vector<ll> const& a,vector<ll> const& b){

            if(a[0]!=b[0]) return a[0]>b[0];
            rep1r(i,9){
                if(a[i]!=b[i]) return a[i]<b[i];
            }
           
            ll ca=0,cb=0;
            rep1(i,9){
                ca += a[i]*i;
                cb += b[i]*i;
            }

            if(ca!=cb) return ca<cb;


            return a[0]>b[0];
        });

        vec(ll) cnt(10);
        ll ans = 0;
        for(auto vi:vv){
            rep1(i,9){
                ans += cnt[0] * vi[i] * i;
                cnt[i] += vi[i];
            }
            cnt[0] += vi[0];
        }

        ans += a0;
        cout << ans << endl;

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
