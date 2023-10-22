#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;
unordered_map <string, vector<int>> table;

vector<int> solution(vector<string> info, vector<string> query) {
	string s[4], str = "";
	for (int i = 0; i < info.size(); i++) {
		istringstream stt(info[i]);
		stt >> s[0] >> s[1] >> s[2] >> s[3] >> str;
		vector<string> lang   = { "-", s[0] };
		vector<string> job    = { "-", s[1] };
		vector<string> career = { "-", s[2] };
		vector<string> food   = { "-", s[3] };
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					for (int z = 0; z < 2; ++z) {
						string key = lang[i] + job[j] + career[k] + food[z];
						table[key].push_back(atoi(str.c_str()));
					}
				}
			}
		}
	}

	for (auto itr = table.begin(); itr != table.end(); itr++)
		sort(itr->second.begin(), itr->second.end());

    vector<int> answer;
	for (int i = 0; i < query.size(); i++) {
		istringstream stt(query[i]);
		stt >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str;

		int score = (int)stoi(str);
		vector <int> v = table[s[0] + s[1] + s[2] + s[3]];
		if (v.size() != 0) {
			int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
			answer.push_back(v.size() - idx);
		}
		else 
			answer.push_back(0);
	}
    return answer;
}
