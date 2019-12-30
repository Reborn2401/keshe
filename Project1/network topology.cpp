#include <iostream>
#include<fstream>
#include<stdlib.h>
#include"Graph.h"
#include"network topology definition.h"
ifstream fin;
Graphlnk r_graph;




using namespace std;

int main()
{
	char option; int circle = 1;
	g_build();
	while (circle)
	{
		cout << "��ѡ��������еĲ�����\n";
		cout << "1.��ѯ·�ɱ�\n2.������������ͼ\n3.�˳�ϵͳ\n";
		cin >> option;
		switch (option)
		{
		case '1':f_table(); break;
		case'2':g_update(); break;
		case'3':circle = 0; break;
		default:
			break;
		}
		cout << "���������ַ�������\n";
		fflush(stdin);
		cin.get();
		cin.get();
		system("cls");
	}
	return 0;
}



void g_build()
{
	router R; int r1, r2, d, n;
	fin.open("Router.txt");//���붥����Ϣ
	if (!fin.is_open()) { cout << "�����ļ���ʧ�ܣ��˳�����\n"; exit(EXIT_FAILURE); }
	while (fin >> n) { if (n == 0)break; R.identi = n; fin >> R.net; r_graph.insertGraph(R); }
	//�������Ϣ
	while (fin >> r1) {
		fin >> r2; fin >> d; r_graph.insertEdge(r1 - 1, r2 - 1, d, 0);
	}
	fin.close();
	r_graph.t_rebuild();
}



