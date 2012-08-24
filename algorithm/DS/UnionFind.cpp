class UF {
private:
    int* id;  // id[i] = parent of i
    int* sz;  // sz[i] = number of objects in subtree rooted at i
    int count; // number of components;
    int objects;
public:
    UF(int n) {
        if (n <= 0) {
            throw std::invalid_argument("n");
        }

        objects = n;
        count = n;
        id = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // return the id of components corresponding to object p
    int find(int p) {
        if (p < 0 || p >= objects) {
            return -1;
        }
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    int count() {
        return count;
    }

    int connected(int p, int q) {
        return find(p) == find(q);
    }

    void union(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j)
            return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        count--;
    }

};

