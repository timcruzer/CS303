#include <string>
using namespace std;

class Employee {
    public:
    virtual double weeklySalary(int hoursworked, int hourlyrate);
    virtual int healthCare(int paycheck);
    virtual int vacationDays(int hoursworked);

    Employee(string firstname, string lastname);
};

class ProfessionalEmployee : public Employee { //subclass of Employee
    public:
    double weeklySalary(int hoursworked, int hourlyrate);
    int healthCare(int paycheck);
    int vacationDays(int hoursworked);

    ProfessionalEmployee(string firstname, string lastname, int hoursworked, int hourlyrate) : Employee(firstname, lastname){

    }
};

class NonProfessionalEmployee : public Employee { //subclass of Employee
    public:
    double weeklySalary(int hoursworked, int hourlyrate);
    int healthCare(int paycheck);
    int vacationDays(int hoursworked);

    NonProfessionalEmployee(string firstname, string lastname, int hoursworked, int hourlyrate) : Employee (firstname, lastname){

    }
};
