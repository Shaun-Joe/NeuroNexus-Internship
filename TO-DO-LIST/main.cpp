#include "todolist.h"

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntegerInput()
{
    int number;
    while (!(cin >> number))
    {
        clearInputBuffer();
        cout << "Invalid input. Please enter an integer: ";
    }
    clearInputBuffer();
    return number;
}

void displayMenu()
{
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main()
{
    ToDoList todoList;
    int choice;

    while (true)
    {
        displayMenu();
        choice = getIntegerInput();

        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Enter task description: ";
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case 2:
        {
            todoList.viewTasks();
            break;
        }
        case 3:
        {
            if (todoList.viewTasks() == -1)
                break;
            cout << "Enter task number to mark as completed: ";
            int taskNumber = getIntegerInput() - 1;
            todoList.markTaskAsCompleted(taskNumber);
            break;
        }
        case 4:
        {
            if (todoList.viewTasks() == -1)
                break;
            cout << "Enter task number to remove: ";
            int taskNumber = getIntegerInput() - 1;
            todoList.removeTask(taskNumber);
            break;
        }
        case 5:
        {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}
