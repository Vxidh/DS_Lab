#include <iostream>
using namespace std;

class Employee {
public:
    int Employee_Number;
    char Employee_Name[100];
    float Basic, DA, IT, Net_Sal, Gross_Salary;

    void dataa() {
        cout << "Enter Employee number: ";
        cin >> Employee_Number;
        cin.ignore();

        cout << "Enter Employee Name: ";
        cin.getline(Employee_Name, 100);

        cout << "Enter Basic Salary: ";
        cin >> Basic;

        DA = 0.12 * Basic;
        Gross_Salary = Basic + DA;
        IT = 0.18 * Gross_Salary;
        Net_Sal = Gross_Salary - IT;

        cout << "Employee Number: " << Employee_Number << endl;
        cout << "Employee Name: " << Employee_Name << endl;
        cout << "Basic Salary: " << Basic << endl;
        cout << "DA: " << DA << endl;
        cout << "Gross Salary: " << Gross_Salary << endl;
        cout << "IT: " << IT << endl;
        cout << "Net Salary: " << Net_Sal << endl;
        cout << endl;
    }
};

int main() {
    int N;
    cout << "Enter the number of employees: ";
    cin >> N;

    Employee employees[N];
    for (int i = 0; i < N; ++i) {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        employees[i].dataa();
    }

    return 0;
}
