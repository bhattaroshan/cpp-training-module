#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

enum VisitType{
    ROUTINE,
    EMERGENCY,
    FOLLOW_UP
};

struct MedicalRecord{
    public:
        vector<string> symptoms;
        VisitType visitType;
        string diagnosis;
        string date;
        vector<string> treatment;

};

 

class Patient{
   
    public:
        Patient(){ //default constructor

        }
        
        Patient(string name, int age, char gender):m_name(name),m_age(age),m_gender(gender){}

        Patient(MedicalRecord MedicalRecord){
            m_medRecords.push_back(MedicalRecord);
        } 
        void addMedicalRecord(MedicalRecord medicalRecord){
            m_medRecords.push_back(medicalRecord);
        }
        vector<MedicalRecord> getMedicalRecord(){
            return m_medRecords;
        }

        virtual int getSubsidyPercent(){
            return 0;
        }

        virtual bool isInHousePatient() = 0;

    protected:
        string m_name;
        int m_age;
        char m_gender;

    private:
        vector<MedicalRecord> m_medRecords;

};

class Employee:public Patient{
    public:
        Employee(string name, int age, char gender):Patient(name,age,gender){}
        bool isInHousePatient() override {
            return true;
        }

};

class Client:public Patient{
    public:
        Client(string name,int age,char gender):Patient(name,age,gender){}
        int getSubsidyPercent() override {
            return 30;
        }
        bool isInHousePatient() override {
            return false;
        }
};

class Doctor:public Patient{
    public:
        Doctor(string name,int age, char gender):Patient(name,age,gender){}
        int getSubsidyPercent() override {
            return 50;
        }
        bool isInHousePatient() override {
            return true;
        }
};

int main(){
    vector<Patient*> patients;

    while(1){
        std::cout<<"Enter patient information"<<endl;
        std::cout<<"Type (C) for client & (D) for doctor, (E) for employee, (N) for termination"<<endl;
        string patientType;
        cin>>patientType;
        Patient *p;
        string name;
        char gender;
        int age;
        std::cout<<"Enter name : ";
        std::cin>>name;
        std::cout<<"Enter age : ";
        std::cin>>age;
        std::cout<<"Enter gender : ";
        std::cin>>gender;

        if(patientType=="C"){
            std::cout<<"Client entry"<<endl;
            Client c(name,age,gender);
            p = &c;
        }else if(patientType=="D"){
            std::cout<<"Doctor entry"<<endl;
            Doctor d(name,age,gender);
            p = &d;
        }else if(patientType=="E"){
            std::cout<<"Employee entry"<<endl;
            Employee e(name,age,gender);
            p = &e;
        }else{
            break;
        }

        //I'm adding same MedicalRecord, add appropriate std in out for adding new record for each patient
        MedicalRecord medRec;
        medRec.symptoms =  {"runny nose", "fever"};
        medRec.visitType = VisitType::ROUTINE;
        medRec.diagnosis = "Common cold";
        medRec.date =  "August 13, 2024";
        medRec.treatment= {"rest", "fluids"};
        p->addMedicalRecord(medRec);
        patients.push_back(p);
    }
    
    return 0;
}


   



