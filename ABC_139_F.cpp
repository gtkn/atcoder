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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

class Timer {
private:
    clock_t startTime;
    double limitTime;

public:
    Timer(double limit) : limitTime(limit) {
        startTime = clock();
    }

    double getElapsedTime() {
        clock_t currentTime = clock();
        return static_cast<double>(currentTime - startTime) / CLOCKS_PER_SEC;
    }

    bool isTimeUp() {
        return getElapsedTime() >= limitTime;
    }

};


struct Solver{


    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }


    void solve(){
        Timer timer(1.95);
        ll N;
        cin >> N;
        vec(Pll) xy(N);
        rep(i,N) cin >> xy[i].first >> xy[i].second;

        
        Pll dir = {1,0};

        auto dot=[](Pll a,Pll b)->ll{
            return a.first*b.first + a.second*b.second;
        };
        auto cross=[](Pll a,Pll b)->ll{
            return a.first*b.second - a.second*b.first;
        };
        auto dist=[](Pll a)->double{
            return sqrt(a.first*a.first + a.second*a.second);
        };

        double ans = 0;

        // vec(Pll) v=xy;
        // for(Pll vi:xy) v.emplace_back(-vi.second, vi.first);
        // for(Pll vi:xy) v.emplace_back(-vi.first, -vi.second);
        // for(Pll vi:xy) v.emplace_back(vi.second, -vi.first);



        // for(Pll vi:v){
        //     Pll now = {0,0};
        //     for(Pll xyi:xy){
        //         if(dot(vi,xyi)<0) continue;
        //         now.first += xyi.first;
        //         now.second += xyi.second;
        //     }
        //     chmax(ans,dist(now));
        // }




        sort(all(xy),[](Pll const& a, Pll const& b){
            return atan2(a.second, a.first) < atan2(b.second, b.first);
        });

        // for(Pll xyi:xy) cout << xyi.first << " " << xyi.second << " : " << atan2(xyi.second, xyi.first) << endl;

        vec(Pll) v=xy;
        for(Pll vi:xy) v.emplace_back(vi.first, vi.second);


        vec(Pll) cum(2*N+1);
        rep(i,2*N) cum[i+1] = {cum[i].first+v[i].first, cum[i].second+v[i].second};

        rep(l,N)rep1(d,N){
            ll r=l+d;
            // cout << l << " " << r << " ----- " << endl;
            // cout << cum[r].first <<"  "<<cum[r].second << endl;
            // cout << cum[l].first <<"  "<<cum[l].second << endl;
            // cout << dist({cum[r].first-cum[l].first, cum[r].second-cum[l].second }) << endl;
            chmax(ans, dist({cum[r].first-cum[l].first, cum[r].second-cum[l].second }));
        }


        printf("%.12f\r\n",ans);        



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
