//returing an array containing those values which results as a true expression in the function fn.
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var filteredArr=[];
    let j=0;
    for(let i=0;i<arr.length;i++)
    {
        if(fn(arr[i],i))
        {
            filteredArr[j]=arr[i];
            j++;
        } 
    }
    return filteredArr;
};