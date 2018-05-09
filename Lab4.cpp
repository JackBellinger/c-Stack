#include <iostream>
#include "Stack.h"
#include "Student.h"

using namespace std;
int menu()
{
    int response = 0;
    
    cout << "Menu:" << endl;
    cout << "1. Push a student to the stack" << endl;
    cout << "2. Delete a student from the stack" << endl;
    cout << "3. Print the top element of the stack" << endl;
    cout << "4. Stack type selection" << endl;
    cout << "Please input the option you would like: ";
    cin >> response;
    cout << "---------------------------------------" << endl;
    return response;
}
template <class DataType>
bool validateInput(int response, Stack<DataType>* stack)
/* returns a bool determining if the program should quit or not, 
 * true if the program should quit
*/
{
    bool quit = false;
    if(response >= 1 && response <= 5)
    {
        switch(response)
        {
            case 1:
            {
				cout << "new data" << endl;
                DataType* x = new DataType();
                addObj(stack, x);
                cout << string(100, '\n');
                break;
            }
            case 2:
            {
                cout << string(100, '\n');
                stack->pop();
                break;
            }
            case 3:
            {
                cout << string(100, '\n');
               	stack->topStack();
                break;
            }
            case 4:
            {
                cout << "back";
                quit = true;
                break;
            }
            
        }//end switch
    }
    else
        cout << string(100, '\n') << "Please enter a valid integer" << endl << endl;
      return quit;          
}
void addObj(Stack<int>* stack, int* x)
{
    cout << "What would you like to add? : ";
    cin >> *x;
    stack->push(*x);
}

void addObj(Stack<Student>*& stack, Student*& x)
{
    cout << "adding" << endl;
	x->inputData();
    stack->push(*x);
}

int main()
{
    Stack<int>* iStack = new Stack<int>();
    Stack<Student>* sStack = new Stack<Student>();
    
    cout << "Choose a stack type" << endl << "0. Student" << endl << "1. Integer" << endl;
    bool isIStack = 0;
    cin >> isIStack;
    
    cout << string(100, '\n');
    bool quit = false;
    while(!quit)//menu asks for which option, which returns the choice into validateInput, which returns if the program should quit
    {
        if(isIStack)
            quit = validateInput(menu(), iStack);
        else
            quit = validateInput(menu(), sStack);
        //stack->printStack();
    }
    return 0;
}

