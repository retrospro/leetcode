/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <stdlib.h>
int cmp( const void* p1, const void* p2 ) {
    return *( ( int* )p1 ) > *( ( int* )p2 );
}

int threeSumClosest( int* nums, int numsSize, int target ) {
    qsort( nums, numsSize, sizeof( int ), cmp );
    int minDiff = __INT_MAX__;

    for ( int i = 0; i < numsSize - 2; i++ ) {
        // 优化，去重
        if ( i > 0 && nums[ i ] == nums[ i - 1 ] ) {
            continue;
        }

        int left       = i + 1;
        int right      = numsSize - 1;
        int curDiffAbs = __INT_MAX__;
        int diff       = __INT_MAX__;

        while ( left < right ) {
            diff       = nums[ i ] + nums[ left ] + nums[ right ] - target;
            curDiffAbs = abs( diff );
            minDiff    = curDiffAbs < abs( minDiff ) ? diff : minDiff;

            if ( diff > 0 ) {
                right--;

                // 优化，去重
                while ( left < right && nums[ right ] == nums[ right + 1 ] ) {
                    right--;
                }
            }
            else if ( diff < 0 ) {
                left++;

                // 优化，去重
                while ( left < right && nums[ left ] == nums[ left - 1 ] ) {
                    left++;
                }
            }
            else {
                return target;
            }
        }
    }

    return minDiff + target;
}
// @lc code=end
