#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Complete\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option (1-5): ";
}

void addTask(std::vector<Task>& tasks) {
    std::cin.ignore(); // clear input buffer
    std::string desc;
    std::cout << "Enter task description: ";
    std::getline(std::cin, desc);
    tasks.push_back(Task(desc));
    std::cout << "Task added.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << "\n";
    }
}

void markComplete(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark.\n";
        return;
    }

    viewTasks(tasks);
    size_t index;
    std::cout << "Enter task number to mark as complete: ";
    std::cin >> index;

    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as complete.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove.\n";
        return;
    }

    viewTasks(tasks);
    size_t index;
    std::cout << "Enter task number to remove: ";
    std::cin >> index;

    if (index < 1 || index > tasks.size()) {
        std::cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markComplete(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter 1–5.\n";
        }
    } while (choice != 5);

    return 0;
}
