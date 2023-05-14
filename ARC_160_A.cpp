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

struct Solver{

    ll N,K;
    vec(ll) ans;
    vec(ll) A,B;
    vec(bool) used;
    ll cnt = 0;
    set<Pll> chk;


    void dfs(ll l){

        // cout <<endl <<  l <<","<< K << "!" << endl;
        // cout << "used ;" ; rep(i,N) if(used[i]) cout << i+1 << " / " ; cout << endl;

        if(l==N){
            K-=N;
            cnt+=N;
            if(K<=0 && ans.empty()) ans = A;
        }


        rep(st,N){
            if(used[st]) continue;

            if(st==A[l]){
                used[A[l]] = true;
                dfs(l+1);
                used[A[l]] = false;
                continue;
            }


            K--;
            cnt++;
            ll r = B[st];

            // cout << cnt << " ;" << l << "," << r << "," << st << ":::  ";
            // reverse(A.begin()+l, A.begin()+r+1);
            // for(ll ai:A) cout << ai+1 << " "; cout << endl;
            // reverse(A.begin()+l, A.begin()+r+1);

            // if(sfind(chk,make_pair(l,r))) cout << "!!!" << l << "," << r << endl;
            // chk.emplace(l,r);
            // if(l>r) cout << "???" << l << "," << r << endl;



            if(K==0){
                // cout << l << " ," << B[st] << endl;
                reverse(A.begin()+l, A.begin()+r+1);
                ans = A;
                reverse(A.begin()+l, A.begin()+r+1);
                

                // for(ll ai:A) cout << ai << " "; cout << endl;
                // ans = A;
            }
        }
    }

    void solve(){
        cin >> N >> K;

        A.resize(N);
        B.resize(N);
        used.resize(N);

        rep(i,N) cin >> A[i];
        rep(i,N) A[i]--;
        rep(i,N) B[A[i]] = i;


        dfs(0);
        for(ll ai:ans) cout << ai+1 << " "; cout << endl;

        // cout << cnt <<"/"<< N*(N+1)/2 << endl;

        // reverse(all(A));

        // vec(ll) v(N);
        // rep(i,N) v[A[i]] = i;

        // rep(st,N){
        //     cout << st << " ; " << v[st] << " ," << K << endl;
        //     if( K<=v[st]+1 ){
        //         rep(i,K) cout << A[v[st]-i]+1 << " ";
        //         cout << endl;
        //         return;                
        //     }
        //     K -= v[st]+1;
        // }


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
