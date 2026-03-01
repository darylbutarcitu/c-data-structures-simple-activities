# Advanced Industrial Machine Monitoring System (Modified Structures)

## 📌 Objective
Develop a C program that models an industrial machine monitoring system using:
- User-defined structures
- Nested structures
- Array as a structure data member
- Array of structures
- Structure pointers
- Dynamic memory allocation
- Function-based computations
- Searching and aggregation algorithms
- Menu-driven implementation

---

## 📝 Problem Description
A manufacturing company needs to digitally store and monitor information for **multiple industrial machines**.

Each machine includes:
- Motor electrical specifications
- Multiple monitoring sensors

The system must:
- Compute motor power
- Classify machine power levels
- Evaluate sensor conditions
- Perform analytics across machines
- Support updating and managing machine records

---

## 🏗️ Structural Design Requirements
The program defines the following structures:

- **Specifications**
  - `voltage` (float)
  - `current` (float)

- **Sensor**
  - `sensorType` (string)
  - `reading` (float)
  - `minRange` (float)
  - `maxRange` (float)

- **Motor**
  - `model` (string)
  - Nested `Specifications`

- **Machine**
  - `name` (string)
  - `id` (int)
  - Nested `Motor`
  - Array of `Sensor` (max 5)
  - `numSensors` (int)

---

## 💾 Memory Management Requirements
- Ask the user for the number of machines.
- Dynamically allocate an array of `Machine` structures using `malloc()`.
- Access members using pointers.
- Release all allocated memory using `free()` before termination.

---

## 🔧 Required Functions
1. **`computePower(Machine *machine)` → float**  
   Computes motor power as:
   `power = voltage × current`

2. **`classifyPowerLevel(float power)` → int**
   - `1` → LOW POWER (`power < 500`)
   - `2` → NORMAL POWER (`500 <= power <= 1500`)
   - `3` → HIGH POWER (`power > 1500`)

3. **`checkSensorStatus(Machine *machine, int sensorIndex)` → int**
   - `1` if reading is within allowable range
   - `0` if out of range

4. **`updateSensorReading(Machine *machine, int sensorIndex, float newReading)` → void**
   - Updates the sensor reading
   - Re-evaluates sensor status after update

5. **`displayMachineInfo(Machine *machine)` → void**
   Displays:
   - Machine details
   - Motor specs
   - Computed power
   - Power classification
   - All sensors and their status

6. **`computeAverageSensorReading(Machine *machine)` → float**
   Computes average reading across all sensors of one machine.

7. **`countOutOfRangeSensors(Machine *machine)` → int**
   Counts sensors outside allowable range.  
   Must internally call `checkSensorStatus()`.

8. **`findMachineByID(Machine *machines, int machineCount, int machineID)` → int**
   - Returns machine index if found
   - Returns `-1` if not found

9. **`computeTotalPowerAllMachines(Machine *machines, int machineCount)` → float**
   Computes total power of all machines.  
   Must internally call `computePower()`.

10. **`getHighestPowerMachine(Machine *machines, int machineCount)` → int**
    Returns index of the machine with highest power.

11. **`removeMachine(Machine *machines, int *machineCount, int machineID)` → void**
    Removes a machine by ID by shifting remaining elements left.

---

## 🧾 Program Flow
### Step 1 – Input Phase
The program asks for:
- Number of machines
- For each machine:
  - Machine name
  - Machine ID
  - Motor model
  - Voltage
  - Current
  - Number of sensors (max 5)
- For each sensor:
  - Sensor type
  - Sensor reading
  - Minimum range
  - Maximum range

---

## 🎮 Menu-Driven System
The program repeatedly displays this menu:

```text
===== INDUSTRIAL MACHINE MONITORING SYSTEM =====
1. Display All Machines
2. Compute and Classify Power of a Machine
3. Check Sensor Status
4. Update Sensor Reading
5. Compute Average Sensor Reading
6. Count Out-of-Range Sensors
7. Find Machine by ID
8. Compute Total Power of All Machines
9. Show Machine with Highest Power
10. Remove Machine
11. Exit
```

### Menu Requirements
- Allow machine selection using **Machine ID**.
- Allow selecting a specific sensor by **index**.
- Continue looping until user selects **Exit**.
- Validate machine and sensor indices properly.
- Display clean, formatted, structured output.

---

## ✅ Expected Outcome
A complete C program that demonstrates advanced structure usage and dynamic data handling for industrial machine monitoring, including per-machine analysis and multi-machine aggregation.