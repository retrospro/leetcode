/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start

// void swap(int* num1, int* num2) {
//     int temp = *num1;
//     *num1 = *num2;
//     *num2 = temp;
// }

int removeElement(int* nums, int numsSize, int val){
    // retSize 跟着 i 走，这种方式，最多会遍历数组两次
    // int retSize = 0;
    // for (int i = 0; i < numsSize; i++) {
    //     if (nums[i] != val) {
    //         nums[retSize++] = nums[i];
    //     }
    // }

    // 如果让左右指针在中间相遇，则最多只会遍历数组一次
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1 && nums[0] == val) {
        return 0;
    }

    // 注意：这样写会导致 [3, 3] 这个 case 通过不了
    /*
    int left = 0;
    int right = numsSize - 1;
    while (left < right ){
        if (nums[left] == val) {
            nums[left] = nums[right];
            right--;
        } else {
            left++;
        }
    }

    return left + 1;
    */

   // 正确写法（小小的差别，结果大不一样）：
   int left = 0;
    int right = numsSize;
    while (left < right ){
        if (nums[left] == val) {
            nums[left] = nums[right - 1];
            right--;
        } else {
            left++;
        }
    }

    return left;
}
// @lc code=end

