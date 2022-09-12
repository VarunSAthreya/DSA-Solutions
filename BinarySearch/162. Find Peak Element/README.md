# [162. Find Peak Element](https://leetcode.com/problems/find-peak-element/)

**Level**: `Medium`.

**Topic**: `Array`, `Binary Search`.

A peak element is an element that is strictly greater than its neighbors.

Given a <strong>0-indexed</strong> integer array <code>nums</code>, find a peak element, and return its index. If the array contains multiple peaks, return the index to <strong>any of the peaks</strong>.

You may imagine that <code>nums[-1] = nums[n] = -∞</code>. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in <code>O(log n)</code> time.

<strong>Example 1:</strong>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 3 is a peak element and your function should return the index number 2.</pre>

<strong>Example 2:</strong>

<pre><strong>Input:</strong> nums = [1,2,1,3,5,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.</pre>

<strong>Constraints:</strong>

<ul>
 <li><code>1 &lt;= nums.length &lt;= 1000</code></li>
 <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
 <li><code>nums[i] != nums[i + 1]</code> for all valid <code>i</code>.</li>
</ul>
