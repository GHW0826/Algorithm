function twoSum(nums: number[], target: number): number[] {
    const table = new Map<number, number>();
    for (let i = 0; i < nums.length; ++i) {
        if (table.has(target - nums[i]))
            return [ table.get(target - nums[i]), i ]
        table.set(nums[i], i)
    }
    return []
};
