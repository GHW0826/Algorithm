#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0)
            return false;
    return true;
}

int num = 0;
int answer = 0;
void makePrime(vector<int>& arr, int start, int depth) {
    if (depth == 3) {
        if (isPrime(num))
            ++answer;
        return;
    }
    
    for (int i = start; i < arr.size(); ++i) {
        num += arr[i];
        makePrime(arr, i + 1, depth + 1);
        num -= arr[i];
    }
}

int solution(vector<int> nums) {
    makePrime(nums, 0, 0);
    return answer;
}
