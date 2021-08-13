# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)

**Level**: `Easy`.

**Topic**: `Array`, `Dynamic Programming`.

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

![Example](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]
```

**Constraints:**

-   `1 <= numRows <= 30`

**Not part of the question:**
But slight variation of the problem:

-   For finding the value of pascal triangle in a specific index(r,c) then formula: <sup>r-1</sup>C<sub>c-1</sub>

-   For printing the value of the n row of pascal triangle in O(n)
    Calculating value of:
    `[n * (n-1) * --- * (n-k+1) ]`
    code:

```c++
for (int i = 0; i < k; i++)
{
    res *= (n - 1);
    res /= (i + 1);
}
```
