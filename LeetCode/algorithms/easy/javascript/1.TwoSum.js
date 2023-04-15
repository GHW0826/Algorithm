/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let table = new Map()
    for (let i = 0; i < nums.length; ++i) {
        if (table.get(target - nums[i]) != undefined)
            return [ table.get(target - nums[i]), i ]
        table.set(nums[i], i);
    }
    return []
};
