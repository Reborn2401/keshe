#include"Graph.h"

void g_update()//��������ͼ
{
	r_graph.outputGraph();
	char option;
	cout << "��ѡ��������еĲ�����\n";
	cout << "1.ɾ����\n2.����·��������\n3.ɾ������\n�������������˵�\n";
	cin >> option;
	switch (option)
	{
	case'1':del_edge(); break;
	case'2':r_graph.inputGraph(); break;
	case'3':del_rou(); break;
	default:return;
		break;
	}

}