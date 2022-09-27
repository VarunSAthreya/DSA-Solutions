# [838. Push Dominoes](https://leetcode.com/problems/push-dominoes/)

**Level:** `Easy`.

**Topic:** `Stack`, `Two Pointer`, `Dynamic Programming`.

There are <code>n</code> dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string <code>dominoes</code> representing the initial state where:

<ul>
 <li><code>dominoes[i] = 'L'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the left,</li>
 <li><code>dominoes[i] = 'R'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the right, and</li>
 <li><code>dominoes[i] = '.'</code>, if the <code>i<sup>th</sup></code> domino has not been pushed.</li>
</ul>

Return <em>a string representing the final state</em>.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> dominoes = "RR.L"
<strong>Output:</strong> "RR.L"
<strong>Explanation:</strong> The first domino expends no additional force on the second domino.
</pre>

<strong>Example 2:</strong>
<img alt="example" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 196px; width: 512px;">
<pre><strong>Input:</strong> dominoes = ".L.R...LR..L.."
<strong>Output:</strong> "LL.RR.LLRRLL.."
</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>n == dominoes.length</code></li>
 <li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
 <li><code>dominoes[i]</code> is either <code>'L'</code>, <code>'R'</code>, or <code>'.'</code>.</li>
</ul>
