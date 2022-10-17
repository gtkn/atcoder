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

double op(double a, double b){return max(a,b);}
double ee(){return -1e10;};


struct Solver{
    ll N,K,L;
    vec(ll) A,B;
    vvec(ll) C;
    vec(ll) ans;
    ll start_time;
    ll TIMELIMIT = 0.95 * CLOCKS_PER_SEC;
    vvec(ll) g;
    vector<set<ll>> gs;

    double pave,qave;
    double sf;


    Solver(){
        // 読み込み
        cin >> N >> K >> L;
        A.resize(K+1);
        B.resize(K+1);
        ans.resize(K+1);
        C = vvec(ll)(N,vec(ll)(N));

        rep1(i,K) cin >> A[i] >> B[i];
        rep(i,N)rep(j,N) cin >> C[i][j];

        start_time = clock();
        


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
        rep1(i,K){
            sort(all(g[i]));
            g[i].erase(unique(all(g[i])), g[i].end());
        }


        // P,Qの平均に近いほうが良いはず
        pave = 0;
        qave = 0;
        rep1(i,K) pave += A[i];
        rep1(i,K) qave += B[i];
        
        pave /= (ll)L;
        qave /= (ll)L;        
        sf = 1.*pave/qave;

        
    }


    // 結果出力
    void Submit(){
        assert(ans.size()==K+1);
        rep1(i,K){
            if(ans[i]<=0 || ans[i]>L) cout << i << ": " << ans[i] << endl;
            assert(ans[i]>0 && ans[i]<=L);
            cout << ans[i] << endl;
        }
    }


    // デバッグ用ファイルに出力
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


    // 経過時間
    ll pasttime(ll st = -1){
        if(st==-1) st = start_time;
        return clock()-st;
    } 


    // 連結チェック
    bool IsConnected(){

        vec(bool) used(L+1);
        vec(bool) reached(1+K);

        rep1(st,K){
            if(reached[st]) continue;
            ll x = ans[st];
            if(used[x]) return false;

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

        return true;
    }


    // スコア計算 PQのみ
    double GetPQScore(){
        double res = 0;
        vec(ll) pp(L+1),qq(L+1);

        rep1(i,K) pp[ans[i]] += A[i];
        rep1(i,K) qq[ans[i]] += B[i];


        ll pmax=0,pmin=llINF,qmax=0,qmin=llINF;
        rep1(i,L){
            chmax(pmax, pp[i]);
            chmin(pmin, pp[i]);
            chmax(qmax, qq[i]);
            chmin(qmin, qq[i]);
        }

        res = min( 1.*pmin/pmax, 1.*qmin/qmax ) * 1000000.;
        if(pmin==0. || qmin==0.) res = 0.;

        return res;
    }


    // スコア計算
    double GetScore(){
        double res = GetPQScore();
        if(!IsConnected()) res/= 1000.;
        return res;
    }


    
    // p,qのばらつき
    double Getpqcost(){
        vec(ll) pp(L+1),qq(L+1);
        rep1(i,K) pp[ans[i]] += A[i];
        rep1(i,K) qq[ans[i]] += B[i];

        double pcost=0, qcost=0;
        rep1(i,L) pcost += abs(pp[i] - pave);
        rep1(i,L) qcost += abs(qq[i] - qave);

        /*
        rep1(i,L) pcost += (pp[i] - pave)*(pp[i] - pave);
        rep1(i,L) qcost += (qq[i] - qave)*(qq[i] - qave);

        pcost = sqrt(pcost);
        qcost = sqrt(qcost);
        */

        return pcost + sf*qcost;

    }


    // 特別区aが(pave,qave)とどのくらい離れているか
    double Getdist(ll a){
        double pp=0,qq=0;
        rep1(i,L) if(ans[i]==a) pp+=A[i];
        rep1(i,L) if(ans[i]==a) qq+=B[i];

        return abs(pave-pp) + sf*abs(qave-qq);
    }

    // 地区xが今の特別区(a)からbに変わった時にaのdistがどのくらい変わるか
    double Getddist_a(ll x,ll b){
        ll a = ans[x];

        double pp=0,qq=0;
        rep1(i,L) if(ans[i]==a) pp+=A[i];
        rep1(i,L) if(ans[i]==a) qq+=B[i];

        double bef,aft;
        bef = abs(pave-pp) + sf*abs(qave-qq);

        pp -= A[x];
        qq -= B[x];
        aft = abs(pave-pp) + sf*abs(qave-qq);

        return aft-bef;
    }

    // 地区xが今の特別区(a)からbに変わった時にbのdistがどのくらい変わるか
    double Getddist_b(ll x,ll b){
        double pp=0,qq=0;
        rep1(i,L) if(ans[i]==b) pp+=A[i];
        rep1(i,L) if(ans[i]==b) qq+=B[i];

        double bef,aft;
        bef = abs(pave-pp) + sf*abs(qave-qq);

        pp += A[x];
        qq += B[x];
        aft = abs(pave-pp) + sf*abs(qave-qq);

        return aft-bef;
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
    }




    // なるべく理想的な人口になるようbfsで適当にL分割
    void solve_bfs_ideal(){
        while(!_solve_bfs_ideal());
    }

    bool _solve_bfs_ideal(){
        vec(ll) tmpv;
        rep1(i,K) tmpv.push_back(i);
        shuffle(all(tmpv),engine);

        rep1(i,K) ans[i]=0;

        ll lcnt = 1;

        // なるべくいい感じの特別区を作る
        for(ll i:tmpv){
            if(ans[i]>0) continue;

            queue<ll> que; que.push(i);
            double pcnt=0, qcnt=0;

            while(!que.empty()){
                ll q0 = que.front();
                que.pop();
                if(ans[q0]>0) continue;
                ans[q0] = lcnt;
                pcnt += A[q0];
                qcnt += B[q0];
                if(pcnt > pave || qcnt>qave) break;

                for(ll to: g[q0]) if(ans[to]==0) que.push(to);
            }
            if(lcnt==L) break;
            lcnt++;
        }

        if(lcnt<L) return false;


        // 余りは適当にくっつける // ここもなるべくいい感じにしたほうがいいか?
        queue<ll> que;
        rep1(i,K) if(ans[i]==0) que.push(i);
        while(!que.empty()){
            ll q0 = que.front();
            que.pop();
            
            double dmax = 1e10;
            ll nxt = 0;
            for(ll to:g[q0]){
                ll b = ans[to];
                if(b==0) continue;
                if(chmin(dmax, Getddist_b(q0, b))) nxt = b;
            }

            if(nxt!=0) ans[q0] = nxt;
            else que.push(q0);
        }

        return true;
    }



    // 焼きなます感じ
    void solve_annealing(){
        double tl1 = TIMELIMIT * 0.7;
        double tl2 = TIMELIMIT * 0.7;

        // 初期値生成
        solve_bfs_ideal();
        double now = GetPQScore(); // 連結なはずなので
        vec(ll) ans2 = ans;
        while(clock()-start_time < tl1){
            solve_bfs();
            if(chmax(now, GetPQScore())) ans2 = ans;
        }
        ans = ans2;



        // p,qの分布を改善
        vec(ll) pp(L+1),qq(L+1);
        rep1(i,K) pp[ans[i]] += A[i];
        rep1(i,K) qq[ans[i]] += B[i];
        vec(double) tmpv(L+1);
        rep1(i,L) tmpv[i] = (pp[i]-pave) + sf * (qq[i]-qave);
        segtree<double, op, ee> seg(tmpv);
        vector<set<ll>> vs(L+1);
        rep1(i,K) vs[ans[i]].insert(i);


        while(clock()-start_time < tl2){
            ll a = seg.all_prod();
        }




        // スコアを改善
        double nowscore = GetScore();
        while(clock()-start_time < TIMELIMIT){
            ll x = RandInt(1,K);
            ll a = ans[x];
            shuffle(all(g[x]),engine);

            for(ll y:g[x]){
                ll b = ans[y];
                if(a==b) continue;
                ans[x] = b;

                if(!IsConnected()){
                    ans[x]=a;
                    continue;
                }

                double nxtscore = GetPQScore();


                //double dt = (clock()-start_time)/TIMELIMIT; //(CLOCKS_PER_SEC);
                double dt = (clock()-start_time-tl2)/(TIMELIMIT -tl2);

                //double T = 30. *exp( 1. / (1.-dt) );
                //double T = (1. - dt)/dt; 
                double T = 30.*(1.-dt);

                double probability = exp( min(0., 1.*(nxtscore-nowscore)/T ) );
                if(Randdouble() < probability){
                    nowscore = nxtscore;
                    break;
                }else{
                    ans[x] = a;
                }
            }
        }





    }


   
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve_annealing();
        //solver.solve_bfs_ideal();
        solver.Submit();
        //solver.Submit_file();
    }
    return 0;
}
