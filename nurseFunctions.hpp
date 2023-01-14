#include<iostream>
#include<string.h>
#include<cstring>
#include<ctime>
#include <cstdlib>


using namespace std;

struct Account
{
	string account, password, type;
	Account *next;
};
extern Account *accountHead;
extern Account *accountTemp;

struct patient
{
	int PID,Age;
	string FirstName, LastName, Gender, Phone, Address, SicknessDescription, VisitDate, VisitTime, DoctorName, MedicineInformation;
	string DisabilityOption; 
	patient *next;
};
extern patient *waitingHead;
extern patient *waitingTemp;
extern patient *lastWaitingNode;

struct history
{
	int PID,Age;
	string FirstName, LastName, Gender, Phone, Address, SicknessDescription, VisitDate, VisitTime, DoctorName, MedicineInformation;
	string DisabilityOption; 
	history *next;
};
extern history *historyHead;
extern history *historyTemp;
extern history *lastHistoryNode;

/*****************************************************************************/
/* Developer Name: Loke Weng Khay                                            */
/* Nurse automatic functions: To display menu and add data into waiting list */
/*****************************************************************************/
void nurseMenu();
void autoAddData();

/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Nurse Function 1.1: add new patient                                  */
/************************************************************************/
void addPatient();
string convertToString(char*,int);
void insertPatientIntoList(string,string,int,string,string,string,string,string,string,string);

/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Nurse Function 1.2: Modify patient priority status    		        */
/************************************************************************/
void changePatientStatus();
void priorityPatient(string,string,int,string,string,string,string,string,string,string);
void searchPatient();
void searchById(int);
patient* copyList(struct patient* head);
struct patient* swap(struct patient* ptr1, struct patient* ptr2);
int bubbleSort(struct patient** head, int count);
struct patient* mid_node(patient* start, patient* last);
struct patient* binarySearch(patient *head, int value);
void searchByName(string,string);
void checkChangesPriority();

/***********************************************************/
/* Developer Name: Loke Weng Khay              	           */
/* Nurse Function 1.3: Display all patient 	     	       */
/***********************************************************/
void displayAll(patient *current);

/******************************************************************/
/* Developer Name: Loke Weng Khay              	                  */
/* Nurse Function 1.4: Call the patient in the queue              */
/******************************************************************/
void callPatient();
void storeToHistory();
history* copyHeadList(patient* head);

/******************************************************************/
/* Developer Name: Lee Han Sen              	                  */
/* Nurse Function 1.5: Search patient from the waiting list       */
/******************************************************************/
void searchAllByName(string apName);
void searchAllByID(int apID);

/******************************************************************/
/* Developer Name: Lee Han Sen              	                  */
/* Nurse Function 1.6: Sort waiting list by patient'svisit time   */
/******************************************************************/
void displayAsc();
int bubbleSort2(patient** head, int count);

/******************************************************************/
/* Developer Name: He XiaoFeng            	                      */
/* Nurse Function 1.7: Login authentication                       */
/******************************************************************/
bool searchAccount(string account2,string password2,string type2);
void insertAccount(string account2,string password2, string type2);




