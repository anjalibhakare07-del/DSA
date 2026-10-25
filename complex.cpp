#include<iostream>
using namespace std;
class complex{
    private:
    float real;
     float imag;
public:
complex()
{
    real=0;
    imag=0;
}
complex(float r,float i)
{
    real=r;
    imag=i;
}
~complex()
    {

    }
    void display(void)
    {
        cout<<real<<"+"<<imag<<"j"<<endl;
    }
};
int main()
{
    complex c1(2.0,3.0);
    cout<<"complex number is="<<endl;
    c1.display();
    complex c2(5.0,7.0);
    cout<<"complex number is="<<endl;
    c2.display();
    complex c3(2.5,3.7);
    cout<<"complex number is="<<endl;
    c3.display();
    return 0;
}

/*PS D:\Siddhant Jadhav> g++ complex.cpp -o out   
PS D:\Siddhant Jadhav>  ./out                
complex number is=
2+3j
complex number is=
5+7j
complex number is=
2.5+3.7j*/