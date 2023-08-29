//returning arr when arr is modified by the function fn.
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for(let i=0;i<arr.length;i++)
    {
        arr[i]= fn(arr[i],i);
    }
    return arr;
};