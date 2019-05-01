#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<conio.h>
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
	float weight;
	float height;
	char allergies; //Y or N
	char medication[20];
	char smoking;
	char alcohol;
	char exercise;
	float bmi;

	struct patient* NEXT;
};

//Prototypes of all methods:
void AddPatientAtStart(struct patient** top);
void AddPatientToEnd(struct patient* top);
void DisplayAll(struct patient* top);
void SearchPatient(struct patient* top);
void UpdatePatient(struct patient* top);
void checkEmail(struct patient* top);
void DeletePatientAtStart(struct patient** top);
void DeletePatientAtPPS(struct patient* top, int ppsSearch);
void CalculateBMI(struct patient* top);
void GenerateStatistics(struct patient* top);
int Listlength(struct patient* top);

void main()
{
	struct patient* headPtr = NULL;
	int choice;
	int ppsSearch;
	FILE* login;
	char username[10];
	char password[6];
	char fileUsername[10];
	char filePassword[10];
	int numInputs;
	char ch;
	int i;

	cout << "/===== LOGIN ======/" << endl;

	printf("Enter User name: ");
	cin >> username;
	printf("Enter the password <5 characters>: ");
	while (1) {
		ch = getch();
		if (ch == 5) 
		{
			password[i] = '\0';

		}
		password[i] = ch;
		i++;
		printf("*");
	}

		login = fopen("userDatabase.txt", "r");

	if (login == NULL) {
		cout << "Sorry, file couldn't be opened." << endl;
	}
	else
	{
		while (!feof(login)) 
		{
			numInputs = fscanf(login, "%s %s" );
		}
	}

	//Program header
	cout << "==================== ABC DENTAL PRACTICE LTD - PATIENT DATABASE ====================" << endl;
	cout << "=================================== G00360253 ======================================" << endl;

	cout << "\n1) Add patient (Note: PPS Number must be unique).\n2) Display all patient details to screen\n3) Display patient details\n4) Update a patient details\n5) Delete patient" << endl;
	cout << "6) Generate statistics (A-D) based on the patient statistics.\n\n\tA. % of patients with a BMI of less than 18.5\n\tB. % of patients with a BMI of less than 25" << endl;
	cout << "\tC. % of patients with a BMI of less than 30\n\tD. % of patients with a BMI of greater than 30\n" << endl;
	cout << "7) Print all patient details into a report file.\n8) List all the patients in order of their last appointment:\n" << endl;

	cin >> choice;
	while (choice != -1)
	{
		if (choice == 1)
		{
			//If headPtr is NULL call add to start function else call add to end function.
			if (headPtr == NULL) {
				AddPatientAtStart(&headPtr);
			}
			else {
				AddPatientToEnd(headPtr);
			}
		}
		else if (choice == 2)
		{
			if (headPtr == NULL) {
				cout << "[ERROR]There are no patients." << endl;
			}
			else {
				//Display all patients function.
				DisplayAll(headPtr);
			}
		}
		else if (choice == 3)
		{
			if (headPtr == NULL) {
				cout << "[ERROR]You cannot search for a patient if no patients have been added." << endl;
			}
			else {
				//Search for a patient and display details.
				SearchPatient(headPtr);
			}
		}
		else if (choice == 4)
		{
			if (headPtr == NULL) {
				cout << "[ERROR]You cannot update a patient if no patients have been added." << endl;
			}
			else {
				//Update a patient's details.
				UpdatePatient(headPtr);
			}
		}
		else if (choice == 5)
		{
			//Delete a patient.
			cout << "Enter the PPS number of the patient you wish to delete:" << endl;
			cin >> ppsSearch;
			if (Listlength(headPtr) == 1) {
				if (ppsSearch == headPtr->pps)
				{
					DeletePatientAtStart(&headPtr);
				}
			}
			else {
				DeletePatientAtPPS(headPtr, ppsSearch);
			}
		}
		else if (choice == 6)
		{
			if (headPtr == NULL) {
				cout << "[ERROR]You cannot generate statistics if no patients have been added." << endl;
			}
			else {
				//Generates statistics.
				CalculateBMI(headPtr);
				GenerateStatistics(headPtr);
			}
		}

		cout << "\n1) Add patient (Note: PPS Number must be unique).\n2) Display all patient details to screen\n3) Display patient details\n4) Update a patient details\n5) Delete patient" << endl;
		cout << "6) Generate statistics (A-D) based on the patient statistics.\n\n\tA. % of patients with a BMI of less than 18.5\n\tB. % of patients with a BMI of less than 25" << endl;
		cout << "\tC. % of patients with a BMI of less than 30\n\tD. % of patients with a BMI of greater than 30\n" << endl;
		cout << "7) Print all patient details into a report file.\n8) List all the patients in order of their last appointment:\n" << endl;
		cin >> choice;
	}
}

void AddPatientAtStart(struct patient** top)
{
	/*
	* Adds a patient to the start of the list.
	* Function is called if lengthList returns 1.
	*/
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
	cout << "Enter the patient's height(in metres):" << endl;
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

void AddPatientToEnd(struct patient* top)
{
	/*
	* Adds a patient to the end of the list.
	* Function is called if lenghtList returns more than 1.
	*/
	struct patient* temp = top;
	struct patient* newPatient;

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newPatient = (struct patient*)malloc(sizeof(struct patient));

	cout << "\n/=============== ADDING PATIENT ===================/" << endl;
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
	cout << "Enter the patient's height(in metres):" << endl;
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
	cout << "\n/=============== PATIENT ADDED ===================/" << endl;

	newPatient->NEXT = NULL;
	temp->NEXT = newPatient;
}

void DisplayAll(struct patient* top)
{
	/*
	* Outputs all patients on the list, including their PPS numbers.
	*/
	int patientCount = 1;
	struct patient* temp = top;
	while (temp != NULL)
	{
		cout << "\n/=============== PATIENT #" << patientCount << " DETAILS ===================/" << endl;
		cout << "PPS no: " << temp->pps << endl;
		cout << "The patient's name is " << temp->firstName << " " << temp->lastName << endl;
		cout << "The patient was born in " << temp->yearBorn << endl;;
		cout << "The patient's gender is " << temp->gender << endl;
		cout << "The patient's email address is " << temp->email << endl;
		cout << "The patient's next of kin is " << temp->nextOfKinFN << " " << temp->nextOfKinLN << endl;
		cout << "The patient's last appointment was " << temp->lastAppt << endl;
		cout << "The patient's weight is " << temp->weight << "kg" << endl;
		cout << "The patient's height is " << temp->height << "m" << endl;
		if (temp->allergies == 'Y' || temp->allergies == 'y') {
			cout << "The medication the patient is allergic to is " << temp->medication << endl;
		}
		else {
			cout << "The patient is not allergic to any medication." << endl;
		}
		if (temp->smoking == 'M' || temp->smoking == 'm') {
			cout << "The patient smokes more than ten cigarettes per day." << endl;
		}
		else if (temp->smoking == 'L' || temp->smoking == 'l') {
			cout << "The patient smokes less than ten cigarettes per day." << endl;
		}
		else {
			cout << "The patient does not smoke." << endl;
		}
		if (temp->exercise == 'M' || temp->exercise == 'm') {
			cout << "The patient exercises more than twice per week." << endl;
		}
		else if (temp->exercise == 'L' || temp->exercise == 'l') {
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

void SearchPatient(struct patient* top)
{
	/*
	* Finds a patient if the ppsSearch matches a pps on the list
	* If found the patient details are output.
	*/
	int patientCount = 1;
	struct patient* temp = top;
	int searchChoice;
	int search;
	char first[20];
	char last[20];

	cout << "Enter 1 to search for a PPS number, Enter 2 to search for a patient name" << endl;
	cin >> searchChoice;
	if (searchChoice == 1)
	{
		cout << "Enter the patients PPS number you wish to search for:" << endl;
		cin >> search;
	}
	else if (searchChoice == 2)
	{
		cout << "Enter the patients name you wish to search for:(firstname lastname)" << endl;
		cin >> first >> last;
	}
	while (temp != NULL)
	{
		if (temp->pps == search || strcmp(temp->firstName, first) == 0 && strcmp(temp->lastName, last) == 0)
		{
			cout << "\n/=============== PATIENT #" << patientCount << " DETAILS ===================/" << endl;
			cout << "The patient's name is " << temp->firstName << " " << temp->lastName << endl;
			cout << "The patient was born in " << temp->yearBorn << endl;;
			cout << "The patient's gender is " << temp->gender << endl;
			cout << "The patient's email address is " << temp->email << endl;
			cout << "The patient's next of kin is " << temp->nextOfKinFN << " " << temp->nextOfKinLN << endl;
			cout << "The patient's last appointment was " << temp->lastAppt << endl;
			cout << "The patient's weight is " << temp->weight << "kg" << endl;
			cout << "The patient's height is " << temp->height << "m" << endl;
			if (temp->allergies == 'Y') {
				cout << "The medication the patient is allergic to is " << temp->medication << endl;
			}
			else {
				cout << "The patient is not allergic to any medication." << endl;
			}
			if (temp->smoking == 'M') {
				cout << "The patient smokes more than ten cigarettes per day." << endl;
			}
			else if (temp->smoking == 'L') {
				cout << "The patient smokes less than ten cigarettes per day." << endl;
			}
			else {
				cout << "The patient does not smoke." << endl;
			}
			if (temp->exercise == 'M') {
				cout << "The patient exercises more than twice per week." << endl;
			}
			else if (temp->exercise == 'L') {
				cout << "The patient exercises less than twice per week" << endl;
			}
			else {
				cout << "The patient does not exercise." << endl;
			}
			cout << "/=====================================================/" << endl;
		}
		patientCount++;
		temp = temp->NEXT;
	}
}

void UpdatePatient(struct patient* top)
{
	/*
	* Loops through the list until the pps matching ppsSearch is found, allows the user to change whichever variables they want by
	* Either choosing the (Y/N) option.
	*/
	int patientCount = 1;
	struct patient* temp = top;
	int searchChoice;
	int search;
	char choice;
	char first[20];
	char last[20];

	cout << "Enter 1 to search for a PPS number, Enter 2 to search for a patient name" << endl;
	cin >> searchChoice;
	if (searchChoice == 1)
	{
		cout << "Enter the patients PPS number you wish to search for:" << endl;
		cin >> search;
	}
	else if (searchChoice == 2)
	{
		cout << "Enter the patients name you wish to search for:(firstname lastname)" << endl;
		cin >> first >> last;
	}

	while (temp != NULL)
	{
		if (temp->pps == search || strcmp(temp->firstName, first) == 0 && strcmp(temp->lastName, last) == 0)
		{
			cout << "\n/=============== UPDATING PATIENT #" << patientCount << "'S DETAILS ===================/" << endl;
			cout << "Would you like to update the patient's PPS?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Please enter the PPS number of the patient:" << endl;
				cin >> temp->pps;
			}
			cout << "Would you like to update the patient's name?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's first name:" << endl;
				cin >> temp->firstName;
				cout << "Enter the patient's last name:" << endl;
				cin >> temp->lastName;
			}
			cout << "Would you like to update the patient's birth year?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's birth year:" << endl;
				cin >> temp->yearBorn;
			}
			cout << "Would you like to update the patient's gender?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's gender:" << endl;
				cin >> temp->gender;
			}
			cout << "Would you like to update the patient's email?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's email address:" << endl;
				cin >> temp->email;
				checkEmail(temp);
			}
			cout << "Would you like to update the patient's next of kin?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's next of kin:(firstname lastname)" << endl;
				cin >> temp->nextOfKinFN >> temp->nextOfKinLN;
			}
			cout << "Would you like to update the patient's last appointment?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's last appointment:(DD/MM/YYYY)" << endl;
				cin >> temp->lastAppt;
			}
			cout << "Would you like to update the patient's weight and height?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Enter the patient's weight(in kgs):" << endl;
				cin >> temp->weight;
				cout << "Enter the patient's height(in metres):" << endl;
				cin >> temp->height;
			}
			cout << "Would you like to update the patient's medicinal allergies?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "Does the patient have any allergies to medication?(Y/N):" << endl;
				cin >> temp->allergies;
				if (temp->allergies == 'Y' || temp->allergies == 'y') {
					cout << "Please re-enter the name of the medication the patient is allergic to:" << endl;
					cin >> temp->medication;
				}
			}
			cout << "Would you like to update the patient's smoking tendencies?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "How many cigarettes does the patient smoke per day?(N for None, L for Less than ten, M for more than ten.):" << endl;
				cin >> temp->smoking;
			}
			cout << "Would you like to update the patient's exercise tendencies?(Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				cout << "How often does the patient exercise?(N for Never, L for Less than twice per week, M for More than twice per week.):" << endl;
				cin >> temp->exercise;
			}
			cout << "/========================================================/" << endl;
		}
		patientCount++;
		temp = temp->NEXT;
	}
}

void checkEmail(struct patient* top)
{
	struct patient* temp = top;
	bool check = false;
	int length, i, checkCount = 0, atCount = 0;
	char a = '@';
	char b = '.';
	char c = 'c';
	char d = 'o';
	char e = 'm';

	length = strlen(temp->email);

	//This series of else ifs checks the last 4 characters of the array, if it equals ".com" then checkCount will have incremented 4 times.
	if (temp->email[length - 1] == e) {
		checkCount++;
	}
	if (temp->email[length - 2] == d) {
		checkCount++;
	}
	if (temp->email[length - 3] == c) {
		checkCount++;
	}
	if (temp->email[length - 4] == b) {
		checkCount++;
	}
	/*
	* This for loop goes over the array and checks for @ symbol.
	* I had to use a for loop as I didn't know where the position of the @ symbol would be as the user could enter in "@hotmail.com" or "@gmail.com" for example.
	* So it loops over the string and if the variable atCount is greater than one it increments checkCount the fifth and final time.
	*/
	for (i = 0; i < length; i++) {
		if (temp->email[i] == a) {
			atCount++;
		}
	}
	if (atCount > 0) {
		checkCount++;
	}
	//If checkCount is not five by the end of the function, @gmail.com is concatenated onto the end of the string by default.
	if (checkCount != 5) {
		strcat(temp->email, "@gmail.com");
	}
}

void DeletePatientAtStart(struct patient** top)
{
	//Deletes patient at start of list.
	struct patient* temp;
	temp = (struct patient*)malloc(sizeof(struct patient));

	temp = *top;

	*top = temp->NEXT;

	free(temp);
}

void DeletePatientAtPPS(struct patient* top, int ppsSearch)
{
	//Deletes patient at a given PPS
	bool found;
	struct patient* temp = top;
	struct patient* prev_temp;

	while (temp != NULL)
	{
		if (ppsSearch == temp->pps)
		{
			//Loops through while until ppsSearch matches a pps in the list, sets the boolean to true and breaks.
			found = true;
			break;
		}
		prev_temp = temp;
		temp = temp->NEXT;
	}
	//After the while ends either through the condition or else is ends through the break, if found is true then it deletes the patient.
	if (found == true) {
		prev_temp->NEXT = temp->NEXT;
		free(temp);
	}
}

void CalculateBMI(struct patient* top)
{
	//Loops through list and calculates BMI for each patient. 
	struct patient* temp = top;

	cout << "Entered CalculateBMI function" << endl;

	while (temp != NULL)
	{
		temp->bmi = (temp->weight) / (temp->height * temp->height);
		cout << "Bmi = " << temp->bmi << endl;

		temp = temp->NEXT;
	}
}

void GenerateStatistics(struct patient* top)
{
	cout << "Entered generate statistics function.." << endl;
	struct patient* temp = top;
	int patientCount = 0;

	float categoryACount = 0, categoryBCount = 0, categoryCCount = 0, categoryDCount = 0;
	float catAPercentage, catBPercentage, catCPercentage, catDPercentage;

	while (temp != NULL)
	{
		if (temp->bmi < 18.5) {
			categoryACount++;
			cout << "Incrementing category a.." << endl;
		}
		else if (temp->bmi < 25) {
			categoryBCount++;
			cout << "Incrementing category b.." << endl;
		}
		else if (temp->bmi < 30) {
			cout << "Incrementing category c.." << endl;
			categoryCCount++;
		}
		else if (temp->bmi > 30) {
			cout << "Incrementing category d.." << endl;
			categoryDCount++;
		}

		patientCount++;
		temp = temp->NEXT;
	}
	cout << "Calculating percentages" << endl;
	catAPercentage = (categoryACount / patientCount) * 100;
	catBPercentage = (categoryBCount / patientCount) * 100;
	catCPercentage = (categoryCCount / patientCount) * 100;
	catDPercentage = (categoryDCount / patientCount) * 100;

	cout << "\n/====================== GENERATED STATISTICS ======================/\n" << endl;
	cout << "Percentage of patients with a BMI under 18.5: " << catAPercentage << "%" << endl;
	cout << "Percentage of patients with a BMI under   25: " << catBPercentage << "%" << endl;
	cout << "Percentage of patients with a BMI under   30: " << catCPercentage << "%" << endl;
	cout << "Percentage of patients with a BMI above   30: " << catDPercentage << "%" << endl;
	cout << "\n===================================================================/" << endl;
}

int Listlength(struct patient* top)
{
	//Iterates through the list and counts the number of patients and returns an int.
	struct patient* temp;
	int count = 0;
	temp = top;

	while (temp != NULL)
	{
		count++;
		temp = temp->NEXT;
	}

	return count;
}