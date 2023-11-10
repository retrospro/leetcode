/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start

// 方法二：哈希
typedef struct hash_table {
    int            key;
    int            value;
    UT_hash_handle hh;
} htable;

htable* g_ht = NULL;

htable* find( int key ) {
    htable* tmp = NULL;

    HASH_FIND_INT( g_ht, &key, tmp );
    if ( tmp == NULL ) {
        return NULL;
    }

    return tmp;
}

void insert( int key, int value ) {
    htable* tmp = find( key );
    if ( tmp != NULL ) {
        tmp->value = value;
    }
    else {
        tmp = ( htable* )malloc( sizeof( htable ) );
        if ( tmp == NULL ) {
            return;
        }

        tmp->key   = key;
        tmp->value = value;

        HASH_ADD_INT( g_ht, key, tmp );
    }
}

int majorityElement( int* nums, int numsSize ) {
    /*************************************
    方法一：时间复杂度O(N^2)，超时
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > (numsSize / 2)) {
            res =  nums[i];
            break;
        }
    }
    **************************************/

    /*************************************
    方法二：时间复杂度O(N)，空间复杂度O(N)
    g_ht        = NULL;
    htable* tmp = NULL;
    int     res = nums[ 0 ];

    for ( int i = 0; i < numsSize; i++ ) {
        tmp = find( nums[ i ] );
        if ( tmp == NULL ) {
            insert( nums[ i ], 1 );
        }
        else {
            tmp->value++;
            if ( tmp->value > ( numsSize / 2 ) ) {
                res = tmp->key;
            }
        }
    }
    **************************************/

    /**************************************
    方法三：相消法
    相同的数，count++；不同的数，count--；count为0时众数变为当前数，同时count加1
    **************************************/
    int res   = nums[ 0 ];
    int count = 1;
    for ( int i = 1; i < numsSize; i++ ) {
        if ( nums[ i ] == res ) {
            count++;
        }
        else {
            count--;
            if ( count == 0 ) {
                res = nums[ i ];
                // count++; // 这里容易忘记
                count = 1;  // count = 1 or count++ 都可以
            }
        }
    }

    return res;
}
// @lc code=end
