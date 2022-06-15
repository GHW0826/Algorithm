#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;

    return true;
}

void find(int num, int N)
{
    if (N == 0)
        cout << num << "\n";

    for (int i = 1; i < 10; i += 2) {
        int tmp = num * 10 + i;
        if (isPrime(tmp))
            find(tmp, N - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> first = { 2, 3, 5, 7 };
    for (int i = 0; i < 4; ++i)
        find(first[i], N - 1);

    return 0;
}
