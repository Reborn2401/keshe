#ifndef Graph_h
#define Graph_h
#include <iostream>
#include"network topology definition.h"
#include<fstream>
using namespace std;

const int DefaultVertices = 30;
void g_build();//创建网络拓扑图
void f_table();//查询路由表
void g_update();//更新网络拓扑图
void del_edge();//删除边
void del_rou();//删除顶点

class Graphlnk {
	friend class r_table;
public:
	const int maxDistance = 100000; // 代表无穷大的值（=∞）
	Graphlnk(int sz = DefaultVertices); // 构造函数
	~Graphlnk(); // 析构函数
	void inputGraph(); // 建立邻接表表示的图
	void outputGraph(); // 输出图中的所有顶点和边信息
	void insertGraph(router& r);//插入一个路由器顶点
	int getIdenti(int i); // 取位置为i的顶点中的值
	int getDistance(int v1, int v2); // 返回边（v1， v2）上的权值
	bool insertRouter(const int& vertex); // 插入顶点
	bool insertEdge(int v1, int v2, int weight, int com); // 插入边
	bool removeRouter(int v); // 删除顶点
	bool removeEdge(int v1, int v2); // 删除边
	int getFirstNeighbor(int v); // 取顶点v的第一个邻接顶点
	int getNextNeighbor(int v, int w); // 取顶点v的邻接顶点w的下一邻接顶点
	int getRouterPos(const int vertex); // 给出顶点vertex在图中的位置
	int numberOfRouters(); // 当前顶点数
	void br_table(int i);//创建位置为i的路由器的路由表
	router* get_r(int i) { return &nodeTable[i]; }//给出位置为i的路由器顶点的地址
	void t_rebuild();//重建所有路由表
	r_table* get_t(int id) {
		for (int i = 0; i < numRouters; i++)if (nodeTable[i].identi == id) return nodeTable[i].table;
		return NULL;
	}
	//返回指定路由器的路由表
	void n_output() {//输出顶点的基本信息
		cout << "路由器编号\t网络号\t\n";
		for (int i = 0; i < numRouters; i++)cout << nodeTable[i].identi << ": " << nodeTable[i].net << endl;;
	}
private:
	int maxVertices; // 图中最大的顶点数
	int numEdges; // 当前边数
	int numRouters; // 当前顶点数
	router* nodeTable; // 顶点表(各边链表的头结点)

};


extern Graphlnk r_graph;

#endif /* Graph_h */
#pragma once
