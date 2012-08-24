// disjoint sets( union-find sets):
//    each set is represent as a pointer based data structue, 
//    with one node per element. 
//    1:makeset(x): initialize one element as set
//    2:find(x): find one element in which set
//    3:union(x, y):
//

#define MAX 100

int father[MAX];
int rank[MAX];

void makeset(int x) {
  father[x] = x;
  rank[x] = 0;
}

int find(x) {
  int root = x;
  if (father[root] != root) {
    root = father[root];
  }
  // compres
  while ( x ! = root) {
    int tmp = father[x];
    father[x] = root;
    x = tmp;
  }
  return root;
}

void union(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rank[x] > rank[y]) {
    father[y] = x;
  } else {
    if (rank[x] == rank[y]) {
      rank[y]++;
    }
    father[x] = y;
  }
}
