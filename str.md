704 Binary Search
  // pseudo
  arr[...n-1], target
  
  start <- 0
  end <- arr.size - 1
  mid <- (start + end) / 2
  while (start <= end) do {
    if (arr[mid] == target)     return mid
    else if (arr[mid] < target) start <- mid + 1
    else if (arr[mid] > target) end <- mid - 1
  }
cpp
// O(logN)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, mid, end = nums.size() - 1
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
        }
        return -1;
    }
};
java
// O(logN)
class Solution {
    public int search(int[] nums, int target) {
        int start = 0, mid, end = nums.length - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                start = mid + 1;
            else if (nums[mid] > target)
                end = mid - 1;
        }
        return -1;
    }
}

// O(logN)
class Solution {
    public int search(int[] nums, int target) {
        int answer = Arrays.binarySearch(nums, target);
       return (answer >= 0) ? answer : -1;
    }
}
2037 Minimum Number of Moves to Seat Everyone
  // pseudo
  sort arr1
  sort arr2
  
  answer <- 0
  For i = 0; to N -1
    answer += abs(arr1[i] - arr2[i])
  
  return answer;
cpp
// O(NlogN) - sort,  O(N) - answer
// O(NlogN)
// sort : quick sort
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int answer = 0;
        for (int i = 0; i < seats.size(); ++i)
            answer += abs(students[i] - seats[i]);
            
        return answer;
    }
};
java
/*
  O(NlogN) - sort, O(N) - answer;
  O(NlogN)
  
  insertion sort + merge sort = tim sort
  insertion sort + quick sort = dual-pivot quick sort
*/
class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        
        int answer = 0;
        for (int i = 0; i < seats.length; ++i)
            answer += Math.abs(students[i] - seats[i]);
    
        return answer;
    }
}
74 Search a 2D Matrix
  // pseudo
  row <- matrix row
  col <- matrix col
  answer <- false;
  For i = 0; to row
    if (target <= matrix[i][col])
      if (row in target)
        answer <- true;
        
  return answer;
cpp
// O(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool answer = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i)
          if (find(matrix[i].begin(), matrix[i].end(), target) != matrix[i].end())
              answer = true;
        
        return answer;
    }
};
java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for(int i = 0; i < matrix.length; i++)
            if(Arrays.binarySearch(matrix[i], target)>=0)
                    return true;
        return false;
    }
}
