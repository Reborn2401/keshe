#include"Graph.h"

void del_edge()//ɾ����
{
	int id, n, id2, i, j; router* p; edge* p2;
	cout << "ɾ���ĸ�·�����ıߣ�\n"; cin >> id;
	n = r_graph.getRouterPos(id); p = r_graph.get_r(n); p2 = p->ed;
	cout << "·������ţ�" << p->identi << endl;
	cout << "����ţ�" << p->net << endl;
	cout << "Ŀ��·������\t���룺\n";
	while (p2 != NULL)
	{
		cout << r_graph.get_r(p2->router2)->identi << "\t" << p2->distance << endl;
		p2 = p2->link;
	}p2 = p->ed;
	cout << "ɾ���ıߵ����ĸ�·������\n";
	cin >> id2;
	i = r_graph.getRouterPos(id); j = r_graph.getRouterPos(id2);
	while (p2 != NULL) { if (r_graph.get_r(p2->router2)->identi == id2)break; p2 = p2->link; }
	if (p2 != NULL) if (r_graph.removeEdge(i, j))cout << "ɾ���ɹ���\n"; else cout << "ɾ��ʧ�ܣ�\n";
	else cout << "û�е����·�����ıߣ�\n";
	cout << "shenruijie";
}

void del_rou()//ɾ��·��������
{
	int id, n;
	r_graph.n_output();
	cout << "ɾ���ĸ�·������\n";
	cin >> id;
	n = r_graph.getRouterPos(id);
	if (r_graph.removeRouter(n))cout << "ɾ���ɹ���\n";
	else cout << "ɾ��ʧ�ܣ�\n";
}
