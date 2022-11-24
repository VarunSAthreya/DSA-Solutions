# [79. Word Search](https://leetcode.com/problems/word-search/)

**Level**: `Medium`.

**Topic**: `Array`, `Backtracking`, `Matrix`.

Given an <code>m x n</code> grid of characters <code>board</code> and a string <code>word</code>, return <code>true</code> <em>if</em> <code>word</code> <em>exists in the grid</em>.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

<strong>Example 1:</strong>

<img alt="image" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg">

<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
<strong>Output:</strong> true
</pre>

<strong>Example 2:</strong>

<img alt="image" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg">

<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
<strong>Output:</strong> true
</pre>

<strong>Example 3:</strong>

<img alt="image" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg">

<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
<strong>Output:</strong> false
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>m == board.length</code></li>
 <li><code>n = board[i].length</code></li>
 <li><code>1 &lt;= m, n &lt;= 6</code></li>
 <li><code>1 &lt;= word.length &lt;= 15</code></li>
 <li><code>board</code> and <code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

<strong>Follow up:</strong> Could you use search pruning to make your solution faster with a larger <code>board</code>?
