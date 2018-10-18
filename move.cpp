#include<bits/stdc++.h>
#include "header.h"
using namespace std;
string moves;
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