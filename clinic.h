#ifndef CLINIC_H
#define CLINIC_H

#define MAX 100

typedef struct {
    char patientId[20];
    char fullName[50];
    char phone[15];
    char dob[15];
} Patient;

typedef struct {
    char patientId[20];
    int status;
} Queue;

typedef struct {
    char visitId[20];
    char patientId[20];
    char changeId[20]; 
    char visitDate[15];
} Visit;

typedef struct {
    char appointmentId[20];
    char patientId[20];
    char appointmentDate[15];
    char timeSlot[20];
    int status; 
} Appointment;

typedef struct {
    char visitId[20];
    char symptoms[100]; 
    float height; 
    float weight;
    char diagnosis[100];
} MedicalRecord;

typedef struct {
    char medicineId[20];
    int quantity;
    float unitPrice;
    char usage[100];
} PrescriptionItem;

typedef struct {
    char prescriptionId[20];
    char visitId[20];
    PrescriptionItem items[MAX];
    int itemCount;
} Prescription;

typedef struct {
    char paymentId[20];
    char visitId[20];
    float totalAmount; 
    int paymentMethods;
} Payment;
#endif