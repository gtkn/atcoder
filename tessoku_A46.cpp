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

    ll N;
    vec(ll) X,Y;
    vvec(double) dist;

    Solver(){
        cin >> N;
        X.resize(N);
        Y.resize(N);
        dist = vvec(double)(N,vec(double)(N));
        
        rep(i,N) cin >> X[i] >> Y[i];
        for(ll i=0; i<N; i++)for(ll j=i+1; j<N; j++){
            ll dx = X[i]-X[j];
            ll dy = Y[i]-Y[j];
            dist[i][j] = sqrt( dx*dx+dy*dy );
            dist[j][i] = dist[i][j];
        }
    }


    // 貪欲法
    void solve1(){
        vec(ll) ans={0};
        vec(bool) used(N);
        used[0]=true;
        rep(_,N-1){
            ll now = ans.back();
            double d=10000.;
            ll nxt = -1;

            rep(i,N){
                if(used[i]) continue;
                if(chmin(d, dist[now][i])) nxt = i;
            }
            ans.push_back(nxt);
            used[nxt]=true;
        }
        for(ll ai:ans ) cout << ai+1 << endl;
        cout << ans[0]+1 << endl;
        return;
    }

    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }

    // スコア計算
    double GetScore(vec(ll) v){
        double res = 0;
        rep(i,N) res += dist[v[i]][v[(i+1)%N]];
        return res;        
    }

    // 山登り法
    void solve2(){
        vec(ll) ans={0};
        vec(bool) used(N);
        used[0]=true;
        rep(_,N-1){
            ll now = ans.back();
            double d=10000.;
            ll nxt = -1;

            rep(i,N){
                if(used[i]) continue;
                if(chmin(d, dist[now][i])) nxt = i;
            }
            ans.push_back(nxt);
            used[nxt]=true;
        }


        double score = GetScore(ans);
        rep(_, 200000){
            ll a,b;
            a = RandInt(2,N);
            b = RandInt(2,N);
            if(b<a) swap(a,b);

            reverse(ans.begin()+a, ans.begin()+b);
            if(!chmin(score, GetScore(ans))) reverse(ans.begin()+a, ans.begin()+b);
            

        }

        for(ll ai:ans ) cout << ai+1 << endl;
        cout << ans[0]+1 << endl;
        //cout << score << endl;
        return;


    }



    // 0.以上1.未満の整数をランダムに返す関数
    double Randdouble(){
        return 1. * rand() / RAND_MAX;
    }


    // 焼きなまし法
    void solve3(){
        vec(ll) ans={0};
        vec(bool) used(N);
        used[0]=true;
        rep(_,N-1){
            ll now = ans.back();
            double d=10000.;
            ll nxt = -1;

            rep(i,N){
                if(used[i]) continue;
                if(chmin(d, dist[now][i])) nxt = i;
            }
            ans.push_back(nxt);
            used[nxt]=true;
        }

        //rep(i,N) ans[i]=i;

        // annealing
        double score = GetScore(ans);
        ll nn = 200000;
        rep1(t, nn){
            ll a,b;
            a = RandInt(2,N);
            b = RandInt(2,N);
            if(b<a) swap(a,b);


            reverse(ans.begin()+a, ans.begin()+b);
            double tmp = GetScore(ans);

            //double T = 30. - 28.*t/double(nn);
            double T = 100. * exp(-t);
            
            double prob = exp( min(0. , (score-tmp)/T ) );
            if(Randdouble() < prob ) score = tmp;
            else reverse(ans.begin()+a, ans.begin()+b);
        
        }

        for(ll ai:ans ) cout << ai+1 << endl;
        cout << ans[0]+1 << endl;
        //cout << score << endl;
        return;


    }





};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve3();
    }
    return 0;
}
