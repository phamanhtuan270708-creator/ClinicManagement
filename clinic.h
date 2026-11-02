//Header file

#ifndef CLINIC_H
#define CLINIC_H

#define MAX_DAILY_PATIENTS 500 
#define MAX_DAILY_APPOINTMENT 500

#define MAX_ID 30
#define MAX_PHONE 12
#define MAX_NAME 100
#define MAX_DATE 13

#define MAX_TIME 10
#define MAX_TEXT 100
#define MAX_METHOD_NAME 20
#define MAX_ITEM 50
#define MAX_STATUS 30

#define TYPE_ONLINE 1
#define TYPE_OFFLINE 2

#define INPUT_BUFFER_SIZE 32
#define STT_DANG_KHAM 1
#define STT_CHUAN_BI_KHAM 2
#define STT_CHO_KHAM 3
#define STT_TRE_HEN 4

#define TAI_KHAM 1
#define BENH_LY_MOI 2

#define MAX_VISITS 500
#define MAX_DAILY_APPOINTMENT 500
#define CLINIC_OPEN_TIME "7:00"
#define CLINIC_CLOSE_TIME "23:00"

#define APP_DANG_CHO 1
#define APP_THANH_CONG 2

typedef struct {
    char patientId [MAX_ID];
    char fullName [MAX_NAME];
    char phone [MAX_PHONE];
    char dateOfBirth [MAX_DATE];

    int type;
    int appointmentTime;
    int arrivalTime;
    int currentStatus;
    char displayTime [MAX_TIME];
} Patient;

typedef struct {
    char visitId [MAX_ID];
    char patientId [MAX_ID];
    char caseId [MAX_ID];
    char visitDate [MAX_DATE];
    int visitType;
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
    int quantity;
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

void inputQueueList (Patient * patient);
void sortQueue (Patient list [], int patientCount);
void printSortQueue(Patient list [], int patientCount);

int clinicFull (int visitCount, int maxVisits);
int inputSingleVisit (Visit *visit, const Visit visits [], int visitCount, int *nextCaseNumber);
void inputVisitList (Visit visits [], int * visitCount, int * nextCaseNumber);
void printVisitList (const Visit visits [], int visitCount);

void deleteFgets (char * buffer, int max_len);
int readInteger (int * value);

int inputAppointment (const Patient patients [],const Appointment list[], Appointment *appointment, int patientCount, int appointmentCount);
void printAppointmentList (const Appointment list [], int appointmentCount);

void themMedicalRecord();
void hienThiMedicalRecords();
void timKiemMedicalRecord();

#endif
