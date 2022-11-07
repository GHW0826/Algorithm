#include <algorithm>
#include <set>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cities.size() == 0)
        return 0;
    else if (cacheSize == 0)
        return cities.size() * 5;
    int answer = 0;
    set<string> cache;
    list<string> order;
    for (int i = 0; i < cities.size(); ++i) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        if (cache.find(cities[i]) != cache.end()) {
            ++answer;
            order.remove(cities[i]);
            order.push_back(cities[i]);
        }
        else {
            answer += 5;
            if (order.empty() == false) {
                auto val = order.front();
                if (cache.size() == cacheSize) {
                    cache.erase(val);
                    order.pop_front();
                }
            }
            cache.insert(cities[i]);
            order.push_back(cities[i]);
        }
    }
    return answer;
}
