#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);

    for(int i = 0; i < N; ++i) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int Alice = 0;
    int Bob = 0;

    for(int i = 0; i < N; ++i) {
        int num = a.at(i);
        if(i % 2 == 0) { Alice += num; }
        else { Bob += num; }
    }

    cout << Alice - Bob << endl;

    return 0;
}
