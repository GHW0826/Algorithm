#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {
    for_each(new_id.begin(), new_id.end(), [](char & c) {
        c = ::tolower(c);
    });
    new_id = regex_replace(new_id, regex("[^0-9a-z._-]"), "");
    new_id = regex_replace(new_id, regex("[.]{2,}"), ".");
    
    if (new_id.find_first_of('.') == 0)
        new_id = new_id.substr(1, new_id.size());
    if (new_id.find_last_of('.') == new_id.size() - 1 && new_id.empty() == false)
        new_id.pop_back();
    
    if (new_id.empty() == true)
        new_id = "a";
        
    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.')
            new_id.pop_back();
    }
    
    if (new_id.size() <= 2) {
        auto word = new_id[new_id.size() - 1];
        while (new_id.size() < 3)
            new_id.push_back(word);
    }
        
    return new_id;
}
