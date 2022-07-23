# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

**Topic:** `Array`, `Dynamic Programming`.
**Level:** `Easy`.

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```txt
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2:**

```txt
Input: nums = [1]
Output: 1
```

**Example 3:**

```txt
Input: nums = [5,4,-1,7,8]
Output: 23
```

**Constraints:**

- <code>1 <= nums.length <= 3 \* 10<sup>4</sup></code>
- <code>-10<sup>5</sup> <= nums[i] <= 10<sup>5</sup></code>

**Follow up:** If you have figured out the O(n) solution, try coding another solution using the **divide and conquer** approach, which is more subtle.
