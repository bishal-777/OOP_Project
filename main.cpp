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

int main(){
    
    return 0;
}