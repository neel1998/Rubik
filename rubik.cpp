#include<bits/stdc++.h>
#include "header.h"
using namespace std;
int rubic[6][3][3];
int cross[5]={0};
int corner[5]={0};
int x=-1;

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

	third_layer();
	// cout<<moves<<"\n";
	return 0;
}