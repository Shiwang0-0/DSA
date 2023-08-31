//split each element of an array into an array itself.
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    let brr=[];
    let i=0,j=0;
    while(i<arr.length)
    {
        brr[j]=arr.slice(i,size+i);
        i=i+size;
        j++;
    }
    return brr;
};