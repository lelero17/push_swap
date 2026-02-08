_This project has been created as part of the 42 curriculum by lemmerli._

# push_swap

## Description

push_swap is a sorting algorithm project that challenges you to sort a stack of integers using the smallest possible number of operations. The program uses two stacks (A and B) and a limited set of operations to sort numbers in ascending order efficiently.

The main learning objectives are understanding algorithm complexity, implementing multiple sorting strategies for different input sizes, and optimizing for performance within strict constraints.

## Instructions

### Compilation
```bash
make
```

### Usage
```bash
./push_swap [numbers]
```

Example:
```bash
./push_swap 3 2 1 5 4
```

The program outputs the list of operations needed to sort the stack.

### Testing
```bash
# Test with random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

# Check correctness (if checker available)
./push_swap $ARG | ./checker_linux $ARG
```

### Input Requirements

- Arguments must be integers within `int` range
- No duplicates allowed
- At least one number required
- Program outputs "Error\n" to stderr for invalid input

## Allowed Operations

- `sa/sb/ss` : swap first 2 elements
- `pa/pb` : push top element between stacks
- `ra/rb/rr` : rotate (shift all elements up)
- `rra/rrb/rrr` : reverse rotate (shift all elements down)

## Project Description

### Algorithm Strategy

The program selects different algorithms based on input size:

**Small inputs (2-5 elements):**
- Hardcoded optimized solutions
- Uses "shortest path" rotation (choosing between ra/rra based on position)

**Medium inputs (6-100 elements):**
- Chunk sort algorithm
- Divides numbers into groups and processes efficiently

**Large inputs (500+ elements):**
- Radix sort using binary representation
- O(n log n) complexity with predictable performance

### Design Choices

**Chunk Sort (6-100 elements):**

Strategy:
1. Replace values with sorted indices (0 to n-1)
2. Divide into chunks of optimal size
3. For each chunk, find closest element (shortest path calculation)
4. Push to stack B
5. Push back to A in descending order (largest first)

**Why this approach?**
- Minimizes rotations by choosing most efficient element each time
- Chunk size varies with input (5 for small, 18 for 100 elements)
- Balances simplicity with performance

**Radix Sort (500+ elements):**

Strategy:
1. Convert numbers to indices
2. Sort bit by bit (LSB to MSB)
3. For each bit: separate 0s and 1s, then recombine
4. Requires log₂(n) passes

**Why this approach?**
- Consistent performance regardless of input order
- No comparisons needed, just bit checks
- Works well for large datasets

**Shortest Path Optimization:**

For all rotations:
- Calculate cost of `ra` (forward): position
- Calculate cost of `rra` (backward): size - position
- Choose minimum
- Reduces operations by ~50% for small sorts

### Code Structure

**File organization:**
```
Input handling:
├── input_val.c       # Validation (duplicates, format, range)
├── input_parsing.c   # Convert args to stack
└── utils.c           # ft_atoi with long long

Stack operations:
├── stack_utils.c     # Creation and memory management
├── stack_helpers.c   # Utilities (size, min, max, sorted check)
├── operation_*.c     # All 11 operations (swap, push, rotate)

Sorting algorithms:
├── sort_small.c      # 2-5 elements (hardcoded solutions)
├── sort_chunk.c      # Chunk sort main logic
├── chunk_utils.c     # Chunk helpers (size calculation, max finding)
├── chunk_search.c    # Optimized element selection
└── sort_large.c      # Radix sort implementation
```

**Norm compliance challenges:**
- Max 5 functions per file → split chunk sort across 3 files
- Max 25 lines per function → extracted helpers aggressively
- Max 5 variables per function → inline calculations, reuse variables

## Resources

### Documentation

- [Sorting Algorithms Visualization](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)
- [Radix Sort Explained](https://www.geeksforgeeks.org/radix-sort/)
- [Big O Cheat Sheet](https://www.bigocheatsheet.com/)
- [42 Norm v4](https://cdn.intra.42.fr/pdf/pdf/960/the_norm.en.pdf)

### AI Usage

AI (Claude by Anthropic) was used as a learning assistant throughout this project:

**How AI was used:**
- Student explained problem → AI provided conceptual guidance
- Student wrote all code independently
- Student debugged and tested all implementations

**What AI did NOT do:**
- Write function implementations
- Make algorithm choices
- Perform testing or benchmarking

---

**Author:** lemmerli  
**School:** 42 Heilbronn  
**Project:** push_swap