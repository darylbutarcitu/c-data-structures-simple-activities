# Smart Student Enrollment System – Singly Linked List

## 📌 Project Description
This activity implements a **menu-driven Smart Student Enrollment System in C** using a **singly linked list**.
Each student record is stored dynamically in a node with:
- Student ID (unique)
- Full Name
- Program
- Year Level (1–5)
- GPA (0.0–4.0)

⚠️ Student records are managed through linked-list nodes (no array-based student storage).

---

## 📝 Functional Requirements Implemented
The system supports the following operations:

1. **Regular Enrollment** – insert at end, reject duplicate ID
2. **Priority Enrollment** – insert at front if GPA ≥ 3.0
3. **Manual Insert** – insert at valid 1-based position
4. **Late Enrollment** – GPA-ranked insert (descending), no post-sort
5. **Display All Students** – formatted table, handles empty list
6. **Search Student by ID** – shows full record if found
7. **Delete Student by ID** – handles head/middle/last/not found
8. **Count Students** – displays total enrolled students
9. **Promote Year Level** – +1 year for all, removes graduates (>5)
10. **Compute Average GPA** – handles empty list
11. **Display Top N Students** – displays first N or all if N is larger
12. **Reverse List** – uses three-pointer technique
13. **Exit**

---

## 🔧 Menu Structure
```text
===== SMART ENROLLMENT SYSTEM =====
1. Regular Enrollment
2. Priority Enrollment
3. Manual Insert
4. Late Enrollment
5. Display All Students
6. Search Student
7. Delete Student
8. Count Students
9. Promote Year Level
10. Compute Average GPA
11. Display Top N Students
12. Reverse List
13. Exit
```

---

## 🧩 Core Functions
- `createStudent(...)`
- `regEnrol(...)`
- `priorityEnrol(...)`
- `manualEnrol(...)`
- `lateEnrol(...)`
- `displayAll(...)`
- `searchById(...)`
- `deleteById(...)`
- `getCount(...)`
- `promoteAll(...)`
- `getAverageGPA(...)`
- `displayTopN(...)`
- `reverse(...)`
- `freeList(...)`

---

## 💾 Memory Management
- Student nodes are allocated dynamically using `malloc`.
- Deleted or temporary rejected nodes are properly `free`d.
- Remaining list memory is released before program exit.


