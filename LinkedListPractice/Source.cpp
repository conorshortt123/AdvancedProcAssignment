#include<stdio.h>
#include<stdlib.h>
#include <string>
#include <iostream>
using namespace std;

struct patient {
	int pps;
	char firstName[20];
	char lastName[20];
	int yearBorn;
	char gender[6];
	char email[40];//Must check for '@', '.' and "com"
	char nextOfKinFN[20];
	char nextOfKinLN[20];
	char lastAppt[20];//E.G 30th of May
	int weight;
	int height;
	char allergies; //Y or N
	char medication[20];
	char smoking;
	char alcohol;
	char exercise;
	struct patient* NEXT;
};

//void AddElementAtStart(struct patient** top);
void DisplayPatient(struct patient* top, int ppsSearch);
void AddPatientAtStart(struct patient** top);
void AddPatient(struct patient* top);
void DisplayAll(struct patient* top);
void checkEmail(struct patient* top);
bool emailContains;

void main()
{
	struct patient* headPtr = NULL;
	int choice;
	int search;

	//Program header
	cout << "==================== ABC DENTAL PRACTICE LTD - PATIENT DATABASE ====================" << endl;
	cout << "=================================== G00360253 ======================================" << endl;

	cout << "\n1) Add patient (Note: PPS Number must be unique).\n2) Display all patient details to screen\n3) Display patient details\n4) Update a patient details\n5) Delete patient" << endl;
	cout << "6) Generate statistics (A-D) based on the user selecting one of the criteria listed in I - II\n\n\tA. % of patients with a BMI of less than 18.5\n\tB. % of patients with a BMI of less than 25" << endl;
	cout << "\tC. % of patients with a BMI of less than 30\n\tD. % of patients with a BMI of greater than 30\n\n\tI.  How many cigarettes would you smoke per day\n\tII. How often do you exercise\n" << endl;
	cout << "7) Print all patient details into a report file.\n8) List all the patient of the following countries in order of their last appointment:\n" << endl;
	
	cin >> choice;
	while (choice != -1)
	{
		if (choice == 1)
		{
			//if (headPtr == NULL) {
				AddPatientAtStart(&headPtr);
			//}
			//else {
			//	AddPatient(headPtr);
			//}
		}
		else if (choice == 2)
		{
			DisplayAll(headPtr);
		}
		else if (choice == 3)
		{
			cout << "Enter the patients PPS number you wish to search for:" << endl;
			cin >> search;
			DisplayPatient(headPtr, search);
		}

		cout << "\n1) Add patient (Note: PPS Number must be unique).\n2) Display all patient details to screen\n3) Display patient details\n4) Update a patient details\n5) Delete patient" << endl;
		cout << "6) Generate statistics (A-D) based on the user selecting one of the criteria listed in I - II\n\n\tA. % of patients with a BMI of less than 18.5\n\tB. % of patients with a BMI of less than 25" << endl;
		cout << "\tC. % of patients with a BMI of less than 30\n\tD. % of patients with a BMI of greater than 30\n\n\tI.  How many cigarettes would you smoke per day\n\tII. How often do you exercise\n" << endl;
		cout << "7) Print all patient details into a report file.\n8) List all the patient of the following countries in order of their last appointment:\n" << endl;
		cin >> choice;
	}
}

void AddPatientAtStart(struct patient** top)
{
	struct patient* newPatient;

	newPatient = (struct patient*)malloc(sizeof(struct patient));
	cout << "Please enter the PPS number of the patient:" << endl;
	cin >> newPatient->pps;
	cout << "Enter the patient's first name:" << endl;
	cin >> newPatient->firstName;
	cout << "Enter the patient's last name:" << endl;
	cin >> newPatient->lastName;
	cout << "Enter the patient's birth year:" << endl;
	cin >> newPatient->yearBorn;
	cout << "Enter the patient's gender:" << endl;
	cin >> newPatient->gender;
	cout << "Enter the patient's email address:" << endl;
	cin >> newPatient->email;
	checkEmail(newPatient);
	cout << "Enter the patient's next of kin:(firstname lastname)" << endl;
	cin >> newPatient->nextOfKinFN >> newPatient->nextOfKinLN;
	cout << "Enter the patient's last appointment:(DD/MM/YYYY)" << endl;
	cin >> newPatient->lastAppt;
	cout << "Enter the patient's weight(in kgs):" << endl;
	cin >> newPatient->weight;
	cout << "Enter the patient's height(in cms):" << endl;
	cin >> newPatient->height;
	cout << "Does the patient have any allergies to medication?(Y/N):" << endl;
	cin >> newPatient->allergies;
	if (newPatient->allergies == 'Y' || newPatient->allergies == 'y') {
		cout << "Please enter the name of the medication the patient is allergic to:" << endl;
		cin >> newPatient->medication;
	}
	cout << "How many cigarettes does the patient smoke per day?(N for None, L for Less than ten, M for more than ten.):" << endl;
	cin >> newPatient->smoking;
	cout << "How often does the patient exercise?(N for Never, L for Less than twice per week, M for More than twice per week.):" << endl;
	cin >> newPatient->exercise;

	newPatient->NEXT = *top;
	*top = newPatient;
}

void AddPatient(struct patient* top)
{
	struct patient* temp = top;
	struct patient* newPatient;

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newPatient = (struct patient*)malloc(sizeof(struct patient));

	cout << "Please enter the PPS number of the patient:" << endl;
	cin >> newPatient->pps;
	cout << "Enter the patient's first name:" << endl;
	cin >> newPatient->firstName;
	cout << "Enter the patient's last name:" << endl;
	cin >> newPatient->lastName;
	cout << "Enter the patient's birth year:" << endl;
	cin >> newPatient->yearBorn;
	cout << "Enter the patient's gender:" << endl;
	cin >> newPatient->gender;
	cout << "Enter the patient's email address:" << endl;
	cin >> newPatient->email;
	checkEmail(newPatient);
	cout << "Enter the patient's next of kin:(firstname lastname)" << endl;
	cin >> newPatient->nextOfKinFN >> newPatient->nextOfKinLN;
	cout << "Enter the patient's last appointment:(DD/MM/YYYY)" << endl;
	cin >> newPatient->lastAppt;
	cout << "Enter the patient's weight(in kgs):" << endl;
	cin >> newPatient->weight;
	cout << "Enter the patient's height(in cms):" << endl;
	cin >> newPatient->height;
	cout << "Does the patient have any allergies to medication?(Y/N):" << endl;
	cin >> newPatient->allergies;
	if (newPatient->allergies == 'Y' || newPatient->allergies == 'y') {
		cout << "Please enter the name of the medication the patient is allergic to:" << endl;
		cin >> newPatient->medication;
	}
	cout << "How many cigarettes does the patient smoke per day?(N for None, L for Less than ten, M for more than ten.):" << endl;
	cin >> newPatient->smoking;
	cout << "How often does the patient exercise?(N for Never, L for Less than twice per week, M for More than twice per week.):" << endl;
	cin >> newPatient->exercise;

	newPatient->NEXT = NULL;
	temp->NEXT = newPatient;
}

void DisplayAll(struct patient* top)
{
	int patientCount = 1;
	struct patient* temp = top;
	while (temp != NULL)
	{
		cout << "\n/=============== PATIENT #" << patientCount << " DETAILS ===================/" << endl;
		cout << "The patient's name is " << top->firstName << " " << top->lastName << endl;
		cout << "The patient was born in " << top->yearBorn << endl;;
		cout << "The patient's gender is " << top->gender << endl;
		cout << "The patient's email address is " << top->email << endl;
		cout << "The patient's next of kin is " << top->nextOfKinFN << " " << top->nextOfKinLN << endl;
		cout << "The patient's last appointment was " << top->lastAppt << endl;
		cout << "The patient's weight is " << top->weight << "kg" << endl;
		cout << "The patient's height is " << top->height << "cm" << endl;
		if (top->allergies == 'Y' || top->allergies == 'y') {
			cout << "The medication the patient is allergic to is " << top->medication << endl;
		}
		else {
			cout << "The patient is not allergic to any medication." << endl;
		}
		if (top->smoking == 'M' ||  top->smoking == 'y') {
			cout << "The patient smokes more than ten cigarettes per day." << endl;
		}
		else if (top->smoking == 'L' ||  top->smoking == 'l') {
			cout << "The patient smokes less than ten cigarettes per day." << endl;
		}
		else {
			cout << "The patient does not smoke." << endl;
		}
		if (top->exercise == 'M' ||  top->exercise == 'm') {
			cout << "The patient exercises more than twice per week." << endl;
		}
		else if (top->exercise == 'L' ||  top->exercise == 'l') {
			cout << "The patient exercises less than twice per week" << endl;
		}
		else {
			cout << "The patient does not exercise." << endl;
		}
		cout << "/====================================================/" << endl;
		patientCount++;
		temp = temp->NEXT;
	}
}

void DisplayPatient(struct patient* top, int ppsSearch)
{
	struct patient* temp = top;
	while (temp != NULL) 
	{
		if (top->pps == ppsSearch)
		{
			cout << "\n/=============== PATIENT DETAILS ===================/" << endl;
			cout << "The patient's name is " << top->firstName << " " << top->lastName << endl;
			cout << "The patient was born in " << top->yearBorn << endl;;
			cout << "The patient's gender is " << top->gender << endl;
			cout << "The patient's email address is " << top->email << endl;
			cout << "The patient's next of kin is " << top->nextOfKinFN << " " << top->nextOfKinLN << endl;
			cout << "The patient's last appointment was " << top->lastAppt << endl;
			cout << "The patient's weight is " << top->weight << "kg" << endl;
			cout << "The patient's height is " << top->height << "cm" << endl;
			if (top->allergies == 'Y'){
				cout << "The medication the patient is allergic to is " << top->medication << endl;
			}
			else {
				cout << "The patient is not allergic to any medication." << endl;
			}
			if (top->smoking == 'M') {
				cout << "The patient smokes more than ten cigarettes per day." << endl;
			}
			else if (top->smoking == 'L') {
				cout << "The patient smokes less than ten cigarettes per day." << endl;
			}
			else {
				cout << "The patient does not smoke." << endl;
			}
			if (top->exercise == 'M') {
				cout << "The patient exercises more than twice per week." << endl;
			}
			else if(top->exercise == 'L'){
				cout << "The patient exercises less than twice per week" << endl;
			}
			else {
				cout << "The patient does not exercise." << endl;
			}
			cout << "/==================================================/" << endl;
		}
		temp = temp->NEXT;
	}
}

void checkEmail(struct patient* top)
{
	bool check = false;
	char at[10] = "@";
	char dotcom[10] = ".com";

	//Initial if uses a string method to find if the email contains the string contained in our at and dotcom string's, if it find both of these in the email it returns true.
	strcmp(at, dotcom);
}