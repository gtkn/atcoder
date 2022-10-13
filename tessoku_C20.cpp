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

random_device seed_gen;
mt19937 engine(seed_gen());

struct Solver{
    ll N,K,L;
    vec(ll) A,B;
    vvec(ll) C;
    vec(ll) ans;
    vec(ll) p,q;
    //ll pmax,pmin,qmax,qmin;
    ll start_time;
    ll TIMELIMIT = 0.9 * CLOCKS_PER_SEC;
    vvec(ll) g;


    Solver(){
        cin >> N >> K >> L;
        A.resize(K+1);
        B.resize(K+1);
        ans.resize(K+1);
        C = vvec(ll)(N,vec(ll)(N));

        rep1(i,K) cin >> A[i] >> B[i];
        rep(i,N)rep(j,N) cin >> C[i][j];

        start_time = clock();
        


        p.resize(L+1);
        q.resize(L+1);

        // 適当に解を初期化
        //rep1(i,K) ans[i]=i%L + 1;
        solve_random();
        rep1(i,K) p[ans[i]] += A[i];
        rep1(i,K) q[ans[i]] += B[i];


        // 隣接する地区リスト
        g.resize(K+1);
        rep(i,N)rep(j,N){
            ll now = C[i][j];
            if(now==0) continue;
            if(i<N-1){
                ll to = C[i+1][j];
                if(now!=to && to!=0){
                    g[now].push_back(to);
                    g[to].push_back(now);
                }
            }
            if(j<N-1){
                ll to = C[i][j+1];
                if(now!=to && to!=0){
                    g[now].push_back(to);
                    g[to].push_back(now);
                }
            }
        }
        



    }

    void Submit(){
        assert(ans.size()==K+1);
        rep1(i,K){
            assert(ans[i]>0 && ans[i]<=L);
            cout << ans[i] << endl;
        }
    }

    void Submit_file(){
        ofstream outputfile("out.dat");
        rep1(i,K) outputfile<< ans[i] << endl;
        outputfile.close();
        cout << GetScore() << endl;
    }


    // 0.以上1.未満の整数をランダムに返す関数
    double Randdouble(){
        return 1. * rand() / RAND_MAX;
    }

    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }



    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};


    double GetScore_botu(bool conncheck=true){
        double res = 0;
        bool connected = true;

        ll pmax=0,pmin=llINF,qmax=0,qmin=llINF;
        rep1(i,L){
            chmax(pmax, p[i]);
            chmin(pmin, p[i]);
            chmax(qmax, q[i]);
            chmin(qmin, q[i]);
        }


        // 連結チェック
        if(conncheck){
            /*
            vvec(ll) vv(N,vec(ll)(N));
            rep(i,N)rep(j,N) vv[i][j] = ans[C[i][j]];
            vvec(bool) reached(N,vec(bool)(N));
            vec(bool) used(L+1);

            rep(si,N)rep(sj,N){
                if(reached[si][sj]) continue;
                ll x = vv[si][sj];
                if(x>0 && used[x]) connected = false;

                queue<Pll> q;
                q.emplace(si,sj);

                while(!q.empty()){
                    Pll q0 = q.front();
                    q.pop();
                    reached[q0.first][q0.second]=true;

                    rep(di,4){
                        ll h1,w1;
                        h1 = q0.first + dh[di];
                        w1 = q0.second+ dw[di];
                        if(h1<0 || h1>=N || w1<0 || w1>=N) continue;
                        if(!reached[h1][w1] && vv[h1][w1]==x) q.emplace(h1,w1);
                    }
                }
                used[x]=true;
            }
            */

            vec(bool) used(L+1);
            vec(bool) reached(1+K);
            rep1(st,K){
                if(reached[st]) continue;
                ll x = ans[st];
                if(used[x]) connected = false;

                queue<ll> que;
                que.push(st);

                while(!que.empty()){
                    ll q0 = que.front();
                    que.pop();
                    if(reached[q0]) continue;
                    reached[q0]=true;

                    for(ll to:g[q0]){
                        if(!reached[to] && ans[to]==x) que.push(to);
                    }
                }
                used[x]=true;
            }
        }


        res = min( 1.*pmin/pmax, 1.*qmin/qmax );
        //cout << pmin <<" , " << pmax << " , " << qmin << " , " << qmax << " , " << res << endl;
        if(connected) res *= 1000000.;
        else res *= 1000.;

        //return round(res);
        return res;
    }



    double GetScore(bool conncheck=true){
        double res = 0;
        bool connected = true;

        rep1(i,L) p[i]=0;
        rep1(i,L) q[i]=0;
        

        // 連結チェック
        if(conncheck){

            vec(bool) used(L+1);
            vec(bool) reached(1+K);
            rep1(st,K){
                if(reached[st]) continue;
                ll x = ans[st];
                if(used[x]) connected = false;

                queue<ll> que;
                que.push(st);

                while(!que.empty()){
                    ll q0 = que.front();
                    que.pop();
                    if(reached[q0]) continue;
                    reached[q0]=true;
                    p[x]+=A[q0];
                    q[x]+=B[q0];

                    for(ll to:g[q0]){
                        if(!reached[to] && ans[to]==x) que.push(to);
                    }
                }
                used[x]=true;
            }
        }


        ll pmax=0,pmin=llINF,qmax=0,qmin=llINF;
        rep1(i,L){
            chmax(pmax, p[i]);
            chmin(pmin, p[i]);
            chmax(qmax, q[i]);
            chmin(qmin, q[i]);
        }

        res = min( 1.*pmin/pmax, 1.*qmin/qmax );
        if(connected) res *= 1000000.;
        else res *= 1000.;

        return res;
    }





    // ランダムな解
    void solve_random(){
        vec(ll) v(K);
        rep(i,K){
            if(i<L) v[i] = i+1;
            else v[i] = RandInt(1,L);
        }
        shuffle(all(v), engine);
        rep(i,K) ans[i+1] = v[i];
    }


    // 山登り法1
    void solve_climb1(){
        double now = GetScore();

        while(clock()-start_time < TIMELIMIT){
            ll x,a,b;
            x = RandInt(1,K);
            a = ans[x];
            b = RandInt(1,L);
            if(a==b) continue;

            p[a] -= A[x];
            p[b] += A[x];
            q[a] -= B[x];
            q[b] += B[x];
            ans[x] = b;

            double tmp = GetScore();
            if(chmax(now,tmp)) continue;

            p[a] += A[x];
            p[b] -= A[x];
            q[a] += B[x];
            q[b] -= B[x];
            ans[x] = a;

        }
    }


    // bfsで適当にL分割
    void solve_bfs(){

        vec(ll) tmpv;
        rep1(i,K) tmpv.push_back(i);
        shuffle(all(tmpv),engine);

        rep1(i,K) ans[i]=0;
        queue<ll> que;
        auto qpush = [&](ll to, ll x){
            if(ans[to]>0) return;
            ans[to] = x;
            que.emplace(to);
        };

        rep(i,L) qpush(tmpv[i], i+1);

        while(!que.empty()){
            ll q0 = que.front();
            que.pop();
            
            for(ll to:g[q0]){
                qpush(to, ans[q0]);
            }
        }

        rep1(i,L) p[i] = 0;
        rep1(i,L) q[i] = 0;

        rep1(i,K){
            p[ans[i]] += A[i];
            q[ans[i]] += B[i]; 
        }

    }


    // annealing1
    void solve_annealing1(){
        // 初期値生成
        solve_bfs();

        double now = GetScore();

        while(clock()-start_time < TIMELIMIT){
            ll x = RandInt(1,K);
            ll a = ans[x];
            shuffle(all(g[x]),engine);

            for(ll y:g[x]){
                ll b = ans[y];
                if(a==b) continue;

                p[a] -= A[x];
                p[b] += A[x];
                q[a] -= B[x];
                q[b] += B[x];
                ans[x] = b;

                double nxt = GetScore();
                double dt = (clock()-start_time)/TIMELIMIT; //(CLOCKS_PER_SEC);
                double T = 30. *exp( 1. / (1.-dt) );
                //double T = 30.*(1.-dt); 

                double probability = exp( min(0., 1.*(nxt-now)/T ) );
                if(Randdouble() < probability && p[a]>0 && q[a]>0){
                    now = nxt;
                    break;
                }

                //if(chmax(now,nxt)) break;

                p[a] += A[x];
                p[b] -= A[x];
                q[a] += B[x];
                q[b] -= B[x];
                ans[x] = a;
            }

        }


    }



    // annealing2
    void solve_annealing2(){

        double tl1 = TIMELIMIT * 0.5;
        double tl2 = TIMELIMIT - tl1;

        // 初期値生成
        double now = GetScore_botu();
        vec(ll) ans2 = ans, p2=p, q2=q;
        while(clock()-start_time < tl1){
            solve_bfs();
            if(chmax(now, GetScore_botu())){
                ans2 = ans; p2=p; q2=q;
            }
        }
        ans = ans2; p=p2; q=q2;

        //for(ll ti=0; clock()-start_time < TIMELIMIT ; ti++){
        while(clock()-start_time < TIMELIMIT){
            ll x = RandInt(1,K);
            ll a = ans[x];
            shuffle(all(g[x]),engine);

            for(ll y:g[x]){
                ll b = ans[y];
                if(a==b) continue;

                p[a] -= A[x];
                p[b] += A[x];
                q[a] -= B[x];
                q[b] += B[x];
                ans[x] = b;

                double nxt = GetScore_botu();

                if(nxt*100. > now){

                    double dt = (clock()-start_time)/TIMELIMIT; //(CLOCKS_PER_SEC);
                    //double dt = (clock()-start_time-tl1)/tl2;

                    //double T = 30. *exp( 1. / (1.-dt) );
                    //double T = (1. - dt)/dt; 
                    double T = 30.*(1.-dt);

                    double probability = exp( min(0., 1.*(nxt-now)/T ) );
                    if(Randdouble() < probability && p[a]>0 && q[a]>0){
                        now = nxt;
                        break;
                    }

                    //if(chmax(now,nxt)) break;
                }


                p[a] += A[x];
                p[b] -= A[x];
                q[a] += B[x];
                q[b] -= B[x];
                ans[x] = a;
            }

        }
    }



    // annealing2-2
    void solve_annealing22(){

        double tl1 = TIMELIMIT * 0.6;
        double tl2 = TIMELIMIT - tl1;

        // 初期値生成
        double now = GetScore();
        vec(ll) ans2 = ans, p2=p, q2=q;
        while(clock()-start_time < tl1){
            solve_bfs();
            if(chmax(now, GetScore())){
                ans2 = ans; p2=p; q2=q;
            }
        }
        ans = ans2; p=p2; q=q2;

        while(clock()-start_time < TIMELIMIT){
            ll x = RandInt(1,K);
            ll a = ans[x];
            shuffle(all(g[x]),engine);

            for(ll y:g[x]){
                ll b = ans[y];
                if(a==b) continue;
                ans[x] = b;

                double nxt = GetScore();

                if(nxt*100. > now){
                    double dt = (clock()-start_time)/TIMELIMIT; //(CLOCKS_PER_SEC);
                    //double dt = (clock()-start_time-tl1)/tl2;

                    //double T = 30. *exp( 1. / (1.-dt) );
                    //double T = (1. - dt)/dt; 
                    double T = 10.*(1.-dt);

                    double probability = exp( min(0., 1.*(nxt-now)/T ) );
                    if(Randdouble() < probability){
                        now = nxt;
                        break;
                    }
                }
                ans[x] = a;
            }

        }
    }



    // annealing3
    void solve_annealing3(){

        ll tryN = 3;
        double tl1 = TIMELIMIT/tryN;
        double bestscore = 0.;
        vec(ll) bestans = ans;

        rep(_,tryN){

            // 初期値生成
            solve_bfs();
            double now = GetScore();

            while(clock()-start_time < TIMELIMIT){
                ll x = RandInt(1,K);
                ll a = ans[x];
                shuffle(all(g[x]),engine);

                for(ll y:g[x]){
                    ll b = ans[y];
                    if(a==b) continue;
                    ans[x] = b;

                    double nxt = GetScore();

                    if(nxt*100. > now){
                        double dt = (clock()-start_time)/TIMELIMIT; //(CLOCKS_PER_SEC);
                        
                        //double T = 30. *exp( 1. / (1.-dt) );
                        //double T = (1. - dt)/dt; 
                        double T = 30.*(1.-dt);

                        double probability = exp( min(0., 1.*(nxt-now)/T ) );
                        if(Randdouble() < probability){
                            now = nxt;
                            break;
                        }
                    }
                    ans[x] = a;
                }
            }

            if(chmax(bestscore, now)) bestans = ans;
        }
        ans = bestans;
    }




};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve_annealing22();
        solver.Submit();
        //solver.Submit_file();
    }
    return 0;
}
