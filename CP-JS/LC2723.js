//adding two promises
//use await to resolve both promisesso that none promise is left behind.
//use an array to store the promises value returned by the function

/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    const [value1 ,value2]= await Promise.all([promise1,promise2]);
    return value1+value2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */