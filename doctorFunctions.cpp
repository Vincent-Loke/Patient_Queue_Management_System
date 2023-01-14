#include"doctorFunctions.hpp"

/**********************************************/
/* Developer Name: Loke Weng Khay             */
/* Function: To display Nurse menu options   */
/**********************************************/
void doctorMenu()
{
	while(true)
	{
	    int selection;
	    bool input = false;
	    cout<<"\n**********************************\n*           Doctor Menu          *\n**********************************\n";
	    cout<<"1. View all patients on the original waiting list\n";
	    cout<<"2. Search Specific Patient from the patient's visit history and modify patient records\n";
	    cout<<"3. Sort and display all records from the patient's visit history list in descending order\n";
	    cout<<"4. Search patients from the patient's visit history list based on sickness description or first name\n";
	    cout<<"5. Logout\nYour Selection: ";
	    while(input!=true)
	    {
	        cin>>selection;
	        if(cin.fail())
	        {
	            cin.clear();
	            cin.ignore(100, '\n');
	            cout<<"Invalid input entered\nEnter Again\n";
	        }
	        else if(selection<=0 || selection>5)
	        {
	            cout<<"Invalid input entered\nEnter Again\n";
	        }
	        else if(selection>0 && selection<6)
	        {
	            input=true;
	        }
	    }
	    if(selection==1)
	    {
	        waitingTemp=waitingHead;
	        cout<<"\n\n**********************************\n*   All Waiting Patient Details  *\n**********************************\n";
	        displayAll(waitingTemp);
	    } 
		else if(selection==2) 
		{
	        searchPatientHistoryLog(true);
	    }
	    else if (selection == 3)
	    {
	    	cout<<"\n\n**********************************\n*   All History Patient Details  *\n**********************************\n";
	        displayHL(historyHead);
	    }
	    else if(selection==4) 
		{
	        searchPatientHistoryLog(false);
	    }
	    else if(selection==5) 
		{
	    	cout<<"\nLogout Successfully\n\n";
	    	system("pause");
	    	system("cls");
	        return;
	    }
	    system("pause");
	    system("cls");
	}
}
/**********************************************************************************************/
/* Developer Name: Lee Han Sen            	                                                  */
/* Nurse Function 2.3: sort and display all records from the patient's visit history list     */  
/* Function: Sort and display all record from patient visit history list in descending order  */
/**********************************************************************************************/
void displayHL(history *historyHead)
{
    historyTemp = historyHead;
    while (historyTemp != NULL)
	{
		cout <<"ID: "<<historyTemp->PID<< endl;
		cout <<"Name: "<< historyTemp->FirstName<<" "<<historyTemp->LastName<<endl;
		cout <<"Age: "<<historyTemp->Age<<endl;
		cout <<"Gender: "<< historyTemp->Gender<<endl;
		cout <<"Phone Number: "<< historyTemp->Phone<<endl;
		cout <<"Address: "<< historyTemp->Address<<endl;
		cout <<"Sickness Description: "<< historyTemp->SicknessDescription<<endl;
		cout <<"Visit Date: "<< historyTemp->VisitDate<<endl;
		cout <<"Visit Time: "<< historyTemp->VisitTime<<endl;
		cout <<"Disability Option: "<< historyTemp->DisabilityOption<<endl;
		cout <<"Doctor Name: "<< historyTemp->DoctorName<<endl;
		cout <<"Medicine Information: "<<historyTemp->MedicineInformation<<endl<<endl;
		historyTemp = historyTemp->next;
	}

}
/******************************************************************/
/* Developer Name: He Xiao Feng             	                  */
/* Doctor function 2.2 and Doctor function 2.4: Search and modify */
/* Function: To search Patient History Log                        */
/******************************************************************/
void searchPatientHistoryLog(bool modifyFlag)
{
    /*cout<<"\n\n**********************************\n*     All Patient Details        *\n**********************************\n";
    historyTemp = historyHead;
    while(historyTemp != NULL)
    {
        printPatientInfo(historyTemp);
        historyTemp = historyTemp->next;
    }*/

    int num2;
    cout<<"\n\n**********************************\n*         Search Methods         *\n**********************************\n";
    cout<<"Search patient using:\n1. ID number\n2. First and Last Name\n3. Sickness Description\nYour Selection: ";

    cin.ignore();
    cin>>num2;
    history* patientHistory = searchPatientHistory(num2);
    if(modifyFlag && patientHistory!=NULL)
	{
        modifyHistoryLog(patientHistory);
    }
}

void printPatientInfo(history* patientInfo)
{
    cout <<"ID: "<<patientInfo->PID<< endl;
    cout <<"Name: "<< patientInfo->FirstName<<" "<<patientInfo->LastName<<endl;
    cout <<"Age: "<<patientInfo->Age<<endl;
    cout <<"Gender: "<< patientInfo->Gender<<endl;
    cout <<"Phone Number: "<< patientInfo->Phone<<endl;
    cout <<"Address: "<< patientInfo->Address<<endl;
    cout <<"Sickness Description: "<< patientInfo->SicknessDescription<<endl;
    cout <<"Visit Date: "<< patientInfo->VisitDate<<endl;
    cout <<"Visit Time: "<< patientInfo->VisitTime<<endl;
    cout <<"Disability Option: "<< patientInfo->DisabilityOption<<endl;
    cout <<"Doctor Name: "<< patientInfo->DoctorName<<endl;
    cout <<"Medicine Information: "<<patientInfo->MedicineInformation<<endl<<endl;
}

history* searchPatientHistory(int num2)
{
    history* patientHistory = new history;
    bool modifyFlag = false;
    int id;
    string fName2,lName2,SicknessDescription2;
    string confirmation;
    historyTemp = historyHead;
    if(num2 == 1)
	{
        cin.ignore();
        cout<<"\n\n**********************************\n*      Search Patient by ID      *\n**********************************\n";
        cout<<"Enter ID number\n";
        cin>>id;
        cin.ignore();
    } 
	else if(num2 == 2)
	{
        cin.ignore();
        cout<<"\n\n**********************************\n*     Search Patient by Name     *\n**********************************\n";
        cout<<"Enter Patient First Name\n";
        getline(cin,fName2);
        cout<<"Enter Patient Last Name\n";
        getline(cin,lName2);
    } 
	else if(num2 == 3)
	{
        cin.ignore();
        cout<<"\n\n**********************************************\n*  Search Patient by Sickness Description    *\n**********************************************\n";
        cout<<"Enter Patient Sickness Description\n";
        getline(cin,SicknessDescription2);
    }
    while (historyTemp != NULL) 
	{
        if(num2 == 1)
		{
            if (historyTemp->PID == id) 
			{
                modifyFlag = true;
            }
        } 
		else if(num2 == 2)
		{
            if (historyTemp->FirstName == fName2 && historyTemp->LastName == lName2 ) 
			{
                modifyFlag = true;
            }
        }
        else if(num2 == 3)
		{
            if (historyTemp->SicknessDescription == SicknessDescription2 ) 
			{
                modifyFlag = true;
            }
        }
        if (modifyFlag) 
		{
            cout<<"\n\n**********************************\n*    Patient History Details     *\n**********************************\n";
            printPatientInfo(historyTemp);
            patientHistory = historyTemp;
            break ;
        }
        historyTemp = historyTemp->next;
    }

    if(!modifyFlag)
	{
    	patientHistory = NULL;
        if(num2 == 1)
		{
            cout<<"ID not found"<<endl;

        } else if(num2 == 2)
		{
            cout<<"Name not found"<<endl;

        } else if(num2 == 3)
		{
            cout<<"Sickness Description is not found"<<endl;
        }
    }
    return patientHistory;
}
void modifyHistoryLog(history* patientHistory)
{
    cout<<"\n\n**********************************\n*             Modify             *\n**********************************\n";
    cout<<"Select what do you want to modify:\n1. First Name\n2. Last Name\n3. Age\n4. Gender\n5. Phone Number\n6. Address\n7. Sickness Description\n8. DoctorName\n9. Medicine Information\nYour Selection: ";
    int num;
    bool input=false;
   	while(input!=true)
   	{ 
   		cin>>num;
   		cin.ignore(256,'\n');
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout<<"Invalid input entered\nEnter Again\n";
		}
		else if(num<1 || num>9)
		{
			cout<<"Invalid input entered\nEnter Again\n";
		}
		else if(num>0 && num<10)
		{
			input=true;
		}
	}
	if(num==1)
   	{
   		cout<<"Enter New First Name: ";
	   	getline(cin,patientHistory->FirstName);
	}
	else if(num==2)
	{
	   	cout<<"Enter New Last Name: ";
	   	getline(cin,patientHistory->LastName);
	}
	else if(num==3)
	{
		int age1;
		bool vrf5=false;
	   	cout<<"Enter New Age: ";
		while(vrf5!=true)
		{
			cin>>age1;
			if(age1>0 && age1<122)
			{
				vrf5=true;
				patientHistory->Age=age1;
			}
			else if(cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout<<"Please Enter Appropriate Age:\n";
			}
			else
			{
				cout<<"Please Enter Appropriate Age:\n";
			}
		}
	    cin.ignore();
	    
	}
	else if(num==4)
	{
		string gender1;
		bool vrf4=false;
	   	cout<<"Enter New Gender: ";
	   	while(vrf4!=true)
		{
			getline(cin, gender1);
			if(strcasecmp(gender1.c_str(),"male")==0)
			{
				vrf4=true;
				gender1="Male";
				patientHistory->Gender=gender1;
			}
			else if(strcasecmp(gender1.c_str(),"female")==0)
			{
				vrf4=true;
				gender1="Female";
				patientHistory->Gender=gender1;
			}
			else
			{
				cout<<"Please Enter Appropriate Gender:\n";
			}
		}
	}
	else if(num==5)
	{
	   	 cout<<"Enter New Phone: ";
	   	getline(cin,patientHistory->Phone);
	}
	else if(num==6)
	{
	   	cout<<"Enter New Address: ";
	   	getline(cin,patientHistory->Address);
	}
	else if(num==7)
	{
	   	cout<<"Enter New Sickness Description: ";
	   	getline(cin,patientHistory->SicknessDescription);
	}
	else if(num==8)
	{
	   	cout<<"Enter New Doctor Name: ";
	   	getline(cin,patientHistory->DoctorName);
	}
	else if(num==9)
	{
	   	cout<<"Enter New Medicine Information: ";
	   	getline(cin,patientHistory->MedicineInformation);
	}
	
}
