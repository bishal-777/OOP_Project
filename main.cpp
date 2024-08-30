#include<iostream>

using namespace std;

class Student_PersonalData{
    protected:
    char name[100],faculty[20],phone_no[50],address[100],roll[50];       //roll no is also in char datatype since roll no will be 'ACE080BCT024'
    public:
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
    cin>>marks_lab_exam,marks_viva;
    cout<<"Enter marks of attendance"<<endl;
    cin>>marks_attendance;
    cout<<"Enter marks of assignment and project:"<<endl;
    cin>>marks_assigment>>marks_project;
}
void Student_Evaluation::calculate_Marks(){
    float temp;
    temp=marks_assigment+marks_attendance+marks_first_assement+marks_second_assement+marks_lab_exam+marks_project+marks_viva;
    cout<<"The total internal marks is :"<<temp<<"Out of 100"<<endl;
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
    void Student_Edit();
};
void Student_Manage::Student_Add(){
    Student_Evaluation new_s;
    new_s.getdata_PersonalData();
    new_s.getdata_Marks();
}
void Student_Manage::Student_Display(){

}
void Student_Manage::Student_Edit(){

    }
int main(){
    Student_Manage s;
    int  choice;
    cout<<"\nWelcome to Student Management System\n";
    cout<<"Press 1 to Add Student\n";
    cout<<"Press 2 to Display All Students\n";
    cout<<"Press 3 to Edit Student Details\n";
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
        s.Student_Edit();
        break;
    
    default:
    }
    return 0;
}