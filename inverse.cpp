#include <iostream>
#include <math.h>

//Nama	:  Fadhilah Rizki Fatoni
//NIM	: 19/445636/PA/19460
using namespace std;

double pi=M_PI;


class segment{
	
	public:
		double a[2];
		double b[2];
		
		double angle;
		double len;
		double newAngle;
		segment* parent;
		segment* child;
		
		segment(double x,double y, double len,double angle){
			
			this->a[0] =x;
			this->a[1] =y;
			this->len=len;
			this->angle=angle;
			calculateB();
		}
		
		segment(segment &parent, double len,double angle){
			this->parent=&parent;
			this->a[0] =parent.b[0];
			this->a[1] =parent.b[1];
			this->len=len;
			this->angle=angle;
			this->parent = &parent;
			calculateB();
	
		}
		
		void setAngle(double angle){
			this->angle=angle;
			calculateB();
		}
		
		void setAngle(segment &parent,double angle){
			this->angle=angle;
			this->a[0] =parent.b[0];
			this->a[1] =parent.b[1];
			calculateB();
			
			
		}
		
		
		void getAngle(double tx,double ty){
			
			double t[2];
			t[0]=tx;
			t[1]=ty;
			double dir[2];
//			dir[0] = t[0]-this->a[0];
//			dir[1] = t[1]-this->a[1];
			
////			this->newAngle=atan2(dir[1],dir[0])* 180 / pi;
////			cout<<"atan : x = "<<dir[1]<<" , y = "<<dir[0]<<endl;
//			double d1 = sqrt((tx-(this->b[0]))*(tx-(this->b[0])) + (ty-(this->b[1]))*(ty-(this->b[1])));
//			double d2 = sqrt((tx-(this->a[0]))*(tx-(this->a[0])) + (ty-(this->a[1]))*(ty-(this->a[1])));
//			double d3 = sqrt((this->a[0]-(this->b[0]))*(this->a[0]-(this->b[0])) + (this->a[1]-(this->b[1]))*(this->a[1]-(this->b[1])));
//			this->newAngle = acos((d2*d2 + d3*d3 - d1*d1)/(2*d2*d3))*180 / pi;
////			this->b[0] = tx;
////			this->b[1] = ty;
//			double db[2];
//			db[0] = sqrt((this->a[0]-(this->b[0]))*(this->a[0]-(this->b[0])));
//			db[1] = sqrt((this->a[1]-(this->b[1]))*(this->a[1]-(this->b[1])));
//			this->a[0] = a[0] + dir[0];
//			this->a[1] = a[1] + dir[1];
//
//			dir[0] = dir[0] + db[0];
//			dir[1] = dir[1] + db[1];
//			
//			this->a[0] = t[0] - dir[0];
//			this->a[1] = t[1] - dir[1];
			double r;
			r = sqrt((pow(t[0],2)) + pow(t[1],2));
			double l = parent->len;
			this->newAngle = acos((pow(l,2) + pow(this->len, 2) - pow(r , 2))/(2*l*this->len))*180 / pi;

			calculateB();
			calculateB(this->newAngle);
		}
		
		
		void getAngle(segment &child){
			double t[2];
			t[0]=child.a[0];
			t[1]=child.a[1];
//			double dir[2];
//			dir[0] = t[0]-this->a[0];
//			dir[1] = t[1]-this->a[1];
//			
//		//	this->newAngle=atan2(dir[1],dir[0])* 180 / pi;
//			double d1 = sqrt((t[0]-(this->b[0]))*(t[0]-(this->b[0])) + (t[1]-(this->b[1]))*(t[1]-(this->b[1])));
//			double d2 = sqrt((t[0]-(this->a[0]))*(t[0]-(this->a[0])) + (t[1]-(this->a[1]))*(t[1]-(this->a[1])));
//			double d3 = sqrt((this->a[0]-(this->b[0]))*(this->a[0]-(this->b[0])) + (this->a[1]-(this->b[1]))*(this->a[1]-(this->b[1])));
//			this->newAngle = (acos((d2*d2 + d3*d3 - d1*d1)/(2*d2*d3)))*180 / pi;

			double beta, gama;
			beta = atan((this->len*sin(child.newAngle))/(this->len+child.newAngle*cos(child.newAngle)))*180/pi;
			gama = atan(t[1]/t[0])*180/pi;
			this->newAngle = gama-beta;

		}
		
		
		void calculateB(){
			
			double dx = this->len*cos(this->angle*pi/180);
			double dy = this->len*sin(this->angle*pi/180);
			this->b[0]=a[0]+dx;
			this->b[1]=a[1]+dy;
		}
	
		void calculateB(double angle){
			
			double dx = this->len*cos(angle*pi/180);
			double dy = this->len*sin(angle*pi/180);
			this->b[0]=a[0]+dx;
			this->b[1]=a[1]+dy;
		}
	
		void display(){
			
			cout<<this->newAngle<<endl;
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
	segment *seg1 = new segment(0,0,7,45);
	segment *seg2 = new segment(*seg1,5,60);
	double x,y;
	while(1){
		
		
		cout<<" --------------------------------------------------------------------- "<<endl;
		//nanti sudut yang dimasukkan akan ditambahkan dengan sudut default
		cout<<" Masukkan koordinat titik (x,y) : "<<endl;
		cout<<" x : ";
		cin>>x;
		cout<<" y : ";
		cin>>y;
		seg2->getAngle(x,y);
		seg1->getAngle(*seg2);

		cout<<endl;
		cout<<" Untuk segmen 1 : ";
		seg1->display();
		cout<<endl;
		cout<<" Untuk segmen 2 : ";
		seg2->display();
	
	}
	delete seg1;
	delete seg2;

}
