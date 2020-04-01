
#ifdef __SINGLETON_H
class singleton
{
protected:
    singleton()
    {}
private:
    static singleton* p;
public:
    static singleton* initance();
};

singleton* singleton::p = new singleton;

singleton* singleton::initance()
{
    return p;
}
#endif

#ifdef __HOGSVM_H
class singleton_HOGSVM
{
public:
    static singleton_HOGSVM* instance()
    {
        if(m_pHogSvmInstance == NULL){
            m_pHogSvmInstance = new singleton_HOGSVM();
        }
    }
private:
    static String obj_det_filename;
    static singleton_HOGSVM* m_pHogSvmInstance;

};
#endif

#include<iostream>
#include<string.h>
using namespace std;

#define MONITOR_PENCIL_LEN 5

#ifdef _PENCIL_H
class Pencil
{
public:
    Pencil()
    {
        length = MONITOR_PENCIL_LEN;
    };
    virtual ~Pencil(){};
    int write(){
        if(0 >= length){
            cout<<"Pencil used out!"<<endl;
            return -1;
        }
        cout<<"Pencil became shorter because writing."<<endl;
        length = length-1;
        return 0;
    };
    
private:
    int length = 10;    
};
#endif

class Monitor
{
public:
    ~Monitor(){};
    static Monitor& GetInstance()
    {
        static Monitor my_monitor;
        return my_monitor;
    };

    //other class method
    int writing()
    {
        cout<< name <<" is not happy"<<endl;
    };
    int change_name(string new_name)
    {
        name = new_name;
    };
private:
    Monitor(){};
    Monitor(const Monitor&);
    string name = "Guo Zhenghua";
};

int main()
{
    Monitor& my_monitor = Monitor::GetInstance();
    my_monitor.writing();
    my_monitor.change_name("Zhu Qiming");
    Monitor& his_monitor = Monitor::GetInstance();
    his_monitor.writing();
};