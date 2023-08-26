//2626. Array Reduce Transformation
//perform operation on elements of an array,operations are decided by the function fn.
/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    
    for(let i=0 ;i < nums.length ; i++)
    {
        init= fn(init,nums[i]);
    } 
    return init;

};
