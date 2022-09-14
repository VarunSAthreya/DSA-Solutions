# [2405. Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/)

**Level**: `Medium`.

**Topic**: `Bit Manipulation`, `string`.

Given a string <code>s</code>, partition the string into one or more <strong>substrings</strong> such that the characters in each substring are <strong>unique</strong>. That is, no letter appears in a single substring more than <strong>once</strong>.

Return <em>the <strong>minimum</strong> number of substrings in such a partition.</em>

Note that each character should belong to exactly one substring in a partition.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "abacaba"
<strong>Output:</strong> 4
<strong>Explanation:</strong>
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "ssssss"
<strong>Output:</strong> 6
<strong>Explanation:
</strong>The only valid partition is ("s","s","s","s","s","s").
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
 <li><code>s</code> consists of only English lowercase letters.</li>
</ul>
