#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<long long> tree;
vector<long long> arr;

long long init(int start, int end, int node) {
    if (start == end)
        return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) +
        sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff) {
    if (index < start || index > end)
        return;
    tree[node] += diff;
    if (start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    arr.resize(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    tree.resize(4 * N, 0);
    init(0, N - 1, 1);

    long long a, b, c;
    vector<long long> answer;
    for (int i = 0; i < M + K; ++i) {
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b - 1];
            arr[b - 1] = c;
            update(0, N - 1, 1, b - 1, diff);
        }
        else if (a == 2)
            answer.push_back(sum(0, N - 1, 1, b - 1, c - 1));
    }

    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << endl;

    return 0;

}
