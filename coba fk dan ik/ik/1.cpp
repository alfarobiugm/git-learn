#include <iostream>
#include <math.h>
using namespace std;

class segment{
	public:
		float length1, length2;
		float q1, q2;
		float endPointX;
		float endPointY;
		float dx, dy, dx2, dy2;
		
	segment(float length_, float dx_, float dy_){
		dx = dx_;
		dy = dy_;
		length1 = length_;
	}
	
	segment(float length_, float length2_, float epx, float epy){
		length1 = length_;
		length2 = length2_;
		endPointX = epx;
		endPointY = epy;
		
		calculateQ2();
	}
		
	void calculateQ2(){
		float r, alpha;
		r = sqrt((pow(endPointX,2) + pow(endPointY,2)));
		alpha = 1/cos((pow(length1,2) + pow(length2,2) - pow(r,2))/(2*length1*length2));
		q2 = 1/cos(-cos(alpha));
		
//		cout<<alpha<<endl;
//		cout<<q2<<endl;
//		
		calculateQ1();
	}
	
	void calculateQ1(){
		float beta, gama;
		beta = atan((length2*sin(q2))/(length1+length2*cos(q2)));
		gama = atan(endPointY/endPointX);
		q1 = gama-beta;
		
//		cout<<beta<<endl;
//		cout<<q1<<endl;
	}
	
	void update(float q1_, float q2_, float one){
		q1 = q1_;
		q2 = q2_;
//		cout<<length1<<endl;
		
		dx2 = length1 * cos(q1);
		dy2 = length1 * sin(q1);
		
//		cout<<dx2<<endl;
//		cout<<dy2<<endl;
	}
	
	void update(float dx2_, float dx1_){
		dx = dx2_;
		dy = dx1_;
		
		dx2 = length2 * cos(q2);
		dy2 = length2 * sin(q2);
	}
	
//	void show(float dx11, float dy11, float dx12, float dy12, float dx21, float dy21, float dx22, float dy22){
//		cout<< " START POINT SEGMENT 1 :  "<<"dx = "<< dx11<<"  dy = "<<dy11<<endl; 
//		cout<< " END POINT SEGMENT 1 :  "<<"dx = "<< dx12<<"  dy = "<<dy12<<endl;
//		cout<< " START POINT SEGMENT 2 :  "<<"dx = "<< dx21<<"  dy = "<<dy21<<endl;
//		cout<< " END POINT SEGMENT 2 :  "<<"dx = " <<dx22<<"  dy = "<<dy22<<endl;
//	}
};
//
	void show(float dx11,float dy11, float dx12, float dy12, float dx21, float dy21, float dx22, float dy22){
		cout<< " START POINT SEGMENT 1 :  "<<"dx = "<< dx11<<"  dy = "<<dy11<<endl; 
		cout<< " END POINT SEGMENT 1 :  "<<"dx = "<< dx12<<"  dy = "<<dy12<<endl;
		cout<< " START POINT SEGMENT 2 :  "<<"dx = "<< dx21<<"  dy = "<<dy21<<endl;
		cout<< " END POINT SEGMENT 2 :  "<<"dx = "<< dx22<<"  dy = "<<dy22<<endl;
	}

int main(){
	segment two(15, 25, 4, 5);
	segment one(two.length1, 0, 0);
	one.update(two.q1, two.q2, 1);
	two.update(one.dx, one.dy);
	show(one.dx, one.dy, one.dx2, one.dy2, one.dx2, one.dy2, two.dx2, two.dy2);
	return 0;
}


