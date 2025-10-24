# Problem: Dice Combinations (CSES)
Problem link: https://cses.fi/problemset/task/1633

This problem asks for the number of ways to get a sum `n` by rolling a standard 1-6 die. The order of the rolls matters.

## Approach

This is a classic **Dynamic Programming** problem. The number of ways to get to a sum `n` is dependent on the number of ways we could have gotten to the sums *before* it.

I defined a DP state `dp[i]` as:
**`dp[i]` = "The total number of ways to get a sum of `i`."**

## Implementation

The solution uses a bottom-up DP approach.

1.  **Base Case:** I initialize `dp[0] = 1`. There is exactly one way to get a sum of 0 (by rolling no dice).
2.  **Recurrence Relation:** To find `dp[i]`, I look back at the 6 possible states I could have come from. If I am at sum `i`, I could have gotten here from `i-1` (by rolling a 1), `i-2` (by rolling a 2), ..., or `i-6` (by rolling a 6).
3.  **Final Formula:** Therefore, the total number of ways to get `i` is the sum of the ways to get those previous states:
    **`dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]`**
4.  **Modulus:** I apply the modulus `% 1000000007` at each addition step to prevent integer overflow.

The final answer is simply the value stored in `dp[n]`.

## Complexity

* **Time Complexity:** $O(n)$. We have a single loop from 1 to `n`, and the inner loop is a constant size of 6.
* **Space Complexity:** $O(n)$ to store the `dp` array.
