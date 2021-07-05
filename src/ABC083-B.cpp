#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int total = 0;

    for(int i = 1; i <= N; ++i) {
        int sum = 0;
        int x = i;

        while(x) {
            sum += x % 10;
            x /= 10;
        }

        if(A <= sum && sum <= B) { total += i; }
    }

    cout << total << endl;

    return 0;
}
