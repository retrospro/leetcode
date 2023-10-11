/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
// #include "uthash.h"

typedef struct hash_table {
    int h_key;
    int h_value;
    UT_hash_handle hh;
} htable;

htable* g_ht = NULL;

htable* find(int key) {
    // htable* tmp = malloc(sizeof(htable));
    htable* tmp = NULL;

    HASH_FIND_INT(g_ht, &key, tmp);
    // 查找失败，释放内存
    if (tmp == NULL) {
        return NULL;
    }

    // 查找成功，由调用者负责释放内存
    return tmp;
}

void insert(int key, int value) {
    htable* tmp = find(key);

    if(tmp != NULL) {
        tmp->h_value = value;
    }else {
        tmp = malloc(sizeof(htable));
        if (tmp == NULL) {
            return;
        }

        tmp->h_key = key;
        tmp->h_value = value;
        HASH_ADD_INT(g_ht, h_key, tmp);
    }
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    g_ht = NULL;
    htable* tmp = NULL;

    int* ret = malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        tmp = find(target - nums[i]);
        if (tmp != NULL) {
            ret[0] = i;
            ret[1] = tmp->h_value;
            *returnSize = 2;

            return ret;
        } else {
            insert(nums[i], i);
        }
    }

    *returnSize = 0;
    return NULL; 
}
// @lc code=end

