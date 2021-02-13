#include <iostream>
#include <cmath>
using namespace std;

class object{
	public:
		double length;
		double angle;
		double dx;
		double dy;
		double dx2;
		double dy2;
		
	object(double lgth_, double angle_){
		dx = 0;
		dy = 0;
		length = lgth_;
		angle = angle_;
		
		calculate_fk();
	}
	
	object(double parentX, double parentY, double lgth_, double angle_){
		dx = parentX;
		dy = parentY;
		
		length = lgth_;
		angle = angle_;
		
		calculate_fk();
	}
	
	void calculate_fk(){
		double dx_ = length * cos(angle);
		double dy_ = length * sin(angle);
		
		dx2 = dx_;
		dy2 = dy_;
		
		if(dx == 0)
			show_fk();
		else
			show_fk_next();
	}
	
	void show_fk(){
		cout<<"Startinggg point , dx : "<<0<<" dy : "<<0<<endl;
		cout<<"End point , dx "<<dx2<<" dy: "<<dy2<<endl;
	}	
	
	void show_fk_next(){
		cout<<endl;
		cout<<"Starting point , dx : "<<dx<<" dy : "<<dy<<endl;
		cout<<"End point , dx "<<dx2<<" dy: "<<dy2<<endl;
	}		
};

int main(){
	object p1(1,2);
	object p2(p1.dx2, p1.dy2, 1, 3);
	object p3(p2.dx2, p2.dy2, 1, 4);
	return 0;
}
