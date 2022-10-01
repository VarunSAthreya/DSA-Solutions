# [91. Decode Ways](https://leetcode.com/problems/decode-ways/description/)

**Level**: `Medium`.

**Topic**: `String`, `Dynamic Programming`.

A message containing letters from <code>A-Z</code> can be <strong>encoded</strong> into numbers using the following mapping:

<pre>'A' -&gt; "1"
'B' -&gt; "2"
...
'Z' -&gt; "26"
</pre>

To <strong>decode</strong> an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, <code>"11106"</code> can be mapped into:

<ul>
 <li><code>"AAJF"</code> with the grouping <code>(1 1 10 6)</code></li>
 <li><code>"KJF"</code> with the grouping <code>(11 10 6)</code></li>
</ul>

Note that the grouping <code>(1 11 06)</code> is invalid because <code>"06"</code> cannot be mapped into <code>'F'</code> since <code>"6"</code> is different from <code>"06"</code>.

Given a string <code>s</code> containing only digits, return <em>the <strong>number</strong> of ways to <strong>decode</strong> it</em>.

The test cases are generated so that the answer fits in a <strong>32-bit</strong> integer.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> s = "12"
<strong>Output:</strong> 2
<strong>Explanation:</strong> "12" could be decoded as "AB" (1 2) or "L" (12).
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> s = "226"
<strong>Output:</strong> 3
<strong>Explanation:</strong> "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> s = "06"
<strong>Output:</strong> 0
<strong>Explanation:</strong> "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= s.length &lt;= 100</code></li>
 <li><code>s</code> contains only digits and may contain leading zero(s).</li>
</ul>
