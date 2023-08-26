//PROBLEM 2620 LEETCODE
//Given an integer n, return a counter function. This counter function initially returns n and then returns 1 more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).

// function need to return value n at the first call then after each new call it will increase the value of n by 1.
var createCounter = function(n) {
    return function() {
        return n++;
    };
};
let calling= createCounter(5);
// console.log(calling);   
console.log(calling());
console.log(calling());

