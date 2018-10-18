#include<bits/stdc++.h>
#include "header.h"
using namespace std;

int corner_find(int i,int T){
	if(rubic[i][0][0]==T){
		return 1;
	}
	else if(rubic[i][0][2]==T){
		return 2;
	}
	else if(rubic[i][2][0]==T){
		return 3;
	}
	else if(rubic[i][2][2]==T){
		return 4;
	}
	else{
		return 0;
	}
}
void corner_front1(){
	int top_color=rubic[4][2][0];
	int left_color=rubic[3][0][2];
	if(top_color==2 && left_color==1){
		Front();
		bottom();
		front();
		right();
		bottom();
		Right();
		corner[2]=1;
	}
	else if(top_color==3 && left_color==0 ){
		Front();
		Bottom();
		Bottom();
		front();
		Left();
		bottom();
		bottom();
		left();
		corner[3]=1;
	}
	else if(top_color==0 && left_color==2){
		Front();
		bottom();
		front();
		front();
		bottom();
		bottom();
		Front();
		corner[4]=1;
	}
	else if(top_color==1 && left_color==3 ){
		Front();
		Back();
		bottom();
		back();
		front();
		corner[1]=1;
	}
	return;
}
void corner_front2(){
	int top_color=rubic[4][2][2];
	int right_color=rubic[2][0][0];
	if(top_color==3 && right_color==1 ){
		front();
		Bottom();
		left();
		Bottom();
		Left();
		Front();
		corner[1]=1;
	}
	else if(top_color==0 && right_color==3 ){
		front();
		bottom();
		bottom();
		Front();
		Front();
		Bottom();
		front();
		corner[3]=1;
	}
	else if(top_color==2 && right_color==0 ){
		front();
		bottom();
		bottom();
		Front();
		Right();
		Bottom();
		Bottom();
		right();
		corner[4]=1;
	}
	else if(top_color==1 && right_color==2 ){
		front();
		Bottom();
		Front();
		bottom();
		back();
		Bottom();
		Back();
		corner[2]=1;
	}
	return;
}
void corner_front3(){
	int bot_color=rubic[5][0][0];
	int left_color=rubic[3][2][2];
	if(bot_color==3 && left_color==1 ){
		Back();
		bottom();
		back();
		corner[1]=1;
	}
	else if(bot_color==0 && left_color==3 ){
			Bottom();
			Left();
			bottom();
			left();
			corner[3]=1;
	}
	else if(bot_color==1 && left_color==2 ){
		bottom();
		right();
		bottom();
		Right();
		corner[2]=1;
	}
	else if(bot_color==2 && left_color==0 ){
		bottom();
		front();
		Bottom();
		Bottom();
		Front();
		corner[4]=1;
	}
	return;
}
void corner_front4(){
	int bot_color=rubic[5][0][2];
	int right_color=rubic[2][2][0];
	if(bot_color==1 && right_color==3 ){
		Bottom();
		left();
		Bottom();
		Left();
		corner[1]=1;
	}
	else if(bot_color==2 && right_color==1 ){
		back();
		Bottom();
		Back();
		corner[2]=1;
	}
	else if(bot_color==0 && right_color==2 ){
		bottom();
		Right();
		Bottom();
		right();
		corner[4]=1;
	}
	else if(bot_color==3 && right_color==0 ){
		Bottom();
		Front();
		bottom();
		bottom();
		front();
		corner[3]=1;	
	}
	return;
}
void first_layer(){
	//front
	int t=corner_find(0,4);
	if(t==1){
		corner_front1();
	}
	else if(t==2){
		corner_front2();
	}
	else if(t==3){
		corner_front3();
	}
	else if(t==4){
		corner_front4();
	}
	printf("\n");
	//back
	t=corner_find(1,4);
	if(t==1){
		back();
		bottom();
		bottom();
		Back();
		corner_front3();
	}
	else if(t==2){
		Back();
		Bottom();
		Bottom();
		back();
		corner_front4();
	}
	else if(t==3){
		bottom();
		bottom();
		corner_front3();
	}
	else if(t==4){
		Bottom();
		Bottom();
		corner_front4();
	}
	printf("\n");
	//right
	t=corner_find(2,4);
	if(t==1){
		Right();
		bottom();
		right();
		corner_front3();
	}
	else if(t==2){
		right();
		bottom();
		bottom();
		Right();
		Bottom();
		corner_front4();
	}
	else if(t==3){
		bottom();
		corner_front3();
	}
	else if(t==4){
		bottom();
		corner_front4();
	}
	printf("\n");
	//left
	t=corner_find(3,4);
	if(t==1){
		left();
		Bottom();
		Bottom();
		Left();
		bottom();
		corner_front3();
	}
	else if(t==2){
		Left();
		Bottom();
		left();
		corner_front4();
	}
	else if(t==3){
		Bottom();
		corner_front3();
	}
	else if(t==4){
		Bottom();
		corner_front4();
	}
	printf("\n");
	//bottom
	t=corner_find(5,4);
	if(t==1){
		if(corner[1]==0){
			Bottom();
			left();
			Bottom();
			Bottom();
			Left();
			Back();
			Bottom();
			Bottom();
			back();
			corner_front4();
		}
		else if(corner[2]==0){
			right();
			bottom();
			bottom();
			Right();
			back();
			bottom();
			bottom();
			Back();
			corner_front3();
		}
		else if(corner[3]==0){
			Bottom();
			Left();
			bottom();
			left();
			corner_front1();
		}
		else if(corner[4]==0){
			Right();
			Bottom();
			right();
			corner_front2();
		}
	}
	else if(t==2){
		if(corner[1]==0){
			left();
			bottom();
			Left();
			Bottom();
			Bottom();
			corner_front4();	
		}
		else if(corner[2]==0){
			bottom();
			right();
			bottom();
			bottom();
			Right();
			back();
			bottom();
			bottom();
			Back();
			corner_front3();
		}
		else if(corner[3]==0){
			Left();
			bottom();
			left();
			corner_front1();
		}
		else if(corner[4]==0){
			bottom();
			Right();
			Bottom();
			right();
			corner_front2();
		}
	}
	else if(t==3){
		if(corner[1]==0){
			bottom();
			left();
			Bottom();
			Left();
			Back();
			Bottom();
			Bottom();
			back();
			corner_front4();
		}
		else if(corner[2]==0){
			Bottom();
			back();
			Bottom();
			Bottom();
			Back();
			right();
			bottom();
			bottom();
			Right();
			Bottom();
			corner_front4();
		}
		else if(corner[3]==0){
			bottom();
			Left();
			Bottom();
			left();
			corner_front3();
		}
		else if(corner[4]==0){
			Right();
			bottom();
			right();
			corner_front4();
		}
	}
	else if(t==4){
		if(corner[1]==0){
			bottom();
			Back();
			bottom();
			bottom();
			back();
			left();
			Bottom();
			Bottom();
			Left();
			corner_front3();
		}
		else if(corner[2]==0){
			Bottom();
			right();
			bottom();
			Right();
			back();
			bottom();
			bottom();
			Back();
			corner_front3();
		}
		else if(corner[3]==0){
			Left();
			Bottom();
			left();
			corner_front3();
		}
		else if(corner[4]==0){
			Bottom();
			Right();
			bottom();
			right();
			corner_front4();
		}
	}
	printf("\n");
	//top
	t=corner_find(4,4);
	if(t==1 && rubic[3][0][0]!=3 && rubic[1][0][2]!=1 ){
		Back();
		Bottom();
		back();
		corner_front3();
	}
	else if(t==2 && rubic[1][0][0]!=1 && rubic[2][0][2]!=2){
		back();
		bottom();
		Back();
		corner_front4();
	}
	else if(t==3 && rubic[0][0][0]!=0 && rubic[3][0][2]!=3){
		Left();
		Bottom();
		left();
		bottom();
		corner_front3();
	}
	else if(t==4 && rubic[2][0][0]!=2 && rubic[0][0][2]!=0){
		Right();
		bottom();
		right();
		Bottom();
		corner_front4();
	}
	printf("\n");
}