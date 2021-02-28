#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, a, b) for (ll i = a; i > b; i--)
#define ll long long
#define ld long double
#define vll vector<ll>
#define vv vector<vll>
#define mll map<ll, ll>
#define sll set<ll>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define pi acos(-1.0)
#define print(v)           \
    for (auto it : v)      \
        cout << it << " "; \
    cout << endl
#define fill(v, a) memset(v, a, sizeof(v))
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define p3(x, y, z) cout << "x=" << x << " y=" << y << " z=" << z << endl
#define p2(x, y) cout << "x=" << x << " y=" << y << endl
#define p1(x) cout << "x=" << x << endl
#define p(s, x) cout << s << " " << x << endl
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define InputOutput freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);
const ll mod = 1000000000 + 7;                        //10^9+7
const ll INF = 9000000000000000000;                   // 9*10^18

using namespace std;

void yes() { cout << "YES" << endl; }

void no() { cout << "NO" << endl; }

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    return (a * b / (gcd(a, b)));
}

ll dist[1001][1001];
bool vis[1001][1001];
char grid[1001][1001];

void solve()
{
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ll n, m, k, si, sj, di, dj;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            vis[i][j] = false;
            dist[i][j] = INF;
        }
    }

    cin >> si >> sj >> di >> dj;
    si--, sj--, di--, dj--;

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int x = node.first, y = node.second;

        for (auto d : dir)
        {
            for (int K = 1; K <= k; K++)
            {
                int xk = x + (d[0] * K), yk = y + (d[1] * K);

                if (xk < 0 || yk < 0 || xk >= n || yk >= m || grid[xk][yk] == '#')
                    break;

                if (vis[xk][yk])
                    continue;

                if (dist[x][y] + 1 < dist[xk][yk])
                {
                    dist[xk][yk] = dist[x][y] + 1;
                    q.push({xk, yk});
                    vis[xk][yk] = true;
                    if (xk == di && yk == dj)
                    {
                        cout << dist[di][dj] << endl;
                        return;
                    }
                }
            }
        }
    }

    if (dist[di][dj] == INF)
        cout << -1 << endl;
    else
        cout << dist[di][dj] << endl;
}

// #define OJ

int main()
{
    IOS;
#ifndef OJ
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}