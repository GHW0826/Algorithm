class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int h = std::min(height[left], height[right]);
            int w = right - left;
            answer = std::max(answer, h * w);

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return answer;
    }
};
