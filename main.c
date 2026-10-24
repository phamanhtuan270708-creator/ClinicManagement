#include<stdio.h>
#include"patient.h"

int main () 
{
    Patient patientList[MAX_PATIENTS];
    int patient_list_current_quantity = 0;

    inputPatientList(patientList, &patient_list_current_quantity);
    printPatientList(patientList, patient_list_current_quantity);

}
