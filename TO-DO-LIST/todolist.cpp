#include "todolist.h"

Task::Task(const string &description)
    : description(description), completed(false) {}

string Task::getDescription() const
{
    return description;
}

bool Task::isCompleted() const
{
    return completed;
}

void Task::markAsCompleted()
{
    completed = true;
}

void Task::markAsPending()
{
    completed = false;
}

void ToDoList::addTask(const string &description)
{
    tasks.emplace_back(description);
}

int ToDoList::viewTasks() const
{
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
        return -1;
    }

    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].getDescription();
        if (tasks[i].isCompleted())
        {
            cout << " [Completed]";
        }
        else
        {
            cout << " [Pending]";
        }
        cout << endl;
    }
    return 1;
}

void ToDoList::markTaskAsCompleted(int index)
{
    if (index < 0 || static_cast<size_t>(index) >= tasks.size())
    {
        cout << "Invalid task index." << endl;
        return;
    }
    tasks[index].markAsCompleted();
}

void ToDoList::removeTask(int index)
{
    if (index < 0 || static_cast<size_t>(index) >= tasks.size())
    {
        cout << "Invalid task index." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index);
}
