#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; ++i) {
        cin >> A.at(i);
    }

    int max_count = 1000000000;

    for(int i = 0; i < N; ++i) {
        int count = 0;
        int num = A.at(i);

        while(num) {
            if(num % 2 == 0) { num /= 2; ++count; }
            else { break; }
        }

        if(max_count > count) { max_count = count; }
    }

    cout << max_count << endl;

    return 0;
}
