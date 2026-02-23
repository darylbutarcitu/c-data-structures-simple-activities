# Advanced Statistical Analysis Using Arrays in C

## 📌 Project Description
This project implements a **menu-driven statistical analysis system in C** using a one-dimensional integer array.  
The program allows users to compute various statistical measures and distributions without relying on built-in sorting or statistical libraries (except `math.h` where needed).

---

## 📝 Activity Instructions
The program must implement the following tasks:

### 1️⃣ Median of Array Elements
- Sort the array in ascending order.  
- If odd number of elements → median is the middle element.  
- If even number of elements → median is the average of the two middle elements.  
- Display the sorted array and the computed median.

### 2️⃣ Mode (Most Frequent Element)
- Count frequency of each element.  
- Display element(s) with the highest frequency.  
- If all elements appear only once → display "No mode".

### 3️⃣ Standard Deviation
- Compute mean (average).  
- Subtract mean from each element and square the result.  
- Compute variance (average of squared differences).  
- Standard deviation = square root of variance.  
- Display mean, variance, and standard deviation.

### 4️⃣ Range and Interquartile Range (IQR)
- Sort the array in ascending order.  
- Range = largest − smallest value.  
- Compute Q1 (first quartile) and Q3 (third quartile).  
- IQR = Q3 − Q1.  
- Display range, Q1, Q3, and IQR.

### 5️⃣ Frequency Distribution Table
- Identify all unique elements.  
- Count occurrences of each unique element.  
- Display results in tabular format:  

### 6️⃣ Cumulative Sum (Prefix Sum)
- Create a second array of same size.  
- Each element = sum of all elements up to that index.  
- Display original array and cumulative sum array.  
- Explain how cumulative sums can be used in data analysis.

### 7️⃣ Percentage Distribution
- Compute total sum of array elements.  
- For each element, compute percentage contribution to total.  
- Store percentages in a floating-point array.  
- Display results in tabular format:  

- Ensure total percentage ≈ 100% (allow rounding differences).

---

## 🔧 Technical Requirements
- Use **functions** for each statistical operation.  
- Accept array size from user input.  
- Proper comments and indentation required.  
- Programs must compile and run without errors.  
- No built-in sorting/statistical libraries (except `math.h`).  

