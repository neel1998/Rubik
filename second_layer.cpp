#include<bits/stdc++.h>
#include "header.h"
using namespace std;
void front_second(){
	if(rubic[0][2][1]==2 && rubic[5][0][1]==1 ){
		back();
		Bottom();
		Back();
		Bottom();
		right();
		bottom();
		Right();
	}
	else if(rubic[0][2][1]==1 && rubic[5][0][1]==2 ){
		bottom();
		right();
		bottom();
		Right();
		bottom();
		back();
		Bottom();
		Back();
	}
	else if(rubic[0][2][1]==2 && rubic[5][0][1]==0 ){
		Bottom();
		Bottom();
		front();
		bottom();
		Front();
		bottom();
		Right();
		Bottom();
		right();

	}
	else if(rubic[0][2][1]==0 && rubic[5][0][1]==2 ){
		bottom();
		Right();
		Bottom();
		right();
		Bottom();
		front();
		bottom();
		Front();
	}
	else if(rubic[0][2][1]==1 && rubic[5][0][1]==3 ){
		Bottom();
		left();
		Bottom();
		Left();
		Bottom();
		Back();
		bottom();
		back();
	}
	else if(rubic[0][2][1]==3 && rubic[5][0][1]==1 ){
		Back();
		bottom();
		back();
		bottom();
		left();
		Bottom();
		Left();
	}
	else if(rubic[0][2][1]==0 && rubic[5][0][1]==3 ){
		Bottom();
		Left();
		bottom();
		left();
		bottom();
		Front();
		Bottom();
		front();
	}	
	else if(rubic[0][2][1]==3 && rubic[5][0][1]==0 ){
		bottom();
		bottom();
		Front();
		Bottom();
		front();
		Bottom();
		Left();
		bottom();
		left();
	}
}
void second_layer(){
	//first
	front_second();
	printf("\n");
	int x=0;
	//back
	int t1=rubic[1][2][1],t2=rubic[5][2][1];
	if((t1==1 && t2==2) || (t1==2 && t2==1) || (t1==1 && t2==3) || (t1==3 && t2==1) || (t1==0 && t2==2) || (t1==2 && t2==0) || (t1==3 && t2==0) || (t1==0 && t2==3)){
		Bottom();
		Bottom();
		front_second();
		x++;
	}
	printf("\n");
	//right
	t1=rubic[2][2][1];
	t2=rubic[5][1][2];
	if((t1==1 && t2==2) || (t1==2 && t2==1) || (t1==1 && t2==3) || (t1==3 && t2==1) || (t1==0 && t2==2) || (t1==2 && t2==0) || (t1==3 && t2==0) || (t1==0 && t2==3)){
		bottom();
		front_second();
		x++;
	}
	printf("\n");
	//left
	t1=rubic[3][2][1];
	t2=rubic[5][1][0];
	if((t1==1 && t2==2) || (t1==2 && t2==1) || (t1==1 && t2==3) || (t1==3 && t2==1) || (t1==0 && t2==2) || (t1==2 && t2==0) || (t1==3 && t2==0) || (t1==0 && t2==3)){
		Bottom();
		front_second();
		x++;
	}
	if(x==0){
		t1=rubic[0][1][0];
		t2=rubic[3][1][2];
		if((t1==1 && t2==2) || (t1==2 && t2==1) || (t1==1 && t2==3) || (t1==3 && t2==1) || (t1==0 && t2==2) || (t1==2 && t2==0) || (t1==3 && t2==0)){
			Left();
			bottom();
			left();
			bottom();
			Front();
			Bottom();
			front();
		}
		t1=rubic[0][1][2];
		t2=rubic[2][1][0];
		if((t1==1 && t2==2) || (t1==2 && t2==1) || (t1==1 && t2==3) || (t1==3 && t2==1) || (t1==2 && t2==0) || (t1==3 && t2==0) || (t1==0 && t2==3)){
			Right();
			Bottom();
			right();
			Bottom();
			front();
			bottom();
			Front();
		}
		t1=rubic[2][1][2];
		t2=rubic[1][1][0];
		if((t1==1 && t2==2) || (t1==1 && t2==3) || (t1==3 && t2==1) || (t1==2 && t2==0) || (t1==0 && t2==2) || (t1==3 && t2==0) || (t1==0 && t2==3)){
			back();
			Bottom();
			Back();
			Bottom();
			right();
			bottom();
			Right();
		}
		t1=rubic[1][1][2];
		t2=rubic[3][1][0];
		if((t1==1 && t2==2) || (t1==2 && t2==1) || (t1==3 && t2==1) || (t1==2 && t2==0) || (t1==0 && t2==2) || (t1==3 && t2==0) || (t1==0 && t2==3)){
			Back();
			bottom();
			back();
			bottom();
			left();
			Bottom();
			Left();
		}

	}
	printf("\n");
}