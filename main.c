#include<stdio.h>
#include"patient.h"

int main () 
{
    Patient data_list[MAX_PATIENTS];
    int patient_list_current_quantity = 0;

    inputPatientList(data_list, &patient_list_current_quantity);
    printPatientList(data_list, &patient_list_current_quantity);

}