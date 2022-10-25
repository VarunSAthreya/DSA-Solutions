# [1662. Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/)

**Level:** `Easy`.

**Topic:** `Array`, `String`, `String Matching`.

Given two string arrays <code>word1</code> and <code>word2</code>, return<em> </em><code>true</code><em> if the two arrays <strong>represent</strong> the same string, and </em><code>false</code><em> otherwise.</em>

A string is <strong>represented</strong> by an array if the array elements concatenated <strong>in order</strong> forms the string.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> word1 = ["ab", "c"], word2 = ["a", "bc"]
<strong>Output:</strong> true
<strong>Explanation:</strong>
word1 represents string "ab" + "c" -&gt; "abc"
word2 represents string "a" + "bc" -&gt; "abc"
The strings are the same, so return true.</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> word1 = ["a", "cb"], word2 = ["ab", "c"]
<strong>Output:</strong> false
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
<strong>Output:</strong> true
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>3</sup></code></li>
 <li><code>1 &lt;= word1[i].length, word2[i].length &lt;= 10<sup>3</sup></code></li>
 <li><code>1 &lt;= sum(word1[i].length), sum(word2[i].length) &lt;= 10<sup>3</sup></code></li>
 <li><code>word1[i]</code> and <code>word2[i]</code> consist of lowercase letters.</li>
</ul>
