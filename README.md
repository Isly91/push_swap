# 🧩 push_swap

**push_swap** is an algorithmic project from the 42/Codam curriculum focused on sorting data using only a restricted set of stack operations. It challenges you to find the most efficient way to sort numbers using two stacks (`a` and `b`) and a limited instruction set.

The project emphasizes algorithm design, optimization, and understanding how low-level memory and data structures work in C.

---

## 📦 Project Description

Given a stack of integers, your goal is to output a sequence of operations that sorts the stack using:

- Only allowed operations (push, swap, rotate, reverse rotate)
- The fewest possible moves

- `push_swap`: Takes unsorted numbers and prints the operations to sort them

---

## ⚙️ Allowed Instructions

| Operation | Description                              |
|----------:|------------------------------------------|
| `sa`      | Swap the first 2 elements of stack a     |
| `sb`      | Swap the first 2 elements of stack b     |
| `ss`      | `sa` and `sb` at the same time           |
| `pa`      | Push the first element from b to a       |
| `pb`      | Push the first element from a to b       |
| `ra`      | Rotate stack a up (first becomes last)   |
| `rb`      | Rotate stack b up                        |
| `rr`      | `ra` and `rb` at the same time           |
| `rra`     | Reverse rotate stack a (last becomes first) |
| `rrb`     | Reverse rotate stack b                   |
| `rrr`     | `rra` and `rrb` at the same time         |

---

## 🧠 What I Learned

- Implementing and managing **linked lists** for stack representation
- Designing **sorting algorithms** optimized for constrained environments
- Thinking in terms of **operations instead of values**
- Minimizing operations while maintaining correctness and efficiency
- Handling **edge cases**, input validation, and memory management in C

---

### Run the program

- Type ./push_swap followed by a list of integers to sort them.
- The program will output the sequence of operations needed to sort the numbers.
- The program will also check for errors in the input (e.g., duplicates, non-integer values).
- The program will exit with an error message if the input is invalid.
- To run the program, you can use the following command:

```bash
./push_swap 4 67 3 87 23
```

- ./push_swap [list of integers]

### Compile

```bash
make
