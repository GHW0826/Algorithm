#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == 0)
            numbers[i] = 11;
        numbers[i] -= 1;
    }

    string left = "036";
    string right = "258";
    string answer = "";
    int left_pos = 9, right_pos = 11;
    for (int i = 0; i < numbers.size(); ++i) {
        if (left.find(to_string(numbers[i])) != string::npos) {
            answer += "L";
            left_pos = numbers[i];
        }
        else if (right.find(to_string(numbers[i])) != string::npos) {
            answer += "R";
            right_pos = numbers[i];
        }
        else {
            int left_dist = abs(left_pos / 3 - numbers[i] / 3) +
                            abs(left_pos % 3 - numbers[i] % 3);
            int right_dist = abs(right_pos / 3 - numbers[i] / 3) +
                             abs(right_pos % 3 - numbers[i] % 3);
            if (left_dist < right_dist) {
                answer += "L";
                left_pos = numbers[i];
            }
            else if (right_dist < left_dist) {
                answer += "R";
                right_pos = numbers[i];
            }
            else {
                if (hand == "right") {
                    answer += "R";
                    right_pos = numbers[i];
                }
                else {
                    answer += "L";
                    left_pos = numbers[i];
                }
            }
        }
    }
    return answer;
}
