# Mastering Algorithms — ACA'25 | Stamatics, IIT Kanpur

A structured summer project under **Stamatics (ACA), IIT Kanpur** focused on building strong algorithmic foundations through curated problem-solving, competitive programming contests, and weekly deep-dives into core algorithmic paradigms.

## Project Overview

| Duration | May 2025 – July 2025 |
|---|---|
| **Organization** | Stamatics, ACA — IIT Kanpur |
| **Focus** | Data Structures, Algorithms, Competitive Programming |
| **Language** | C++ |

## Topics Covered

### Week 1 — Arrays & Sorting
- Boyer-Moore Voting Algorithm (Majority Element)
- Kadane's Algorithm (Maximum Subarray & Product variant)
- Binary Search on Answer (Nth Root)
- Matrix Rotation (Transpose + Reverse)
- Spiral Matrix Traversal
- Two-Pointer Technique (Remove Duplicates, 3Sum/4Sum)
- Dutch National Flag Algorithm (Sort Colors)
- Next Permutation (Lexicographic ordering)
- Bit Manipulation & DP (Codeforces 2053C)

### Week 2 — Prefix Sums, Binary Search & Divide and Conquer
- 1D/2D Prefix Sum arrays
- Longest Increasing Subsequence — O(n log n) via Patience Sorting
- Floating Point Precision pitfalls (Codeforces 1809B)

### Week 3 — Recursion
- Josephus Problem (recursive & iterative)
- Decode String (recursive parsing & stack-based)
- K-th Symbol in Grammar (popcount parity insight)

### Week 4 — Backtracking
- N-Queens Problem
- Sudoku Solver
- Subset Generation (Power Set)

### Week 5 — Dynamic Programming
- 0/1 Knapsack (space-optimized)
- Subset Sum
- Coin Change
- Longest Common Subsequence
- Edit Distance (Levenshtein)

## Repository Structure

```
.
├── Week1_Arrays_Sorting/
│   ├── 01_majority_element.cpp
│   ├── 02_maximum_subarray.cpp
│   ├── 03_nth_root.cpp
│   ├── 04_bewitching_stargazer.cpp
│   ├── 05_rotate_image.cpp
│   ├── 06_spiral_matrix.cpp
│   ├── 07_remove_duplicates.cpp
│   ├── 08_sort_colors.cpp
│   ├── 09_next_permutation.cpp
│   └── 10_three_sum.cpp
├── Week2_Prefix_Sums_Binary_Search/
│   ├── 01_prefix_sum.cpp
│   ├── 02_lis_binary_search.cpp
│   └── 03_floating_point_precision.cpp
├── Week3_Recursion/
│   ├── 01_josephus_problem.cpp
│   ├── 02_decode_string.cpp
│   └── 03_kth_symbol_grammar.cpp
├── Week4_Backtracking/
│   └── 01_backtracking_problems.cpp
├── Week5_Dynamic_Programming/
│   └── 01_dp_fundamentals.cpp
└── README.md
```

## Key Takeaways

- **Brute-force → Optimization**: Every problem was first approached naively, then iteratively optimized for time and space
- **Pattern Recognition**: Identifying recurring paradigms — two pointers, sliding window, binary search on answer, memoization
- **Competitive Programming**: Participated in private Codeforces contests, practiced with CP-31 sheet and Codeforces Ladders
- **Precision Awareness**: Learned to avoid floating-point arithmetic where integer solutions exist

## How to Run

```bash
# Compile any solution
g++ -std=c++17 -O2 -o solution Week1_Arrays_Sorting/01_majority_element.cpp

# Run
./solution
```

## Resources Used

- [Striver's A2Z DSA Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/)
- [USACO Guide — Prefix Sums](https://usaco.guide/silver/prefix-sums?lang=cpp)
- [Aditya Verma — DP Playlist](https://youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go)
- [CP-31 Sheet](https://www.tle-eliminators.com/cp-sheet)
- [GeeksforGeeks — C++ STL](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)

