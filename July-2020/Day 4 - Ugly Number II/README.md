# [Ugly Number II](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/)

Write a program to find the `n`-th ugly number.

Ugly numbers are **positive numbers** whose prime factors only include `2, 3, 5`.

**Example:**

```
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
```

**Note:**

1. `1` is typically treated as an ugly number.
2. `n` **does not exceed 1690.**

**Hint #1**

The naive approach is to call `isUgly` for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.

**Hint #2**

An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.

**Hint #3**

The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.

**Hint #4**

Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 _ 2, L2 _ 3, L3 \* 5).
