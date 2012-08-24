#include <iostream>
using namespace std;

int timef = 0;
int n;
int a[100][100]; //临接矩阵
int f[100];     // finish time

int vis[100]; // 1: found 2: finish

//dfs
void DFS(int u) {
  vis[u] = 1;
  for (int v = 1; v <=n; v++) {
    if (a[u][v] && vis[v] == 0)
      DFS(v);
  }
  vis[u] = 2;
  timef++;
  f[u] = timef;
}

void DFS_main() {
  timef = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0)
      DFS(i);
  }
}

void Topological_sort() {
  int tp[100];
  DFS_main();
  for (int i = 0; i < n; i++) {
    tp[n-f[i]+1] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << tp[i] << " "
  }

  cout << endl;
}

int main() {
  memset(vis, 0, sizeof(vis));
  cin >> n;

  // input a[i][j]
  Topological_sort();
  return 0;
}


// DAG directed acyclic graph(do not have cycle)

class Graph {

};

