#include<stdio.h>
#include"clinic.h"

int main () 
{
//danh sach benh nhan
    Patient data_list[MAX_DAILY_PATIENTS];
    int patient_list_current_quantity = 0;

    inputPatientList(data_list, &patient_list_current_quantity);
    printPatientList(data_list, patient_list_current_quantity);
//thu tu kham 
     for (int index = 0; index < patient_list_current_quantity; index++) {
        inputQueueList(&patientList[index]);
    }
    sortQueue(patientList, patient_list_current_quantity);
    printSortQueue(patientList, patient_list_current_quantity);

    //luot kham
  Visit visitList [MAX_VISITS];
    int visitCount = 0;
    int nextCaseNumber = 1;
    inputVisitList(visitList, &visitCount, &nextCaseNumber);
    printVisitList(visitList, visitCount);
    return 0;
}
