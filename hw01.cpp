/*
*   Evan Moncheck : 002905615 : no special compiling instructions
*   
*   basic header for a c++ program to include necessary functions and simplify print statements
*/
#include <iostream>
#include <string>
using namespace std;

//
class Person
{
    private:
        string fullname;
        string address;
        int age;
    public:

        //fills the thee private Person variables with user inputs
        void readPersonInfo()
        {
            //age verified to be between 9 and 99
        }

        //prints the three private Person variables
        void printPersonInfo()
        {

        }

        //returns person's age
        int personAGE()
        {

        }

        //returns person's name
        string personName()
        {

        }
};

class Student : public Person
{
    private:
        string ID;
        string major;
        float gpa;
    public:

        //first calls the base class function: readPersonInfo
        void readStudentInfo()
        {

        }

        /*  first calls the base class function printPersonInfo, 
            then prints the above student’s three private attributes
        */
        void printStudentInfo()
        {

        }

        //returns the student’s GPA
        float studentGPA()
        {

        }

        //returns the student’s Major
        string studentMajor()
        {

        }
};

class Course
{
    private:
        string ID;
        string title;
        int credits;

    public:

        //
        void printCourse()
        {

        }

        //add constructor

};

class CourseSection : public Course
{
    private:
        int sectionSize;
        Student *roster;

    public:

        //
        void fillRosterInfo()
        {

        }

        //
        void printSectionInfo()
        {

        }

        //
        void printAverageGPA()
        {

        }

        //
        void printMaxGPAinfo()
        {

        }

        //
        void printMajorStudents(string mjr)
        {

        }

        //add courseSection constructor and destructor
};

int main() {
    /*
    int num, cr;
    string id, tl, mj;

    cout << "What is the Course ID? "; cin >> id;
    cout << "What is the course title? ";
    cin.get(); //remove the leftover "new line" character from cin
    getline(cin, tl); //allows for spaces in the title but first clear the input buffer.
    cout << "What are the course credit hours? "; cin >> cr;
    cout << "How many students in the course section? ";
    cin >> num;
    cin.get(); //remove the leftover "new line" character from cin
    CourseSection sec(id, tl, cr, num);

    cout << "Input the info of all students in the section:\n";
    sec.fillRosterInfo();

    cout << "The following is the section info (course and students info):\n";
    sec.printSectionInfo();

    cout << "\nThe average GPA of the students in the section = ";
    sec.printAverageGPA();

    cout << "\nThe max GPA info: ";
    sec.printMaxGPAinfo();

    cout << "What major you want to print its students? "; cin >> mj;
    cout << "\nThe list of students in the major:\n";
    sec. printMajorStudents(mj);
    */
    return 0;
}