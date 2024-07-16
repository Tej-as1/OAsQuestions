/*Tejas Sharma*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define mi map<int,int>
#define si set<int>
#define sc set<char>
#define maxheap1 priority_queue<int>
#define minheap1 priority_queue<int,vector<int>,greater<int>>
#define maxheap priority_queue<pair<int,int>>
#define minheap priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define bend(x) x.begin(),x.end()
#define rbend(x) x.rbegin(), x.rend()
const int N = 1e6 + 10;
vector<bool>isPrime(N,1);
vector<int>hp(N), lp(N);
vector<int> spf(1000001, 1);
void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i < N;i++){
        if(isPrime[i]){
          lp[i] = hp[i] = i;
          for(int j = 2 * i;j < N;j += i){
              isPrime[j] = 0;
              hp[j] = i;
              if(lp[j] == 0) lp[j] = i;
          } 
      }
    }
}
int countPrimeFactors(int num){
  set<int>s;
  while(num > 1){
    int pf = hp[num];
    while(num % pf == 0){
        num /= pf;
        s.insert(pf);
    }
  }
  return s.size();
}
const int M = 1e9+7;
void solve(){
    int n;cin >> n;
    vvi v(n,vi(n));
    for(int i = 0;i < n;i++){
      for(int j = 0;j < n;j++) cin >> v[i][j];
    }
    minheap pq;
    vvi dist(n,vi(n,1e9));
    dist[0][0] = 0;
    pq.push({0,0,0});  // dist x y
    while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int dis = it[0], x =it[1], y = it[2];
      int p = countPrimeFactors(v[x][y]);
      for(int i = -p;i <= p;i++){
        for(int j = -p;j <= p;j++){
          int nx = x + i, ny = y + j;
          if(nx >= 0 and nx < n and ny >= 0 and ny < n and abs(nx - x) + abs(ny - y) <= p){
            if(dist[nx][ny] > dis + sqrt(v[x][y])){
              dist[nx][ny] = dis + sqrt(v[x][y]);
              pq.push({dist[nx][ny],nx,ny});
            }
          }
        }
      }
    }
    cout << dist[n - 1][n - 1] << endl;
}
int32_t main(){
  sieve();
  solve();
  
}