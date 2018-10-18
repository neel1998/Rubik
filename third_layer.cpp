#include<bits/stdc++.h>
#include "header.h"
using namespace std;
//find shape on bottom layer
int layer3_check(){
	//cross
	if(rubic[5][0][1]==5 && rubic[5][1][0]==5 && rubic[5][1][2]==5 && rubic[5][2][1]==5 ){
		return 1;
	}
	//line
	else if(rubic[5][0][1]!=5 && rubic[5][1][0]==5 && rubic[5][1][2]==5 && rubic[5][2][1]!=5 ){
		return 2;
	}
	//line
	else if(rubic[5][0][1]==5 && rubic[5][1][0]!=5 && rubic[5][1][2]!=5 && rubic[5][2][1]==5 ){
		bottom();
		return 2;
	}
	//dot
	else if(rubic[5][0][1]!=5 && rubic[5][1][0]!=5 && rubic[5][1][2]!=5 && rubic[5][2][1]!=5 ){
		return 3;
	}
	//L
	else{
		if(rubic[5][0][1]==5 && rubic[5][1][0]!=5 && rubic[5][1][2]==5 && rubic[5][2][1]!=5){
			bottom();
		}
		else if(rubic[5][0][1]!=5 && rubic[5][1][0]==5 && rubic[5][1][2]!=5 && rubic[5][2][1]==5 ){
			Bottom();
		}
		else if(rubic[5][0][1]!=5 && rubic[5][1][0]!=5 && rubic[5][1][2]==5 && rubic[5][2][1]==5 ){
			bottom();
			bottom();
		}
		return 4;
	}
}
// make cross on bottom layer
void layer3_cross(){
	front();
	Left();
	Bottom();
	left();
	bottom();
	Front();
}
bool two_centers(){
	int c0,c1,c2,c3,count=0;
	c0=rubic[0][2][1];
	c1=rubic[1][2][1];
	c2=rubic[2][2][1];
	c3=rubic[3][2][1];
	if(c0==0){count++;}
	if(c1==1){count++;}
	if(c2==2){count++;}
	if(c3==3){count++;}

	if(count>=2){
		return true;
	}
	else{
		return false;
	}
}
//match centers on bottom layer
void match_center(){
	while(!two_centers()){
		bottom();
	}
	printf("\n");
}
void all_centers(){
	int c0,c1,c2,c3;
		c0=(rubic[0][2][1]==0 )?1:0;
		c1=(rubic[1][2][1]==1 )?1:0;
		c2=(rubic[2][2][1]==2 )?1:0;
		c3=(rubic[3][2][1]==3 )?1:0;
		if(c0 && c1){
			Left();
			Bottom();
			left();
			Bottom();
			Left();
			Bottom();
			Bottom();
			left();
			// Bottom();
			all_centers();

		}
		else if(c0 && c2){
			right();
			Bottom();
			Right();
			Bottom();
			right();
			Bottom();
			Bottom();
			Right();
			Bottom();
		}
		else if(c0 && c3){
			front();
			Bottom();
			Front();
			Bottom();
			front();
			Bottom();
			Bottom();
			Front();
			Bottom();
		}
		else if(c1 && c2){
			Back();
			Bottom();
			back();
			Bottom();
			Back();
			Bottom();
			Bottom();
			back();
			Bottom();
		}
		else if(c1 && c3){
			Left();
			Bottom();
			left();
			Bottom();
			Left();
			Bottom();
			Bottom();
			left();
			Bottom();
		}
		else if(c2 && c3){
			front();
			Bottom();
			Front();
			Bottom();
			front();
			Bottom();
			Bottom();
			Front();
			all_centers();
		}
}
void set_corners(){
	printf("\n");
	//top left corner
	int c00=rubic[5][0][0];
	int c01=rubic[0][2][0];
	int c02=rubic[3][2][2];

	//top right corner
	int c10=rubic[5][0][2];
	int c11=rubic[0][2][2];
	int c12=rubic[2][2][0];

	//bottom left corner
	int c20=rubic[5][2][0];
	int c21=rubic[1][2][2];
	int c22=rubic[3][2][0];

	//bottom right corner
	int c30=rubic[5][2][2];
	int c31=rubic[1][2][0];
	int c32=rubic[2][2][2];

	int cor1,cor2,cor3,cor4;
	cor1=cor2=cor3=cor4=0;
	if(c00==0 && c01==3 && c02==5 || c00==0 && c01==5 && c02==3 || c00==3 && c01==0 && c02==5 || c00==3 && c01==5 && c02==0 || c00==5 && c01==0 && c02==3 || c00==5 && c01==3 && c02==0 ){
		cor1=1;
	}
	if(c10==0 && c11==2 && c12==5 || c10==0 && c11==5 && c12==2 || c10==2 && c11==0 && c12==5 || c10==2 && c11==5 && c12==0 || c10==5 && c11==0 && c12==2 || c10==5 && c11==2 && c12==0 ){
		cor2=1;
	}
	if(c20==1 && c21==3 && c22==5 || c20==1 && c21==5 && c22==3 || c20==3 && c21==1 && c22==5 || c20==3 && c21==5 && c22==1 || c20==5 && c21==1 && c22==3 || c20==5 && c21==3 && c22==1 ){
		cor3=1;
	}
	if(c30==1 && c31==2 && c32==5 || c30==1 && c31==5 && c32==2 || c30==2 && c31==1 && c32==5 || c30==2 && c31==5 && c32==1 || c30==5 && c31==1 && c32==2 || c30==5 && c31==2 && c32==1 ){
		cor4=1;
	}
	if(!cor1 && !cor2 && !cor3 && !cor4){
		left();
		Bottom();
		right();
		bottom();
		Left();
		Bottom();
		Right();
		bottom();
		set_corners();
	}
	else if(cor1 && !cor2 && !cor3 && !cor4){
		Right();
		Bottom();
		Left();
		bottom();
		right();
		Bottom();
		Left();
		bottom();
		set_corners();
	}
	else if(!cor1 && cor2 && !cor3 && !cor4){
		back();
		Bottom();
		front();
		bottom();
		Back();
		Bottom();
		Front();
		bottom();
		set_corners();
	}	
	else if(!cor1 && !cor2 && cor3 && !cor4){
		Front();
		Bottom();
		Back();
		bottom();
		front();
		Bottom();
		back();
		bottom();
		set_corners();
	}
	else if(!cor1 && !cor2 && !cor3 && cor4){
		left();
		Bottom();
		right();
		bottom();
		Left();
		Bottom();
		Right();
		bottom();
		set_corners();
	}
}
void flip_corners(){
	//top left corner
	int c00=rubic[5][0][0];
	int c01=rubic[0][2][0];
	int c02=rubic[3][2][2];

	//top right corner
	int c10=rubic[5][0][2];
	int c11=rubic[0][2][2];
	int c12=rubic[2][2][0];

	//bottom left corner
	int c20=rubic[5][2][0];
	int c21=rubic[1][2][2];
	int c22=rubic[3][2][0];

	//bottom right corner
	int c30=rubic[5][2][2];
	int c31=rubic[1][2][0];
	int c32=rubic[2][2][2];
	int cor1,cor2,cor3,cor4;
	cor1=cor2=cor3=cor4=0;
	if(c00==5 && c01==0 && c02==3)cor1=1;
	if(c10==5 && c11==0 && c12==2)cor2=1;
	if(c20==5 && c21==1 && c22==3)cor3=1;
	if(c30==5 && c31==1 && c02==2)cor4=1;

	if(!cor1 && !cor2 && !cor3 && !cor4){
		if(rubic[0][2][0]==5 && rubic[2][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
		}
		else if(rubic[3][2][2]==5 && rubic[0][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();	
		}
		else if(rubic[3][2][2]==5 && rubic[2][2][0]==5 && rubic[1][2][0]==5 && rubic[1][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
		}
		else if(rubic[3][2][0]==5 && rubic[3][2][2]==5 && rubic[2][2][0]==5 && rubic[2][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();			

		}
		else if(rubic[0][2][0]==5 && rubic[0][2][2]==5 && rubic[1][2][0]==5 && rubic[1][2][2]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
		}
		else if(rubic[0][2][0]==5 && rubic[0][2][2]==5 && rubic[2][2][2]==5 && rubic[3][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
		}
	}
	
	else if(cor1 && !cor2 && !cor3 && !cor4){
		if(rubic[0][2][2]==5){
			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

		}
		else if(rubic[2][2][0]==5){
			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
		}
	}
	else if(!cor1 && cor2 && !cor3 && !cor4){
		if(rubic[3][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();
			Bottom();
		}
		else if(rubic[0][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();
			Bottom();
		}
	}
	else if(!cor1 && !cor2 && cor3 && !cor4){
		if(rubic[3][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			bottom();
		}
		else if(rubic[0][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			bottom();
		}
	}
	else if(!cor1 && !cor2 && !cor3 && cor4){
		if(rubic[3][2][2]==5){
			Bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();

		}
		else if(rubic[0][2][0]==5){
			Bottom();
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();
		}
	}

	else if(cor1 && cor2 && !cor3 && !cor4){
		//12
		if(rubic[3][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();

		}
		else if(rubic[0][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();
			Bottom();
		}
	}
	else if(cor1 && !cor2 && cor3 && !cor4){
		//13
		if(rubic[3][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

		}
		else if(rubic[0][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();
			bottom();
		}
	}
	else if(cor1 && !cor2 && !cor3 && cor4){
		//14
		if(rubic[3][2][2]==5){
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();
			Bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			bottom();

		}
		else if(rubic[0][2][0]==5){
			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			Bottom();
			Bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();
			bottom();
			bottom();
		}
	}
	else if(!cor1 && cor2 && cor3 && !cor4){
		//23
		if(rubic[0][2][2]==5){
			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
		}
		else if(rubic[2][2][0]==5){
			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
		}
	}
	else if(!cor1 && cor2 && !cor3 && cor4){
		//24
		if(rubic[0][2][2]==5){
			bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			bottom();
		}
		else if(rubic[2][2][0]==5){
			bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			bottom();
		}
	}
	else if(!cor1 && !cor2 && cor3 && cor4){
		//34
		if(rubic[1][2][2]==5){
			Bottom();
			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			Bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();
			bottom();
		}
		else if(rubic[3][2][0]==5){
			Bottom();

			Top();
			left();
			top();
			Left();
			Top();
			left();
			top();
			Left();

			bottom();

			left();
			Top();
			Left();
			top();
			left();
			Top();
			Left();
			top();

			bottom();
			bottom();
		}
	}
}
void third_layer(){
	int l3=layer3_check();
	if(l3==2){
		layer3_cross();
		//line
	}
	else if(l3==3){
		layer3_cross();
		layer3_cross();
		bottom();
		layer3_cross();
		//dot
	}
	else if(l3==4){
		layer3_cross();
		bottom();
		layer3_cross();
		//L
	}
	printf("\n");
	match_center();
	if(rubic[0][2][1]!=0 || rubic[1][2][1]!=1 || rubic[2][2][1]!=2 || rubic[3][2][1]!=3){
		all_centers();
	}
	printf("\n");
	set_corners();
	flip_corners();
}