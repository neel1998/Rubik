#ifndef HEAD_H
	#define HEAD_H

	void Front();
	void Back();
	void Right();

	void Left();
	void Top();
	void Bottom();
	void front();

	void back();
	void right();
	void left();
	void top();
	void bottom();
	void cross_check();
	void first_layer();
	void second_layer();
	void third_layer();
	int find(int i,int T);
	extern int rubic[6][3][3];
	extern int cross[5];
	extern int corner[5];
	extern int x;
	extern std::string moves;

#endif