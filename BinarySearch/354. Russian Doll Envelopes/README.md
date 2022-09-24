# [354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)

**Level**: `Hard`.

**Topic**: `Array`, `Binary Search`, `Dynamic Programming`, `Sorting`.

You are given a 2D array of integers <code>envelopes</code> where <code>envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>]</code> represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return <em>the maximum number of envelopes you can Russian doll (i.e., put one inside the other)</em>.

<strong>Note:</strong> You cannot rotate an envelope.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> envelopes = [[5,4],[6,4],[6,7],[2,3]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The maximum number of envelopes you can Russian doll is <code>3</code> ([2,3] =&gt; [5,4] =&gt; [6,7]).
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> envelopes = [[1,1],[1,1],[1,1]]
<strong>Output:</strong> 1
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= envelopes.length &lt;= 10<sup>5</sup></code></li>
 <li><code>envelopes[i].length == 2</code></li>
 <li><code>1 &lt;= w<sub>i</sub>, h<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
