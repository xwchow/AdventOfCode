#include "../../includes/util.hpp"

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    ll b = 0, c = 0, h = 0;
    b = 81;
    c = b;
    b *= 100;
    b += 100000;
    c = b + 17000;

    for (int i = b; i <= c; i += 17) {
        if (!isPrime(i)) h++;
    }
    
    cout << h << endl;
}

