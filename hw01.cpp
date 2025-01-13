//Evan Moncheck : 002905615 : no special compiling instructions 
    
//basic header for a c++ program to include necessary functions and simplify print statements.
#include <iostream>
#include <string>
using namespace std;

//the person class is a parent class with some attributes of a person and 
//functions for creating an object and accessing the attributes
class Person
{
    //the three private variables were outlined in the homework assignment instructions
    private:
        string fullname;
        string address;
        int age;

    //the public functions were outlined in the homework assignment instructions
    //the functions allow for the creation of new person objects and for the user to access the private variables
    public:

        //used to store values in the private variables of the class
        void readPersonInfo()
        {
            //cin.ignore is used to disregard any "spaces" left over from previous user keyboard entries
            cin.ignore();

            //store name in private variable
            cout << "Enter the name of the person: ";
            getline(cin, fullname);

            //store address in private variable
            cout << "Enter the address of the person: ";
            getline(cin, address);  

            //store age in private variable
            cout << "Enter the age of the person: ";
            cin >> age;

            // Age verified to be between 9 and 99
            while (age < 9 || age > 99) 
            {
                //prompt user to keep overwriting age until it falls between bounds
                cout << endl << "Invalid age. Please enter an age between 9 and 99: ";
                cin >> age;
            }

            // Clear the input buffer before the next getline (important if any further getline calls are used)
            cin.ignore();  // This clears the newline character left in the input buffer

            //prints when all person attributes are successfully filled
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

//subclass of person. Primary purpose is to provides unique student attributes
class Student : public Person
{
    //private variables as define in homework asignment instructions
    private:
        string ID;
        string major;
        float gpa;

    //public functions implemented as defined in homework assignment instructions
    //provides user the ability to create student object with attributes and access these attributes
    public:

        //first calls the base class function readPersonInfo() to assign person attributes 
        //then stores user inputs into the student attributes
        void readStudentInfo()
        {
            readPersonInfo();
            cout << "Enter the student's ID: ";    cin >> ID;
            cout << "Enter the student's major: ";    cin >> major;
            cout << "Enter the student's GPA: ";    cin >> gpa;

            //prints after student attributes are assigned successfully
            cout << "Student attributes assigned successfully to " << personName() << endl << endl;
        }

        //first calls the base class function printPersonInfo, 
        //then prints the above student’s three private attributes
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

//the course class is a parent class with some attributes of a course and 
//functions for creating an object and printing the attributes
class Course
{
    //private attributes as defined in homework assignment instructions
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

            //prints after course attributes assigned successfully
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

//subclass of course. Provides unique course section attributes and functions to dynamically assign
//students in memory. contains functions to obtain data from all students in section
class CourseSection : public Course
{
    //private attributes as defined in homework assignment instructions
    private:
        int sectionSize;
        //roster defined as pointer to a student object in memory used to create an array of students
        //dynamically allocated in memory
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
            //assume first student has highest gpa
            float tempMAX = roster[0].studentGPA();
            for(int x=1; x < sectionSize; x++)
            {
                //overwrite max gpa each time a new highest one is found
                if(roster[x].studentGPA()>tempMAX)
                {
                    tempMAX = roster[x].studentGPA();
                }
            }
            //return the highest gpa found associated with a student
            cout << "The highest GPA is: " << tempMAX << endl;
        }

        //prints info of the students in the section who are from major mjr
        void printMajorStudents(string mjr)
        {
            for(int x=0; x < sectionSize; x++)
            {
                //sort through array of students. everytime a student with the desired major is found, the 
                //printStudentInfo() function is called for the student
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

//used to test functionality of each class
int main() 
{
    //variables for user to pass information to create classes and call functions
    int num, cr;
    string id, tl, mj;

    //prompt user for information to create a course section
    cout << "What is the Course ID? "; cin >> id;
    cout << "What is the Course title? "; cin >> tl;
    cout << "How many credits is the course? "; cin >> cr;
    cout << "How many students are in the section? "; cin >> num;
    //create a course section
    CourseSection sec(id, tl, cr, num);
    //fill course section with students
    sec.fillRosterInfo();

    //call the printSectionInfo() function for the created course section
    //displays information about the course and the students in the section
    cout << "The following is the section info (course and students info):\n";
    sec.printSectionInfo();
    cout << endl;

    //The average GPA of the students in the section
    cout << "\nOutput of the printAverageGPA() function:\n";
    sec.printAverageGPA();
    cout << endl;

    //The max GPA info
    cout << "Output of the printMaxGPAinfo() function:\n";
    sec.printMaxGPAinfo();
    cout << endl;

    //displays information about the students with the desired major in the specific course section
    cout << "What major you want to print its students? "; cin >> mj;
    cout << "\nThe list of students in the major:\n";
    sec. printMajorStudents(mj);
    
    return 0;
    //course section falls out of scope and course destructor is called
 }