#include <iostream>
#include <math.h>
using namespace std;
//Nama	:  Fadhilah Rizki Fatoni
//NIM	: 19/445636/PA/19460
double pi=M_PI;


class segment{
	
	public:
		double a[2];
		double b[2];
		
		double angle;
		double len;
		
		segment* parent;
		segment* child;
		
		segment(double x,double y, double len,double angle){
			
			this->a[0] =x;
			this->a[1] =y;
			this->len=len;
			this->angle=angle;
			calculateB();
			parent=NULL;
		}
		
		segment(segment &parent, double len,double angle){
			this->parent=&parent;
			this->a[0] =parent.b[0];
			this->a[1] =parent.b[1];
			this->len=len;
			this->angle=angle;
			calculateB();
		}
		
		void setAngle(double angle){
			this->angle+=angle;
			calculateB();
		}
		
		void setAngle(segment &parent,double angle){
			this->angle+=angle;
			this->a[0] =parent.b[0];
			this->a[1] =parent.b[1];
			calculateB();
		}
		
		
		void calculateB(){
			
			double dx = this->len*cos(this->angle*pi/180);
			double dy = this->len*sin(this->angle*pi/180);
			this->b[0]=a[0]+dx;
			this->b[1]=a[1]+dy;
		}
	
		void display(){
			
			cout<<"[A] titik A : "<<endl;
			
			cout<<"          x : "<<this->a[0]<<endl;
			cout<<"          y : "<<this->a[1]<<endl;
			
			cout<<"[B] titik B : "<<endl;
			
			cout<<"          x : "<<this->b[0]<<endl;
			cout<<"          y : "<<this->b[1]<<endl;
			
			
		}	
	
};

int main(){
	//default sudut untuk segmen1 = 45
	//default sudut untuk segmen2 = 60
	segment *seg1 = new segment(0,0,15,0);
	segment *seg2 = new segment(*seg1,25,0);
	double sudut1,sudut2;
	while(1){
		
		
		cout<<" --------------------------------------------------------------------- "<<endl;
		//nanti sudut yang dimasukkan akan ditambahkan dengan sudut default
		cout<<" Masukkan sudut yang ingin ditambahkan untuk segmen 1 (derajat) : ";
		cin>>sudut1;
		cout<<endl;
		cout<<" Masukkan sudut yang ingin ditambahkan untuk segmen 2 (derajat) : ";
		cin>>sudut2;
		seg1->setAngle(sudut1);
		seg2->setAngle(*seg1,sudut2);
		cout<<endl;
		cout<<" Untuk segmen 1 : "<<endl;
		seg1->display();
		cout<<endl;
		cout<<" Untuk segmen 2 : "<<endl;
		seg2->display();
		
	}

delete seg1;
delete seg2;
}
