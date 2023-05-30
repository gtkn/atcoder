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


struct Timer{
    ll start; // [clocks]
    ll limit;
    ll endt;

    void begin(double x){ // x[sec]
        start = clock();
        limit = x * CLOCKS_PER_SEC;
        endt = start + limit;
    }

    bool inTime(){
        return (clock()-start < limit);
    }

    bool inTime(double x){ // [sec]
        return (clock()-start < x*CLOCKS_PER_SEC);
    }

    ll remain(){
        return endt-clock();
    }

    ll past(){
        return clock()-start;
    }

    double past_rate(){
        return 1.*past()/limit;
    }

    double past_rate(double x){ // [sec]
        ll diff = x*CLOCKS_PER_SEC;
        return 1.*(past()-diff)/(limit-diff);
    }


};


// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}


struct Solver{
 
    void solve(){
        Timer timer;
        timer.begin(1.95);
        

        ll N;
        cin >> N;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];


        set<ll> used;
        while(timer.inTime()){
            ll ii,jj;
            ii = RandInt(0,N-2);
            jj = RandInt(ii+1,N-1);

            ll dif = abs(A[ii]-A[jj]);


            vec(ll) cand;
            if(dif%4==0) cand.push_back(4);
            while(dif%2==0) dif/=2;
            for(ll x=3; x*x<=dif; x+=2){
                if(dif%x==0) cand.push_back(x);
                while(dif%x==0) dif/=x;            
            }
            if(dif>1) cand.push_back(dif);



            for(ll ci:cand){
                if(sfind(used,ci)) continue;
                map<ll,ll> cnt;
                for(ll ai:A) cnt[ai%ci]++;

                ll cmax=0;
                for(auto mi:cnt) chmax(cmax,mi.second);
                if(cmax>N/2){
                    cout << ci << endl;
                    return;
                }
                used.insert(ci);
            }
        }

        cout << -1 << endl;


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
