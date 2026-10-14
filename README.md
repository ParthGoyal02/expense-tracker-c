# Expense Tracker in C

A simple, menu-driven command-line Expense Tracker built using the C programming language. It allows users to record expenses, view their spending, calculate totals, and save expense records for future sessions.

## Features

- **Add Expense:** Record an expense with its category and amount.
- **View All Expenses:** Display all recorded expenses.
- **Total Spending:** Calculate the total amount spent.
- **Category-wise Spending:** Group expenses by category and calculate spending for each category.
- **Persistent Storage:** Save expenses in a text file and load them when the program starts.
- **Input Validation:** Handle invalid menu choices and non-positive expense amounts.

## Technologies Used

- C Programming Language
- Structures (`struct`)
- Arrays
- Switch Statements
- Loops and Conditional Statements
- File Handling (`fopen`, `fprintf`, `fscanf`, `fclose`)
- String Handling (`strcmp`)

## Project Structure

```text
expense-tracker-c/
├── main.c
├── README.md
├── .gitignore
└── expenses.txt
```

`expenses.txt` is created when the program saves its first expense. It stores the recorded expenses between sessions.

## Requirements

- A C compiler, such as GCC
- A terminal or command prompt

## How to Compile and Run

### Windows

Compile the program:

```bash
gcc main.c -o expense_tracker.exe
```

Run it:

```bash
.\expense_tracker.exe
```

### Linux / macOS

Compile the program:

```bash
gcc main.c -o expense_tracker
```

Run it:

```bash
./expense_tracker
```

## How to Use

When you run the program, a menu appears:

```text
===== EXPENSE TRACKER =====
1. Add expense
2. View all expenses
3. Show total spending
4. Show category-wise spending
5. Exit
```

Enter the number corresponding to the operation you want to perform.

### Example

Suppose you record the following expenses:

| Category  | Amount |
| --------- | -----: |
| Food      |   ₹100 |
| Transport |    ₹50 |
| Food      |    ₹80 |

The total spending will be:

```text
Total spending: Rs. 230.00
```

Category-wise spending will be:

```text
--- Category-wise Spending ---
Food: Rs. 180.00
Transport: Rs. 50.00
```

## Limitations

- The program supports a maximum of 100 expenses.
- Category names are case-sensitive.
- Expense records are stored in a local text file.
- The program does not currently support editing or deleting expenses.

## Learning Objectives

This project was developed to practise fundamental C programming concepts, including:

- Structures and arrays
- Menu-driven programming using `switch`
- Loops and conditional logic
- Functions from the standard input/output library
- File handling and persistent storage
- Basic input validation

## Future Improvements

- Add functions to organize the code into smaller modules.
- Allow users to edit and delete expenses.
- Add dates to expense records.
- Improve input validation and error handling.
- Generate monthly spending summaries.

## Author

Parth Goyal

---

_This project is part of my engineering learning journey and my exploration of C programming, Git, and GitHub._
