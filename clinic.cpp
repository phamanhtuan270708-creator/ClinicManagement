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
    int visitId;
    int patientId;
    int changeId;
    char visitDate[15];
} Visit;

typedef struct {
    int visitId;
    char symptoms[100];
    float height;
    float weight;
    char diagnosis[100];
} MedicalRecord;

typedef struct {
    int paymentId;
    int visitId;
    float totalAmount;
    int paymentMethods;
} Payment;
#endif