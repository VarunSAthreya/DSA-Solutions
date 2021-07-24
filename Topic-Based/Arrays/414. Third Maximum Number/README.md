# [414. Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)

**Level:** `Easy`.

**Topics:** `Array`, `Sorting`.

Given integer array `nums`, return the third _maximum number in this array_. If the third maximum does not exist, return the maximum number.

**Example 1:**

```
Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.
```

**Example 2:**

```
Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
```

**Example 3:**

```
Input: nums = [2,2,3,1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
```

**Constraints:**

-   <code>1 <= nums.length <= 10<sup>4</sup></code>
-   <code>-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1</code>

**Follow up:** Can you find an `O(n)` solution?
