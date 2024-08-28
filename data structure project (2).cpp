#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Employee {
public:
    string id, name, address, dob, mobile_no, doj, marstatus, workd, workl, ctc, socialins, email;
    Employee(string id, string name, string address, string dob, string mobile_no, string doj, string marstatus, string workd, string workl, string ctc, string socialins, string email) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->dob = dob;
        this->mobile_no = mobile_no;
        this->doj = doj;
        this->marstatus = marstatus;
        this->workd = workd;
        this->workl = workl;
        this->ctc = ctc;
        this->socialins = socialins;
        this->email = email;
    }

    void display() const {
        cout << "** PERSONAL DETAILS **" << endl;
        cout << "Full Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Marital Status: " << marstatus << endl;
        cout << "** WORK DETAILS **" << endl;
        cout << "Id: " << id << endl;
        cout << "Date of Joining: " << doj << endl;
        cout << "Work Department: " << workd << endl;
        cout << "Work Location: " << workl << endl;
        cout << "CTC: " << ctc << endl;
        cout << "Social Insurance: " << socialins << endl;
        cout << "** CONTACT DETAILS **" << endl;
        cout << "Mobile NO: " << mobile_no << endl;
        cout << "Email Id: " << email << endl;
    }
};

vector<Employee> employees;

void enter() {
    int ch;
    cout << "How Many Employees' Data Do You Want to Enter?" << endl;
    cin >> ch;
    for (int i = 0; i < ch; i++) {
        string id, name, address, dob, mobile_no, doj, marstatus, workd, workl, ctc, socialins, email;
        cout << "\nEnter the Data of Employee " << i + 1 << endl;
        cout << "** PERSONAL DETAILS **" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Enter Mobile No: ";
        cin >> mobile_no;
        cout << "Enter Date of Joining: ";
        cin >> doj;
        cout << "Enter Marital Status: ";
        cin >> marstatus;
        cout << "** WORK DETAILS **" << endl;
        cout << "Enter Work Department: ";
        cin >> workd;
        cout << "Enter Work Location: ";
        cin >> workl;
        cout << "Enter CTC: ";
        cin >> ctc;
        cout << "Enter Social Insurance: ";
        cin >> socialins;
        cout << "Enter Email Id: ";
        cin >> email;
        employees.push_back(Employee(id, name, address, dob, mobile_no, doj, marstatus, workd, workl, ctc, socialins, email));
    }
}

void update_employee() {
    string id;
    cout << "Enter the ID of the employee you want to update: ";
    cin >> id;
    for (auto &emp : employees) {
        if (emp.id == id) {
            cout << "Enter new details for the employee: " << endl;
            cout << "Enter Name: ";
            cin >> emp.name;
            cout << "Enter Address: ";
            cin >> emp.address;
            cout << "Enter Date of Birth: ";
            cin >> emp.dob;
            cout << "Enter Mobile No: ";
            cin >> emp.mobile_no;
            cout << "Enter Date of Joining: ";
            cin >> emp.doj;
            cout << "Enter Marital Status: ";
            cin >> emp.marstatus;
            cout << "Enter Work Department: ";
            cin >> emp.workd;
            cout << "Enter Work Location: ";
            cin >> emp.workl;
            cout << "Enter CTC: ";
            cin >> emp.ctc;
            cout << "Enter Social Insurance: ";
            cin >> emp.socialins;
            cout << "Enter Email Id: ";
            cin >> emp.email;
            cout << "Employee details updated successfully." << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found." << endl;
}

void delete_employee() {
    string id;
    cout << "Enter the ID of the employee you want to delete: ";
    cin >> id;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == id) {
            employees.erase(it);
            cout << "Employee deleted successfully." << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found." << endl;
}

void search_employee() {
    string id;
    cout << "Enter the ID of the employee you want to search: ";
    cin >> id;
    for (const auto &emp : employees) {
        if (emp.id == id) {
            emp.display();
            return;
        }
    }
    cout << "Employee with ID " << id << " not found." << endl;
}

void display_all_employees() {
    for (const auto &emp : employees) {
        emp.display();
    }
}

void sort_employees() {
    cout << "Choose a sorting criteria: 1) Name 2) ID 3) Salary 4) Date of Joining" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
                return a.name < b.name;
            });
            break;
        case 2:
            sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
                return a.id < b.id;
            });
            break;
        case 3:
            sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
                return a.ctc < b.ctc;
            });
            break;
        case 4:
            sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b) {
                return a.doj < b.doj;
            });
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }
    cout << "Employees sorted successfully." << endl;
}

void generate_report() {
    cout << "Choose a report type: 1) All Employees 2) By Salary Range" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            display_all_employees();
            break;
        case 2: {
            float min_salary, max_salary;
            cout << "Enter minimum salary: ";
            cin >> min_salary;
            cout << "Enter maximum salary: ";
            cin >> max_salary;
            for (const auto &emp : employees) {
                if (stof(emp.ctc) >= min_salary && stof(emp.ctc) <= max_salary) {
                    emp.display();
                }
            }
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            return;
    }
}

void guest_mode() {
    cout << "Guest Mode:" << endl;
    cout << "1) Search Employee 2) Generate Report" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            search_employee();
            break;
        case 2:
            generate_report();
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }
}

void admin_mode() {
    cout << "Admin Mode:" << endl;
    cout << "1) Add Employee 2) Update Employee 3) Delete Employee 4) Search Employee 5) Display All Employees 6) Sort Employees 7) Generate Report" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            enter();
            break;
        case 2:
            update_employee();
            break;
            
        case 3:
            delete_employee();
            break;
        case 4:
            search_employee();
            break;
        case 5:
            display_all_employees();
            break;
        case 6:
            sort_employees();
            break;
        case 7:
            generate_report();
            break;
        default:
            cout << "Invalid choice." << endl;
            return;
    }
}

int main() {
    while (true) {
        cout << "Choose User Mode: 1) Admin 2) Guest 3) Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                admin_mode();
                break;
            case 2:
                guest_mode();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}

/*
 1 - enter():

Job: This function prompts the user to enter data for a specified number of employees and adds each employee to the employees vector.
It gathers personal, work, and contact details for each employee.
 
 2 - update_employee():

Job: This function allows the user to update the details of an existing employee by searching for the employee using their ID.
If the ID is found, it prompts the user to enter new data, updating the employee's information.
 
 3 - delete_employee():

Job: This function deletes an employee from the employees vector by their ID. If the ID matches an employee,
that employee is removed from the list.

 4 - search_employee():

Job: This function searches for an employee by their ID and displays their details if found. If the employee is not found,
it notifies the user.
 
 5 - display_all_employees():

Job: This function iterates over the employees vector and displays the details of every employee stored in it.

 6 - sort_employees():

Job: This function sorts the employees in the employees vector based on a user-selected criterion (e.g., name, ID, salary,
or date of joining). It uses the C++ sort() function with appropriate comparison logic for each criterion.
 
 7 - generate_report():

Job: This function generates and displays a report of employees based on the user's choice. 
It can either show all employees or filter them by a specified salary range.
 
 8 - guest_mode():

Job: This function provides a simplified interface for guests,
allowing them to search for an employee by ID or generate a report (all employees or by salary range).
 
 9 - admin_mode():

Job: This function provides a more comprehensive interface for administrators, 
giving them access to all functions: adding, updating, deleting, searching, displaying, sorting employees, and generating reports.
 
 10 - main():

Job: The entry point of the program. It continuously prompts the user to select between Admin mode, Guest mode,
or exiting the program. Based on the user's selection, it calls the appropriate function (either admin_mode(), 
guest_mode(), or exits the program).

*/



















