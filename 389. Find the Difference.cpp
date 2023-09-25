/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    const len = t.length;
    let c = t.charCodeAt(len - 1);
    
    for (let i = 0; i < len - 1; i++) {
    	c ^= (s.charCodeAt(i));
    	c ^= (t.charCodeAt(i));
    }
    
    return String.fromCharCode(c);
};