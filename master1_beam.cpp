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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

mt19937 rng(42);

// 0.以上1.未満の整数をランダムに返す関数
double Randdouble(){
    return 1. * rand() / RAND_MAX;
}

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}



//--- TIMER -----------------------------------
constexpr double TIMELIMIT = 1.90;


class Timer {
private:

public:
    clock_t startTime;
    double limitTime;


    Timer(double limit=0.) : limitTime(limit) {
        startTime = clock();
    }

    void restart(double limit){
        startTime = clock();
        limitTime = limit;
    }

    double getElapsedTime() {
        clock_t currentTime = clock();
        return static_cast<double>(currentTime - startTime) / CLOCKS_PER_SEC;
    }

    double getProgressRate() {
        return getElapsedTime()/limitTime;
    }



    bool isTimeUp() {
        return getElapsedTime() >= limitTime;
    }

};


Timer timer(TIMELIMIT);



//---
struct Character{
    int x,y;
};

vec(ll) dx = {1,0,-1,0,0};
vec(ll) dy = {0,1,0,-1,0};
vec(char) move_name = {'D','R','U','L','.'};




// [i][j][move], 
vvvec(int) abailableMoves;


class MapState
{
private:
    int t,N;
    vvec(int) a; //, wall_v, wall_h;
    int turn_, max_turn_;
    vector<Character> characters_;



    // 全体のDの計算
    int calcAllD(const vvec(int)& aa){
        int res = 0;
        rep(i,N)rep(j,N){
            if(abailableMoves[i][j][0]){
                int da = aa[i][j] - aa[i+1][j];
                res += da*da;
            }
            if(abailableMoves[i][j][1]){
                int da = aa[i][j] - aa[i][j+1];
                res += da*da;
            }
        }
        return res;
    }


    // ある2箇所をswapしたときのDの差分
    int calcDiffD(Character c0, Character c1, const vvec(int)& aa){
        int pre=0, nxt=0;

        rep(_,2){
            rep(mv,4){
                if(abailableMoves[c0.x][c0.y][mv]){
                    int da = aa[c0.x][c0.y] - aa[c0.x + dx[mv]][c0.y + dy[mv]];
                    pre += da*da;

                    da = aa[c1.x][c1.y] - aa[c0.x + dx[mv]][c0.y + dy[mv]];
                    nxt += da*da;
                }
            }

            swap(c0,c1);
        }

        return nxt - pre;
    }


public:
    int D_ini, D;
    // pair<int, int> first_moves_;
    tuple<int,int,int> first_action_;


    // MapState(const int t, const int N, const vvec(int)& wall_v, const vvec(int)& wall_h, vvec(int) a):
    // t(t),N(N),wall_v(wall_v), wall_h(wall_h), a(a)
    MapState(const int t, const int N, vvec(int) a):
    t(t),N(N),a(a)
    {
        this->characters_.resize(2);
        this->setInitPos_ramdom();
        this->D_ini = calcAllD(a);
        this->D = this->D_ini;
        this->turn_ = 0;
        this->max_turn_ = 4*N*N;
        this->first_action_ = {0,4,4}; // 0 . . // 何もしない、で初期化
    }


    // 初期位置の設定 ランダム
    void setInitPos_ramdom(){
        for(auto &c: this->characters_){
            c.x = RandInt(0,this->N-1);
            c.y = RandInt(0,this->N-1);
        }
    }


    // 位置の表示
    void printCharacterPos(){
        for(auto &c: this->characters_){
            cout << c.x << " " << c.y << " ";
        }
        cout << endl;
    }


    // player_idの有効手を取得
    vec(int) legalMoves(const int player_id){
        vec(int) moves;
        const Character& c = this->characters_[player_id];

        rep(mv,5){
            if(abailableMoves[c.x][c.y][mv]) moves.push_back(mv);
        }

        return moves;
    }


    // 1手進める
    void advance(const int do_swap, const int mv0, const int mv1){
        Character &c0 = this->characters_[0];
        Character &c1 = this->characters_[1];

        if(do_swap){
            int d_diff = calcDiffD(c0, c1, this->a);
            this->D += d_diff;
            swap(this->a[c0.x][c0.y], this->a[c1.x][c1.y]);
        }

        c0.x += dx[mv0];
        c0.y += dy[mv0];
        c1.x += dx[mv1];
        c1.y += dy[mv1];

        this->turn_++;
    }


    // 最大ターン到達確認
    bool is_timeup(){
        return this->turn_ >= this->max_turn_;
    }


    // 今いる場所をswapしたときのDの差分
    int calcDiffD_nowpos(){
        Character &c0 = this->characters_[0];
        Character &c1 = this->characters_[1];

        int d_diff = calcDiffD(c0, c1, this->a);
        return d_diff;
    }
};

bool operator<(const MapState &a, const MapState &b){
    return a.D < b.D;
}
bool operator>(const MapState &a, const MapState &b){
    return a.D > b.D;
}




const int beam_depth = 4;
const int beam_width = 16;

tuple<int,int,int> beam1(const MapState& state){ //, const int beam_depth, const int beam_width){

    priority_queue<MapState, vector<MapState>, greater<MapState>>  now_beam;
    now_beam.push(state);
    MapState best_state = state;


    rep(t, beam_depth){
        // cerr << "now beam dep : " << t << endl;
        priority_queue<MapState, vector<MapState>, greater<MapState>>  nxt_beam;

        rep(_,beam_width){
            if(now_beam.empty()) break;
            MapState now_state = now_beam.top();
            now_beam.pop();

            auto legal_moves0 = now_state.legalMoves(0);
            auto legal_moves1 = now_state.legalMoves(1);
            rep(do_swap,2)for(int mv_idx0:legal_moves0)for(int mv_idx1:legal_moves1){
                MapState nxt_state = now_state;
                nxt_state.advance(do_swap, mv_idx0, mv_idx1);
                if(t==0){
                    nxt_state.first_action_ = {do_swap, mv_idx0, mv_idx1};
                }
                nxt_beam.push(nxt_state);
            }
        }

        now_beam = nxt_beam;
        best_state = now_beam.top();
        if(best_state.is_timeup()) break;
    }

    return best_state.first_action_;

}




void sim_random(const MapState& ini_state){
    MapState state = ini_state;

    state.setInitPos_ramdom(); // 初期位置もランダムに設定
    state.printCharacterPos();


    while(!state.is_timeup()){

        vec(int) mv_cand0 = state.legalMoves(0);
        vec(int) mv_cand1 = state.legalMoves(1);
        
        // とりあえずランダムに解く
        int do_swap=0;
        if(state.calcDiffD_nowpos() < 0) do_swap = 1; // Dが減るならスワップ
        int mv_idx0 = mv_cand0[ (0, mv_cand0.size()-1) ];
        int mv_idx1 = mv_cand1[ RandInt(0, mv_cand1.size()-1) ];


        // cerr << "---" << endl;
        // state.printCharacterPos();

        cout << do_swap <<" " << move_name[mv_idx0] << " " << move_name[mv_idx1] << endl;
        state.advance(do_swap, mv_idx0, mv_idx1);
    }

    
    // 結果の確認
    cerr << "initial D : " << state.D_ini << endl;
    cerr << "final D : " << state.D << endl;

}






void sim_beam1(const MapState& ini_state ){
    MapState state = ini_state;

    state.setInitPos_ramdom(); // 初期位置もランダムに設定
    state.printCharacterPos();


    while(!state.is_timeup() && !timer.isTimeUp() ){
        // cerr << "---" << endl;
        // state.printCharacterPos();
        

        auto [do_swap, mv_idx0, mv_idx1] = beam1(state);//, 10, 10);


        cout << do_swap <<" " << move_name[mv_idx0] << " " << move_name[mv_idx1] << endl;
        state.advance(do_swap, mv_idx0, mv_idx1);
    }

    
    // 結果の確認
    cerr << "initial D : " << state.D_ini << endl;
    cerr << "final D : " << state.D << endl;

}









void solve(const int t, const int N, const vvec(int)& wall_v, const vvec(int)& wall_h, vvec(int) a){

    // マスごとの有効な移動を列挙しておく
    vvvec(int) moveCheck(N,vvec(int)(N,vec(int)(5,true))); // i,j, ['D','R','U','L','.']

    rep(i,N)rep(j,N-1){
        if(wall_v[i][j]==0) continue;
        moveCheck[i][j][1] = false;
        moveCheck[i][j+1][3] = false;
    }
    rep(i,N) moveCheck[i][N-1][1] = false;
    rep(i,N) moveCheck[i][0][3] = false;

    rep(i,N-1)rep(j,N){
        if(wall_h[i][j]==0) continue;
        moveCheck[i][j][0] = false;
        moveCheck[i+1][j][2] = false;
    }
    rep(j,N) moveCheck[N-1][j][0] = false;
    rep(j,N) moveCheck[0][j][2] = false;


    abailableMoves = moveCheck;


    // 盤面の状態の生成
    MapState state(t,N,a);

    // 操作をシミュレート
    // sim_random(state);
    sim_beam1(state);


}





int main(){

    // Timer timer(TIMELIMIT);
    timer.restart(TIMELIMIT);

    int t,N;
    cin >> t >>  N;

    vvec(int) v(N,vec(int)(N-1));
    vvec(int) h(N-1,vec(int)(N));
    vvec(int) a(N,vec(int)(N));

    rep(i,N){
        string s; cin >> s;
        rep(j,N-1) v[i][j]= (s[j]-'0') ;
    }
    rep(i,N-1){
        string s; cin >> s;
        rep(j,N) h[i][j]= (s[j]-'0') ;
    }

    rep(i,N)rep(j,N) cin >> a[i][j];

    solve(t,N,v,h,a);




    return 0;
}
