# 🧩 push_swap

**push_swap** is an algorithmic project from the 42/Codam curriculum focused on sorting data using only a restricted set of stack operations. It challenges you to find the most efficient way to sort numbers using two stacks (`a` and `b`) and a limited instruction set.

The project emphasizes algorithm design, optimization, and understanding how low-level memory and data structures work in C.

---

## 📦 Project Description

Given a stack of integers, your goal is to output a sequence of operations that sorts the stack using:

- Only allowed operations (push, swap, rotate, reverse rotate)
- The fewest possible moves

You write two programs:
1. `push_swap`: Takes unsorted numbers and prints the operations to sort them
2. `checker`: Takes the operations and checks if they indeed sort the stack correctly (bonus)

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

## 🛠️ Usage

- ./push_swap 4 67 3 87 23

- ./push_swap [list of integers]

### Compile

```bash
make
