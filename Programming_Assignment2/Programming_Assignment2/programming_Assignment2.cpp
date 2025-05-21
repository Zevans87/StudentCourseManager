//Zachery Evans
//COSC-1337
//Programing Assignment 2
//04/??/2023
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

//Structures
struct Course
{
	string courseID;
	string faculty;
	int numStudents;
	string* roster;
	string rosterFile;
};

//Function Prototype
void displayCourseInfo(vector <Course>);
Course* cancelACourse(vector <Course>&, string);
void dropTheStudent(vector <Course>&, string, string);
string* isVacant(vector <Course>&, string);
void enrollTheStudent(string*, string);
vector <string> getCourseList(vector <Course>, string);

int main()
{
	//Variables, Vectors, Arrays, and Pointers
	Course courseInfo, addCourse;
	Course* coursePtr = nullptr;
	vector <Course> courseVec;
	vector <Course *> vacantCourseList;
	vector <string> getCourseVec;
	ifstream infile;
	int size = 0, menuChoice = 0;
	string cancelCourse, dropStu, dropCourse, enrollCourse, enrollStu, getCourseStu;
	string* sPtr = nullptr;

	//Populating the Vector and Roster Arrays
	infile.open("courseInfo.txt");
	while (infile >> courseInfo.courseID)
	{
		infile >> courseInfo.faculty >> courseInfo.numStudents >> courseInfo.rosterFile;
		courseVec.push_back(courseInfo);
	}
	infile.close();

	for (int i = 0; i < courseVec.size(); i++)
	{
		infile.open(courseVec[i].rosterFile);
		courseVec[i].roster = nullptr;
		courseVec[i].roster = new string[courseVec[i].numStudents];
		for (int j = 0; j < courseVec[i].numStudents; j++)
		{
			infile >> courseVec[i].roster[j];
		}
		infile.close();
	}

	//Menu
	while (menuChoice != 7)
	{
		cout << "1.     Cancel a course: " << endl;
		cout << "2.     Drop a student: " << endl;
		cout << "3.     Enroll a student: " << endl;
		cout << "4.     Add a course: " << endl;
		cout << "5.     Display information on all courses: " << endl;
		cout << "6.     List of courses taken by a student: " << endl;
		cout << "7.     Exit: " << endl;
		cout << "Please choose an option: ";
		cin >> menuChoice;
		switch (menuChoice)
		{
		case 1:
			cout << "Please enter the course name: ";
			cin >> cancelCourse;
			coursePtr = cancelACourse(courseVec, cancelCourse);
			if (coursePtr == nullptr)
				cout << "The course you entered was not found." << endl;
			else
			{
				cout << "Course " << cancelCourse << " was canceled." << endl;
				vacantCourseList.push_back(coursePtr);
			}
			break;
		case 2:
			cout << "Please enter the name of the student and the course: ";
			cin >> dropStu >> dropCourse;
			dropTheStudent(courseVec, dropStu, dropCourse);
			break;
		case 3:
			cout << "Please enter the course: ";
			cin >> enrollCourse;
			cout << "Please enter the name of the student: ";
			cin >> enrollStu;
			sPtr = isVacant(courseVec, enrollCourse);
			if (sPtr == nullptr)
				cout << "Unfortunately, there is no vacancy in course " << enrollCourse << endl;
			else enrollTheStudent(sPtr, enrollStu);
			break;
		case 4:
			cout << "Please enter the course information line: ";
			cin >> addCourse.courseID >> addCourse.faculty >> addCourse.numStudents >> addCourse.rosterFile;
			if (vacantCourseList.empty())
				courseVec.push_back(addCourse);
			else
			{
				for (Course* c : vacantCourseList)
				{
					c->courseID = addCourse.courseID;
					c->faculty = addCourse.faculty;
					c->numStudents = addCourse.numStudents;
					c->rosterFile = addCourse.rosterFile;
				}
			}

			break;
		case 5:
			displayCourseInfo(courseVec);
			break;
		case 6:
			cout << "Please enter the name of the student: ";
			cin >> getCourseStu;
			getCourseVec = getCourseList(courseVec, getCourseStu);
			cout << "This is the list of courses for student " << getCourseStu << ": " << endl;
			for (int i = 0; i < getCourseVec.size(); i++)
			{
				cout << getCourseVec[i] << " ";
			}
			cout << endl;

			break;
		default:
			break;
		}
	}

	return 0;
}

//Function Definition
void displayCourseInfo(vector <Course> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << left << vec[i].courseID << ":     " << setw(10) << vec[i].faculty;
		if (vec[i].roster != nullptr)
			for (int j = 0; j < vec[i].numStudents; j++)
				cout << right << vec[i].roster[j] << " ";
		cout << endl;
	}
}

Course* cancelACourse(vector <Course>& vec, string course)
{
	Course* iPtr = nullptr;
	
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].courseID == course)
		{
			vec[i].courseID = "--------";
			vec[i].faculty = "--------";
			vec[i].numStudents = 0;
			vec[i].roster = nullptr;
			vec[i].rosterFile = "--------";
			iPtr = &vec[i];
			break;
		}
	}

	return iPtr;
}

void dropTheStudent(vector <Course>& vec, string student, string course)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].courseID == course)
		{
			for (int j = 0; j < vec[i].roster->size(); j++)
			{
				if (vec[i].roster[j] == student)
					vec[i].roster[j] = "--------";
			}
		}
	}
}

string* isVacant(vector <Course>& vec, string course)
{
	string* sPtr = nullptr;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].courseID == course)
		{
			for (int j = 0; j < vec[i].roster->size(); j++)
			{
				if (vec[i].roster[j] == "--------")
					sPtr = &vec[i].roster[j];
			}
		}
	}

	return sPtr;
}

void enrollTheStudent(string* sPtr, string student)
{
	*sPtr = student;
}

vector <string> getCourseList(vector <Course> vec, string student)
{
	vector <string> stringVec;

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].roster->size(); j++)
		{
			if (vec[i].roster[j] == student)
				stringVec.push_back(vec[i].courseID);
		}
	}

	return stringVec;
}