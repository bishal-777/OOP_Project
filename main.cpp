#include<iostream>
#include<string.h>
using namespace std;

class Student_PersonalData{
    protected:
    char name[100],faculty[20],phone_no[50],address[100]; 
    float marks;
    public:
    int roll;
    void getdata_PersonalData();
    void showdata_PersonalData();
};
void Student_PersonalData::getdata_PersonalData(){
    cout<<"Enter name:"<<endl;
    cin>>name;
    cout<<"Enter roll no:"<<endl;
    cin>>roll;
    cout<<"Enter faculty:"<<endl;
    cin>>faculty;
    cout<<"Enter phone number:"<<endl;
    cin>>phone_no;
    cout<<"Enter address:"<<endl;
    cin>>address;
}
void Student_PersonalData::showdata_PersonalData(){
    cout<<"Name:\t"<<name<<"\n"<<"Roll no:\t"<<roll<<"\n"<<"Faculty:\t"<<faculty<<"\n"<<"Phone number:\t"<<phone_no<<"\n"<<"Address:\t"<<address<<endl;
}


class Student_Evaluation:public Student_PersonalData{
    protected:
    float marks_first_assement,marks_second_assement,marks_lab_exam,marks_viva;
    int marks_attendance,marks_assigment,marks_project;
    public:
    void getdata_Marks();
    void calculate_Marks();
    void display_Marks();
};
/*Marks distribition is as follows:
attendance=10%      -10 marks
first assesment=25% -25 marks
second assement=25% -25 marks
Assignment=10%      -10 marks
project=10%         -10 marks
lab exam=10%        -10 marks
viva=10%            -10 marks
*/
void Student_Evaluation::getdata_Marks(){
    cout<<"Enter marks of first and second assesment:"<<endl;
    cin>>marks_first_assement>>marks_second_assement;
    cout<<"Enter marks of lab exam and viva:";
    cin>>marks_lab_exam>>marks_viva;
    cout<<"Enter marks of attendance"<<endl;
    cin>>marks_attendance;
    cout<<"Enter marks of assignment and project:"<<endl;
    cin>>marks_assigment>>marks_project;
}
void Student_Evaluation::calculate_Marks(){
    marks=marks_assigment+marks_attendance+marks_first_assement+marks_second_assement+marks_lab_exam+marks_project+marks_viva;
}
void Student_Evaluation::display_Marks(){
        cout<<"The total internal marks is : "<<marks<<" Out of 100"<<endl;
}

class Student_Manage{
    int Student_count;
    Student_Evaluation all_s[100];     //HA-SA relationship
    public:
    Student_Manage(){
        Student_count=0;
    }
    void Student_Add();
    void Student_Display();
    void Student_Edit(int);
};
void Student_Manage::Student_Add(){
    Student_Evaluation new_s;
    new_s.getdata_PersonalData();
    new_s.getdata_Marks();
    all_s[Student_count]=new_s;
    Student_count++;
    cout<<"Student added"<<endl;
}
void Student_Manage::Student_Display(){
     for(int i=0;i<Student_count;i++){
        all_s[i].showdata_PersonalData();
        all_s[i].display_Marks();
    }
}
void Student_Manage::Student_Edit(int r){
    for(int i=0;i<Student_count;i++){
        if(all_s[i].roll==r){
        all_s[i].getdata_PersonalData();
        all_s[i].getdata_Marks();
        all_s[i].calculate_Marks();
        cout<<"Editied student data"<<endl;
        }
    }
    }
    
int main(){
    Student_Manage s;
    int  choice,r;
    do{
    cout<<"\nWelcome to Student Management System\n";
    cout<<"Press 1 to Add Student\n";
    cout<<"Press 2 to Display All Students\n";
    cout<<"Press 3 to Edit Student Details\n";
    cout<<"Press 4 to Exit the application\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        s.Student_Add();
        break;

    case 2:
        s.Student_Display();
        break;

    case 3:
        cout<<"Enter the roll no of student:"<<endl;
        cin>>r;
        s.Student_Edit(r);
        break;
    
    case 4:
        cout<<"Exiting the application"<<endl;
        break;

    default:
    cout<<"Invalid option!"<<endl;
    }
    }while(choice!=4);
    return 0;
}