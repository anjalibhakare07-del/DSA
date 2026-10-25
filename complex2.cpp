#include<iostream>
using namespace std;
class Complex{
    private:
    float real;
    float imag;
    public:
    Complex(){
        real=0;
        imag=0;
    }
    Complex(float r,float i){
        real=r;
        imag=i;
    }
    ~Complex(){}
    void display(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    Complex add(Complex c){
        return Complex(real+c.real,imag+c.imag);
    }
    Complex subtract(Complex c){
        return Complex(real-c.real,imag-c.imag);
    }
    Complex multiply(Complex c){
        float r = real*c.real-imag*c.imag;
        float i = real*c.imag+imag*c.real;
        return Complex(r,i);
    }
};
int main(){
    Complex c1(4,5),c2(2,3);
    cout<<"\nFirst Complex Number:";
    c1.display();
    cout<<"Second Complex Number:";
    c2.display();
    Complex sum=c1.add(c2);
    cout<<"\nSum:";
    sum.display();
    Complex diff=c1.subtract(c2);
    cout<<"Difference:";
    diff.display();
    Complex prod=c1.multiply(c2);
    cout<<"Product:";
    prod.display();
    return 0;
}

/*PS D:\Siddhant Jadhav> g++ complex2.cpp -o out                                               
PS D:\Siddhant Jadhav> ./out                  

First Complex Number:4+5i
Second Complex Number:2+3i

Sum:6+8i
Difference:2+2i
Product:-7+22i*/