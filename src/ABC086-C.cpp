#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

/*
// 深さ優先探索(TLE)

bool judge(tuple<int, int, int> current_point, tuple<int, int, int> &destination_point) {
    int current_point_t = get<0>(current_point);
    int current_point_x = get<1>(current_point);
    int current_point_y = get<2>(current_point);
    int destination_point_t = get<0>(destination_point);

    if(current_point == destination_point) { return true; }
    if(current_point_t >= destination_point_t) { return false; }

    tuple<int, int, int> t1(current_point_t+1, current_point_x+1, current_point_y);
    tuple<int, int, int> t2(current_point_t+1, current_point_x-1, current_point_y);
    tuple<int, int, int> t3(current_point_t+1, current_point_x, current_point_y+1);
    tuple<int, int, int> t4(current_point_t+1, current_point_x, current_point_y-1);

    return judge(t1, destination_point) || judge(t2, destination_point) || judge(t3, destination_point) || judge(t4, destination_point);
}
*/

/*
// 幅優先探索(TLE)

queue<tuple<int, int, int>> q;

bool judge(tuple<int, int, int> starting_point, tuple<int, int, int> &destination_point) {
    q.push(starting_point);

    while(!q.empty()) {
        tuple<int, int, int> current_point = q.front();
        q.pop();

        if(current_point == destination_point) { return true; }

        int current_point_t = get<0>(current_point);
        int current_point_x = get<1>(current_point);
        int current_point_y = get<2>(current_point);
        int destination_point_t = get<0>(destination_point);

        if(current_point_t < destination_point_t) {
            tuple<int, int, int> t1(current_point_t+1, current_point_x+1, current_point_y);
            tuple<int, int, int> t2(current_point_t+1, current_point_x-1, current_point_y);
            tuple<int, int, int> t3(current_point_t+1, current_point_x, current_point_y+1);
            tuple<int, int, int> t4(current_point_t+1, current_point_x, current_point_y-1);
            q.push(t1);
            q.push(t2);
            q.push(t3);
            q.push(t4);
        }
    }

    return false;
}
*/

/*
// 枝刈り深さ優先探索(TLE)

bool judge(tuple<int, int, int> current_point, tuple<int, int, int> &destination_point) {
    int current_point_t = get<0>(current_point);
    int current_point_x = get<1>(current_point);
    int current_point_y = get<2>(current_point);
    int destination_point_t = get<0>(destination_point);
    int destination_point_x = get<1>(destination_point);
    int destination_point_y = get<2>(destination_point);
    int diff_t = abs(current_point_t - destination_point_t);
    int diff_x = abs(current_point_x - destination_point_x);
    int diff_y = abs(current_point_y - destination_point_y);

    if(current_point == destination_point) { return true; }
    if(current_point_t >= destination_point_t) { return false; }
    if(diff_t < diff_x + diff_y) { return false; }

    tuple<int, int, int> t1(current_point_t+1, current_point_x+1, current_point_y);
    tuple<int, int, int> t2(current_point_t+1, current_point_x-1, current_point_y);
    tuple<int, int, int> t3(current_point_t+1, current_point_x, current_point_y+1);
    tuple<int, int, int> t4(current_point_t+1, current_point_x, current_point_y-1);

    return judge(t1, destination_point) || judge(t2, destination_point) || judge(t3, destination_point) || judge(t4, destination_point);
}
*/

/*
// 枝刈り幅優先探索(TLE)

queue<tuple<int, int, int>> q;

bool judge(tuple<int, int, int> starting_point, tuple<int, int, int> &destination_point) {
    q.push(starting_point);

    while(!q.empty()) {
        tuple<int, int, int> current_point = q.front();
        q.pop();

        if(current_point == destination_point) { return true; }

        int current_point_t = get<0>(current_point);
        int current_point_x = get<1>(current_point);
        int current_point_y = get<2>(current_point);
        int destination_point_t = get<0>(destination_point);
        int destination_point_x = get<1>(destination_point);
        int destination_point_y = get<2>(destination_point);
        int diff_t = abs(current_point_t - destination_point_t);
        int diff_x = abs(current_point_x - destination_point_x);
        int diff_y = abs(current_point_y - destination_point_y);

        if(current_point_t < destination_point_t && diff_t >= diff_x + diff_y) {
            tuple<int, int, int> t1(current_point_t+1, current_point_x+1, current_point_y);
            tuple<int, int, int> t2(current_point_t+1, current_point_x-1, current_point_y);
            tuple<int, int, int> t3(current_point_t+1, current_point_x, current_point_y+1);
            tuple<int, int, int> t4(current_point_t+1, current_point_x, current_point_y-1);
            q.push(t1);
            q.push(t2);
            q.push(t3);
            q.push(t4);
        }
    }

    return false;
}
*/

bool judge(tuple<int, int, int> current_point, tuple<int, int, int> &destination_point) {
    int current_point_t = get<0>(current_point);
    int current_point_x = get<1>(current_point);
    int current_point_y = get<2>(current_point);
    int destination_point_t = get<0>(destination_point);
    int destination_point_x = get<1>(destination_point);
    int destination_point_y = get<2>(destination_point);
    int diff_t = abs(current_point_t - destination_point_t);
    int diff_x = abs(current_point_x - destination_point_x);
    int diff_y = abs(current_point_y - destination_point_y);
    int min_move = diff_x + diff_y;

    return (diff_t >= min_move) && ((diff_t - min_move) % 2 == 0);
}

bool plan_judge(vector<tuple<int, int, int>> &plan, int &len) {
    for(int i = 0; i < len; ++i) {
        if(i == 0) { continue; }
        tuple<int, int, int> current_point = plan.at(i-1);
        tuple<int, int, int> destination_point = plan.at(i);
        bool is_ok = judge(current_point, destination_point);
        if(is_ok == false) { return false; }
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    int len = N + 1;

    vector<tuple<int, int, int>> plan(len);
    plan.at(0) = make_tuple(0, 0, 0);

    for(int i = 1; i < len; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        plan.at(i) = make_tuple(t, x, y);
    }

    bool is_ok = plan_judge(plan, len);

    cout << (is_ok ? "Yes" : "No") << endl;

    return 0;
}
