#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include"nurseFunctions.hpp"

using namespace std;

/******************************************************************************/
/* Developer Name: Loke Weng Khay                                             */
/* Doctor automatic functions: To display menu and add data into waiting list */
/******************************************************************************/
void doctorMenu();

/******************************************************************************************/
/* Developer Name: Lee Han Sen                                                            */
/* Nurse Function 2.3: sort and display all records from the patient's visit history list */
/******************************************************************************************/
void displayHL(history *historyHead);

/******************************************************************************/
/* Developer Name: He Xiao Feng                                               */
/* Doctor function 2.2 and Doctor function 2.4: Search and modify             */
/******************************************************************************/
void searchPatientHistoryLog(bool modifyFlag);
history* searchPatientHistory(int num2);
void printPatientInfo(history* patientInfo);
void modifyHistoryLog(history* patientHistory);
