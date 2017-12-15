#include "../../util.hpp"


struct Hex {
    int x, y, z;
    
    Hex() {}
    Hex(int x, int y, int z) : x(x), y(y), z(z) {}
    
    bool operator<(const Hex& o) const {
        return x < o.x || (x == o.x && y < o.y) || (x == o.x && y == o.y && z < o.z);
    }
    
    int dist() { return (abs(x) + abs(y) + abs(z)) / 2; }
    Hex operator+(const Hex& o) const { return Hex(x + o.x, y + o.y, z + o.z); }
    Hex& operator+=(const Hex& o) { x += o.x; y += o.y; z += o.z; return *this; }
    Hex operator-(const Hex& o) const { return Hex(x - o.x, y - o.y, z - o.z); }
    Hex& operator-=(const Hex& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};

const string DIR[] = {"n", "ne", "se", "s", "sw", "nw"};
Hex nbr[6] = { Hex(-1, 1, 0),
               Hex(0, 1, -1),
               Hex(1, 0, -1),
               Hex(1, -1, 0),
               Hex(0, -1, 1),
               Hex(-1, 0, 1) };

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    string line;     cin >> line;
    vs words = split(line, ',');
    Hex coord(0, 0, 0);

    int Ma = 0;
    for (string w : words) {
        int i = find(DIR, DIR + 6, w) - DIR;
        coord += nbr[i];
        Ma = max(Ma, coord.dist());
    }
    
    cout << Ma << endl;
}

