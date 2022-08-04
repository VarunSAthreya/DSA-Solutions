# Leetcode: [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

**Level**: `Medium`.

**Topic**: `Array`, `Binary Search`, `Matrix`.

Write an efficient algorithm that searches for a value in an `m x n` matrix. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```txt
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```txt
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- <code>-10<sup>4</sup> <= matrix[i][j], target <= 10<sup>4</sup></code>

# GfG: [Search in a matrix](https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1)

**Level**: `Easy`.

**Topic**: `Binary Search`, `Matrix`.

Given a matrix **mat[][]** of size **N x M**, where every row and column is sorted in increasing order, and a number **X** is given. The task is to find whether element **X** is present in the matrix or not.

**Example 1:**

```txt
Input:
N = 3, M = 3
mat[][] = 3 30 38
         44 52 54
         57 60 69
X = 62
Output:
0
Explanation:
62 is not present in the
matrix, so output is 0
```

**Example 2:**

```txt
Input:
N = 1, M = 6
mat[][] = 18 21 27 38 55 67
X = 55
Output:
1
Explanation:
55 is present in the
matrix at 5th cell.
```

**Your Task:**
You don't need to read input or print anything. You just have to complete the function matSearch() which takes a 2D matrix mat[][], its dimensions N and M and integer X as inputs and returns 1 if the element X is present in the matrix and 0 otherwise.

**Expected Time Complexity: O(N+M).**
**Expected Auxiliary Space: O(1).**

**Constraints:**

- `1 <= N, M <= 1005`
- `1 <= mat[][] <= 10000000`
- `1<= X <= 10000000`
