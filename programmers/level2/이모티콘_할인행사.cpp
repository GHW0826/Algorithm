#include <string>
#include <vector>

using namespace std;

int maxOutfit = 0;
int maxJoinPlusService = 0;
vector<int> discount = { 40, 30, 20, 10 };
vector<int> snapShot;
void dfs(vector<vector<int>>& users, vector<int>& emoticons)
{
	if (snapShot.size() == emoticons.size()) {
		int sumUserOutfit = 0;
		int joinPlusService = 0;
		for (int i = 0; i < users.size(); ++i) {
			int perUserOutfit = 0;
			for (int j = 0; j < snapShot.size(); ++j) {
				if (users[i][0] <= snapShot[j]) {
					perUserOutfit += emoticons[j] * ((100 - snapShot[j]) / static_cast<double>(100));
				}
			}
			if (perUserOutfit >= users[i][1]) {
				perUserOutfit = 0;
				++joinPlusService;
			}
			sumUserOutfit += perUserOutfit;
		}
		if (joinPlusService > 0) {
			if (maxJoinPlusService < joinPlusService) {
				maxJoinPlusService = joinPlusService;
				maxOutfit = sumUserOutfit;
			}
			else if (maxJoinPlusService == joinPlusService) {
				if (maxOutfit <= sumUserOutfit) {
					maxJoinPlusService = joinPlusService;
					maxOutfit = sumUserOutfit;
				}
			}
		}
		else {
			if (maxJoinPlusService == 0 && maxOutfit <= sumUserOutfit) {
				maxJoinPlusService = joinPlusService;
				maxOutfit = sumUserOutfit;
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		snapShot.push_back(discount[i]);
		dfs(users, emoticons);
		snapShot.pop_back();
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	dfs(users, emoticons);

	return { maxJoinPlusService, maxOutfit };
}
