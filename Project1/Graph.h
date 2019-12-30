#ifndef Graph_h
#define Graph_h
#include <iostream>
#include"network topology definition.h"
#include<fstream>
using namespace std;

const int DefaultVertices = 30;
void g_build();//������������ͼ
void f_table();//��ѯ·�ɱ�
void g_update();//������������ͼ
void del_edge();//ɾ����
void del_rou();//ɾ������

class Graphlnk {
	friend class r_table;
public:
	const int maxDistance = 100000; // ����������ֵ��=�ޣ�
	Graphlnk(int sz = DefaultVertices); // ���캯��
	~Graphlnk(); // ��������
	void inputGraph(); // �����ڽӱ��ʾ��ͼ
	void outputGraph(); // ���ͼ�е����ж���ͱ���Ϣ
	void insertGraph(router& r);//����һ��·��������
	int getIdenti(int i); // ȡλ��Ϊi�Ķ����е�ֵ
	int getDistance(int v1, int v2); // ���رߣ�v1�� v2���ϵ�Ȩֵ
	bool insertRouter(const int& vertex); // ���붥��
	bool insertEdge(int v1, int v2, int weight, int com); // �����
	bool removeRouter(int v); // ɾ������
	bool removeEdge(int v1, int v2); // ɾ����
	int getFirstNeighbor(int v); // ȡ����v�ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w); // ȡ����v���ڽӶ���w����һ�ڽӶ���
	int getRouterPos(const int vertex); // ��������vertex��ͼ�е�λ��
	int numberOfRouters(); // ��ǰ������
	void br_table(int i);//����λ��Ϊi��·������·�ɱ�
	router* get_r(int i) { return &nodeTable[i]; }//����λ��Ϊi��·��������ĵ�ַ
	void t_rebuild();//�ؽ�����·�ɱ�
	r_table* get_t(int id) {
		for (int i = 0; i < numRouters; i++)if (nodeTable[i].identi == id) return nodeTable[i].table;
		return NULL;
	}
	//����ָ��·������·�ɱ�
	void n_output() {//�������Ļ�����Ϣ
		cout << "·�������\t�����\t\n";
		for (int i = 0; i < numRouters; i++)cout << nodeTable[i].identi << ": " << nodeTable[i].net << endl;;
	}
private:
	int maxVertices; // ͼ�����Ķ�����
	int numEdges; // ��ǰ����
	int numRouters; // ��ǰ������
	router* nodeTable; // �����(���������ͷ���)

};


extern Graphlnk r_graph;

#endif /* Graph_h */
#pragma once
