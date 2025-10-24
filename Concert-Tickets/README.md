# Problem: Concert Tickets (CSES)
Problem link: https://cses.fi/problemset/task/1091
Given `n` ticket prices and `m` customers, each with a maximum price they are willing to pay, what price does each customer pay? They should be assigned the *highest* possible ticket price that is *still less than or equal to* their maximum price. Once a ticket is sold, it cannot be sold again.

## Approach

This problem requires a data structure that can efficiently:
1.  Store multiple tickets of the same price.
2.  Keep the ticket prices sorted.
3.  Find the "best-fit" ticket for a customer.
4.  Remove a ticket after it's sold.

The perfect data structure for this is the C++ **`std::multiset`**.

## Implementation

1.  **Data Structure:** I insert all `n` ticket prices into a `std::multiset<long> ms`. A multiset automatically keeps all elements sorted and allows duplicates, which is perfect for this problem.
2.  **Querying:** For each of the `m` customers with max price `a`:
    * I use `ms.upper_bound(a)`. This function finds the iterator to the *first* element *strictly greater* than `a`.
    * **Key Insight:** The ticket we want is the one *just before* this iterator.
    * I check if `it` is not `ms.begin()`. If it is, no ticket is $\le a$.
    * If it's not, I decrement the iterator (`it--`) to point to the largest ticket $\le a$.
3.  **Validation & Output:**
    * I do a final check (`*it <= a`) to ensure the ticket found is valid.
    * If a valid ticket is found, I print its price (`*it`) and—most importantly—**erase it from the multiset** (`ms.erase(it)`) so it cannot be used again.
    * If no ticket is found (either the set is empty or all tickets are too expensive), I print -1.

## Complexity

* **Time Complexity:** $O((n+m) \log n)$.
    * $O(n \log n)$ to insert the `n` tickets into the multiset.
    * For each of the `m` customers, we perform an `upper_bound` ($O(\log n)$) and an `erase` ($O(\log n)$). This results in $O(m \log n)$.
* **Space Complexity:** $O(n)$ to store the `n` tickets in the multiset.
