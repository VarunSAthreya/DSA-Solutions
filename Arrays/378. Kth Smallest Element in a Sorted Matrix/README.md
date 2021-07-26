# [378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

**Level:** `Medium`.

**Topics:** `Array`, `Binary Search`, `Sorting`, `Heap(Priority Queue)`, `Matrix`.

Given an `n x n` `matrix` where each of the rows and columns are sorted in ascending order, return the <code>k<sup>th</sup></code> _smallest element in the matrix_.

Note that it is the <code>k<sup>th</sup></code> smallest element **in the sorted order**, not the <code>k<sup>th</sup></code> **distinct** element.

**Example 1:**

```
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
```

**Example 2:**

```
Input: matrix = [[-5]], k = 1
Output: -5
```

**Constraints:**

-   `n == matrix.length`
-   `n == matrix[i].length`
-   `1 <= n <= 300`
-   <code>-10<sup>9</sup> <= matrix[i][j] <= 10<sup>9</sup></code>
-   All the rows and columns of matrix are **guaranteed** to be sorted in **non-decreasing order**.
-   <code>1 <= k <= n<sup>2</sup></code>
