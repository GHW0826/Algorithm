#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer;
    map<string, string> table;
    for (int i = 0; i < db.size(); ++i)
        table[db[i][0]] = db[i][1];
    
    if (table.find(id_pw[0]) != table.end())
        answer = (table[id_pw[0]] == id_pw[1]) ? "login" : "wrong pw";
    else
        answer = "fail";
    return answer;
}
