# [1239. Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/)

**Level**: `Medium`.

**Topic**: `Array`, `String`, `Backtracking`,`Bit Manipulation`.

You are given an array of strings <code>arr</code>. A string <code>s</code> is formed by the <strong>concatenation</strong> of a <strong>subsequence</strong> of <code>arr</code> that has <strong>unique characters</strong>.

Return <em>the <strong>maximum</strong> possible length</em> of <code>s</code>.

A <strong>subsequence</strong> is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> arr = ["un","iq","ue"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> arr = ["cha","r","act","ers"]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> arr = ["abcdefghijklmnopqrstuvwxyz"]
<strong>Output:</strong> 26
<strong>Explanation:</strong> The only string in arr has all 26 characters.
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= arr.length &lt;= 16</code></li>
 <li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
 <li><code>arr[i]</code> contains only lowercase English letters.</li>
</ul>
