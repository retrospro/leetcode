/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
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

// c语言是值传递，
// 函数外部需要使用 int returnSize 和 int* returnColumnSizes，
// 想要在函数内部修改 int returnSize 和 int* returnColumnSizes，则必须以 int* returnSize 和 int** returnColumnSizes 作为入参
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // *returnSize 必须要初始化
    *returnSize = 0;

    if (numsSize < 4) {
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    long long sum;
    // int** res = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    int** res = NULL;
    int resSize = 0;
    // int resCapacity = 0;

    // 给结果赋值的方式二需要在此处就预先分配内存
    // *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);

    for (int i = 0; i < numsSize - 3; i++) {
        if (nums[i] > 0 && nums[i] > target) {
            break;
        }

        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j ++) {
            if (nums[j] > 0 && nums[j] + nums[i] > target) {
                break;
            }

            if ((j > i + 1) && nums[j] == nums[j - 1]) {
                continue;
            }

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                // 先加再转类型，在转类型之前已经溢出了
                // sum = (long long)(nums[i] + nums[j] + nums[left] + nums[right]);
                sum = (long long)nums[i] + nums[j] + nums[left] + nums[right]; // long long 类型与int类型相加，结果是 long long 类型
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    // if (resSize == resCapacity) {
                    //     resCapacity = resCapacity == 0 ? 1 : resCapacity * 2;
                    //     res = (int**)realloc(res, sizeof(int*) * resCapacity);
                    //     (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), sizeof(int) * resCapacity);
                    // }
                    res = (int**)realloc(res, sizeof(int*) * (resSize + 1));

                    res[resSize] = (int*)malloc(sizeof(int) * 4);
                    res[resSize][0] = nums[i];
                    res[resSize][1] = nums[j];
                    res[resSize][2] = nums[left];
                    res[resSize][3] = nums[right];

                    (*returnColumnSizes)[resSize] = 4;
                    resSize++;
                    // 给结果赋值的方式一
                    // int* tmpRes = (int*)malloc(sizeof(int) * 4);
                    // tmpRes[0] = nums[i];
                    // tmpRes[1] = nums[j];
                    // tmpRes[2] = nums[left];
                    // tmpRes[3] = nums[right];
                    
                    // case 1
                    // res[(*returnSize)++] = tmpRes;

                    // case 2（必须要先分配内存，在进行memcpy，
                    // 因为 int** res = (int**)malloc(sizeof(int*) * numsSize * numsSize); 只是分配了 int* 类型的地址，
                    // 没有分配 int 类型的地址
                    // res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    // memcpy(res[(*returnSize)], tmpRes, sizeof(int) * 4);

                    /* 
                    在将 tmpRes 赋值给 res 后，立即释放了 tmpRes 的内存，
                    这样 res 中存储的指针就指向了一个已经被释放的内存地址，导致程序出现未定义的行为。
                    分配给临时变量 tmpRes 的内存应该在 res 中的所有指针都不再指向它时释放。
                    因为 res 中的指针指向的是 tmpRes 中的元素，只有当 res 中的指针都指向其他内存地址时，
                    才能释放 tmpRes 的内存，否则就会出现指针悬挂的问题。
                    */
                    // free(tmpRes);
                    // tmpRes = NULL;
                    // (*returnSize)++;

                    /************************************************************/
                    // 给结果赋值的方式二
                    // (*returnColumnSizes)[*returnSize] = 4;
                    // res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    // res[*returnSize][0] = nums[i];
                    // res[*returnSize][1] = nums[j];
                    // res[*returnSize][2] = nums[left];
                    // res[*returnSize][3] = nums[right];
                    // (*returnSize)++;

                    left++;
                    right--;

                    // 去重
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
    }

        
    // *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    // for (int j = 0; j < *returnSize; j++) {
    //     (*returnColumnSizes)[j] = 4;
    // }
    *returnSize = resSize;

    return res;
}

// 想想这个 g_ht 全局变量可以如何优化（慎用全局变量）
// @lc code=end

