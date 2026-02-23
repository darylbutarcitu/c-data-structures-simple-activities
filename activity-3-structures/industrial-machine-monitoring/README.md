# Industrial Machine Monitoring System (CPE264H1-2ndSem2-2526)

## 📌 Objective
Develop a C program that models an industrial machine monitoring system using:
- User-defined structures
- Nested structures
- Structure pointers
- Dynamic memory allocation
- Function-based computations

---

## 📝 Problem Description
A manufacturing company wants to digitally store and monitor information about a single industrial machine.  
The system records:
- Machine details  
- Motor electrical specifications  
- Sensor monitoring data  

It also performs analytical checks on system performance.

---

## 🏗️ Structural Design
The program defines the following structures:

- **Specifications Structure**
  - Voltage (float)
  - Current (float)

- **Sensor Structure**
  - Sensor type (string)
  - Current reading (float)
  - Minimum allowable range (float)
  - Maximum allowable range (float)

- **Motor Structure**
  - Motor model (string)
  - Nested Specifications structure

- **Machine Structure**
  - Machine name (string)
  - Machine ID (int)
  - Nested Motor structure
  - Nested Sensor structure

⚠️ Only one machine record is handled.  
⚠️ Arrays of structures are **not allowed**.

---

## 💾 Memory Management
- Dynamically allocate memory for the `Machine` structure using `malloc`.
- Access members via pointers.
- Release memory using `free()` before program termination.

---

## 🔧 Functions Implemented
1. **computePower(Machine*) → float**  
   Computes motor power:  
   

\[
   \text{Power} = \text{Voltage} \times \text{Current}
   \]



2. **checkSensorStatus(Machine*) → int**  
   - Returns `1` if sensor reading is within allowable range  
   - Returns `0` otherwise  

3. **classifyPowerLevel(float power) → int**  
   - Returns `1` → LOW POWER (< 500 W)  
   - Returns `2` → NORMAL POWER (500–1500 W)  
   - Returns `3` → HIGH POWER (> 1500 W)  

4. **updateSensorReading(Machine*, float newReading) → void**  
   - Updates sensor reading  
   - Re-evaluates sensor status  

---

## 🎮 Program Behavior
- Accepts user input for machine/motor/sensor details.
- Computes motor power and classifies power level.
- Evaluates sensor status.
- Provides option to update sensor reading.
- Displays updated results.
- Outputs all information in a structured format.
- Implements a **menu-driven program**.
