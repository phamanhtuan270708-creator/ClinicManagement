#ifndef CLINIC_H
#define CLINIC_H

#define MAX 100

typedef struct {
    int patientId;
    char fullName[50];
    char phone[15];
    char dob[15];
} Patient;

typedef struct {
    int patientId;
    int status;
} Queue;

typedef struct {
    int visitId;
    int patientId;
    int changeId;
    char visitDate[15];
} Visit;

typedef struct {
    int appointmentId;
    int patientId;
    char appointmentDate[15];
    char timeSlot[20];
    int status;
} Appointment;

typedef struct {
    int visitId;
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
    int prescriptionId;
    int visitId;
    PrescriptionItem items[MAX];
    int itemCount;
} Prescription;

typedef struct {
    int paymentId;
    int visitId;
    float totalAmount;
    int paymentMethods;
} Payment;
#endif