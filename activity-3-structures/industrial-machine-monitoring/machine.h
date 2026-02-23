#ifndef MACHINE_H
#define MACHINE_H
#define STR_SIZE 50

// Specifications struct
typedef struct {
    float voltage;
    float current;
} Specifications;

// Sensor struct
typedef struct {
    char type[STR_SIZE];
    float reading;
    float min;
    float max;
} Sensor;

// Motor struct
typedef struct {
    char model[STR_SIZE];
    Specifications specs;
} Motor;

// Machine struct
typedef struct {
    char name[STR_SIZE];
    int id;
    Motor motor;
    Sensor sensor;
} Machine;

/* Function Prototypes */
float computePower(Machine *m);
int checkSensorStatus(Machine *m);
int classifyPowerLevel(float power);
void updateSensorReading(Machine *m, float newReading);

#endif
