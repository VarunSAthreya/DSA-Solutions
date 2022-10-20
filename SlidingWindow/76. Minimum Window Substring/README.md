# [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/)

**Level:** `Hard`.

**Topic:** `Sliding Window`, `Hash Table`, `String`.

Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window substring</strong> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window. If there is no such substring</em><em>, return the empty string </em><code>""</code><em>.</em>

The testcases will be generated such that the answer is <strong>unique</strong>.

A <strong>substring</strong> is a contiguous sequence of characters within the string.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "ADOBECODEBANC", t = "ABC"
<strong>Output:</strong> "BANC"
<strong>Explanation:</strong> The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "a", t = "a"
<strong>Output:</strong> "a"
<strong>Explanation:</strong> The entire string s is the minimum window.
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> s = "a", t = "aa"
<strong>Output:</strong> ""
<strong>Explanation:</strong> Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>m == s.length</code></li>
 <li><code>n == t.length</code></li>
 <li><code>1 &lt;= m, n&nbsp;&lt;= 10<sup>5</sup></code></li>
 <li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?
