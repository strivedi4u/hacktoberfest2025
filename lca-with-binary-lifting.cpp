// time: for precomputing O(Nlog)
// time: per query O(log(N))
// space: O(Nlog)
#include <iostream>
#include <vector>
using namespace std;

void getDepth(int node, int parent,
vector<int>& par, vector<vector<int>>& tree,
vector<int>& depth, int d) {
    par[node] = parent;
    depth[node] = d;
    for(auto &adj : tree[node]) {
        if (adj == parent) continue;
        getDepth(adj, node, par, tree, depth, d + 1);
    }
}

int getLOG(int depth) {
    int LOG = 1;
    while ((1 << LOG) <= depth) LOG++;
    return LOG;
}

int goUp(int& node, int steps, vector<vector<int>>& up, int LOG) {
    for(int i = 0; i < LOG; ++i, steps >>= 1) {
        if (steps & 1)
            node = up[node][i];
    }
    return node;
}

int lca(int a, int b, vector<vector<int>>& up, int LOG, vector<int>& depth) {
    if (depth[a] < depth[b])
        swap(a, b);

    int diff_depth = depth[a] - depth[b];
    goUp(a, diff_depth, up, LOG);

    if (a == b) return a;

    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

void binaryLifting(vector<int>& par, int& LOG, vector<int>& depth,
vector<vector<int>>& up, vector<vector<int>>& tree) {
    int n = par.size();
    // choose 0 as the root
    int root = 0;
    getDepth(root, root, par, tree, depth, 0);
    LOG = getLOG(n);
    up = vector<vector<int>>(n, vector<int>(LOG));

    // set parents
    for (int i = 0; i < n; ++i)
        up[i][0] = par[i];
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i < n; ++i) {
            up[i][j] = up[ up[i][j - 1] ][j - 1];
        }
    }
}

int main()  {

    int n, q;
    cin >> n >> q;
    vector<int> par(n);
    vector<vector<int>> tree(n);

    // if 0 is root:
    par[0] = 0;
    for(int i = 1; i < n; ++i) {
        int boss;
        cin >> boss;
        boss--;
        par[i] = boss;
        tree[i].push_back(boss);
        tree[boss].push_back(i);
    }

    // if we receive the edges:
    // for(int i = 0; i < n; ++i) {
    //     int a, b;
    //     cin >> a >> b;
    //     --a; --b;
    //     tree[a].push_back(b);
    //     tree[b].push_back(a);
    // }

    vector<int> depth(n);
    vector<vector<int>> up;
    int LOG;
    binaryLifting(par, LOG, depth, up, tree);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << lca(a, b, up, LOG, depth) + 1 << "\n";
    }

    return 0;
}