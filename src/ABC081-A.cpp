#include <vector>
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    vector<char> s(3);

    for(int i = 0; i < 3; ++i) {
        cin >> s.at(i);
    }

    for(int i = 0; i < 3; ++i) {
        char c = s.at(i);
        if(c == '1') { ++count; }
    }

    cout << count << endl;

    return 0;
}
