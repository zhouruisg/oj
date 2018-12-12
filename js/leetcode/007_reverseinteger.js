/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var sign = 1;
    if (x < 0) {
        sign = -1;
        x = -x;
    }
    var s = x.toString();
    return sign*Number(s.split("").reverse().join(""));

};

console.log(reverse(123));
console.log(reverse(0));
console.log(reverse(-123));