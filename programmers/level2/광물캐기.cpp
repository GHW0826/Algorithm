#include <vector>
#include <map>

using namespace std;

int answer = 987654321;
map<pair<int, string>, int> table = {
	make_pair(make_pair(0, "diamond"), 1), make_pair(make_pair(0, "iron"), 1), make_pair(make_pair(0, "stone"), 1),
	make_pair(make_pair(1, "diamond"), 5), make_pair(make_pair(1, "iron"), 1), make_pair(make_pair(1, "stone"), 1),
	make_pair(make_pair(2, "diamond"), 25), make_pair(make_pair(2, "iron"), 5), make_pair(make_pair(2, "stone"), 1),
};

int fiveMine(int start, int pickType, vector<string>& mines) {
	int fatigue = 0;
	for (int i = (start * 5); i < (start + 1) * 5; ++i) {
		if (i >= mines.size())
			break;
		fatigue += table[make_pair(pickType, mines[i])];
	}
	return fatigue;
}

void dfs(int cnt, int res, vector<int>& picks, vector<string>& mines) {
	if ((!picks[0] && !picks[1] && !picks[2]) || cnt * 5 >= mines.size()) {
		answer = min(answer, res);
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (picks[i]) {
			--picks[i];
			dfs(cnt + 1, res + fiveMine(cnt, i, mines), picks, mines);
			++picks[i];
		}
	}
}

int solution(vector<int> picks, vector<string> minerals) {
	dfs(0, 0, picks, minerals);
	return answer;
}
