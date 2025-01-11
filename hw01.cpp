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
            cout << "Enter the name of the person: " ;
            cin >> fullname ;
            cout << endl << "Enter the address of the person: ";
            cin >> address;
            cout << endl << "Enter the age of the person: ";
            cin >> age;

            //age verified to be between 9 and 99
            while(age < 9 || age > 99)
            {
                cout << endl << "Invalid age. Please enter an age between 9 and 99.";
                cin >> age;
            }

            cout << endl << "Person attributes assigned successfully.";
        }

        //prints the three private Person variables
        void printPersonInfo()
        {
            cout << "name: " << fullname << endl;
            cout << "address: " << address << endl;
            cout << "age: " << age << endl;
        }

        //returns person's age
        int personAGE()
        {
            return age;
        }

        //returns person's name
        string personName()
        {
            return fullname;
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

        //displays the above Course’s three private attributes
        void printCourse()
        {

        }

        //add a constructor that is used to fill the data of the Course’s three private attributes.
        Course()
        {
            
        }

};

class CourseSection : public Course
{
    private:
        //Number of students enrolled in the section
        int sectionSize;
        //to store a list of Student objects representing the students enrolled in the section
        Student *roster;

    public:

        // reads the info of all students in the section one at a time,
        // using readStudentInfo(). After reading the info of a student object, insert it
        // in the roster list
        void fillRosterInfo()
        {

        }

        //prints the section info starting with its course info,
        //followed by printing the info of all students in the section
        void printSectionInfo()
        {

        }

        //prints the average GPA of the students in the section
        void printAverageGPA()
        {

        }

        //prints the max GPA and the student info with that GPA
        //Assume there is no more than one student with such max GPA.
        void printMaxGPAinfo()
        {

        }

        //prints info of the students in the
        //section who are from major mjr
        void printMajorStudents(string mjr)
        {

        }

        ///a constructor that takes as argument the three attributes of the Course to which the
        //section belongs as well as the section size. First, this constructor invokes the base
        //class (Course) constructor using the course three attributes. Then it dynamically
        //creates the array needed for the roster attribute with size sectionSize.
        /// a destructor to delete any dynamically allocated memory
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