# Leetcode: [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) GfG: [Search in a row wise and column wise sorted matrix](https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/)

**Level**: `Medium`.

**Topic**: `Array`, `Binary Search`, `Matrix`.

Write an efficient algorithm that searches for a value in an `m x n` matrix. This matrix has the following properties:

-   Integers in each row are sorted from left to right.
-   The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**

-   `m == matrix.length`
-   `n == matrix[i].length`
-   `1 <= m, n <= 100`
-   <code>-10<sup>4</sup> <= matrix[i][j], target <= 10<sup>4</sup></code>
