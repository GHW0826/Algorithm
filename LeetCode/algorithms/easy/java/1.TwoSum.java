class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> table = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (table.get(target - nums[i]) != null)
                return new int[] { table.get(target - nums[i]), i };
            table.put(nums[i], i);
        }
        return new int[] {};
    }
}
