#pragma once


#include<iostream>
#include<string>

using namespace std;



struct rtuple //·�ɱ�Ԫ����
{
	char destn[20];//Ŀ������
	int distance;//����
	int next;//��һ��
	rtuple* link;//������һ��
	rtuple() { link = NULL; }
	rtuple(char* de, int d, int n, rtuple* l = NULL)
		:distance(d), link(l), next(n) {
		strncpy_s(destn, de, 20);
	}
};




class r_table //·�ɱ���
{
public:
	r_table() {
		last = NULL; currentsize = 0; first = new rtuple;
	}//���캯��
	r_table(int id) { identi = id; first = new rtuple; last = NULL; currentsize = 0; }//���캯��
	~r_table();//��������
	rtuple* getfirst() { return first; }//ȡ��һ��
	int* get_rid() { return &identi; }//ȡ·�ɱ��Ŵ洢��ַ
	void size_add() { currentsize++; }
	int getsize() { return currentsize; }
private:
	int identi;//·�������
	rtuple* first;//��һ��
	rtuple* last;//���һ��
	int currentsize;
	rtuple* search(char* d) {
		rtuple* p = first;
		while (p != NULL) { if (!strcmp(d, p->destn))return p; p = p->link; }
		return p;
	}
	friend ostream& operator<<(ostream& out, r_table& r);//���·�ɱ�
};

struct edge//��
{
	int router2;//��һ����λ��
	int distance;//����
	edge* link;//��һ������ָ��
	edge() { link = NULL; }
	~edge() {}
};


struct router//·���������㣩
{
	int identi;//·�������
	char net[20];//�����
	r_table* table;//·�ɱ���
	edge* ed;//������ͷָ��
	router() { ed = NULL; table = new r_table; }
	router(int i, char* n) :identi(i) { strncpy_s(net, n, 20); ed = NULL; table = new r_table; }
	void apply() { table = new r_table; }//����һ���µı�
	friend ostream& operator<<(ostream& out, router& r);//���·�����Լ����ıߵ���Ϣ
};



#pragma once
