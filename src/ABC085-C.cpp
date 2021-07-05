#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    bool is_exist = false;

    for(int x = 0; x <= N; ++x) {
        if(10000 * x > Y) { break; }

        for(int y = 0; y <= N - x; ++y) {
            int z = N - y - x;

            if(10000 * x + 5000 * y + 1000 * z == Y) {
                cout << x << " " << y << " " << z << endl;
                is_exist = true;
                break;
            }
        }

        if(is_exist) { break; }
    }

    if(!is_exist) { cout << "-1 -1 -1" << endl; }

    return 0;
}
