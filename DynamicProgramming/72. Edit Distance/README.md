# [72. Edit Distance](https://leetcode.com/problems/edit-distance/)

**Level**: `Hard`.

**Topic**: `String`, `Dynamic Programming`.

Given two strings <code>word1</code> and <code>word2</code>, return <em>the minimum number of operations required to convert <code>word1</code> to <code>word2</code></em>.

You have the following three operations permitted on a word:

<ul>
 <li>Insert a character</li>
 <li>Delete a character</li>
 <li>Replace a character</li>
</ul>

<strong>Example 1:</strong>

<pre><strong>Input:</strong> word1 = "horse", word2 = "ros"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
horse -&gt; rorse (replace 'h' with 'r')
rorse -&gt; rose (remove 'r')
rose -&gt; ros (remove 'e')
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> word1 = "intention", word2 = "execution"
<strong>Output:</strong> 5
<strong>Explanation:</strong>
intention -&gt; inention (remove 't')
inention -&gt; enention (replace 'i' with 'e')
enention -&gt; exention (replace 'n' with 'x')
exention -&gt; exection (replace 'n' with 'c')
exection -&gt; execution (insert 'u')
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>0 &lt;= word1.length, word2.length &lt;= 500</code></li>
 <li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>
