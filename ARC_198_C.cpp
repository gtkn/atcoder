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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N), B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];

    ll atot=0, btot=0;
    rep(i,N){
        atot += A[i];
        btot += B[i];
    }
    if(atot != btot) sayno;


    vec(Pll) ans;
    auto f = [&](ll i,ll j)->void{
        if(i==j) return;
        if(i>j) swap(i,j);
        if(A[i]==A[j]-1 && A[j]==A[i]+1) return;

        ans.emplace_back(i,j);
        ll tmp = A[i];
        A[i] = A[j]-1;
        A[j] = tmp+1;
    };

    auto answer = [&]()->void{
        cout << "Yes" << nl;
        cout << ans.size() << nl;
        for(auto [x,y]: ans){
            cout << x+1 << " " << y+1 << nl;
        }
        return;
    };

    auto show = [&]()->void{
        rep(i,N) cerr << A[i] << " "; cerr << nl;
        rep(i,N) cerr << B[i] << " "; cerr << nl;
    };


    if(N==2){
        rep(_,2){
            if(A[0]== B[0] && A[1] == B[1]){
                answer();
                return;
            }
            f(0,1);
        }
        sayno;
    }

    if(N==3){
        rep(i,N-2){
            ll d = A[i] - B[i];
            if(d < 0){
                rep(_,abs(d)){
                    f(i,i+1);
                    f(i+1,i+2);
                    f(i,i+2);
                }
            }
            if(d > 0){
                rep(_,abs(d)){
                    f(i,i+2);
                    f(i+1,i+2);
                    f(i,i+1);
                }
            }
        }

        {
            ll d = A[N-2] - B[N-2];
            if(d < 0){
                rep(_,abs(d)){
                    f(N-2,N-1);
                    f(N-3,N-1);
                    f(N-3,N-2);
                    f(N-3,N-1);
                }
            }
            if(d > 0){
                rep(_,abs(d)){
                    f(N-3,N-2);
                    f(N-3,N-1);
                    f(N-3,N-2);
                    f(N-2,N-1);
                }
            }
        }
        answer();
        return;
    }


    {
        ll d = A[0] - B[0];
        if(d < 0){
            rep(_,abs(d)){
                f(0,1);
                f(1,2);
                f(0,2);
            }
        }
        if(d > 0){
            rep(_,abs(d)){
                f(0,2);
                f(1,2);
                f(0,1);
            }
        }
    }



    vec(ll) s,l;
    rep(i,N){
        if(A[i] < B[i]){
            s.push_back(i);
        }else if(A[i] > B[i]){
            l.push_back(i);
        }
    }

    while(!s.empty() && !l.empty()){
        ll si = s.back();
        ll li = l.back();
        s.pop_back();
        l.pop_back();

        ll d = min(abs(A[si] - B[si]), abs(A[li] - B[li]));
        if(si<li){
            rep(_,d){
                f(si,li);
                f(0,si);
                f(0,li);
                f(0,si);
            }
        }else{
            rep(_,d){
                f(0,si);
                f(0,li);
                f(0,si);
                f(si,li);
            }
        }
        if(A[si]!= B[si]){
            s.push_back(si);
        }
        if(A[li]!= B[li]){
            l.push_back(li);
        }
    }

    answer();
    // show();
    return;







    // rep(i,N-2){
    //     ll d = A[i] - B[i];
    //     if(d < 0){
    //         rep(_,abs(d)){
    //             f(i,i+1);
    //             f(i+1,i+2);
    //             f(i,i+2);
    //         }
    //     }
    //     if(d > 0){
    //         rep(_,abs(d)){
    //             f(i,i+2);
    //             f(i+1,i+2);
    //             f(i,i+1);
    //         }
    //     }
    // }

    // {
    //     ll d = A[N-2] - B[N-2];
    //     if(d < 0){
    //         rep(_,abs(d)){
    //             f(N-2,N-1);
    //             f(N-3,N-1);
    //             f(N-3,N-2);
    //             f(N-3,N-1);
    //         }
    //     }
    //     if(d > 0){
    //         rep(_,abs(d)){
    //             f(N-3,N-2);
    //             f(N-3,N-1);
    //             f(N-3,N-2);
    //             f(N-2,N-1);
    //         }
    //     }
    // }


    // answer();
    // // show();




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
