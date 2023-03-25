
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    vector<int> dist(101, -1);
    vector<int> map(101, 0);
    int start, end;

    // ladder
    for (int i = 0; i < N; ++i) {
        cin >> start >> end;
        map[start] = end;
    }

    // snake
    for (int i = 0; i < M; ++i) {
        cin >> start >> end;
        map[start] = end;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (q.empty() == false) {
        int index = q.front();
        q.pop();
        
        for (int i = 1; i <= 6; ++i) {
            int nextIndex = index + i;
            if (nextIndex > 100)
                continue;

            if (map[nextIndex] != 0)
                nextIndex = map[nextIndex];
            if (dist[nextIndex] == -1) {
                dist[nextIndex] = dist[index] + 1;
                q.push(nextIndex);
            }
        }
    }
    cout << dist[100] << "\n";

    return 0;
}
