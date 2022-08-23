# [Subarray with given XOR](https://www.interviewbit.com/problems/subarray-with-given-xor/)

**Level**: `Medium`.

**Topic**: `Array`, `Hashing`.

Given an array of integers `A` and an integer `B`.

Find _the total number of subarrays having bitwise XOR of all elements equals to B._

**Problem Constraints**

```txt
1 <= length of the array <= 105

1 <= A[i], B <= 109
```

**Input Format**

```txt
The first argument given is the integer array A.

The second argument given is integer B.
```

**Output Format**

```txt
Return the total number of subarrays having bitwise XOR equals to B.
```

**Example Input**

```txt
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5
```

**Example Output**

```txt
Output 1:

 4
Output 2:

 2
```

**Example Explanation**

Explanation 1:

```txt
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:

 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
```
