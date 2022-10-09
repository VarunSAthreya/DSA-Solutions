# [653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/)

**Level**: `Easy`.

**Topic**: `Tree`, `Binary Tree`, `Depth First Search`,`Breath-First String`, `Hash Table`, `Two Pointer`, `Binary Search Tree`.

Given the <code>root</code> of a Binary Search Tree and a target number <code>k</code>, return <em><code>true</code> if there exist two elements in the BST such that their sum is equal to the given target</em>.

<strong>Example 1:</strong>

<img alt="image" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg" style="width: 400px; height: 229px;">

<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 9
<strong>Output:</strong> true
</pre>

<strong>Example 2:</strong>

<img alt="image" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg" style="width: 400px; height: 229px;">

<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 28
<strong>Output:</strong> false
</pre>

<strong>Constraints:</strong>

<ul>
 <li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
 <li><code>-10<sup>4</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>4</sup></code></li>
 <li><code>root</code> is guaranteed to be a <strong>valid</strong> binary search tree.</li>
 <li><code>-10<sup>5</sup>&nbsp;&lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>
