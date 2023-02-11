//title
//#define _GLIBCXX_DEBUG
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

const double PI=acos(-1);


//------------------------------------------------

random_device seed_gen;
mt19937 engine(seed_gen());

bool isdebug = true;
double divide_time = 1.5;
bool divide_anneal = false;
bool connect_anneal = false;
bool solve_anneal = true;


struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};

ll N,M,D,K;
vvec(edge) g;
vvec(ll) all_edges;
vec(ll) group_index;

vec(ll) ans;

vec(Pll) coords;


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
    for(ll ai:ans) outputfile<< ai << endl;
    outputfile.close();
}

// 解を出力
void Submit(const vec(ll) &ans){
    for(ll ai:ans) cout << ai << endl;
}

// 解をチェック
void check_answer(){
    bool isok=true;

    vec(ll) v(D+1);
    rep(i,M){
        if(ans[i]<=0 || ans[i]>D) cout << "invalid answer " << i <<" , " << ans[i] << endl;
        v[ans[i]]++;
    }
    rep1(i,D){
        if(v[i]>K){
            isok=false;
            cout << "OVER : day "<<i<<", cnt "<<v[i]<<endl;
        }
    }
}


// テスト用に適当な解を作る
void test_ans(){
    rep(i,M){
        ans[i]=i%D + 1;
    }
}



// つながった計画にできるかチェック
ll check_connect_eachgroup(const set<ll> &edges_indexset, ll roopnum){
    // パラメータ
    double swap_th = 0.5;
    vvec(ll) edges;

    // 見る範囲で頂点の番号を振りなおす
    set<ll> s;
    for(ll i_:edges_indexset){
        vec(ll) ei = all_edges[i_];
        ll u_ = group_index[ei[0]];
        ll v_ = group_index[ei[1]];
        if(u_==v_){
            s.insert(ei[0]);
            s.insert(ei[1]);
            edges.push_back(ei);
        }else{
            s.insert(u_);
            s.insert(v_);
            edges.push_back({u_,v_,ei[2],ei[3]});
        }
    }

    map<ll,ll> m;
    ll nn = 0; // 頂点数
    for(ll si:s) m[si]=nn++;

    ll mm = edges.size(); // 変数


    // 工事スケジュールを初期化
    vec(ll) sch(mm);
    rep(i,mm) sch[i] = i%D; //RandInt(0,D-1);

    vec(set<ll>) kouzi(D);
    rep(i,mm) kouzi[sch[i]].insert(i);


    
    auto calc_cost_connectonly = [&](set<ll> today_kouzi){
        // ある日の工事で連結かどうかだけ見る
        // 工事件数がK超えてたらペナルティ
        // ダイクストラで書き直し

        ll res = 0;
        if(today_kouzi.size()>K) res += llINF;

        dsu d(nn);

        rep(i,mm){
            if(sfind(today_kouzi,i)) continue;
            ll u_,v_,w_;
            u_ = m[edges[i][0]];
            v_ = m[edges[i][1]];
            w_ = edges[i][2];
        
            d.merge(u_,v_);
        }

        ll dgcnt = 0;
        for(auto dg : d.groups()){
            ll dgsize = dg.size();
            res += dgcnt * dgsize * 1e9;
            dgcnt += dgsize;
        }

        return res;
    };

    


    vec(ll) costs(D);
    rep(i,D) costs[i] = calc_cost_connectonly(kouzi[i]);

    auto check_allconnect = [&](){
        bool res = true;
        rep(i,D) if(costs[i]>0) res = false;
        return res;
    };



    // 最適化
    ll roopcnt_=0;
    //bool allconnect=check_allconnect();
    
    auto get_prob=[&](ll x_){
        if(connect_anneal) return (1. ? x_>0 : 0.);
        //ll dclock = clock()-start;
        double dtime = 1.*roopcnt_/roopnum ;//1.*dclock/dlimitclock;
        double ondo = 1.* 1e9 * (1-dtime) / dtime;
        double res = exp(1.*x_/ondo);  
        return res;
    };

    //while(clock()<limitclock) {
    rep(_,roopnum){
        if(check_allconnect()) break;
        double dice = Randdouble();
        
        ll tosi1 = RandInt(0,mm-1);
        ll day1 = sch[tosi1];
        ll day2 = day1;
        while(day2==day1) day2 = RandInt(0,D-1);
        ll tosi2;
        if(kouzi[day2].empty()){
            tosi2 = -1;
            dice = 0;
        }else{
            tosi2 = random_set(kouzi[day2]);
        }

        if(dice < swap_th){
            // 1つの辺の日程を変更
            kouzi[day1].erase(tosi1);
            kouzi[day2].insert(tosi1);
            sch[tosi1] = day2;
        }else{
            // 2つの辺の日程を入れ替え
            kouzi[day1].erase(tosi1);
            kouzi[day2].insert(tosi1);
            sch[tosi1] = day2;
            kouzi[day2].erase(tosi2);
            kouzi[day1].insert(tosi2);
            sch[tosi2] = day1;
        }
        
        ll cost1 = calc_cost_connectonly(kouzi[day1]);
        ll cost2 = calc_cost_connectonly(kouzi[day2]);
        ll dcost = costs[day1]+costs[day2] - cost1 - cost2;

        // なんか燃やす
        bool iskaizen = true;
        double prob = get_prob(dcost);
        iskaizen = (Randdouble()<prob);

        if(iskaizen){
            // 改善したとき
            costs[day1] = cost1;
            costs[day2] = cost2;
        }else{
            if(dice < swap_th){
                // 1つの辺の日程を戻す
                kouzi[day2].erase(tosi1);
                kouzi[day1].insert(tosi1);
                sch[tosi1] = day1;
            }else{
                // 2つの辺の日程を入れ替え
                kouzi[day2].erase(tosi1);
                kouzi[day1].insert(tosi1);
                sch[tosi1] = day1;
                kouzi[day1].erase(tosi2);
                kouzi[day2].insert(tosi2);
                sch[tosi2] = day2;
            }
        }

        roopcnt_++;
    }


    ll res = 0;
    rep(i,D) res += costs[i];
    return res;
    
}



// 頂点を適当なグループにわける
vec(set<ll>) divide_groups_radian(){

    ll ra = 230;
    ll rb = 363;
    ll diva = 4;
    ll divb = 6;
    ll divc = 9;
    double tha = 2.*PI/diva;
    double thb = 2.*PI/divb;
    double thc = 2.*PI/divc;
    ll cent = 500;

    vec(set<ll>) res(diva+divb+divc); 

    rep(i,N){
        ll x,y;
        x = coords[i].first - cent;
        y = coords[i].second -cent;
        double d = sqrt(x*x+y*y);
        double theta = atan2(y,x);
        if(theta<0) theta+=2*PI;

        ll idx=0;
        if(d<ra){
            idx = floor(theta/tha);
        }else if(d<rb){
            idx = floor(theta/thb) + diva;
        }else{
            idx = floor(theta/thc) + diva + divb;
        }
        
        res[idx].insert(i);
    }    

    return res;

}

vec(set<ll>) divide_groups_connect(double timelimit){
    // パラメータ
    double swap_th = 0.5;
    ll start = clock();
    ll dlimitclock = timelimit*CLOCKS_PER_SEC;
    ll limitclock = start + dlimitclock;
    ll roopnum = 100; // 渡すほう

    // 初期解
    vec(set<ll>) groups = divide_groups_radian();
    ll group_num = groups.size();

    rep(i,group_num) for(ll j:groups[i]) group_index[j]=i;

    //vec(ll) group_index_edge(M);
    vec(set<ll>) group_edges(group_num+1);
    for(vec(ll) ei:all_edges){
        ll idx = group_index[ei[0]];
        ll jdx = group_index[ei[1]];

        if(idx==jdx) group_edges[idx].insert(ei[3]);            
        else group_edges[group_num].insert(ei[3]);
    }


    // 評価関数
    vec(ll) group_costs(group_num+1);
    rep(i,group_num+1) group_costs[i] = check_connect_eachgroup(group_edges[i], roopnum);

    ll nowcost = 0;
    rep(i,group_num+1) nowcost += group_costs[i];


    // 最適化
    auto get_prob=[&](ll x_){
        if(divide_anneal) return (1. ? x_>0 : 0.);
        ll dclock = clock()-start;
        double dtime = 1.*dclock/dlimitclock;
        double ondo = 1.* 1e6 * (1-dtime) / dtime;
        double res = exp(1.*x_/ondo);  
        return res;
    };

    auto group_edge_reset = [&](ll tosi, ll newgroup){
        ll nowgroup = group_index[tosi];

        for(edge ei:g[tosi]){
            ll grp = group_index[ei.to];
            if(nowgroup==grp){
                group_edges[grp].erase(ei.idx);
                group_edges[group_num].insert(ei.idx);
            }else if(newgroup==grp){
                group_edges[group_num].erase(ei.idx);
                group_edges[grp].insert(ei.idx);
            }
        }

        group_index[tosi]=newgroup;
    };


    while(clock()<limitclock && nowcost>0){
        double dice = Randdouble();
        
        ll tosi1 = RandInt(0,N-1);
        ll group1 = group_index[tosi1];
        ll group2 = group1;
        while(group2==group1) group2 = RandInt(0,group_num);
        ll tosi2;
        if(groups[group2].empty()){
            tosi2 = -1;
            dice = 0;
        }else{
            tosi2 = random_set(groups[group2]);
        }

        if(dice < swap_th){
            // 1つの都市を別のグループに変更
            group_edge_reset(tosi1, group2);
        }else{
            // 2つの辺の日程を入れ替え
            group_edge_reset(tosi1, group2);
            group_edge_reset(tosi2, group2);
        }

        ll cost1 = check_connect_eachgroup(group_edges[group1], roopnum);
        ll cost2 = check_connect_eachgroup(group_edges[group2], roopnum);
        ll dcost = group_costs[group1]+group_costs[group2] - cost1 - cost2;

        double prob = get_prob(dcost);
        bool iskaizen = (Randdouble()<prob);

        if(iskaizen){
            // 改善したとき
            group_costs[group1] = cost1;
            group_costs[group2] = cost2;
            nowcost -= dcost;            
        }else{
            // 変更を戻す
            if(dice < swap_th){
                group_edge_reset(tosi1,group1);
            }else{
                group_edge_reset(tosi1,group1);
                group_edge_reset(tosi2,group2);
            }
        }
    }
    
    if(isdebug) rep(i,group_num+1) cout << group_costs[i]/1e9 << " "; cout << endl;

    return groups;
}


// グループごとに解く
vvec(ll) solve_eachgroup(const vvec(ll) &edges, double timelimit){
    // パラメータ
    double th = 0.5; // 2swapとかの分岐
    //ll roopnum = 100; // ループ回数 // 後で時間指定にする
    ll start = clock();
    ll dlimitclock = timelimit*CLOCKS_PER_SEC;
    ll limitclock = start + dlimitclock;


    // 見る範囲で頂点の番号を振りなおす
    set<ll> s;
    for(vec(ll) ei:edges){
        s.insert(ei[0]);
        s.insert(ei[1]);
    }

    map<ll,ll> m;
    ll nn = 0; // 頂点数
    for(ll si:s) m[si]=nn++;

    ll mm = edges.size(); // 変数



    // 工事スケジュールを初期化
    vec(ll) sch(mm);
    rep(i,mm) sch[i] = i%D; //RandInt(0,D-1);

    vec(set<ll>) kouzi(D);
    rep(i,mm) kouzi[sch[i]].insert(i);




    auto calc_cost = [&](set<ll> today_kouzi){
        // ある日の最短距離合計を計算する関数
        // 工事件数がK超えてたらペナルティ
        // ダイクストラで書き直し

        ll res = 0;
        if(today_kouzi.size()>K) res += llINF;

        vvec(Pll) g(nn);
        rep(i,mm){
            if(sfind(today_kouzi,i)) continue;
            ll u_,v_,w_;
            u_ = m[edges[i][0]];
            v_ = m[edges[i][1]];
            w_ = edges[i][2];

            g[u_].emplace_back(v_,w_);
            g[v_].emplace_back(u_,w_);
        }

        for(ll st = 1; st<nn; st++){ // 全頂点対を知りたいのでst=0はスキップ
            vec(ll) dp(nn,1e9);

            priority_queue<Pll, vector<Pll>, greater<Pll>> q;
            auto qpush = [&](ll nxt,ll c){
                if(chmin(dp[nxt], c)){
                    q.emplace(c,nxt);
                }
            };
            qpush(st,0);

            while(!q.empty()){
                Pll q0 = q.top();
                q.pop();
                ll now = q0.second;
                ll c0 = q0.first;
                if(dp[now]<c0) continue;
                for(Pll gi:g[now]) qpush(gi.first, c0+gi.second);
            }
            
            rep(i,st) res+=dp[i];
        }

        return res;
    };

    ll th_connect = 1400*nn*nn;
    auto calc_cost_connectonly = [&](set<ll> today_kouzi){
        // ある日の工事で連結かどうかだけ見る
        // 工事件数がK超えてたらペナルティ
        // ダイクストラで書き直し

        ll res = th_connect;
        if(today_kouzi.size()>K) res += llINF;

        dsu d(nn);

        rep(i,mm){
            if(sfind(today_kouzi,i)) continue;
            ll u_,v_,w_;
            u_ = m[edges[i][0]];
            v_ = m[edges[i][1]];
            w_ = edges[i][2];
        
            d.merge(u_,v_);
        }

        ll dgcnt = 0;
        for(auto dg : d.groups()){
            ll dgsize = dg.size();
            res += dgcnt * dgsize * 1e9;
            dgcnt += dgsize;
        }

        return res;
    };

    


    vec(ll) costs(D);
    //rep(i,D) costs[i] = calc_cost(kouzi[i]);
    rep(i,D) costs[i] = calc_cost_connectonly(kouzi[i]);




    // 最適化
    ll roopcnt_=0;

    auto get_prob=[&](ll x_){
        if(solve_anneal) return (1. ? x_>0 : 0.);
        ll dclock = clock()-start;
        double dtime = 1.*dclock/dlimitclock;
        double ondo = 1.* 1e9 * (1-dtime) / dtime;
        double res = exp(1.*x_/ondo);  
        return res;
    };


    while(clock()<limitclock) {
        double dice = Randdouble();
        
        ll tosi1 = RandInt(0,mm-1);
        ll day1 = sch[tosi1];
        ll day2 = day1;
        while(day2==day1) day2 = RandInt(0,D-1);
        ll tosi2;
        if(kouzi[day2].empty()){
            tosi2 = -1;
            dice = 0;
        }else{
            tosi2 = random_set(kouzi[day2]);
        }


        if(dice < th){
            // 1つの辺の日程を変更
            kouzi[day1].erase(tosi1);
            kouzi[day2].insert(tosi1);
            sch[tosi1] = day2;
        }else{
            // 2つの辺の日程を入れ替え
            kouzi[day1].erase(tosi1);
            kouzi[day2].insert(tosi1);
            sch[tosi1] = day2;
            kouzi[day2].erase(tosi2);
            kouzi[day1].insert(tosi2);
            sch[tosi2] = day1;
        }

        ll cost1 = calc_cost_connectonly(kouzi[day1]);
        ll cost2 = calc_cost_connectonly(kouzi[day2]);
        ll dcost = costs[day1]+costs[day2] - cost1 - cost2;

        // なんか燃やす
        bool iskaizen = true;
        double prob = get_prob(dcost);
        iskaizen = (Randdouble()<prob);

        if(iskaizen){
            // 改善したとき
            costs[day1] = cost1;
            costs[day2] = cost2;
        }else{
            if(dice < th){
                // 1つの辺の日程を戻す
                kouzi[day2].erase(tosi1);
                kouzi[day1].insert(tosi1);
                sch[tosi1] = day1;
            }else{
                // 2つの辺の日程を入れ替え
                kouzi[day2].erase(tosi1);
                kouzi[day1].insert(tosi1);
                sch[tosi1] = day1;
                kouzi[day1].erase(tosi2);
                kouzi[day2].insert(tosi2);
                sch[tosi2] = day2;
            }
        }

        roopcnt_++;
    }


    vvec(ll) res;
    for(set<ll> ki: kouzi){
        if(ki.empty()) continue;
        vec(ll) tmp;
        for(ll kii:ki) tmp.push_back(edges[kii][3]);
        res.push_back(tmp);
    }
    sort(all(res), [](vec(ll) const& a, vec(ll) const& b){ return a.size() > b.size(); });


    if(isdebug) cout << roopcnt_ << "roops" << endl;
    return res;
    
}




//---------------------
int main(){
    ll start = clock();

    // 読み込み
    cin >> N >> M >> D >> K;
    g.resize(N);
    ans.resize(M);
    coords.resize(N);
    all_edges.resize(M);
    group_index.resize(N);

    rep(i,M){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].emplace_back(v,w,i);        
        g[v].emplace_back(u,w,i);        
        all_edges[i] = {u,v,w,i};
    }

    rep(i,N){
        ll x_,y_;
        cin >> x_ >> y_;
        coords[i] = {x_,y_};
    }



    //--- グループにわける
    vec(set<ll>) groups = divide_groups_connect(divide_time);

    ll group_num = groups.size();
    

    vvvec(ll) group_edges(group_num+1);
    for(vec(ll) ei:all_edges){
        ll idx = group_index[ei[0]];
        ll jdx = group_index[ei[1]];
   
        if(idx==jdx){
            group_edges[idx].push_back(ei);            
        }else{
            group_edges[group_num].push_back( {idx, jdx, ei[2], ei[3]} );
        }
    }


    vec(ll) group_cnt(group_num+1);
    rep(i,group_num) group_cnt[i] = groups[i].size();
    group_cnt[group_num] = groups.size();
    ll tot_ = 0;
    rep(i,group_num+1) tot_ += group_cnt[i];   


    // グループごとに解く
    double remtime = 5.85 - (clock()-start)/CLOCKS_PER_SEC;

    vvvec(ll) vvv(group_num+1);
    rep(i,group_num+1){
        double timelimit = remtime * group_cnt[i]/tot_;
        //if(group_edges[i].empty()) cout << "empty" << i << endl;
        vvv[i] = solve_eachgroup(group_edges[i], timelimit);
    }


    // 全体スケジュールに割り振る
    vec(ll) rem(D,K); // 各日の残り可能工事数
    vvec(bool) used(group_num+1, vec(bool)(D+1));
    vec(ll) dayrem(D+1,K);

    rep1(day,D){
        rep(i,group_num+1){
            rep(j,vvv[i].size()){
                if(used[i][j]) continue;
                if(vvv[i][j].size() > dayrem[day]) continue;

                used[i][j]=true;
                dayrem[day] -= vvv[i][j].size();
                for(ll k:vvv[i][j]) ans[k]=day;

                break;                
            }
        }
    }

    vec(ll) mitei;
    // rep(i,group_num+1){
    //     rep(j,vvv[i].size()){
    //         if(used[i][j]) continue;
    //         for(ll k:vvv[i][j]) mitei.push_back(k);
    //     }
    // }
    rep(i,M) if(ans[i]==0) mitei.push_back(i);

    ll daycnt=1;
    while(!mitei.empty()){
        ll mi = mitei.back();
        mitei.pop_back();

        while( dayrem[daycnt]==0 ) daycnt++;
        ans[mi] = daycnt;
        dayrem[daycnt]--;
    }





    // 解を出力
    if(isdebug){
        check_answer();
        Submit_file(ans);
        cout << 1.*(clock()-start)/CLOCKS_PER_SEC<<"[sec]" << endl;
    }else{
        Submit(ans);
    }

    return 0;
}
