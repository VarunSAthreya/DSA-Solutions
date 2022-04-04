# [1721. Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

**Level**: `Medium`.

**Topic**:

You are given the `head` of a linked list, and an integer `k`.

Return the head of the linked list after **swapping** the values of the `k^th` node from the beginning and the `k^th` node _from the end (the list is **1-indexed**)._

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)

```txt

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

**Example 2:**

```txt

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= k <= n <= 10^5`
- `0 <= Node.val <= 100`
