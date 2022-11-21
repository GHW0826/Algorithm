#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>
using namespace std;

class BjDeque
{
public:
    deque<int> d_;
public:
    void push_front(int val) {
        d_.push_front(val);
    }

    void push_back(int val) {
        d_.push_back(val);
    }

    int pop_front() {
        if (d_.empty() == true)
            return -1;
        int front = d_.front();
        d_.pop_front();
        return front;
    }

    int pop_back() {
        if (d_.empty() == true)
            return -1;
        int back = d_.back();
        d_.pop_back();
        return back;
    }

    int size() {
        return d_.size();
    }

    int empty() {
        return (d_.empty() == true);
    }

    int front() {
        if (d_.empty() == true)
            return -1;
        return d_.front();
    }

    int back() {
        if (d_.empty() == true)
            return -1;
        return d_.back();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int commandLine;
    cin >> commandLine;

    BjDeque d;
    string command;
    for (int i = 0; i <= commandLine; ++i) {
        getline(cin, command);

        stringstream ss;
        ss.str(command);
        string preCommand, strVal;
        ss >> preCommand >> strVal;

        int val = atoi(strVal.c_str());
        if (preCommand == "push_front")
            d.push_front(val);
        else if (preCommand == "push_back")
            d.push_back(val);
        else if (preCommand == "pop_front")
            cout << d.pop_front() << endl;
        else if (preCommand == "pop_back")
            cout << d.pop_back() << endl;
        else if (preCommand == "size")
            cout << d.size() << endl;
        else if (preCommand == "empty")
            cout << d.empty() << endl;
        else if (preCommand == "front")
            cout << d.front() << endl;
        else if (preCommand == "back")
            cout << d.back() << endl;
    }

    return 0;
}
