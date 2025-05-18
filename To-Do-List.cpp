//To Do List Using Array
#include <iostream>
#include <string>
using namespace std;

int main() {
    string list[10]; 
    bool status[10] = {false};
    int taskCount = 0, choice, pos;

    do {
        cout<<"\n===== To-Do-List =====";
        cout << "\n1) Add Task";
        cout << "\n2) View Tasks";
        cout << "\n3) Delete Task";
        cout << "\n4) Mark Task Completed";
        cout << "\n5) Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                int newTasks;
                cout << "How many tasks do you want to add? ";
                cin >> newTasks;
                cin.ignore();

                if(taskCount + newTasks > 10) {
                    cout << "\nTask List is Full! Cannot add more tasks.\n";
                    cout<<"---------------------------------------\n";
                } else {
                    for(int i = 0; i < newTasks; i++) {
                        cout << "Enter Task " << taskCount + 1 << ": ";
                        getline(cin, list[taskCount]);
                        status[taskCount] = false;
                        taskCount++;
                    }
                }
                break;
            }
            case 2: {
                if(taskCount == 0) {
                    cout << "\nTask List is empty.\n";
                    cout<<"-------------------\n";
                } else {
                    cout << "\nTasks:\n";
                    for(int i = 0; i < taskCount; i++) {
                        cout << "Task " << i + 1 << " -> " 
                             << list[i] 
                             << " [" << (status[i] ? "Completed" : "Pending") << "]\n";
                    }
                }
                break;
            }
            case 3: {
                if(taskCount == 0) {
                    cout << "\nTask List is already empty.\n";
                    cout<<"---------------------------\n";
                    break;
                }

                cout << "Enter the position of the task you want to delete: ";
                cin >> pos;

                if(pos < 1 || pos > taskCount) {
                    cout << "\nInvalid position! Try again.\n";
                    cout<<"----------------------------\n";
                } else {
                    for(int i = pos - 1; i < taskCount - 1; i++) {
                        list[i] = list[i + 1];
                        status[i] = status[i + 1];
                    }
                    taskCount--;
                    cout << "\nTask deleted successfully.\n";
                    cout<<"--------------------------\n";
                }
                break;
            }
            case 4: {
                if(taskCount == 0) {
                    cout << "\nNo tasks to mark as completed.\n";
                    cout<<"-----------------------------\n";
                    break;
                }

                cout << "Enter the position of the task to mark as completed: ";
                cin >> pos;

                if(pos < 1 || pos > taskCount) {
                    cout << "\nInvalid position! Try again.\n";
                    cout<<"----------------------------\n";
                } else {
                    status[pos - 1] = true;
                    cout << "\nTask marked as completed.\n";
                    cout<<"-------------------------\n";
                }
                break;
            }
            case 5:
                cout << "Exiting... Goodbye!\n";
                cout<<"-------------------\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
                cout<<"----------------------------\n";
        }

    } while(choice != 5);

    return 0;
}
