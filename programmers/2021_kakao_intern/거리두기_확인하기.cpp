#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int infection_prevention_check(vector<pair<int, int>>& pos, vector<pair<int, int>>& tables) 
{
    for (int j = 0; j < pos.size() - 1; ++j) {
        int dist = 0;
        for (int k = j + 1; k < pos.size(); ++k) {
            dist = abs(pos[k].first - pos[j].first) + abs(pos[k].second - pos[j].second);

            if (dist < 2)
                return 0;
            else if (dist <= 2) {
                auto it = find_if(tables.begin(), tables.end(), [&](auto& elem) {
                    int x_min = min(pos[j].first, pos[k].first);
                    int x_max = max(pos[j].first, pos[k].first);
                    int y_min = min(pos[j].second, pos[k].second);
                    int y_max = max(pos[j].second, pos[k].second);

                    return (x_min <= elem.first && elem.first <= x_max) &&
                        (y_min <= elem.second && elem.second <= y_max);
                    });
                if (it != tables.end())
                    return 0;
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int maps = places.size();
    int rows = places[0].size();
    for (int i = 0; i < maps; ++i) {
        vector<pair<int, int>> pos;
        vector<pair<int, int>> tables;

        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < places[i][j].size(); ++k) {
                if (places[i][j][k] == 'P')
                    pos.emplace_back(make_pair(j, k));
                else if (places[i][j][k] == 'O')
                    tables.emplace_back(make_pair(j, k));
            }
        }

        if (pos.size() == 0) {
            answer.push_back(1);
            continue;
        }

        answer.push_back(infection_prevention_check(pos, tables));
    }
    return answer;
}
