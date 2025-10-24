# Problem: Apartments (CSES)
Problem link: https://cses.fi/problemset/task/1084

Given a list of `n` applicants with their desired apartment size and `m` apartments with their actual size, find the maximum number of applicants that can be matched to an apartment. An applicant `i` accepts an apartment `j` if its size is within a range `[a[i]-k, a[i]+k]`.

## Approach

A brute-force $O(n \times m)$ check would be too slow. The most efficient way to solve this matching problem is a **Greedy Two-Pointer Algorithm**.

The main idea is to sort both the applicants and the apartments. This allows us to check for matches in a single pass ($O(n+m)$), as we never need to backtrack.

## Implementation

1.  **Sort:** I first sort both the applicant array `a` and the apartment array `b`. This is the most crucial step.
2.  **Pointers:** I initialize two pointers: `i` for the applicants (array `a`) and `j` for the apartments (array `b`).
3.  **Main Loop:** I loop `while (i < n && j < m)`:
    * **Case 1: Match:** If the current apartment `b[j]` is within the acceptable range for applicant `a[i]`, it's a match. I increment the count `say`, and advance *both* pointers (`i++` and `j++`) to find a new applicant and a new apartment.
    * **Case 2: Apartment is Too Small:** If `b[j]` is smaller than applicant `a[i]`'s minimum range, then this apartment is too small for *all* remaining applicants (since the arrays are sorted). I discard this apartment by advancing the apartment pointer `j++`.
    * **Case 3: Apartment is Too Large:** If `b[j]` is larger than applicant `a[i]`'s maximum range, this apartment is too big for the current applicant. I discard this applicant by advancing the applicant pointer `i++` to see if a *larger* applicant can fit in the *current* apartment.

The loop terminates when we run out of applicants or apartments.

## Complexity

* **Time Complexity:** $O(N \log N + M \log M)$, which is dominated by the two `sort` operations. The two-pointer `while` loop itself is only $O(N + M)$.
* **Space Complexity:** $O(N + M)$ to store the input arrays.
