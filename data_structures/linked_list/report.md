# Linked List Search Algorithms
## Linear Search
- Valid, but has the same issues as in any othr data structure

## Binary Serch
- Isn't efficiently possible in single linked lists due to lack of random access
  - This means that it is even less efficient than linear search
  - Becomes O(N^2) instead of O(N)
- Somewhat possible in double linked lists, but loses alot of efficiency
  - While it does reduce search space, the list head has to keep moving back and forth
  - This causes repeated access to the same nodes wasting time as well
  - Best case is O(N/2) to reach the center
  - Average case and worst case are both O(N)
