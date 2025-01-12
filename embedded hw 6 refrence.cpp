/*
  include statements are used tell the compiler and linker about the libraries to use for the code
  namespace std used to simplify the cout lines and make it easier to print outputs
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
using namespace std;


double* vector;     // Pointer to the array
int capacity;       // Current capacity of the array
int size;           // Number of elements currently stored in the array
    
// store initial values to the global variables
void Initialize()  
{
  capacity = 2;
  size = 0;
  vector = new double[capacity];  // Allocate initial memory
}

// free the memory used for the vector
void Finalize() 
{
  delete[] vector;
}


// function used to grow the array
void Grow() 
{
  capacity *= 2;  // Double the capacity
  double* bigger = new double[capacity];  // Allocate new larger array

  // Copy old array data to the new array
  for (int i = 0; i < size; i++) 
  {
    bigger[i] = vector[i];
  }

  // Delete old array and point vector to the new one
  delete[] vector;
  vector = bigger;
}


// function to add an element to the array
void AddElement(double value)
{
  if (size == capacity) 
  {
    // Need to resize the array if it's full
    cout << "Vector capacity doubled." << endl << endl << "Previous Capacity: " << capacity << endl << endl << "New capacity: " << (capacity*2) << endl << endl;
    Grow();
  }
  
  //place the new value at the end
  vector[size] = value;
  //increase the stored size of the array
  size++;
}


// function to remove last element of the array
void RemoveElement()
{
  //check to make sure there are elements in the dynamic array
  if (size == 0)
  {
    cout << "There are no elements in the vector." << endl << endl;
  }
  else
  {
    //set the last element to a zero to represent it being removed
    vector[size] = 0;
    //decreasing the size by one means that the last value, 0, will not be shown when the vector is printed. it also means it will be overwritten when a new value is appended to the dynamic array
    size--;
    cout << "Last element removed successfully." << endl << endl;

  }
}


// Method to print all elements in the array
void PrintVector()
{
  //simple loop through the array and print value at every index from 0 to size-1
  for (int i = 0; i < size; i++) 
  {
    cout << vector[i] << " ";
  }
  cout << endl;
}

//two inputs, the element being added and where its being added
void InsertElement(int index, double value)
{
  //check to make sure the chosen index is acceptable
  if (index < 0 || index > size) 
  {
    cout << "Invalid index. Please enter a value between 0 and " << size << "." << endl << endl;
    return;
  }

  //check to see if there is room in the current vector to add another element
  if (size == capacity) 
  {
    Grow();  // grow the vector if all values are currently filled
  }

  // Shift elements after the chosen index to the right to make space for the new element
  //loop starts at the end (size) and moves backwards through the vector
  for (int i = size; i > index; i--) 
  {
    vector[i] = vector[i - 1];
  }

  // Insert the new element at the specified index
  vector[index] = value;
  size++;

  cout << "Element " << value << " inserted at index " << index << "." << endl << endl;
}


//the main function is what executes when ./a.out is entered into the terminal. it calls the other functions of the code and is the top of the food chain if programs were carniverous
main()
{
  //initialize the choice variable so the while loop works
  int choice = 0;
  Initialize();
  // loop through user inputs until the user decides to exit the code
  while (choice != 5)
  {
    
    
    // display the main menu and list options
    cout << "Main menu:" << endl << "    1. List vector's contents" << endl << "    2. Append element at the end" << endl << "    3. Remove Last Element"    << endl << "    4. Insert one element" << endl << "    5. Exit" << endl << "Select an option: " ;
    cin >> choice;
    cout << endl;
            
    switch (choice)
    {
      case 1:
        cout << "You selected 'List vector's contents'." << endl << endl;
        
        //check to see if there is anything to print
        if (size == 0)
        {
          cout << "There are no doubles in the vector." << endl << endl;
        }
        else
        {
          //call print vector function when there are doubles in the vector to print
          PrintVector();
          cout << endl;
        }  
        
        break;
          
      case 2:
        cout << "You selected 'Appent element at the end'" << endl << endl << "What value do you want to add to the vector?: " ;
        double newValue;
        if(cin >> newValue)
        {
          //if the new element to add is a double, call the AddElement function and pass the new element to it
          AddElement(newValue);
          cout << "New element successfully added." << endl << endl;
        }
        else
        {
          // Clear the error state
          cin.clear();
          // Ignore any remaining characters in the input buffer
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Make sure to add a numerical value in the form of a double." << endl << endl;
          //see https://cplusplus.com/forum/beginner/70462/ for the resource I used to write the default case to not break with string inputs
        }
        
        break;
      
      case 3:
        cout << "You selected 'Remove Last Element'" << endl << endl;
        //call the remove element function. the remove element function has the necessary tests contained within it to make sure it does not try to remove an element if the size is 0
        RemoveElement();
        
        break;
        
      case 4:
        cout << "You selected 'Insert one element'" << endl << endl;
        
        int index;
        double value;
        
        //ask the user for the new element and the index it goes to
        cout << "Enter the index where you want to insert the element: ";
        cin >> index;
        cout << "Enter the value to insert at index " << index << ": ";
        if (cin >> value)
        {
          //if the values make sense for the code, call the InsertElement function and pass these values to it.
          InsertElement(index, value);
        }
        else
        {
          //same code as above to handle error if user tries to add a value like a character
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input. Please enter a numerical value." << endl << endl;
        }

        break;
        
      case 5:
        // when the user leaves the program, calling finalize deletes the array to free the memory being used to store it
        Finalize();
        break;

      default:
        // Clear the error state
        cin.clear();
        // Ignore any remaining characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid option selection. Please enter an integer between 1 and 5 inclusive." << endl << endl;
        break;
    } 
  }
}