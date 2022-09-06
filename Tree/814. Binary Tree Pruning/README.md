# [814. Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning/)

**Level**: `Medium`.

**Topic**: `Tree`, `Binary Tree`, `Depth-First Search`.

Given the `root` of a binary tree, return _the same tree where every subtree (of the given tree) not containing a `1` has been removed._

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

```txt
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

**Example 2:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

```txt
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

**Example 3:**

```txt
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
 ```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 200]`.
- `Node.val` is either `0` or `1`.
