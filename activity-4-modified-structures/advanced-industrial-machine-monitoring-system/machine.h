#ifndef MACHINE_H
#define MACHINE_H

// Specifications struct
typedef struct {
    float voltage;
    float current;
} Specifications;

// Sensor struct
typedef struct {
    char type[100];
    float reading;
    float min;
    float max;
} Sensor;

// Motor struct
typedef struct {
    char model[100];
    Specifications specs;
} Motor;

// Machine struct
typedef struct {
    char name[100];
    int id;
    Motor motor;
    Sensor sensor[5];
    int sensorCount;
} Machine;

/* Function Prototypes */
float computePower(Machine *m);
int classifyPowerLevel(float power);
int checkSensorStatus(Machine *m, int s_index);
void updateSensorReading(Machine *m, int s_index, float newReading);
void displayMachineInfo(Machine *m);
float computeAverageSensorReading(Machine *m);
int countOutOfRangeSensors(Machine *m);
int findMachineByID(Machine *machines, int machineCount, int machineID);
float computeTotalPowerAllMachines(Machine *machines, int machineCount);
int getHighestPowerMachine(Machine *machines, int machineCount);
void removeMachine(Machine *machines, int *machineCount, int machineID);

#endif
