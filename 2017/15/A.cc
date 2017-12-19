#include "../../includes/util.hpp"

bool match(int A, int B) {
    int low = (1 << 16) - 1;
    return (A & low) == (B & low);
}
int main() {
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int A = 618, B = 814;
    int count = 0;
    for (int i = 0; i < 40000000; i++) {
        A = (ll) A * 16807 % 2147483647;
        B = (ll) B * 48271 % 2147483647;   

        count += match(A, B);
    }
    cout << count << endl;
}

