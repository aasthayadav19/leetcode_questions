/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let left = new Array(height.length)
    let right = new Array(height.length)

    let maxLeft = height[0] ,
        maxRight = height[height.length -1]

    left[0] = maxLeft,
    right[right.length-1] =maxRight

    for(let i=1; i<height.length; i++){
        maxLeft = Math.max (height[i], maxLeft)
        left[i] = maxLeft
    }    

    for(let i=height.length -2; i>=0; i--){
        maxRight = Math.max (height[i], maxRight)
        right[i] = maxRight
    }    

    let ans=0
    for(let i=0; i<height.length; i++){
        ans =( Math.min(left[i], right[i]) -height[i]) + ans
    }
    return ans


};