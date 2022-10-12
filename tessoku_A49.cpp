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


struct State{
    ll score;
    ll X[21];
    char LastMove;
    ll LastPos;
};

bool operator>(const State& a, const State& b){
    return (a.score > b.score);
}



struct Solver{

    ll T;
    ll P[110],Q[110],R[110];
    char ans[110];



    Solver(){
        cin >> T;
        rep(i,T) cin >> P[i] >> Q[i] >> R[i]; 
    }

    void output(){
        rep(i,T) cout << ans[i] << endl;
    }


    // 貪欲法
    void solve1(){
        
        vec(ll) v(21);
        
        rep(i,T){
            ll a=0,b=0;
    
            // A
            if(v[P[i]]==-1) a++;
            if(v[Q[i]]==-1) a++;
            if(v[R[i]]==-1) a++;

            // B
            if(v[P[i]]==1) b++;
            if(v[Q[i]]==1) b++;
            if(v[R[i]]==1) b++;

            ll x=1;
            if(a>=b) ans[i]='A';
            else{
                ans[i]='B';
                x=-1;
            }
            
            v[P[i]] += x;
            v[Q[i]] += x;
            v[R[i]] += x;

        }

        output();
    }




    // ビームサーチ
    void solve2(){
        ll width = 10000;
        ll N = 20;
        vec(ll) NumState(109);
        vvec(State) Beam(109,vec(State)(width));


        // 初期状態
        NumState[0] = 1;
        Beam[0][0].score = 0;
        rep1(i,N) Beam[0][0].X[i] = 0;

        // search
        rep(i,T){
            vec(State) cand;
            rep(j, NumState[i]){
                // A
                State sa = Beam[i][j];
                sa.LastMove = 'A';
                sa.LastPos = j;
                sa.X[P[i]]++;
                sa.X[Q[i]]++;
                sa.X[R[i]]++;
                rep1(k,N) if(sa.X[k]==0) sa.score++;
                cand.push_back(sa);

                // B
                State sb = Beam[i][j];
                sb.LastMove = 'B';
                sb.LastPos = j;
                sb.X[P[i]]--;
                sb.X[Q[i]]--;
                sb.X[R[i]]--;
                rep1(k,N) if(sb.X[k]==0) sb.score++;
                cand.push_back(sb);

            }
            sort(all(cand), greater<State>());
            NumState[i+1] = min(width, (ll)cand.size());
            rep(j,NumState[i+1]) Beam[i+1][j] = cand[j];
        }

        // 復元
        ll now = 0;
        repr(i,T){
            ans[i] = Beam[i+1][now].LastMove;
            now = Beam[i+1][now].LastPos;
        }

        output();
    }








};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve2();
    }
    return 0;
}
