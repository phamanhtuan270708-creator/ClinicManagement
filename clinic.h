//Header file

#ifndef CLINIC_H
#define CLINIC_H

#define MAX_PATIENTS 100 // kich thuoc co dinh cua mang tinh

#define MAX_ID 20
#define MAX_PHONE 15
#define MAX_NAME 100
#define MAX_DATE 13

#define MAX_TIME 20
#define MAX_TEXT 100
#define MAX_METHOD_NAME 20
#define MAX_ITEM 50

// Define cấu trúc for 1 patient
typedef struct {
    char patientId [MAX_ID];
    char fullName [MAX_NAME];
    char phone [MAX_PHONE];
    char dateOfBirth [MAX_DATE];
} Patient;

typedef struct {
    char patientId [MAX_ID];
    int status;
} Queue;

typedef struct {
    char visitId [MAX_ID];
    char patientId [MAX_ID];
    char changeId [MAX_ID];
    char visitDate [MAX_DATE];
} Visit;

typedef struct {
    char appointmentId [MAX_ID];
    char patientId [MAX_ID];
    char appointmentDate [MAX_DATE];
    char timeSlot [MAX_TIME];
    int status;
} Appointment;

typedef struct {
    char visitId [MAX_ID];
    char symptoms [MAX_TEXT];
    float height;
    float weight;
    char diagnosis [MAX_TEXT];
} MedicalRecord;

typedef struct {
    char medicineId[MAX_ID];
    long long  quantity;
    double unitPrice;
    char usage[100];
} PrescriptionItem;

typedef struct {
    char prescriptionId [MAX_ID] ;
    char visitId [MAX_ID];
    PrescriptionItem items[MAX_ITEM];
    int itemCount;
} Prescription;

typedef struct {
    char paymentId [MAX_ID];
    char visitId [MAX_ID];
    double totalAmount;
    char paymentMethods [MAX_METHOD_NAME];
} Payment;

void inputPatientList (Patient list[], int * n);
void printPatientList (const Patient list [], int n);
#endif
