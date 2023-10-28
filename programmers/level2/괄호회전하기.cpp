#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkString(deque<char>& sen)
{
	string open = "[{(";
	string close = "]})";
	stack<char> s;
	for (int i = 0; i < sen.size(); ++i) {
		if (open.find(sen[i]) != string::npos)
			s.push(sen[i]);
		else {
			auto idx = close.find(sen[i]);
			if (s.empty() == false) {
				if (s.top() != open[idx])
					return false;
				s.pop();
			}
			else
				return false;
		}
	}

	return true;
}

int solution(string s) {
    if ((s.size() % 2) == 1)
        return 0;
    
	int answer = 0;
	deque<char> d(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i) {
		if (checkString(d) == true)
			++answer;
		char front = d.front();
		d.pop_front();
		d.push_back(front);
	}
	return answer;
}
