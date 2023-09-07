//To determine hweter the object is empty or not.
//use Object.keys(obj).length to determine the no. of key value pairs in an object.
/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if(Object.keys(obj).length)
    {
        return false;
    }
    return true;
};