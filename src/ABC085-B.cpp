#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> d(N);

    for(int i = 0; i < N; ++i) {
        cin >> d.at(i);
    }

    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());

    set<int> s(d.begin(), d.end());
    int num = s.size();

    cout << num << endl;

    return 0;
}
