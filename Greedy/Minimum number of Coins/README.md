# [Minimum number of Coins](https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1#)

**Level:** `Easy`.

**Topics:** `Greedy`.

Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N.

**Example 1:**

```
Input: N = 43
Output: 20 20 2 1
Explaination:
Minimum number of coins and notes needed
to make 43.
```

**Example 2:**

```
Input: N = 1000
Output: 500 500
Explaination: minimum possible notes
is 2 notes of 500.
```

**Your Task:**
You do not need to read input or print anything. Your task is to complete the function minPartition() which takes the value N as input parameter and returns a list of integers in decreasing order.

**Expected Time Complexity: O(N)**
**Expected Auxiliary Space: O(N)**

**Constraints:**

-   1 ≤ N ≤ 10<sup>6</sup>
