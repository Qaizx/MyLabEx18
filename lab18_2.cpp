#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2){
	double x,y,z;
	x = min((R1->x+R1->w), R2->x+R2->w) - max(R1->x, R2->x);
	y = min(R1->y, R2->y) - max((R1->y-R1->h), R2->y-R2->h);


	if(R1->x+R1->w <= R2->x) z = 0;
	else if(R1->y+R1->h <= R2->h) z = 0;
	else if(R2->y+R2->h < R1->y+R1->h && R2->x+R2->w < R1->x+R1->w){
		x = R2->w;
		y = R2->h;
		z = x*y;
	}
	else z = x*y;

	return z;



}

int main(){
	Rect R1 = {-1,2,6.9,9.6};
	Rect R2 = {0,0,1.2,2.5};	
	cout << overlap(R1,R2);


}
