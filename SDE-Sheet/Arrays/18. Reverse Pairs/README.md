# [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/)

**Level**: `Hard`.

**Topic**: `Array`, `Binary Search`, `Divide and Conquer`, `Binary Indexed Search`, `Segment Tree`, `Merge Sort`, `Ordered Set`.

Given an integer array `nums`, _return the number of **reverse pairs** in the array._

A reverse pair is a pair `(i, j)` where `0 <= i < j < nums.length and nums[i] > 2 * nums[j]`.

**Example 1:**

```txt
Input: nums = [1,3,2,3,1]
Output: 2
```

**Example 2:**

```txt
Input: nums = [2,4,3,5,1]
Output: 3
 ```

**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
