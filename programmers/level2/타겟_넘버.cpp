#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers, int target) {
    int numberCnt = numbers.size();
    
    int answer = 0;
    for (int i = 0; i < numberCnt; ++i) {
        vector<int> dummy(numbers.size(), 1);
        for (int j = 0; j < i + 1; ++j)
            dummy[j] = -1;
        do {
            int sum = 0;
		    for(int k = 0; k < numberCnt; k++)
                sum += numbers[k] * dummy[k];
            
            if (sum == target)
                ++answer;
	    } while (next_permutation(dummy.begin(), dummy.end()));
    }
  
    return answer;
}
