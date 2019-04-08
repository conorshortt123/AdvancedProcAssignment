#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct patient {
	int pps;
	char firstName[20];
	char lastName[20];
	int yearBorn;
	char gender[6];
	char email[20];//Must check for '@', '.' and "com"
	char nextOfKin[20];
	char lastAppt[40];//E.G 30th of May
	int weight;
	int height;
	char allergies; //Y or N
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

void main()
{
	struct patient* headPtr = NULL;
	int choice;
	int search;

	printf("1) Add patient (Note: PPS Number must be unique).\n2) Display all patient details to screen\n3) Display patient details\n4) Update a patient details\n5) Delete patient\n");
	printf("6) Generate statistics (A-D) based on the user selecting one of the criteria listed in I - II\n\n\tA. %% of patients with a BMI of less than 18.5\n\tB. %% of patients with a BMI of less than 25\n");
	printf("\tC. %% of patients with a BMI of less than 30\n\tD. %% of patients with a BMI of greater than 30\n\n\tI. How many cigarettes would you smoke per day\n\tII. How often do you exercise");
	printf("7) Print all patient details into a report file.\n8) List all the patient of the following countries in order of their last appointment:\n\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
		{
			if (headPtr == NULL) {
				AddPatientAtStart(&headPtr);
			}
			else {
				AddPatient(headPtr);
			}
		}
		else if (choice == 2)
		{
		
		}
		else if (choice == 3)
		{
			printf("Enter the patients PPS number you wish to search for:\n");
			scanf("%d", &search);
			DisplayPatient(headPtr, search);
		}

		printf("1) Add patient (Note: PPS Number must be unique).\n2) Display all patient details to screen\n3) Display patient details\n4) Update a patient details\n5) Delete patient\n");
		printf("6) Generate statistics (A-D) based on the user selecting one of the criteria listed in I - II\n\n\tA. % of patients with a BMI of less than 18.5\n\tB. % of patients with a BMI of less than 25\n");
		printf("\tC. % of patients with a BMI of less than 30\n\tD. % of patients with a BMI of greater than 30\n\n\tI. How many cigarettes would you smoke per day\n\tII. How often do you exercise");
		printf("7) Print all patient details into a report file.\n8) List all the patient of the following countries in order of their last appointment:");
		scanf("%d", &choice);
	}
}


void AddPatientAtStart(struct patient** top)
{
	struct patient* newPatient;

	newPatient = (struct patient*)malloc(sizeof(struct patient));
	printf("Please enter the PPS number of the patient:\n");
	scanf("%d", &newPatient->pps);
	printf("Enter the patient's first name:\n");
	scanf("%s", &newPatient->firstName);
	printf("Enter the patient's last name:\n");
	scanf("%s", &newPatient->lastName);
	printf("Enter the patient's birth year:\n");
	scanf("%d", &newPatient->yearBorn);
	printf("Enter the patient's gender:\n");
	scanf(" %c", &newPatient->gender);
	printf("Enter the patient's email address:\n");
	scanf("%s", &newPatient->email);
	printf("Enter the patient's next of kin:\n");
	scanf("%s", &newPatient->nextOfKin);
	printf("Enter the patient's last appointment:\n");
	scanf("%s", &newPatient->lastAppt);
	printf("Enter the patient's weight:\n");
	scanf("%d", &newPatient->weight);
	printf("Enter the patient's height:\n");
	scanf("%d", &newPatient->height);
	printf("Does the patient have any allergies to medication?(Y/N):\n");
	scanf("%c", &newPatient->allergies);
	printf("How many cigarettes does the patient smoke per day?(N for None, L for Less than ten, M for more than ten.):\n");
	scanf("%c", &newPatient->smoking);
	printf("How often does the patient exercise?(N for Never, L for Less than twice per week, M for More than twice per week.):\n");
	scanf("%c", &newPatient->exercise);

	newPatient->NEXT = *top;
	*top = newPatient;
}


void DisplayAll(struct patient* top)
{
	struct patient* temp = top;
	while (temp != NULL)
	{
		//printf("The values of the patient is %d\n", temp->value);
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
			printf("The patients name is %s %s.", top->firstName, top->lastName);
			printf("The patient was born in %d", top->yearBorn);
			printf("The patient's gender is %s", top->gender);
			printf("The patient's email address is %s", top->email);
		}
	}
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

	newPatient = (struct patient*)malloc(sizeof(struct patient));
	printf("Please enter the PPS number of the patient:\n");
	scanf("%d", &newPatient->pps);
	printf("Enter the patient's first name:\n");
	scanf("%s", &newPatient->firstName);
	printf("Enter the patient's last name:\n");
	scanf("%s", &newPatient->lastName);
	printf("Enter the patient's birth year:\n");
	scanf("%d", &newPatient->yearBorn);
	printf("Enter the patient's gender:\n");
	scanf("%c", &newPatient->gender);
	printf("Enter the patient's email address:\n");
	scanf("%s", &newPatient->email);
	printf("Enter the patient's next of kin:\n");
	scanf("%s", &newPatient->nextOfKin);
	printf("Enter the patient's last appointment:\n");
	scanf("%s", &newPatient->lastAppt);
	printf("Enter the patient's weight:\n");
	scanf("%d", &newPatient->weight);
	printf("Enter the patient's height:\n");
	scanf("%d", &newPatient->height);
	printf("Does the patient have any allergies to medication?(Y/N):\n");
	scanf("%c", &newPatient->allergies);
	printf("How many cigarettes does the patient smoke per day?(N for None, L for Less than ten, M for more than ten.):\n");
	scanf("%c", &newPatient->smoking);
	printf("How often does the patient exercise?(N for Never, L for Less than twice per week, M for More than twice per week.):\n");
	scanf("%c", &newPatient->exercise);

	newPatient->NEXT = NULL;
	temp->NEXT = newPatient;
}

bool checkEmail(struct patient* top)
{
	char mail[20];
	bool dot, com, symbol;
	printf("d", mail.length());
}