//Header file
#ifndef PATIENT_H
#define PATIENT_H

#define MAX_ID 20
#define MAX_PHONE 15
#define MAX_NAME 100
#define MAX_DATE 13
#define MAX_PATIENTS 100 // kich thuoc co dinh cua mang tinh
// Define cấu trúc for 1 patient
typedef struct {
    char patient_id [MAX_ID];
    char phone_number [MAX_PHONE];
    char full_name [MAX_NAME];
    char date_of_birth [MAX_DATE];
}Patient;

//Function Prototypes
void inputPatient (patient * p);
void printPatient (const patient * p);
void inputPatientList (patient list[], int * n);
void printPatientList (const patient list [], int n);

#endif;
