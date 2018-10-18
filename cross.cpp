#include<bits/stdc++.h>
#include "header.h"
using namespace std;
void front_find1(){
			int t_color=rubic[4][2][1]; //get the adjacent color of found white face
			if(t_color==0){
				front();
				front();
				if(cross[3]==0){
					bottom();
					left();
					front();
				}
				else if(cross[2]==0){
					Bottom();
					right();
					Front();
					
				}
				else{
					Bottom();
					right();
					Front();
					Right();
				}
				
				cross[0]=1;
			}
			else if(t_color==1){
				Front();
				Front();
				if(cross[2]==0){
					Bottom();
					Right();
					Back();
				}
				else if(cross[3]==0){
					bottom();
					Left();
					back();
				}
				else{
					Bottom();
					Right();
					Back();
					right();
				}
				cross[1]=1;
			}
			else if(t_color==2){
				front();
				right();
				cross[2]=1;
			}
			else if(t_color==3){
				Front();
				left();
				cross[3]=1;
			}
			return;
}
void front_find2(){
	int t_color=rubic[3][1][2];
	if(t_color==0){
		Left();
		Bottom();
		left();
		Front();
		Front();
		cross[0]=1;
	}
	if(t_color==1){
		Left();
		bottom();
		left();
		Back();
		Back();
		cross[1]=1;
	}
	if(t_color==2){
		Left();
		Bottom();
		Bottom();
		left();
		right();
		right();
		cross[2]=1;
	}
	if(t_color==3){
		left();
		cross[3]=1;
	}
	return;
}
void front_find3(){
	int t_color=rubic[2][1][0];
	if(t_color==0){
		Right();
		bottom();
		right();
		Front();
		Front();
		cross[0]=1;
	}
	else if(t_color==1){
		Right();
		Bottom();
		right();
		Back();
		Back();
		cross[1]=1;
	}
	else if(t_color==2){
		right();
		cross[2]=1;
	}
	else if(t_color==3){
		Right();
		bottom();
		bottom();
		right();
		left();
		left();
		cross[3]=1;
	}
	return;
}
void front_find4(){
	int t_color=rubic[5][0][1];
	if(t_color==0){
		bottom();
		left();
		front();
		Left();
		cross[0]==1;
	}
	else if(t_color==1){
		bottom();
		Left();
		back();
		left();
		cross[1]==1;
	}
	else if(t_color==2){
		Front();
		right();;
		front();
		cross[2]==1;
	}
	else if(t_color==3){
		front();
		left();
		Front();
		cross[3]==1;
	}
	return;
}
void back_find1(){
	int t_color=rubic[4][0][1];
	if(t_color==0){
		Back();
		Back();
		Bottom();
		left();;
		front();
		Left();
		cross[0]=1;
	}
	else if(t_color==1){
		Back();
		Back();;
		Bottom();
		Left();
		back();
		left();
		cross[1]=1;
	}
	else if(t_color==2){
		back();
		Right();
		cross[2]=1;
	}
	else if(t_color==3){
		Back();
		Left();
		cross[3]=1;
	}
	return;
}
void back_find2(){
	int t_color=rubic[2][1][2];
	if(t_color==0){
		right();
		bottom();
		Right();
		Front();
		Front();
		cross[0]=1;
	}
	else if(t_color==1){
		right();
		Bottom();
		Right();
		Back();
		Back();
		cross[1]=1;
	}
	else if(t_color==2){
		Right();
		cross[2]=1;
	}
	else if(t_color==3){
		back();
		back();
		Left();
		Back();
		Back();
		cross[3]=1;
	}
	return;
}
void back_find3(){
	int t_color=rubic[3][1][0];
	if(t_color==0){
		left();
		Bottom();
		Left();
		Front();
		Front();
		cross[0]=1;
	}
	else if(t_color==1){
		left();
		bottom();
		Left();
		Back();;
		Back();
		cross[1]=1;
	}
	else if(t_color==2){
		Back();
		Back();
		Right();
		Back();
		Back();
		cross[2]=1;
	}
	else if(t_color==3){
		Left();
		cross[3]=1;
	}
	return;
}
void back_find4(){
	int t_color=rubic[5][2][1];
	if(t_color==0){
		Bottom();
		left();
		front();
		Left();
		cross[0]=1;
	}
	else if(t_color==1){
		Bottom();
		Left();
		back();
		left();
		cross[1]=1;
	}
	else if(t_color==2){
		Back();
		Right();
		back();
		cross[2]=1;
	}
	else if(t_color==3){
		back();
		Left();
		Back();
		cross[3]=1;
	}
	return;
}
void right_find1(){
	int t_color=rubic[4][1][2];
	if(t_color==0){
		cross[0]=1;
		Right();
		Front();
	}
	else if(t_color==1){
		cross[1]=1;
		right();
		Back();;
	}
	else if(t_color==2){
		Right();
		Right();
		bottom();
		Front();
		right();
		front();
		cross[2]=1;
	}
	else if(t_color==3){
		Right();
		Right();
		bottom();
		front();
		left();;
		Front();
		cross[3]=1;
	}
	return;
}
void right_find2(){
	int t_color=rubic[0][1][2];
	if(t_color==0){
		Front();;
		cross[0]=1;
	}
	else if(t_color==1){
		Right();
		Right();
		Back();
		Right();
		Right();
		cross[1]=1;
	}
	else if(t_color==2){
		front();
		Bottom();
		Front();
		Right();
		Right();
		cross[2]=1;
	}
	else if(t_color==3){
		cross[3]=1;
		front();
		bottom();
		Front();
		Left();
		Left();
	}
	return;
}
void right_find3(){
	int t_color=rubic[1][1][0];
	if(t_color==0){
		right();
		right();
		Front();
		Right();
		Right();
		cross[0]=1;
	}
	else if(t_color==1){
		Back();
		cross[1]=1;
	}
	else if(t_color==2){
		right();
		bottom();
		Front();
		right();
		front();
		cross[2]=1;
	}
	else if(t_color==3){		
		right();
		bottom();
		Right();
		front();
		left();
		Front();
		cross[3]=1;
	}
	return;
}
void right_find4(){
	int t_color=rubic[5][1][2];
	if(t_color==0){
		right();
		Front();
		Right();
		cross[0]=1;
	}
	else if(t_color==1){
		Right();
		Back();
		right();
		cross[1]=1;
	}
	else if(t_color==2){
		bottom();
		Front();
		right();
		front();
		cross[2]=1;
	}
	else if(t_color==3){
		bottom();
		front();
		left();
		Front();
		cross[3]=1;
	}
	return;
}
void left_find1(){
	int t_color=rubic[4][1][0];
	if(t_color==0){
		Left();
		front();
		cross[0]==1;
	}
	if(t_color==1){
		left();
		back();
		cross[1]==1;
	}
	if(t_color==2){
		Left();
		Left();
		Bottom();
		Front();
		right();;
		front();
		cross[2]==1;
	}
	else if(t_color==3){
		Left();
		Left();
		Bottom();
		front();
		left();
		Front();;
		cross[3]==1;
	}
	return;
}
void left_find2(){
	int t_color=rubic[1][1][2];
	if(t_color==0){
		Left();
		Left();
		front();
		left();
		left();
		cross[0]==1;
	}
	if(t_color==1){
		back();;
		cross[1]==1;
	}
	if(t_color==2){
		left();
		Bottom();
		Left();
		Front();
		right();
		front();
		cross[2]==1;

	}
	else if(t_color==3){
		Back();
		Bottom();
		back();
		left();
		left();
		cross[3]==1;

	}
	return;
}
void left_find3(){
	int t_color=rubic[0][1][0];
	if(t_color==0){
		front();
		cross[0]==1;
	}
	if(t_color==1){
		Left();
		Left();
		back();
		left();
		left();
		cross[1]==1;
	}
	if(t_color==2){
		Left();
		Bottom();
		left();
		Front();
		right();
		front();
		cross[2]==1;
	}
	else if(t_color==3){
		Front();
		bottom();
		front();
		left();
		left();
		cross[3]==1;
	}
	return;
}
void left_find4(){
	int t_color=rubic[5][1][0];
	if(t_color==0){
		left();
		front();
		Left();
		cross[0]==1;
	}
	if(t_color==1){
		Left();
		back();
		left();
		cross[1]==1;
	}
	if(t_color==2){
		Bottom();
		Front();
		right();
		front();
		cross[2]==1;
	}
	else if(t_color==3){
		Bottom();
		front();
		left();
		Front();
		cross[3]==1;
	}
	return;
}
void bottom_find1(){
	int t_color=rubic[0][2][1];
	if(t_color==0){
		Front();
		Front();
		cross[0]=1;	
	}
	if(t_color==1){
		bottom();
		bottom();
		back();
		back();
		cross[1]=1;	
	}
	if(t_color==2){
		Bottom();
		right();
		right();
		cross[2]=1;	
	}
	else if(t_color==3){
		bottom();
		left();
		left();
		cross[3]=1;	
	}
	return;
}
void bottom_find2(){
	int t_color=rubic[3][2][1];
	if(t_color==0){
		Bottom();
		Front();
		Front();
		cross[0]=1;	
	}
	if(t_color==1){
		bottom();
		Back();
		Back();
		cross[1]=1;	
	}
	if(t_color==2){
		Bottom();
		Bottom();
		Right();
		Right();
		cross[2]=1;	
	}
	else if(t_color==3){
		left();
		left();
		cross[3]=1;	
	}
	return;
}
void bottom_find3(){
	int t_color=rubic[2][2][1];
	if(t_color==0){
		bottom();
		Front();
		Front();
		cross[0]=1;	
	}
	if(t_color==1){
		Bottom();
		Back();
		Back();
		cross[1]=1;	
	}
	if(t_color==2){
		right();
		right();
		cross[2]=1;	
	}
	else if(t_color==3){
		bottom();
		bottom();
		left();
		left();
		cross[3]=1;	
	}
	return;
}
void bottom_find4(){
	int t_color=rubic[1][2][1];
	if(t_color==0){
		bottom();
		bottom();
		Front();
		Front();
		cross[0]=1;	
	}
	if(t_color==1){
		back();
		back();
		cross[1]=1;	
	}
	if(t_color==2){
		bottom();
		right();
		right();
		cross[2]=1;	
	}
	else if(t_color==3){
		Bottom();
		left();
		left();
		cross[3]=1;	
	}
	return;
}
void cross_check(){
		//front
		int t=find(0,4);
		if(t==1){
			front_find1();
		}
		else if(t==2){
			front_find2();
		}
		else if(t==3){
			front_find3();
		}
		else if(t==4){
			front_find4();
		}
		printf("\n");
		//back
		t=find(1,4);
		if(t==1){
			back_find1();
		}
		else if(t==2){
			back_find2();
		}
		else if(t==3){
			back_find3();
		}
		else if(t==4){
			back_find4();
		}
		printf("\n");
		//right
		t=find(2,4);
		if(t==1){
			right_find1();
		}
		else if(t==2){
			right_find2();
		}
		else if(t==3){
			right_find3();
		}
		else if(t==4){
			right_find4();
		}
		printf("\n");
		//left
		t=find(3,4);
		if(t==1){
			left_find1();
		}
		else if(t==2){
			left_find2();
		}
		else if(t==3){
			left_find3();
		}
		else if(t==4){
			left_find4();
		}
		printf("\n");
		//bottom
		t=find(5,4);
		if(t==1){
			bottom_find1();
		}
		else if(t==2){
			bottom_find2();
		}
		else if(t==3){
			bottom_find3();
		}
		else if(t==4){
			bottom_find4();
		}
		printf("\n");
}