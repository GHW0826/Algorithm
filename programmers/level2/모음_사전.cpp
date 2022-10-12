#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
	int answer = 0;
	map<char, int> table;
	vector<int> orders = { 781, 156, 31, 6, 1 };
	table.insert(make_pair('A', 0));
	table.insert(make_pair('E', 1));
	table.insert(make_pair('I', 2));
	table.insert(make_pair('O', 3));
	table.insert(make_pair('U', 4));
	
	int length = 0;
	for (const auto& it : word) {
		answer += 1 + table[it] * orders[length];
		++length;
	}
	
	return answer;
}
