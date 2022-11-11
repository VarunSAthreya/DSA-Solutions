# [374. Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)

**Level**: `Easy`.

**Topic**: `Binary Search`, `Interactive`.

We are playing the Guess Game. The game is as follows:

I pick a number from <code>1</code> to <code>n</code>. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API <code>int guess(int num)</code>, which returns three possible results:

<ul>
 <li><code>-1</code>: Your guess is higher than the number I picked (i.e. <code>num &gt; pick</code>).</li>
 <li><code>1</code>: Your guess is lower than the number I picked (i.e. <code>num &lt; pick</code>).</li>
 <li><code>0</code>: your guess is equal to the number I picked (i.e. <code>num == pick</code>).</li>
</ul>

Return <em>the number that I picked</em>.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> n = 10, pick = 6
<strong>Output:</strong> 6
</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> n = 1, pick = 1
<strong>Output:</strong> 1
</pre>

<strong>Example 3:</strong>

<pre><strong>Input:</strong> n = 2, pick = 1
<strong>Output:</strong> 1
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
 <li><code>1 &lt;= pick &lt;= n</code></li>
</ul>
