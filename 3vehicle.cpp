#include<iostream>
#include<cstring>
using namespace std;
class vehicle
{

    char registerno[15];
    static int counter;
public:

    vehicle()
    {
        counter++;
    }
    ~vehicle()
    {
        counter--;
    }
    void set_reg_no(char *p)
    {
        strcpy(registerno,p);
    }
    void get_reg_no()
    {
       cout<<"number is :"<<registerno;
    }
    void coun();

};
int vehicle::counter=0;
void vehicle::coun()
    {
        cout<<"current number of vehicles in garrage="<<counter<<endl;
    }

int main()
{    char reg[15];
    int ch;
     //vehicle v;
    do{
	vehicle v;
        v.coun();
        cout<<"1.enter the details 2.display 3.vehicle exits 4.exit out of program "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"enter the register number"<<endl;
                    cin>>reg;
                    v.coun();
                    v.set_reg_no(reg);
                    break;

              case 2:v.get_reg_no();

                     break;
              case 3:v.~vehicle();
                      v.coun();
                     break;
               default:return 0;


        }



    }while(1)

;}
