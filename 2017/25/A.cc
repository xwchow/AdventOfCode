#include "../../includes/util.hpp"

int STEPS = 12994925;
int write[2][6] = {
    {1, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1, 1,}
};

int mv[2][6] = {
    {1, 1, -1, -1, 1, -1},
    {-1, 1, 1, -1, 1, 1}
};

int state[2][6] = {
    {1, 2, 3, 4, 0, 0},
    {5, 3, 4, 3, 2, 0}
};

int main() {
    map<int, int> mmap;
    mmap[0] = 0;
    int pos = 0, st = 0;
    for (int s = 0; s < STEPS; s++) {
        int v = mmap[pos];
        mmap[pos] = write[v][st];
        pos += mv[v][st];
        st = state[v][st];
    }
    int sum = 0;
    for (auto it : mmap) {
        sum += it.Y;    
    }
    cout << sum << endl;
}
