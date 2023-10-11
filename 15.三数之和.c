/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* p1, const void* p2) {
    return *((int*)p1) > *((int*)p2);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(sizeof(int*) * 18000);
    *returnSize = 0;

    if (numsSize < 3) {
        return ret;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        if(nums[i] > 0) {
            break;
        }

        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            }else {
                int* temp = (int*)malloc(sizeof(int) * 3);
                temp[0] = nums[i];
                temp[1] = nums[left];
                temp[2] = nums[right];

                ret[(*returnSize)++] = temp;

                left++;
                right--;

                // 去重
                // if (nums[right] == nums[right + 1]) {
                //     right--;
                // }
                // if(nums[left] == nums[left - 1]) {
                //     left++;
                // }
                // if 去重会导致去重不彻底，应该用 while去重
                // 另外 right > left &&  也不能少，否则可能导致访问越界
                while (right > left && nums[right] == nums[right + 1]) {
                    right--;
                }
                while (right > left && nums[left] == nums[left - 1]) {
                    left++;
                }
            }
        }
    }

    // 搞清楚为什么只需要分配int*，而不是分配 int**
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int row = 0; row < *returnSize; row++) {
        (*returnColumnSizes)[row] = 3;
    }

    return ret;
}
// @lc code=end

