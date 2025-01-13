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

        void readPersonInfo()
        {
            cin.ignore();
            cout << "Enter the name of the person: ";
            getline(cin, fullname);  // This reads the full name, even if it has spaces

            cout << "Enter the address of the person: ";
            getline(cin, address);  // This reads the full address, even if it has spaces

            cout << "Enter the age of the person: ";
            cin >> age;

            // Age verified to be between 9 and 99
            while (age < 9 || age > 99) 
            {
                cout << endl << "Invalid age. Please enter an age between 9 and 99: ";
                cin >> age;
            }

            // Clear the input buffer before the next getline (important if any further getline calls are used)
            cin.ignore();  // This clears the newline character left in the input buffer

            cout << "Person attributes assigned successfully." << endl << endl;
        }

        //prints the three private Person variables
        void printPersonInfo()
        {
            cout << "Person's Name: " << fullname << endl;
            cout << "Person's Address: " << address << endl;
            cout << "Person's Age: " << age << endl;
        }

        //returns person's age
        int personAGE(){return age;}

        //returns person's name
        string personName(){return fullname;}
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
            readPersonInfo();
            cout << "Enter the student's ID: ";    
            cin >> ID;
            cout << "Enter the student's major: ";    
            cin >> major;
            cout << "Enter the student's GPA: ";    
            cin >> gpa;
            cout << "Student attributes assigned successfully to " << personName() << endl << endl;
        }

        /*  first calls the base class function printPersonInfo, 
            then prints the above student’s three private attributes
        */
        void printStudentInfo()
        {
            printPersonInfo();
            cout << "Student's ID: " << ID << endl;
            cout << "Student's Major: " << major << endl;
            cout << "Student's GPA: " << gpa << endl;
        }

        //returns the student’s GPA
        float studentGPA(){return gpa;}

        //returns the student’s Major
        string studentMajor(){return major;}
};

class Course
{
    private:

        string ID;
        string title;
        int credits;

    public:

        //a constructor that is used to fill the data of the Course’s three private attributes.
        Course(string i, string t, int c)
        {
            ID = i;
            title = t;
            credits = c;
            cout << "Course created successfully." << endl << endl;
        }

        //displays the above Course’s three private attributes
        void printCourse()
        {
            cout << "Course ID: " << ID << endl;
            cout << "Course Title: " << title << endl;
            cout << "Course Credit Hours: " << credits << endl;
        }
};

class CourseSection : public Course
{
    private:
    
        //Number of students enrolled in the section
        int sectionSize;
        //to store a list of Student objects representing the students enrolled in the section
        Student* roster;

    public:

        //a constructor that takes as argument the three attributes of the Course to which the
        //section belongs as well as the section size. First, this constructor invokes the base
        //class (Course) constructor using the course three attributes. Then it dynamically
        //creates the array needed for the roster attribute with size sectionSize.
        
        CourseSection(string iden, string ttl, int cr, int num) : Course(iden, ttl, cr) 
        {    
            sectionSize = num;
            roster = new Student[sectionSize];
        }
        
        // a destructor to delete any dynamically allocated memory
        ~CourseSection()
        {
            delete[] roster;
        }

        // reads the info of all students in the section one at a time,
        // using readStudentInfo(). After reading the info of a student object, insert it
        // in the roster list
        void fillRosterInfo()
        {
            
            for(int x=0; x < sectionSize; x++)
            {
                Student temp = Student();
                temp.readStudentInfo();
                roster[x] = temp;
            }
        }

        //prints the average GPA of the students in the section
        void printAverageGPA()
        {
            float tempSUM = roster[0].studentGPA();
            for(int x=1; x < sectionSize; x++)
            {
                tempSUM += roster[x].studentGPA();
            }
            cout << "The average GPA of the students in the section: " << tempSUM/sectionSize << endl;
        }

        //prints the max GPA and the student info with that GPA
        //Assume there is no more than one student with such max GPA.
        void printMaxGPAinfo()
        {
            float tempMAX = roster[0].studentGPA();
            for(int x=1; x < sectionSize; x++)
            {
                if(roster[x].studentGPA()>tempMAX)
                {
                    tempMAX = roster[x].studentGPA();
                }
            }
            cout << "The highest GPA is: " << tempMAX << endl;
        }

        //prints info of the students in the
        //section who are from major mjr
        void printMajorStudents(string mjr)
        {
            for(int x=0; x < sectionSize; x++)
            {
                if(roster[x].studentMajor()==mjr)
                {
                    roster[x].printStudentInfo();
                }
                cout << endl;
            }
        }

        //prints the section info starting with its course info,
        //followed by printing the info of all students in the section
        void printSectionInfo()
        {
            printCourse();
            printAverageGPA();
            printMaxGPAinfo();
        }
};

int main() 
{
    
    int num, cr;
    string id, tl, mj;
    /*
    cout << "What is the Course ID? "; cin >> id;
    cout << "What is the Course title? ";
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

    
    
        
    cout << "What is the Course ID? "; cin >> id;
    cout << "What is the Course title? "; cin >> tl;
    cout << "How many credits is the course? "; cin >> cr;
    cout << "How many students are in the section? "; cin >> num;
    CourseSection sec(id, tl, cr, num);
    sec.fillRosterInfo();

    cout << "The following is the section info (course and students info):\n";
    sec.printSectionInfo();
    cout << endl;

    //The average GPA of the students in the section
    sec.printAverageGPA();
    cout << endl;

    //The max GPA info
    sec.printMaxGPAinfo();
    cout << endl;

    cout << "What major you want to print its students? "; cin >> mj;
    cout << "\nThe list of students in the major:\n";
    sec. printMajorStudents(mj);
        
    return 0;


 }