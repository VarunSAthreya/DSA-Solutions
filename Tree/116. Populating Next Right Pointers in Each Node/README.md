# [116. Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

**Level**: `Medium`.

**Topic**: `Tree`, `Binary Tree`, `Depth First Search`, `Linked List`, `Breadth First Search`.

You are given a <strong>perfect binary tree</strong> where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

<pre>struct Node {
  int val;
  Node *left;
Node*right;
  Node *next;
}
</pre>

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.

Initially, all next pointers are set to <code>NULL</code>.

<strong>Example 1:</strong>
<img alt="image" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="width: 500px; height: 171px;">
<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
<strong>Explanation: </strong>Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<strong>Constraints:</strong>

<ul>
 <li>The number of nodes in the tree is in the range <code>[0, 2<sup>12</sup> - 1]</code>.</li>
 <li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<strong>Follow-up:</strong>

<ul>
 <li>You may only use constant extra space.</li>
 <li>The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.</li>
</ul>
