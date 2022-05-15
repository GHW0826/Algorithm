#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int size = 0;
	int exam_size = 0;
    scanf("%d %d", &size, &exam_size);

	int sum = 0;
	vector<long> acc(size + 1, 0);
	for (int i = 1; i <= size; ++i) {
		int num = 0;
		scanf("%d", &num);
		acc[i] = acc[i - 1] + num;
	}

	vector<int> answer;
	for (int i = 0; i < exam_size; ++i) {
		int x = 0, y = 0;
        scanf("%d %d", &x, &y);
        printf("%d\n", (acc[y] - acc[x - 1]));
	}

	return 0;
}
