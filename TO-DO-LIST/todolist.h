#ifndef TODOLIST_H
#define TODOLIST_H

    #include <iostream>
    #include <vector>
    #include <string>
    #include <limits>

    using namespace std;

    class Task
    {
    public:
        Task(const string &description);

        string getDescription() const;
        bool isCompleted() const;
        void markAsCompleted();
        void markAsPending();

    private:
        string description;
        bool completed;
    };

    class ToDoList
    {
    public:
        void addTask(const string &description);
        int viewTasks() const;
        void markTaskAsCompleted(int index);
        void removeTask(int index);

    private:
        vector<Task> tasks;
    };

#endif