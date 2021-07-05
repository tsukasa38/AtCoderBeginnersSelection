#include <iostream>
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int count = 0;

    for(int a = 0; a <= A; ++a) {
        if(500 * a > X) { break; }

        for(int b = 0; b <= B; ++b) {
            if(500 * a + 100 * b > X) { break; }

            for(int c = 0; c <= C; ++c) {
                if(500 * a + 100 * b + 50 * c > X) { break; }
                if(500 * a + 100 * b + 50 * c == X) { count += 1; }
            }
        }
    }

    cout << count << endl;

    return 0;
}
