#include <stdio.h>
#include "clinic.h"
#include <string.h>
#include <stdlib.h>

// Tim luot kham gan nhat cua benh nhan (duyet tu cuoi mang ve dau)
static int findLatestVisit (const Visit visits [], int visitCount, const char * patientId) {
    for (int index = visitCount - 1; index >= 0; index--) {
        if (strcmp(visits [index].patientId, patientId) == 0) {
            return index;
        }
    }
    return -1;
}

int clinicFull (int visitCount, int maxVisits) {
    return visitCount >= maxVisits;
}

static void createNewCaseId (Visit * visit, int * nextCaseNumber) {
    snprintf(visit -> caseId, MAX_ID, "CASE%03d", *nextCaseNumber);
    (*nextCaseNumber)++;    
}

int inputSingleVisit (Visit * visit, const Visit visits [], int visitCount, int * nextCaseNumber) {
    if (visit == NULL || nextCaseNumber == NULL) {
        return 0;
    }

    char input [INPUT_BUFFER_SIZE];
    snprintf(visit -> visitId, MAX_ID, "V%03d", visitCount + 1);
    printf("Ma Luot Kham: %s\n", visit -> visitId);

    printf("Nhap Ma Benh Nhan: ");
    deleteFgets(visit -> patientId, MAX_ID);
    if (visit -> patientId[0] == '\0') {
        printf("Ma benh nhan khong duoc de trong.\n");
        return 0;
    }

    printf("Nhap Ngay Kham (DD/MM/YYYY): ");
    deleteFgets(visit -> visitDate, MAX_DATE);

  int latestIndex = findLatestVisit(visits, visitCount, visit -> patientId);

    if (latestIndex < 0) {
        printf("Day la lan kham dau tien cua benh nhan -> tu dong tao ho so moi.\n");
        visit -> visitType = BENH_LY_MOI;
        createNewCaseId(visit, nextCaseNumber);
    } else {
        printf("Lan kham gan nhat: %s, ngay %s.\n",
               visits[latestIndex].caseId, visits[latestIndex].visitDate);
        printf("1: Tai Kham %s, 2: Benh Ly Moi: ", visits[latestIndex].caseId);
        deleteFgets(input, INPUT_BUFFER_SIZE);
        visit -> visitType = atoi(input);
        }
        if (visit -> visitType == TAI_KHAM) {
            strcpy(visit -> caseId, visits[latestIndex].caseId);
    } else if (visit -> visitType == BENH_LY_MOI) {
        createNewCaseId(visit, nextCaseNumber);
    } else {
        printf("Hinh thuc kham khong hop le. Luot kham chua duoc luu.\n");
        return 0;
    }

    printf("CASE ID: %s\n", visit -> caseId);
    return 1;
}

void inputVisitList (Visit visits [], int * visitCount, int * nextCaseNumber) {
    char input [INPUT_BUFFER_SIZE];
    printf("\nNhap so luot kham can ghi nhan (con trong %d cho): ", MAX_VISITS - *visitCount);
    deleteFgets(input, INPUT_BUFFER_SIZE);
    int requestedCount = atoi(input);

    for (int index = 0; index < requestedCount; index++) {
        if (clinicFull(*visitCount, MAX_VISITS)) {
            printf("So luot kham da dat toi da (%d).\n", MAX_VISITS);
            break;
        }
        printf("\n=== Nhap Luot Kham Thu %d ===\n", index + 1);
        if (inputSingleVisit(&visits[*visitCount], visits, *visitCount, nextCaseNumber)) {
            (*visitCount)++;
        }
    }
}

void printVisitList (const Visit visits [], int visitCount) {
    printf("\n==== Danh Sach Luot Kham ====\n");
    printf("| %-8s | %-20s | %-10s | %-12s | %-10s |\n","Ma Luot", "Ma Id Benh Nhan", "Ma Case", "Ngay kham", "Loai");
    for (int index = 0; index < visitCount; index++) {
        printf("| %-8s | %-20s | %-10s | %-12s | %-10s |\n",visits[index].visitId, visits[index].patientId, visits[index].caseId,visits[index].visitDate,visits[index].visitType == TAI_KHAM ? "Tai kham" : "Benh moi");
    }
}





