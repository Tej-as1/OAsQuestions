#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long K = 25;
long long dp[10000][K];
vector<long long> primes;
vector<bool> isPrime(202, 1);

class PrimeTree {
public:
    void sieve() {
        isPrime[0] = isPrime[1] = 0;
        for (long long i = 2; i <= 202; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 2 * i; j <= 202; j += i)
                    isPrime[j] = 0;
            }
        }
    }

    void dfs(long long node, long long par, vector<long long> adj[]) {
        for (long long i = 0; i < K; i++)
            dp[node][i] = 1;
        for (auto &child : adj[node]) {
            if (child == par) continue;
            dfs(child, node, adj);
            for (long long i = 0; i < K; i++) {
                long long ways = 0;
                for (long long j = 0; j < K; j++) {
                    if (isPrime[primes[i] + primes[j]] == 0) {
                        (ways += dp[child][j]) %= M;
                    }
                }
                dp[node][i] = (dp[node][i] * ways) % M;
            }
        }
    }

    long long getNumberOfArrangements(long long n, std::vector<std::vector<long long>> edges) {
        vector<long long> adj[n];
        for (auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        sieve();
        dfs(0, -1, adj);
        long long ans = 0;
        for (long long i = 0; i < K; i++) {
            (ans += dp[0][i]) %= M;
        }
        return ans;
    }
};
