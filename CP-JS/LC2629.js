// /**
//  * @param {Function[]} functions
//  * @return {Function}
//  */
// var compose = function(functions) {
//     if(functions.length===0)
//     {
//         return function(x)
//         {
//             return x;
//         }
//     }
//     return functions.reduceRight(function(accumulator,current)
//     {
//         return function(x)
//         {
//             return current(accumulator(x));
//             //On the first call, its value is the last element if initialValue is specified; otherwise its value is the second-to-last element.
//             // The value resulting from the previous call to callbackFn. On the first call, its value is initialValue if the latter is specified; otherwise its value is the last element of the array.

//         };
//     });
// };

// /**
//  * const fn = compose([x => x + 1, x => 2 * x])
//  * fn(4) // 9
//  */