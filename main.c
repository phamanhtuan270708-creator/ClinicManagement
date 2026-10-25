#include<stdio.h>
#include"clinic.h"

int main () 
{
    Patient data_list[MAX_PATIENTS];
    int patient_list_current_quantity = 0;

    inputPatientList(data_list, &patient_list_current_quantity);
    printPatientList(data_list, patient_list_current_quantity);

     for (int index = 0; index < patient_list_current_quantity; index++) {
        inputQueueList(&patientList[index]);
    }
    sortQueue(patientList, patient_list_current_quantity);
    printSortQueue(patientList, patient_list_current_quantity);
    return 0;
}
