# [Top View of Binary Tree](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

**Level**: `Medium`.

**Topic**: `Tree`, `Binary Search Tree`.

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

```txt
       1
    /     \
   2       3
  /  \    /   \
4    5  6   7
```

Top view will be: 4 2 1 3 7
**Note:** Return nodes from **leftmost** node to **rightmost** node.

**Example 1:**

```txt
Input:
      1
   /    \
  2      3
Output: 2 1 3
```

**Example 2:**

```txt
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
```

**Your Task:**
Since this is a function problem. You don't have to take input. Just complete the function **topView()** that takes **root node** as parameter and returns a list of nodes visible from the top view from left to right.

**Expected Time Complexity:** O(N)
**Expected Auxiliary Space:** O(N).

**Constraints:**

- `1 ≤ N ≤ 10^5`
- `1 ≤ Node Data ≤ 10^5`
