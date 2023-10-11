/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
// #define min(x, y) ({                \
//     typeof(x) _min1 = (x);          \
//     typeof(y) _min2 = (y);          \
//     (void) (&_min1 == &_min2);      \
//     _min1 < _min2 ? _min1 : _min2; })

// #define max(x, y) ({                \
//     typeof(x) _max1 = (x);          \
//     typeof(y) _max2 = (y);          \
//     (void) (&_max1 == &_max2);      \
//     _max1 > _max2 ? _max1 : _max2; })
// #define min(x, y) ((x) < (y) ? (x) : (y))
// #define max(x, y) ((x) > (y) ? (x) : (y))


int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int res = 0;
    int area = 0;
    while (left < right) {
        area = fmin(height[left], height[right]) * (right - left);
        res = fmax(res, area);
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}
// @lc code=end

