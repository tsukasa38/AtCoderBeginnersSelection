#include <iostream>
#include <algorithm>
using namespace std;

/*
// 深さ優先探索(TLE)

bool judge(string &s, string t) {
    if(s == t) { return true; }
    if(s.size() <= t.size()) { return false; }

    return judge(s, t + "dream") || judge(s, t + "dreamer") || judge(s, t + "erase") || judge(s, t + "eraser");
}
*/

/*
// 幅優先探索(TLE)

queue<string> q;

bool judge(string &s) {
    q.push("");

    while(!q.empty()) {
        string str = q.front();
        q.pop();

        if(s == str) { return true; }

        if(s.size() > str.size()) {
            q.push(str + "dream");
            q.push(str + "dreamer");
            q.push(str + "erase");
            q.push(str + "eraser");
        }
    }

    return false;
}
*/

bool judge(string &s, string &str1, string &str2, string &str3, string &str4) {
    string t = "";
    int len1 = str1.size();
    int len2 = str2.size();
    int len3 = str3.size();
    int len4 = str4.size();
    int slen = s.size();
    int tlen = 0;

    while(true) {
        if(s == t) { return true; }
        if(slen <= tlen) { return false; }

        int diff = slen - tlen;
        if(diff >= len1 && s.substr(tlen, len1) == str1) { t += str1; tlen += len1; }
        else if(diff >= len2 && s.substr(tlen, len2) == str2) { t += str2; tlen += len2; }
        else if(diff >= len3 && s.substr(tlen, len3) == str3) { t += str3; tlen += len3; }
        else if(diff >= len4 && s.substr(tlen, len4) == str4) { t += str4; tlen += len4; }
        else{ return false; }
    }

}

int main() {
    string s;
    cin >> s;

    string str1 = "dreamer";
    string str2 = "eraser";
    string str3 = "dream";
    string str4 = "erase";

    reverse(s.begin(), s.end());
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    reverse(str3.begin(), str3.end());
    reverse(str4.begin(), str4.end());

    bool is_ok = judge(s, str1, str2, str3, str4);

    if(is_ok) { cout << "YES" << endl; }
    else { cout << "NO" << endl; }

    return 0;
}
