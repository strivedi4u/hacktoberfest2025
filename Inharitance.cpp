#include <bits/stdc++.h>
using namespace std;

// single inharitance

class Human
{
protected:
    string name;
    int age;

public:
    void introduce()
    {
        cout << "Hello my name is : " << name << endl;
    }
};

class employee : public Human
{
protected:
    int salary;

public:
    void monthlySalary()
    {
        cout<<"My monthly salary is : "<< salary<<endl;
    }
    
};


// Multilevel inharitance

class Manager : public employee{
    public:
    string department;

    Manager(string name, int age, int salary, string department)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
        this -> department = department;
    }
    void display()
    {
        cout<< "Name = "<<name<<" Age = "<<age<<" Year "<<" Salary = "<<salary<<" Department = "<<department<<endl;
    }

    void work(){
        cout<< " I am leading the department of : "<<department<<endl;
    }

};






// Multiple inharitance

class Engineer{
    
};
int main()
{
    employee A1("Massao", 5, 40000);
    A1.display();
    A1.introduce();

    Manager A2("Shinchan", 5, 80000, "IT");
    A2.work();
    A2.monthlySalary();
    A2.display();
    A2.introduce();
    A2.department = "Sales";
    A2.display();
    A2.work();
    return 0;
};
