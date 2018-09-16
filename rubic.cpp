#include<bits/stdc++.h>
using namespace std;
int rubic[6][3][3];
int cross[5]={0};
int corner[5]={0};
int x=-1;
string moves;
char a[6]={'F','B','R','L','T','b'};
void print(){
	for(int i=0;i<6;i++){
			printf("%c:\n",a[i]);
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					printf("%d",rubic[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}
}
void Front(){
	moves+="F";
	printf("F ");
	int temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=2,k=0;j>=0 && k<3;j--,k++){
			temp[j][i]=rubic[0][i][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[0][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][0][0],rubic[2][1][0],rubic[2][2][0]};
	int temp_l[3]={rubic[3][0][2],rubic[3][1][2],rubic[3][2][2]};
	int temp_b[3]={rubic[5][0][0],rubic[5][0][1],rubic[5][0][2]};
	int temp_t[3]={rubic[4][2][0],rubic[4][2][1],rubic[4][2][2]};

	rubic[4][2][0]=temp_r[0];
	rubic[4][2][1]=temp_r[1];
	rubic[4][2][2]=temp_r[2];

	rubic[3][0][2]=temp_t[2];
	rubic[3][1][2]=temp_t[1];
	rubic[3][2][2]=temp_t[0];

	rubic[5][0][0]=temp_l[0];
	rubic[5][0][1]=temp_l[1];
	rubic[5][0][2]=temp_l[2];

	rubic[2][0][0]=temp_b[2];
	rubic[2][1][0]=temp_b[1];
	rubic[2][2][0]=temp_b[0];
}
void Back(){
	moves+=" Ba";
	printf(" Ba ");
	int temp[3][3];
	for(int i=2,j=0;i>=0 && j<3;i--,j++)
	{
		for(int k=0;k<3;k++){
			temp[k][i]=rubic[1][j][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[1][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][0][2],rubic[2][1][2],rubic[2][2][2]};
	int temp_l[3]={rubic[3][0][0],rubic[3][1][0],rubic[3][2][0]};
	int temp_b[3]={rubic[5][2][0],rubic[5][2][1],rubic[5][2][2]};
	int temp_t[3]={rubic[4][0][0],rubic[4][0][1],rubic[4][0][2]};

	rubic[4][0][0]=temp_r[0];
	rubic[4][0][1]=temp_r[1];
	rubic[4][0][2]=temp_r[2];

	rubic[3][0][0]=temp_t[2];
	rubic[3][1][0]=temp_t[1];
	rubic[3][2][0]=temp_t[0];

	rubic[5][2][0]=temp_l[0];
	rubic[5][2][1]=temp_l[1];
	rubic[5][2][2]=temp_l[2];

	rubic[2][0][2]=temp_b[2];
	rubic[2][1][2]=temp_b[1];
	rubic[2][2][2]=temp_b[0];

}
void Right(){
	moves+="R";
	printf("R ");
	int temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=2,k=0;j>=0 && k<3;j--,k++){
			temp[j][i]=rubic[2][i][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[2][i][j]=temp[i][j];
		}
	}
	int temp_t[3]={rubic[4][0][2],rubic[4][1][2],rubic[4][2][2]};
	int temp_f[3]={rubic[0][0][2],rubic[0][1][2],rubic[0][2][2]};
	int temp_b[3]={rubic[5][0][2],rubic[5][1][2],rubic[5][2][2]};
	int temp_B[3]={rubic[1][0][0],rubic[1][1][0],rubic[1][2][0]};

	rubic[0][0][2]=temp_t[0];
	rubic[0][1][2]=temp_t[1];
	rubic[0][2][2]=temp_t[2];

	rubic[5][0][2]=temp_f[0];
	rubic[5][1][2]=temp_f[1];
	rubic[5][2][2]=temp_f[2];

	rubic[1][0][0]=temp_b[2];
	rubic[1][1][0]=temp_b[1];
	rubic[1][2][0]=temp_b[0];

	rubic[4][0][2]=temp_B[2];
	rubic[4][1][2]=temp_B[1];
	rubic[4][2][2]=temp_B[0];

}
void Left(){
	moves+="L";
	printf("L ");
	int temp[3][3];
	for(int i=2,j=0;i>=0 && j<3;i--,j++)
	{
		for(int k=0;k<3;k++){
			temp[k][i]=rubic[3][j][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[3][i][j]=temp[i][j];
		}
	}

	int temp_t[3]={rubic[4][0][0],rubic[4][1][0],rubic[4][2][0]};
	int temp_f[3]={rubic[0][0][0],rubic[0][1][0],rubic[0][2][0]};
	int temp_b[3]={rubic[5][0][0],rubic[5][1][0],rubic[5][2][0]};
	int temp_B[3]={rubic[1][0][2],rubic[1][1][2],rubic[1][2][2]};

	rubic[0][0][0]=temp_t[0];
	rubic[0][1][0]=temp_t[1];
	rubic[0][2][0]=temp_t[2];

	rubic[5][0][0]=temp_f[0];
	rubic[5][1][0]=temp_f[1];
	rubic[5][2][0]=temp_f[2];

	rubic[1][0][2]=temp_b[2];
	rubic[1][1][2]=temp_b[1];
	rubic[1][2][2]=temp_b[0];

	rubic[4][0][0]=temp_B[2];
	rubic[4][1][0]=temp_B[1];
	rubic[4][2][0]=temp_B[0];

}
void Top(){
	moves+="T";
	printf("T ");
	int temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=2,k=0;j>=0 && k<3;j--,k++){
			temp[j][i]=rubic[4][i][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[4][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][0][0],rubic[2][0][1],rubic[2][0][2]};
	int temp_f[3]={rubic[0][0][0],rubic[0][0][1],rubic[0][0][2]};
	int temp_B[3]={rubic[1][0][0],rubic[1][0][1],rubic[1][0][2]};
	int temp_l[3]={rubic[3][0][0],rubic[3][0][1],rubic[3][0][2]};

	rubic[0][0][0]=temp_l[0];
	rubic[0][0][1]=temp_l[1];
	rubic[0][0][2]=temp_l[2];

	rubic[1][0][0]=temp_r[0];
	rubic[1][0][1]=temp_r[1];
	rubic[1][0][2]=temp_r[2];

	rubic[2][0][0]=temp_f[0];
	rubic[2][0][1]=temp_f[1];
	rubic[2][0][2]=temp_f[2];

	rubic[3][0][0]=temp_B[0];
	rubic[3][0][1]=temp_B[1];
	rubic[3][0][2]=temp_B[2];

}
void Bottom(){
	moves+="B";
	printf("B ");
	int temp[3][3];
	for(int i=2,j=0;i>=0 && j<3;i--,j++)
	{
		for(int k=0;k<3;k++){
			temp[k][i]=rubic[5][j][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[5][i][j]=temp[i][j];
		}
	}
	
	int temp_r[3]={rubic[2][2][0],rubic[2][2][1],rubic[2][2][2]};
	int temp_f[3]={rubic[0][2][0],rubic[0][2][1],rubic[0][2][2]};
	int temp_B[3]={rubic[1][2][0],rubic[1][2][1],rubic[1][2][2]};
	int temp_l[3]={rubic[3][2][0],rubic[3][2][1],rubic[3][2][2]};

	rubic[0][2][0]=temp_l[0];
	rubic[0][2][1]=temp_l[1];
	rubic[0][2][2]=temp_l[2];

	rubic[1][2][0]=temp_r[0];
	rubic[1][2][1]=temp_r[1];
	rubic[1][2][2]=temp_r[2];

	rubic[2][2][0]=temp_f[0];
	rubic[2][2][1]=temp_f[1];
	rubic[2][2][2]=temp_f[2];

	rubic[3][2][0]=temp_B[0];
	rubic[3][2][1]=temp_B[1];
	rubic[3][2][2]=temp_B[2];

}
void front(){
	moves+="f";
	printf("f ");
	int temp[3][3];
	for(int i=2,j=0;i>=0 && j<3;i--,j++)
	{
		for(int k=0;k<3;k++){
			temp[k][i]=rubic[0][j][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[0][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][0][0],rubic[2][1][0],rubic[2][2][0]};
	int temp_l[3]={rubic[3][0][2],rubic[3][1][2],rubic[3][2][2]};
	int temp_b[3]={rubic[5][0][0],rubic[5][0][1],rubic[5][0][2]};
	int temp_t[3]={rubic[4][2][0],rubic[4][2][1],rubic[4][2][2]};

	rubic[4][2][0]=temp_l[2];
	rubic[4][2][1]=temp_l[1];
	rubic[4][2][2]=temp_l[0];

	rubic[3][0][2]=temp_b[0];
	rubic[3][1][2]=temp_b[1];
	rubic[3][2][2]=temp_b[2];

	rubic[5][0][0]=temp_r[2];
	rubic[5][0][1]=temp_r[1];
	rubic[5][0][2]=temp_r[0];

	rubic[2][0][0]=temp_t[0];
	rubic[2][1][0]=temp_t[1];
	rubic[2][2][0]=temp_t[2];

}
void back(){
	moves+=" ba ";
	printf(" ba ");
	int temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=2,k=0;j>=0 && k<3;j--,k++){
			temp[j][i]=rubic[1][i][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[1][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][0][2],rubic[2][1][2],rubic[2][2][2]};
	int temp_l[3]={rubic[3][0][0],rubic[3][1][0],rubic[3][2][0]};
	int temp_b[3]={rubic[5][2][0],rubic[5][2][1],rubic[5][2][2]};
	int temp_t[3]={rubic[4][0][0],rubic[4][0][1],rubic[4][0][2]};

	rubic[4][0][0]=temp_l[2];
	rubic[4][0][1]=temp_l[1];
	rubic[4][0][2]=temp_l[0];

	rubic[3][0][0]=temp_b[0];
	rubic[3][1][0]=temp_b[1];
	rubic[3][2][0]=temp_b[2];

	rubic[5][2][0]=temp_r[2];
	rubic[5][2][1]=temp_r[1];
	rubic[5][2][2]=temp_r[0];

	rubic[2][0][2]=temp_t[0];
	rubic[2][1][2]=temp_t[1];
	rubic[2][2][2]=temp_t[2];

}
void right(){
	moves+="r";
	printf("r ");
	int temp[3][3];
	for(int i=2,j=0;i>=0 && j<3;i--,j++)
	{
		for(int k=0;k<3;k++){
			temp[k][i]=rubic[2][j][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[2][i][j]=temp[i][j];
		}
	}
	int temp_t[3]={rubic[4][0][2],rubic[4][1][2],rubic[4][2][2]};
	int temp_f[3]={rubic[0][0][2],rubic[0][1][2],rubic[0][2][2]};
	int temp_b[3]={rubic[5][0][2],rubic[5][1][2],rubic[5][2][2]};
	int temp_B[3]={rubic[1][0][0],rubic[1][1][0],rubic[1][2][0]};

	rubic[0][0][2]=temp_b[0];
	rubic[0][1][2]=temp_b[1];
	rubic[0][2][2]=temp_b[2];

	rubic[5][0][2]=temp_B[2];
	rubic[5][1][2]=temp_B[1];
	rubic[5][2][2]=temp_B[0];

	rubic[1][0][0]=temp_t[2];
	rubic[1][1][0]=temp_t[1];
	rubic[1][2][0]=temp_t[0];

	rubic[4][0][2]=temp_f[0];
	rubic[4][1][2]=temp_f[1];
	rubic[4][2][2]=temp_f[2];

}
void left(){
	moves+="l";
	printf("l ");
	int temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=2,k=0;j>=0 && k<3;j--,k++){
			temp[j][i]=rubic[3][i][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[3][i][j]=temp[i][j];
		}
	}
	int temp_t[3]={rubic[4][0][0],rubic[4][1][0],rubic[4][2][0]};
	int temp_f[3]={rubic[0][0][0],rubic[0][1][0],rubic[0][2][0]};
	int temp_b[3]={rubic[5][0][0],rubic[5][1][0],rubic[5][2][0]};
	int temp_B[3]={rubic[1][0][2],rubic[1][1][2],rubic[1][2][2]};

	rubic[0][0][0]=temp_b[0];
	rubic[0][1][0]=temp_b[1];
	rubic[0][2][0]=temp_b[2];

	rubic[5][0][0]=temp_B[2];
	rubic[5][1][0]=temp_B[1];
	rubic[5][2][0]=temp_B[0];

	rubic[1][0][2]=temp_t[2];
	rubic[1][1][2]=temp_t[1];
	rubic[1][2][2]=temp_t[0];

	rubic[4][0][0]=temp_f[0];
	rubic[4][1][0]=temp_f[1];
	rubic[4][2][0]=temp_f[2];

}
void top(){
	moves+="t";
	printf("t ");
	int temp[3][3];
	for(int i=2,j=0;i>=0 && j<3;i--,j++)
	{
		for(int k=0;k<3;k++){
			temp[k][i]=rubic[4][j][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[4][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][0][0],rubic[2][0][1],rubic[2][0][2]};
	int temp_f[3]={rubic[0][0][0],rubic[0][0][1],rubic[0][0][2]};
	int temp_B[3]={rubic[1][0][0],rubic[1][0][1],rubic[1][0][2]};
	int temp_l[3]={rubic[3][0][0],rubic[3][0][1],rubic[3][0][2]};

	rubic[0][0][0]=temp_r[0];
	rubic[0][0][1]=temp_r[1];
	rubic[0][0][2]=temp_r[2];

	rubic[1][0][0]=temp_l[0];
	rubic[1][0][1]=temp_l[1];
	rubic[1][0][2]=temp_l[2];

	rubic[2][0][0]=temp_B[0];
	rubic[2][0][1]=temp_B[1];
	rubic[2][0][2]=temp_B[2];

	rubic[3][0][0]=temp_f[0];
	rubic[3][0][1]=temp_f[1];
	rubic[3][0][2]=temp_f[2];

}
void bottom(){
	moves+="b";
	printf("b ");
	int temp[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=2,k=0;j>=0 && k<3;j--,k++){
			temp[j][i]=rubic[5][i][k];
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			rubic[5][i][j]=temp[i][j];
		}
	}
	int temp_r[3]={rubic[2][2][0],rubic[2][2][1],rubic[2][2][2]};
	int temp_f[3]={rubic[0][2][0],rubic[0][2][1],rubic[0][2][2]};
	int temp_B[3]={rubic[1][2][0],rubic[1][2][1],rubic[1][2][2]};
	int temp_l[3]={rubic[3][2][0],rubic[3][2][1],rubic[3][2][2]};

	rubic[0][2][0]=temp_r[0];
	rubic[0][2][1]=temp_r[1];
	rubic[0][2][2]=temp_r[2];

	rubic[1][2][0]=temp_l[0];
	rubic[1][2][1]=temp_l[1];
	rubic[1][2][2]=temp_l[2];

	rubic[2][2][0]=temp_B[0];
	rubic[2][2][1]=temp_B[1];
	rubic[2][2][2]=temp_B[2];

	rubic[3][2][0]=temp_f[0];
	rubic[3][2][1]=temp_f[1];
	rubic[3][2][2]=temp_f[2];

	
}
bool checkTop(int T,int F,int B,int R,int L){
	if(rubic[4][0][1]==T && rubic[4][1][0]==T && rubic[4][1][2]==T && rubic[4][2][1]==T && rubic[0][0][1]==F && rubic[1][0][1]==B && rubic[2][0][1]==R && rubic[3][0][1]==L){
		return true;
	}
	else{
		return false;
	}
}
int find(int i,int T){
	if(rubic[i][0][1]==T){
		return 1;
	}
	else if(rubic[i][1][0]==T){
		return 2;
	}
	else if(rubic[i][1][2]==T){
		return 3;
	}
	else if(rubic[i][2][1]==T){
		return 4;
	}
	else{
		return 0;
	}
}
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
bool corner_check(){
	if(rubic[4][0][0]==4 && rubic[4][0][2]==4 && rubic[4][2][0]==4 && rubic[4][2][2]==4 && 
		rubic[0][0][0]==0 && rubic[0][0][2]==0 &&
		rubic[1][0][0]==1 && rubic[1][0][2]==1 &&
		rubic[2][0][0]==2 && rubic[2][0][2]==2 && 
		rubic[3][0][0]==3 && rubic[3][0][2]==3  ){
		return true;
	}
	else {
		return false;
	}
}
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
			front_find4();
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
			front_find3();
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



bool layer2_check(){
	if(rubic[0][1][0]==0 && rubic[0][1][2]==0 &&
		rubic[1][1][0]==1 && rubic[1][1][2]==1 &&
		rubic[2][1][0]==2 && rubic[2][1][2]==2 &&
		rubic[3][1][0]==3 && rubic[3][1][2]==3 ){
		return true;
	}
	else {
		return false;
	}
}
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
	printf("\n");
}
int main(){

	for(int i=0;i<6;i++){
		printf("Enter %c:\n",a[i]);
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				scanf("%d",&rubic[i][j][k]);
			}
		}
	}
	while(!checkTop(rubic[4][1][1],rubic[0][1][1],rubic[1][1][1],rubic[2][1][1],rubic[3][1][1])){
			cross_check();
	}
	while(!corner_check()){
		first_layer();
		printf("\n");
	}
	while(!layer2_check()){
		second_layer();
	}
	return 0;
}