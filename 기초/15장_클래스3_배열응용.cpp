#include <iostream>
#include <string>
using namespace std;

class MyInfo {
    private:
        string name;
        int height;
        int weight;
    public:
        MyInfo(const string& name="hi",int h=180,int w=70) {
            this->name=name;//this의 또다른 이용방법.
            weight=w;
            height=h;
        }
        void getinfo() {
            cout<<"이름 : "<<name<<endl;
            cout<<"키 : "<<height<<endl;
            cout<<"몸무게 : "<<weight<<endl;
        }
        ~MyInfo() {
            cout<<"소멸"<<endl;
        }
};

int main(void) {

    //방식1
    MyInfo myinfo[3]={MyInfo("수호랑",150,50),MyInfo("고길동",190,90),MyInfo("그",190,100)};

    for (int i=0;i<3;i++) {
        myinfo[i].getinfo();
    }

    //방식2
    MyInfo *test[2];
    for (int i=0;i<2;i++) {
        test[i]=new MyInfo();
    }
    return 0;
}