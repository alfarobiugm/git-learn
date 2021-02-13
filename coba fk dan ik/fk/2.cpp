#include <iostream>
#include <cmath>
#include <ctime>
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
		dx = NULL;
		dy = NULL;
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
	
	void update(){
		//endpoint
		angle = angle + 0.01;
		
		calculate_fk();
	}
	
	void update2(double parentX, double parentY){
		//startpoint
		dx = parentX;
		dy = parentY;	
		
		calculate_fk();
	}
	
	void show_fk(){
		cout<<"Startinggg point , dx : "<<0<<" dy : "<<0<<endl;
		cout<<"End point , dx "<<dx2<<" dy: "<<dy2<<endl;
	}	
	
	void show_fk_next(){
		cout<<"Starting point , dx : "<<dx<<" dy : "<<dy<<endl;
		cout<<"End point , dx "<<dx2<<" dy: "<<dy2<<endl;
		cout<<endl;
	}		
};

void wait_until_next_second()
{
    time_t before = time(0);
    while (difftime(time(0), before) < 1);
}

int main(){
	
	object p1(1,2);
	object p2(p1.dx2, p1.dy2, 1, 3);
//	object p3(p2.dx2, p2.dy2, 1, 2);
	int i=10;
	while(i >0){
		p1.update();
		p2.update2(p1.dx2, p1.dy2);
//		p3.update2(p2.dx2, p2.dy2);
	--i;
	}
	return 0;
}
