#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int INFINITY = INT8_MAX;

int main() {
    int num, start, finish;
    cout << "Number, start, finish vertex: " << endl;
    cin >> num >> start >> finish;
    start--;
    finish--;

    vector <vector<int>> a(num, vector<int>(num));
    for (int i = 0; i < num; i++) {
        cout << "Table of adjunctions. Row #" << i + 1 << ": " << endl;
        for (int j = 0; j < num; j++)
            cin >> a.at(i).at(j);
    }

    vector<int> distances(num, INFINITY);
    distances.at(start) = 0;

    priority_queue <pair<int, int>> pairsQueue;
    pairsQueue.push(make_pair(0, start));

    int len, vertex;
    while (!pairsQueue.empty()) {
        len = -pairsQueue.top().first;
        vertex = pairsQueue.top().second;
        pairsQueue.pop();

        if (len > distances.at(vertex))
            continue;

        for (int i = 0; i < num; i++) {
            int to = i;
            int length = a.at(vertex).at(i);
            if (distances.at(to) > distances.at(vertex) + length && length >= 0) {
                distances.at(to) = distances.at(vertex) + length;
                pairsQueue.push(make_pair(-distances.at(to), to));
            }
        }
    }

    if (distances.at(finish) == INFINITY)
        cout << "Can't get to that vertex";
    else
        cout << "Min distance: " << distances.at(finish);

    return 0;
}