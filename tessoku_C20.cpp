//title
//#define _GLIBCXX_DEBUG
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
    ll TIMELIMIT = 0.95 * CLOCKS_PER_SEC;
    //vvec(ll) g;
    vector<set<ll>> g;
    vvec(bool) gvv; // 地区の隣接グラフgの行列表現

    double pave,qave;

    vec(ll) pvec,qvec;
    ll pmax=0,pmin=llINF,qmax=0,qmin=llINF;


    ll start_time;
    vec(ll) ans,ans_tmp;
    vector<set<ll>> rev_ans; // rev_ans[i]:特別区iに属する地区のset
    vvec(set<ll>) vvs; // vvs[i][j]:特別区iに属する,特別区jに隣接する地区のset


    Solver(){
        // 読み込み
        cin >> N >> K >> L;
        A.resize(K+1);
        B.resize(K+1);
        C = vvec(ll)(N,vec(ll)(N));

        rep1(i,K) cin >> A[i] >> B[i];
        rep(i,N)rep(j,N) cin >> C[i][j];

        pvec.resize(L+1);
        qvec.resize(L+1);

        ans.resize(K+1);
        rev_ans.resize(L+1);
        vvs = vector<vector<set<ll>>>(L+1,vector<set<ll>>(L+1));


        // 隣接する地区リスト
        g.resize(K+1);
        gvv = vvec(bool)(K+1,vec(bool)(K+1));
        rep(i,N)rep(j,N){
            ll now = C[i][j];
            if(now==0) continue;
            if(i<N-1){
                ll to = C[i+1][j];
                if(now!=to && to!=0){
                    //g[now].push_back(to);
                    //g[to].push_back(now);
                    g[now].insert(to); g[to].insert(now);
                }
            }
            if(j<N-1){
                ll to = C[i][j+1];
                if(now!=to && to!=0){
                    //g[now].push_back(to);
                    //g[to].push_back(now);
                    g[now].insert(to); g[to].insert(now);
                }
            }
        }
        rep1(i,K){
            //sort(all(g[i]));
            //g[i].erase(unique(all(g[i])), g[i].end());
            for(ll j:g[i]) gvv[i][j]=true;
        }


        // P,Qの平均に近いほうが良いはず
        pave = 0;
        qave = 0;
        rep1(i,K) pave += A[i];
        rep1(i,K) qave += B[i];
        
        pave /= (ll)L;
        qave /= (ll)L;        
        
    }




    // answerの更新
    void SetAnswer(ll x,ll b){
        assert(x>0 && x<=K && b>0 && b<=L);
        ll a = ans[x];
        ans[x]=b;
        rev_ans[a].erase(x);
        rev_ans[b].insert(x);
        pvec[a]-=A[x];
        pvec[b]+=A[x];
        qvec[a]-=B[x];
        qvec[b]+=B[x];

        /*
        for(ll y:g[x]){
            if(ans[y]==0) continue;
            if(ans[y]==a){
                vvs[a][b].insert(y);
                vvs[b][a].insert(x);
            }else if(ans[y]==b){
                if(a>0) vvs[a][b].erase(x);
                if(a>0) vvs[b][a].erase(y);
            }else{
                if(a>0) vvs[a][ans[y]].erase(x);
                if(a>0) vvs[ans[y]][a].erase(y);
                vvs[b][ans[y]].insert(x);
                vvs[ans[y]][b].insert(y);
            }
        }        
        */
    }

    // answerの初期化
    void ResetAnswer(){
        rep(i,K+1) ans[i]=0;
        rep(i,L+1) pvec[i]=0;
        rep(i,L+1) qvec[i]=0;
        rep(i,L+1) rev_ans[i].clear();
        rep1(i,K) rev_ans[0].insert(i);
        //rep1(i,L)rep1(j,L) vvs[i][j].clear();
    }

    // p/q/min/maxの更新
    void UpdatePQ(){
        pmax=0; pmin=llINF;
        qmax=0; qmin=llINF;

        rep1(i,L){
            chmax(pmax, pvec[i]);
            chmin(pmin, pvec[i]);
            chmax(qmax, qvec[i]);
            chmin(qmin, qvec[i]);
        }

    }


    // vvsを張りなおす
    void Updatevvs(vvec(set<ll>) &vvs){
        //rep1(i,L)rep1(j,L) if(!vvs[i][j].empty()) vvs[i][j].clear();
        rep(i,L+1)rep(j,L+1) vvs.at(i).at(j).clear();
        rep1(a,K){
            for(ll b:g[a]){
                if(ans[a]<=0 || ans[a]>L) cout << a << " error" << ans[a]<< endl;
                if(ans[b]<=0 || ans[b]>L) cout << b << " error" << ans[b]<< endl;
                if(b<=0 || b>K) cout << b <<" erroror" << a<< endl;
                if(ans[a]==ans[b]) continue;
                vvs[ans[a]][ans[b]].insert(a);
            }
        }
    }


    // vvsのデバッグ用
    void check_vvs_debug(){
        vvec(set<ll>) vvs_tmp = vvs;
        Updatevvs(vvs);
        rep1(i,L)rep1(j,L){
            if(vvs[i][j].size() != vvs_tmp[i][j].size()){
                cout << "nono " << i << " , " << j << endl;
                for(ll si:vvs[i][j]) cout << si <<" "; cout << endl;
                for(ll si:vvs_tmp[i][j]) cout << si <<" "; cout << endl;
                return;
            }
            for(ll si:vvs[i][j])for(ll sj:vvs_tmp[i][j]){
                if(si!=sj){
                    cout << "aaa" << si <<" , " << sj << endl;
                    return;
                }
            }
        }
    }



    // 結果出力
    void Submit(){
        assert(ans.size()==K+1);
        rep1(i,K){
            //if(ans[i]<=0 || ans[i]>L) cout << i << ": " << ans[i] << endl;
            assert(ans[i]>0 && ans[i]<=L);
            cout << ans[i] << endl;
        }
    }


    // デバッグ用ファイルに出力
    void Submit_file(){
        ofstream outputfile("out.dat");
        rep1(i,K) outputfile<< ans[i] << endl;
        outputfile.close();
        cout <<  GetScore() << endl;
    }


    // 0.以上1.未満の整数をランダムに返す関数
    double Randdouble(){
        return 1. * rand() / RAND_MAX;
    }

    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }

    // setからランダムに値を得る
    ll random_set(set<ll> &s){
        auto it = s.cbegin();
        int random = rand() % s.size();
        advance(it, random);
        return *it;
    }



    // startからの経過時間
    double pasttime(ll st = -1){
        return 1.*(clock()-st)/TIMELIMIT;
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


    // ある特別区について連結チェック // rev_ans[a]は正しいとする
    bool IsConnected_PS(ll a){
        map<ll,bool> used;
        for(ll ai:rev_ans[a]) used[ai]=false;


        queue<ll> que;
        que.push(*rev_ans[a].begin());
        while(!que.empty()){
            ll q0 = que.front();
            que.pop();
            if(used[q0]) continue;
            used[q0] = true;
            for(ll to:g[q0]) if(ans[to]==a) que.push(to);
        }

        for(ll ai:rev_ans[a]) if(!used[ai]) return false;
        return true;
    }


    // スコア計算 PQのみ
    double GetPQScore(){
        double res = 0;
        UpdatePQ();

        res = min( 1.*pmin/pmax, 1.*qmin/qmax ) * 1000000.;
        if(pmin==0 || qmin==0) res = 0.;

        return res;
    }


    // スコア計算
    double GetScore(){
        double res = GetPQScore();
        if(!IsConnected()) res/= 1000.;
        rep1(i,K) if(ans[i]==0) res = 0.;
        return res;
    }


    


    // 特別区aが(pave,qave)とどのくらい離れているか
    double Getdist(ll a){
        //return abs(pave-pvec[a]) + sf*abs(qave-qvec[a]);
        double dp,dq;
        dp = (pave-pvec[a])/pave;
        dq = (qave-qvec[a])/qave;
        return dp*dp + dq*dq;
    }



    // 地区xが今の特別区(a)からbに変わった時に a のdistがどのくらい変わるか
    double Getddist_a(ll x){
        ll a = ans[x];
        double res = 0.;
        pvec[a] -= A[x];
        qvec[a] -= B[x];
        res += Getdist(x);
        pvec[a] += A[x];
        qvec[a] += B[x];
        res -= Getdist(x);

        return res;
    }

    // 地区xが今の特別区(a)からbに変わった時に b のdistがどのくらい変わるか
    double Getddist_b(ll x,ll b){
        double res = 0.;
        pvec[b] += A[x];
        qvec[b] += B[x];
        res += Getdist(x);
        pvec[b] -= A[x];
        qvec[b] -= B[x];
        res -= Getdist(x);

        return res;
    }

    // 地区xが今の特別区(a)からbに変わった時に 全体 のdistがどのくらい変わるか
    double Getddist_ab(ll x,ll b){
        return Getddist_a(x) + Getddist_b(x,b);
    }



    // ある地区aiを他の特別区に変える時に一緒に変えるべき地区のリスト
    // aiによって特別区が2個に分断される場合小さいほうを道連れにする
    set<ll> bridge_group(ll ai){
        ll a = ans[ai];

        vector<set<ll>> vs;
        vec(bool) used(L+1);
        used[ai]=true;

        for(ll st:rev_ans[a]){
            if(used[st]) continue;

            set<ll> tmp;
            queue<ll> que;
            que.push(st);

            while(!que.empty()){
                ll q0 = que.front();
                que.pop();
                if(used[q0]) continue;
                used[q0]=true;
                tmp.insert(q0);
                for(ll q1:g[q0]) if(ans[q1]==a) que.push(q1);
            }
            
            vs.push_back(tmp);
        }

        if(vs.size()!=2) return {ai};

        rep(i,2) vs[i].insert(ai);
        if(vs[0].size() < vs[1].size()) return vs[0];
        else return vs[1];
    }



    // 2点変更して孤立しないか
    bool check_close(ll a1,ll a2){
        ll sp1=ans[a1];
        ll sp2=ans[a2];

        bool f1=false;
        for(ll b:g[a1]) if(b!=a2 && ans[b]==sp2) f1=true;
        bool f2=false;
        for(ll b:g[a2]) if(b!=a1 && ans[b]==sp1) f2=true;

        return f1&f2;
    }


    // 操作時の改善度合
    double eval_diff(ll sp1,ll sp2,set<ll> s1,set<ll> s2){
        double bef,aft;
        bef = Getdist(sp1) + Getdist(sp2);
        
        ll p1,p2,q1,q2;
        p1 = pvec[sp1]; p2 = pvec[sp2];
        q1 = qvec[sp1]; q2 = qvec[sp2];


        // sp1 -> sp2
        for(ll x:s1){
            p1 -= A[x];
            p2 += A[x];
            q1 -= B[x];
            q2 += B[x];
        }

        // sp2 -> sp1
        for(ll x:s2){
            p2 -= A[x];
            p1 += A[x];
            q2 -= B[x];
            q1 += B[x];
        }


        swap(p1,pvec[sp1]); swap(p2,pvec[sp2]);
        swap(q1,qvec[sp1]); swap(q2,qvec[sp2]);

        aft = Getdist(sp1) + Getdist(sp2);

        swap(p1,pvec[sp1]); swap(p2,pvec[sp2]);
        swap(q1,qvec[sp1]); swap(q2,qvec[sp2]);


        return bef - aft; // 正なら改善
    }



    // ランダムな解
    void solve_random(){
        ResetAnswer();
        vec(ll) v(K);
        rep(i,K){
            if(i<L) v[i] = i+1;
            else v[i] = RandInt(1,L);
        }
        shuffle(all(v), engine);
        rep(i,K) SetAnswer(i+1, v[i]); //ans[i+1] = v[i];
    }





    // bfsで適当にL分割
    void solve_bfs(){
        ResetAnswer(); //rep1(i,K) ans[i]=0;

        vec(ll) tmpv;
        rep1(i,K) tmpv.push_back(i);
        shuffle(all(tmpv),engine);

        queue<ll> que;
        auto qpush = [&](ll to, ll a){
            if(ans[to]>0) return;
            SetAnswer(to,a); //ans[to] = a;
            que.emplace(to);
        };

        rep(i,L) qpush(tmpv[i], i+1);

        while(!que.empty()){
            ll q0 = que.front();
            que.pop();
            for(ll to:g[q0]) qpush(to, ans[q0]);
        }
    }




    // なるべく理想的な人口になるようbfsで適当にL分割
    void solve_bfs_ideal(){
        while(!_solve_bfs_ideal());
    }

    bool _solve_bfs_ideal(){
        ResetAnswer(); //rep1(i,K) ans[i]=0;

        vec(ll) tmpv;
        rep1(i,K) tmpv.push_back(i);
        shuffle(all(tmpv),engine);


        ll lcnt = 1;

        // なるべくいい感じの特別区を作る
        for(ll i:tmpv){
            if(ans[i]>0) continue;
            queue<ll> que; que.push(i);

            while(!que.empty()){
                ll q0 = que.front();
                que.pop();
                if(ans[q0]>0) continue;
                SetAnswer(q0,lcnt); //ans[q0] = lcnt;
                if(pvec[lcnt]>pave || qvec[lcnt]>qave) break;

                for(ll to:g[q0]) if(ans[to]==0) que.push(to);
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
            
            double dmax = 1e15;
            ll nxt = 0;
            for(ll to:g[q0]){
                ll b = ans[to];
                if(b==0) continue;
                if(chmin(dmax, Getddist_b(q0, b))) nxt = b;
                //nxt=b; break;
            }

            if(nxt!=0) SetAnswer(q0,nxt);//ans[q0] = nxt;
            else que.push(q0);
        }

        return true;
    }







    //--- 解く ---
    void solve(){
        start_time = clock();        
        double tl1 = TIMELIMIT * 0.01;
        double tl2 = TIMELIMIT;// * 0.99;


        // 初期値生成
        ll _cnt0=0;
        double nowscore = -1;
        while(clock()-start_time < tl1){
            solve_bfs_ideal();
            _cnt0++;
            if(chmax(nowscore, GetPQScore())) ans_tmp = ans; // 連結なはずなのでPQのスコアのみ確認
        }
        if(nowscore<0) solve_bfs();

        
        ResetAnswer();
        rep1(i,K) SetAnswer(i, ans_tmp[i]); // ans = ans2;
        Updatevvs(vvs); // vvsがでたらめになっているので初期化
        nowscore = GetPQScore();


        cout << "cnt0 : " << _cnt0 << " ; " << nowscore <<endl;
        //Submit_file();


    



        // p,qの分布を改善
        vec(double) dvec(L+1);
        rep1(i,L) dvec[i] = Getdist(i);

        ll _cnt1 = 0;
        //vec(ll) idxs;
        //rep1(i,L) idxs.push_back(i);

        while(clock()-start_time < tl2){
            // 一番理想から遠そうな特別区を探す            
            //sort(all(idxs),[&](ll const& vi,ll const& vj){return dvec[vi]>dvec[vj];});
            // とりあえずランダムで


            // 摂動を調べる
            // s1の地区を特別区sp2に変える
            ll sp1,sp2=0;
            set<ll> s1,s2;
            Submit_file();

            while(s1.empty()){
            //for(ll a:idxs){
                // 初期化
                sp1 = RandInt(1,L);
                if(rev_ans[sp1].size() < 3) continue;

                while(1){
                    ll x = RandInt(1,L);
                    if(vvs[sp1][x].empty()) continue;
                    if(sp1==sp2) continue;
                    sp2=x;
                    break;
                }
                s1.clear(); s2.clear();

                cout << _cnt1 << " : " << sp1 << " , " << sp2 << endl;
                cout << vvs[sp1][sp2].size() <<":"<< vvs[sp1][sp2].empty()<<  endl;
                cout << vvs[sp2][sp1].size() <<":"<< vvs[sp2][sp1].empty()<<  endl;

                for(ll si:vvs[sp1][sp2]) cout << si <<" "; cout << ",,," << sp1 << "-" << sp2 << endl; 
                for(ll si:vvs[sp2][sp1]) cout << si <<" "; cout << ",,," << sp2 << "-" << sp1 << endl; 

                ll a1 = random_set(vvs[sp1][sp2]);
                ll a2 = random_set(vvs[sp2][sp1]);

                cout << a1 <<" ! " << a2 << endl;


                if(Randdouble()<1.5){ // 1点変更
                    s1 = bridge_group(a1);
                    if(s1.size()>1){
                        if( pvec[sp2]>0.9*pave && qvec[sp2]>0.9*qave) continue; // 道連れするうまみが無ければcontinue
                    }
                    cout << "1point" << endl; 
                }else{ // 2点変更
                    if(!check_close(a1,a2)) continue;
                    if(bridge_group(a1).size()>1 || bridge_group(a2).size()>1) continue;
                    s1.insert(a1); s2.insert(a2);
                }

            }


            // 更新

            double dd = eval_diff(sp1,sp2,s1,s2);
            double dt = (clock()-start_time-tl1)/(tl2 -tl1);
            double T = 30 * 1./(1. + exp(dt*2.-1.)); // シグモイド的な
            double probability = exp( min(0., 1.*dd/T ) );


            if(Randdouble() < probability){
                _cnt1++;

                for(ll si:s1) cout << si <<" "; cout << " ; " << sp1 << endl;
                for(ll si:s2) cout << si <<" "; cout << " ; " << sp2 << endl;
                //Submit_file();


                for(ll si:rev_ans[sp1]) cout << si << " "; cout <<" ::" <<sp1 << endl;
                for(ll si:s1) SetAnswer(si, sp2);

                for(ll si:rev_ans[sp2]) cout << si << " "; cout <<" ::" <<sp2 << endl;
                if(!s2.empty()) for(ll si:s2) SetAnswer(si, sp1); // 1点変更の時はs2はemptyのはず
                
                cout << "update" << endl;
                Updatevvs(vvs);
                cout << "done " << endl;

                break;
                //return;

            }



        }
        cout << "cnt1 : " << _cnt1 << endl;


    }



    void check(){

        vec(ll) pchk = pvec, qchk=qvec;

        rep1(i,K) pchk[ans[i]]-=A[i];
        rep1(i,K) qchk[ans[i]]-=B[i];

        /*
        rep1(i,L){
            cout << i <<" :: ";
            for(ll x:rev_ans[i]) cout << x << " ";
            cout << endl;
        }
        */
        rep1(i,K) if(!sfind( rev_ans[ans[i]], i )) cout << i << " ! " << ans[i] << endl;

        rep1(i,L) if(pchk[i]!=0) cout << i << " p " << pchk[i] << endl;
        rep1(i,L) if(qchk[i]!=0) cout << i << " q " << qchk[i] << endl;

    }

    void AverageScore(){
        ll nn = 10;
        vec(ll) scores(nn);

        rep(i,nn){
            cout << " ---"<<i<<"----" << endl;
            ResetAnswer();
            start_time = clock();
            solve();
            scores[i] = GetScore();
            cout << "socre : " << scores[i] << endl;
        }

        double ave = 0;
        rep(i,nn) ave += scores[i];
        ave/=(ll)nn;
        cout <<"average : " <<  ave << endl;

    }

   
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
        //solver.solve_bfs_ideal();
        //solver.solve_bfs();
        //solver.Submit();
        //solver.check();
        solver.Submit_file();
        //solver.AverageScore();
    }
    return 0;
}
