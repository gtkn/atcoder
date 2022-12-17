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

ll N=50;
ll K=400;
ll L=20;



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


// 0.以上1.未満の整数をランダムに返す関数
double Randdouble(){
    return 1. * rand() / RAND_MAX;
}

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}

// setからランダムに値を得る
ll random_set(const set<ll> &s){
    if(s.empty()) cerr << "s is empty in random_set" << endl;
    auto it = s.cbegin();
    int random = rand() % s.size();
    advance(it, random);
    return *it;
}



// デバッグ用ファイルに出力
void Submit_file(const vec(ll) &ans){
    ofstream outputfile("out.dat");
    rep1(i,K) outputfile<< ans[i] << endl;
    outputfile.close();
}



struct SR{
    ll asum,bsum;
    set<ll> regions;
    set<ll> neighbors;

    SR(){
        asum=0,bsum=0;
    }
};




// なるべく理想的な人口になるようbfsで適当にL分割
vec(ll) bfs_ideal(const vec(ll) &A, const vec(ll) &B, const vec(set<ll>) &g, double pave, double qave){
    vec(ll) res(K+1);

    vec(ll) tmpv(K);
    rep(i,K) tmpv[i] = i+1;
    shuffle(all(tmpv),engine);


    vec(ll) pvec(L+1),qvec(L+1);
    auto getDist = [&](ll x){
        double diffp = (pave-pvec[x])/pave;
        double diffq = (qave-qvec[x])/qave;
        return diffp*diffp + diffq*diffq;
    };



    ll lcnt = 1;

    // なるべくいい感じの特別区を作る
    for(ll i:tmpv){
        if(res[i]>0) continue;
        queue<ll> que; que.push(i);
        double pcnt=0,qcnt=0;

        while(!que.empty()){
            ll q0 = que.front();
            que.pop();
            if(res[q0]>0) continue;

            res[q0]=lcnt;
            pcnt += A[q0];
            qcnt += B[q0];

            if(pcnt>pave || qcnt>qave) break;
            for(ll to:g[q0]) if(res[to]==0) que.push(to);
        }
        pvec[lcnt] = pcnt;
        qvec[lcnt] = qcnt;

        if(lcnt==L) break;
        lcnt++;
    }

    if(lcnt<L){
        res[0]=-1;
        return res;
    }


    // 余りは適当にくっつける // ここもなるべくいい感じにしたほうがいいか?
    queue<ll> que;
    rep1(i,K) if(res[i]==0) que.push(i);
    while(!que.empty()){
        ll q0 = que.front();
        que.pop();
        
        ll nxt = 0;
        double dmin=1e10;
        for(ll to:g[q0]){
            ll b = res[to];
            if(b==0) continue;
            pvec[b]+=A[q0]; qvec[b]+=B[q0];
            if(chmin(dmin, getDist(b))) nxt = b;
            pvec[b]-=A[q0]; qvec[b]-=B[q0];
        }

        if(nxt!=0){
            res[q0] = nxt;
            pvec[nxt]+=A[q0]; qvec[nxt]+=B[q0];
        }else que.push(q0);
    }

    return res;
}


// p,qの更新
void update_PQ(const vec(ll) &A, const vec(ll) &B, const vec(ll) &ans, vec(ll) &pvec, vec(ll) &qvec){
    rep(i,L+1) pvec[i]=0;
    rep(i,L+1) qvec[i]=0;
    
    rep1(i,K) pvec[ans[i]] += A[i];
    rep1(i,K) qvec[ans[i]] += B[i];
}

// 連結としてPQから解を計算
ll getScore_PQ(const vec(ll) &pvec, const vec(ll) &qvec){
    ll pmax=0,pmin=llINF,qmax=0,qmin=llINF;
    rep1(i,L) chmax(pmax,pvec[i]);
    rep1(i,L) chmin(pmin,pvec[i]);
    rep1(i,L) chmax(qmax,qvec[i]);
    rep1(i,L) chmin(qmin,qvec[i]);

    ll res = 0;
    if(pmin>0 && qmin>0) res = round( 1000000. * min(1.*pmin/pmax, 1.*qmin/qmax) );

    return res;
}



// 特別区と地区の隣接関係を更新 // vvs[a][b] : 特別区aに隣接する特別区bの地区
void update_vvs(vvec(set<ll>) &vvs ,const vec(ll) &ans, const vec(set<ll>) &g){
    rep(i,L+1)rep(j,L+1) vvs[i][j].clear();

    rep1(i,K)for(ll j:g[i]){
        if(ans[i]==ans[j]) continue;
        vvs[ans[i]][ans[j]].insert(i);
    }



}



// rev_ansの更新
void update_rev_ans(vec(set<ll>) &rev_ans, const vec(ll) &ans){
    rep1(i,L) rev_ans[i].clear();
    rep1(i,K) rev_ans[ans[i]].insert(i);
}




// ある地区xを他の特別区に変える時に一緒に変えるべき地区のリスト
// xによって特別区が2個に分断される場合小さいほうを道連れにする
set<ll> bridge_group(const ll x, const vec(set<ll>) &g, const vec(ll) &ans){
    ll a = ans[x];

    vector<set<ll>> vs;
    vec(bool) used(K+1);
    used[x]=true;

    rep1(st,K){
        if(ans[st]!=a) continue;
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

    if(vs.size()>2) return {};
    if(vs.size()==1) return {x};

    rep(i,2) vs[i].insert(x);
    if(vs[0].size() < vs[1].size()) return vs[0];
    else return vs[1];
}



// 2点変更して孤立しないか
bool check_close(ll r1,ll r2, const vec(set<ll>) g,const vec(ll) &ans){
    ll sp1=ans[r1];
    ll sp2=ans[r2];

    bool f1=false;
    for(ll b:g[r1]){
        if(b!=r2 && ans[b]==sp2) f1=true;
    }
    bool f2=false;
    for(ll b:g[r2]){
        if(b!=r1 && ans[b]==sp1) f2=true;
    }
    return f1&f2;
}




//---------------------
int main(){
    Timer timer;
    timer.begin(0.95);
    double timelimit1 = 0.02;

    // 読み込み
    cin >> N >> K >> L;
    vec(ll) A(K+1),B(K+1);
    rep1(i,K) cin >> A[i] >> B[i];
    vvec(ll) C(N,vec(ll)(N));
    rep(i,N)rep(j,N) cin >> C[i][j];


    // P,Qの平均に近いほうが良いはず
    double pave=0., qave=0.;
    rep1(i,K) pave += A[i];
    rep1(i,K) qave += B[i];    
    pave /= (ll)L;
    qave /= (ll)L;
    


    // 隣接する地区リスト
    vector<set<ll>> g(K+1);
    vvec(bool) gvv(K+1,vec(bool)(K+1)); // 地区の隣接グラフgの行列表現
    rep(i,N)rep(j,N){
        ll now = C[i][j];
        if(now==0) continue;
        if(i<N-1){
            ll to = C[i+1][j];
            if(now!=to && to!=0){g[now].insert(to); g[to].insert(now);}
        }
        if(j<N-1){
            ll to = C[i][j+1];
            if(now!=to && to!=0){g[now].insert(to); g[to].insert(now);}
        }
    }

    rep1(i,K) for(ll j:g[i]) gvv[i][j]=true;


    // その他変数
    vec(ll) pvec(L+1),qvec(L+1);
    vec(ll) ans(K+1), ans_tmp(K+1);
    vec(set<ll>) rev_ans(L+1);
    vvec(set<ll>) vvs(L+1,vec(set<ll>)(L+1)); // vvs[a][b] : 特別区aに隣接する特別区bの地区

    ll nowscore = 0;

    auto getDist = [&](ll x){
        double diffp = (pave-pvec[x])/pave;
        double diffq = (qave-qvec[x])/qave;
        return diffp*diffp + diffq*diffq;
    };




    // 初期解
    while(timer.inTime(timelimit1)){
        ans_tmp = bfs_ideal(A,B,g,pave,qave);
        update_PQ(A,B,ans_tmp,pvec,qvec);
        if(chmax(nowscore, getScore_PQ(pvec,qvec)) ) ans = ans_tmp;
    }
    update_PQ(A,B,ans,pvec,qvec);
    nowscore = getScore_PQ(pvec,qvec);
    update_vvs(vvs, ans, g);
    update_rev_ans(rev_ans,ans);





    // 焼きなます
    while(timer.inTime()){
        ll sp1,sp2=0;
        set<ll> s1,s2;

        while(s1.empty()){
            sp1 = RandInt(1,L);
            if(rev_ans[sp1].size()<3) continue;

            sp2=0;
            while(sp2==0){
                sp2 = RandInt(1,L);
                if(vvs[sp1][sp2].empty()) sp2=0;
            }



            ll r1 = random_set(vvs[sp1][sp2]);
            ll r2 = random_set(vvs[sp2][sp1]);



            if(Randdouble()<0.5){ // 1点変更,r1をsp2に
                s1 = bridge_group(r1,g,ans);
                if(s1.size()>1){
                    if( 0.9*pvec[sp2] > pave && 0.9*qvec[sp2] > qave) continue;
                }
            }else{ // 2点変更
                if(!check_close(r1,r2,g, ans)) continue;
                if(bridge_group(r1,g,ans).size()!=1 || bridge_group(r2,g,ans).size()!=1) continue;
                s1.insert(r1); s2.insert(r2);
            }
        }
        



        // p,qの改善を確認
        double dd = getDist(sp1) + getDist(sp2);
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

        dd -= getDist(sp1);
        dd -= getDist(sp2);

        swap(p1,pvec[sp1]); swap(p2,pvec[sp2]);
        swap(q1,qvec[sp1]); swap(q2,qvec[sp2]);




        double dt = timer.past_rate(timelimit1);
        //double T = 1e-10 * (1.-exp(-dt/(1.-dt)));
        double T = 1e-11 * exp(-dt/(1.-dt));
        //double T0 = 0.1*pow(10, -2);
        //double T1 = 0.5*pow(10, -4);
        //double T= pow(T1, (1-dt))*pow(T0, dt);
        chmax(T,0.);

        double probability = exp( min(0., 1.*dd/T ) );
        //double probability = ( (dd>0.)? 1. : 0)  ;

        //cout << dt << " ; " << T << " , "  << dd << endl;


        //cout << dd << endl;

        if(Randdouble() < probability){

            for(ll si:s1){
                ans[si] = sp2;
                rev_ans[sp1].erase(si);
                rev_ans[sp2].insert(si);
            }
            pvec[sp1] = p1;
            qvec[sp1] = q1;

            for(ll si:s2){
                ans[si] = sp1;
                rev_ans[sp2].erase(si);
                rev_ans[sp1].insert(si);
            }
            pvec[sp2] = p2;
            qvec[sp2] = q2;

            nowscore = getScore_PQ(pvec,qvec);
            update_vvs(vvs, ans, g);
        }

    }


    // submit
    rep1(i,K) cout << ans[i] << endl;
    //submit_file(ans);
    //cout << nowscore<< endl;


    return 0;
}
