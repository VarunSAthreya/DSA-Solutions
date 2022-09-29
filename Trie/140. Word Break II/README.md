# [140. Word Break II](https://leetcode.com/problems/word-break-ii/description/)

**Level**: `Hard`.

**Topic**: `HashMap`, `String`, `Trie`, `Dynamic Programming`, `Backtracking`, `Memoization`.

Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, add spaces in <code>s</code> to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in <strong>any order</strong>.

<strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
<strong>Output:</strong> ["cats and dog","cat sand dog"]
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
<strong>Output:</strong> ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
<strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
<strong>Output:</strong> []
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= s.length &lt;= 20</code></li>
 <li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
 <li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
 <li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
 <li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
</ul>