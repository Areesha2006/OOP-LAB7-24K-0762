#include<iostream>
using namespace std;
class Student;
class Course{
    int courseid,credits,numStudents=0;
    string instructor,schedule;
    Student *students[100];
    public:
        string courseName;
        Course(int id,int credits,string name,string instructor,string schedule):courseid(id),courseName(name),instructor(instructor),schedule(schedule){}
        void registerStudent(Student &s){
            students[numStudents]=&s;
            numStudents++;
            cout<<"Studnet registered successfully"<<endl;
        }
        void calculateGrade(Student &s){
            int found=0;
            for (int i = 0; i < 100; i++)
            {
                if(students[i]==&s){
                    found=1;
                    break;
                }    
            }
            if(!found){
                cout<<"No such student is registered in this course";
            }
            else{
                int marks;
                cout<<"Enter your marks: ";
                cin>>marks;
                cout<<"Grade: ";
                if(marks>=80){
                    cout<<"A+";
                }
                else if(marks>=70){
                    cout<<"A";
                }
                else if(marks>=60){
                    cout<<"B";
                }
                else if(marks>=50){
                    cout<<"C";
                }
                else if(marks>=40){
                    cout<<"D";
                }
                else{
                    cout<<"Fail";
                }
                cout<<endl;
            }
        }
};
class Person{
    int id;
    string name,address,phoneNumber,email;
    public:
        Person(int id,string name,string add,string phone,string email){
            this->id=id;
            this->name=name;
            address=add;
            phoneNumber=phone;
            this->email=email;
        }
        virtual void displayInfo(){
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Phone Number: "<<phoneNumber<<endl;
            cout<<"Email: "<<email<<endl;
        }
        void updateInfo(){
            cout<<"Enter ID: ";
            cin>>id;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Ennter address: ";
            cin>>address;
            cout<<"Enter phone number: ";
            cin>>phoneNumber;
            cout<<"Enter email: ";
            cin>>email;
        }
};
class Student: public Person{
    int enrollmentYear,numCourses;
    float GPA;
    Course *coursesEnrolled[20];
    public:
        Student(int id,string name,string add,string phone,string email,float gpa,int year,Course *courses[],int n):Person(id,name,add,phone,email),GPA(gpa),enrollmentYear(year){
            numCourses=n;
            for(int i=0;i<n;i++){
                coursesEnrolled[i]=*(courses+i);
            }
        }
        void displayInfo(){
            Person::displayInfo();
            cout<<"Enrollment Year: "<<enrollmentYear<<endl;
            cout<<"Courses Enrolled"<<endl;
            for (int i = 0; i < numCourses; i++)
            {
                cout<<"\t"<<i+1<<". "<<coursesEnrolled[i]->courseName<<endl;
            }
            cout<<"GPA: "<<GPA<<endl;
        }
};
class Professor: public Person{
    int salary,numCourses;
    string department;
    Course *coursesTaught[20];
    public:
        Professor(int id,string name,string add,string phone,string email,string dept,int sal,Course *courses[],int n):Person(id,name,add,phone,email),department(dept),salary(sal){
            numCourses=n;
            for(int i=0;i<n;i++){
                coursesTaught[i]=courses[i];
            }
        }
        void displayInfo(){
            Person::displayInfo();
            cout<<"Department: "<<department<<endl;;
            cout<<"Cources Taught"<<endl;
            for (int i = 0; i < numCourses; i++)
            {
                cout<<"\t"<<i+1<<". "<<coursesTaught[i]->courseName<<endl;
            }
            cout<<"Salary: "<<salary<<endl;
        }
};
class Staff: public Person{
    int salary;
    string department,position;
    public:
        Staff(int id,string name,string add,string phone,string email,string dept,int sal,string pos):Person(id,name,add,phone,email),department(dept),salary(sal),position(pos){}
        void displayInfo(){
            Person::displayInfo();
            cout<<"Department: "<<department<<endl;;
            cout<<"Position: "<<position<<endl;
            cout<<"Salary: "<<salary<<endl;
        }
};
int main(){
    Course *courses[100];
    Person *person;
    int num,year,person_id,n,credits,course_id,salary;
    float gpa;
    string pos,dept,person_name,address,phoneNumber,email,course_name,instructor,schedule;
    cout<<"Enter ID of the student: ";
    cin>>person_id;
    cout<<"Enter name of the student: ";
    cin>>person_name;
    cout<<"Ennter address of the student: ";
    cin>>address;
    cout<<"Enter phone number of the student: ";
    cin>>phoneNumber;
    cout<<"Enter email of student: ";
    cin>>email;
    cout<<"Enter your GPA: ";
    cin>>gpa;
    cout<<"Enter your enrollement year: ";
    cin>>year;
    cout<<"In how many courses are you enrolled in: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"For course "<<i+1<<endl;        
        cout<<"Enter ID of the course: ";
        cin>>course_id;
        cout<<"Enter name of the course: ";
        cin>>course_name;
        cout<<"Enter no of credits: ";
        cin>>credits;
        cout<<"Enter the instructor: ";
        cin>>instructor;
        cout<<"Enter the schedule: ";
        cin>>schedule;
        cout<<endl;
        courses[i]=new Course(course_id,credits,course_name,instructor,schedule);
    }
    Student s(person_id,person_name,address,phoneNumber,email,gpa,year,courses,n);
    for (int i = 0; i < n; i++)
    {
        courses[i]->registerStudent(s);
    }
    person=&s;
    cout<<"Displaying student;s details"<<endl;
    person->displayInfo();
    cout<<"Calculaing grade of each course"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"For course "<<i+1<<endl;
        courses[i]->calculateGrade(s);
        cout<<endl;
    }
    char update;
    cout<<"Do you want to uodate your personal information (Enter 'y' or 'Y' for yes or else anything for no): ";
    cin>>update;
    while(update=='y'||update=='Y'){
        person->updateInfo();
        cout<<"Displaying updated information: "<<endl;
        person->displayInfo();
        cout<<"Do you want to uodate your personal information again(Enter 'y' or 'Y' for yes or else anything for no): ";
        cin>>update;
    }
    num=n;
    cout<<endl<<"Enter ID of the professor: ";
    cin>>person_id;
    cout<<"Enter name of the professor: ";
    cin>>person_name;
    cout<<"Ennter address of the professor: ";
    cin>>address;
    cout<<"Enter phone number of the professor: ";
    cin>>phoneNumber;
    cout<<"Enter email of professor: ";
    cin>>email;
    cout<<"Enter your department: ";
    cin>>dept;
    cout<<"Enter your salary: ";
    cin>>salary;
    cout<<"How many courses do you teach: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"For course "<<i+1<<endl;        
        cout<<"Enter ID of the course: ";
        cin>>course_id;
        cout<<"Enter name of the course: ";
        cin>>course_name;
        cout<<"Enter no of credits: ";
        cin>>credits;
        cout<<"Enter the schedule: ";
        cin>>schedule;
        cout<<endl;
        courses[i]=new Course(course_id,credits,course_name,person_name,schedule);
    }
    Professor p(person_id,person_name,address,phoneNumber,email,dept,salary,courses,n); 
    person=&p;
    cout<<"Displaying professor's details"<<endl;
    person->displayInfo();
    cout<<"Do you want to uodate your personal information (Enter 'y' or 'Y' for yes or else anything for no): ";
    cin>>update;
    while(update=='y'||update=='Y'){
        person->updateInfo();
        cout<<"Displaying updated information: "<<endl;
        person->displayInfo();
        cout<<"Do you want to uodate your personal information again(Enter 'y' or 'Y' for yes or else anything for no): ";
        cin>>update;
    }
    cout<<endl<<"Enter ID of the staff: ";
    cin>>person_id;
    cout<<"Enter name of the staff: ";
    cin>>person_name;
    cout<<"Ennter address of the staff: ";
    cin>>address;
    cout<<"Enter phone number of the staff: ";
    cin>>phoneNumber;
    cout<<"Enter email of staff: ";
    cin>>email;
    cout<<"Enter your department: ";
    cin>>dept;
    cout<<"Enter your salary: ";
    cin>>salary;            
    cout<<"Enter the position: ";
    cin>>pos;
    Staff st(person_id,person_name,address,phoneNumber,email,dept,salary,pos); 
    person=&st;
    cout<<"Displaying staff's details"<<endl;
    person->displayInfo();
    cout<<"Do you want to uodate your personal information (Enter 'y' or 'Y' for yes or else anything for no): ";
    cin>>update;
    while(update=='y'||update=='Y'){
        person->updateInfo();
        cout<<"Displaying updated information: "<<endl;
        person->displayInfo();
        cout<<"Do you want to uodate your personal information again(Enter 'y' or 'Y' for yes or else anything for no): ";
        cin>>update;
    }
    delete[] courses;
    return 0;
}