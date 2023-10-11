/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
// for (int i = m; i < nums1Size; i++)
// {
//     nums1[i] = nums2[i - m];
// }

// qsort(nums1, nums1Size, sizeof(int), cmp);

int cmp(const void* p1, const void* p2) {
    return *((int *)p1) > *((int *)p2);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int left = 0;
    int right = 0;
    int* tmp = (int*)malloc(sizeof(int) * nums1Size);
    while(left < m && right < n) {
        if(nums1[left] <= nums2[right]) {
            tmp[left + right] = nums1[left];
            left++;
        } else {
            tmp[left + right] = nums2[right];
            right++;
        }
    }

    while (left < m) {
        tmp[left + right] = nums1[left];
        left++;
    }

    while (right < n) {
        tmp[left + right] = nums2[right];
        right++;
    }

    // 方式一：
    // for (int a =0; a < m+n; a++) {
    //     nums1[a] = tmp[a];
    // }

    // 方式二：为什么此方式不对，归根结底是值传递与引用传递的问题
    // 见：/root/dev/c_coding/array_pass_by_value.c 和 /root/dev/c_coding/array_pass_by_reference.c
    // tmp[0] = 223345;
    nums1 = tmp;

    // 方式三：
    // memcpy(nums1, tmp, sizeof(int) * (m + n));
}
// @lc code=end

