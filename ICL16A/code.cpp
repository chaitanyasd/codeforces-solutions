#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
// #define OJ

vector<string> grid;
vector<int> parent;
vector<int> urank;
vector<pair<int, pair<int, int>>> edges;

int find(int i)
{
    if (i != parent[i])
        parent[i] = find(parent[i]);
    return parent[i];
}

bool _union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return false;

    if (urank[pa] > urank[pb])
        parent[pb] = pa;
    else if (urank[pb] > urank[pa])
        parent[pa] = pb;
    else
    {
        urank[pa]++;
        parent[pb] = pa;
    }

    return true;
}

void solve(int n)
{
    int ans = 0, rowsMerged = n - 1, i = 0;
    while (rowsMerged)
    {
        auto edge = edges[i++];
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        if (_union(u, v))
        {
            rowsMerged--;
            if (!rowsMerged)
            {
                cout << w << endl;
                return;
            }
        }
    }
}

int main()
{
    fast_cin();
#ifndef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    grid.resize(n + 1);
    parent.resize(n + 1);
    urank.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> grid[i];
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int maxEdge = INT_MIN;
            for (int k = 0; k < m; k++)
            {
                maxEdge = max(maxEdge, abs(grid[i][k] - grid[j][k]));
            }
            edges.push_back({maxEdge, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    solve(n);

    return 0;
}