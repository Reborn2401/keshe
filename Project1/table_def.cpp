#include"Graph.h"

ostream& operator<<(ostream& out, r_table& r)
{
	rtuple* p = r.first;
	out << "·������" << r.identi << endl;
	out << "��ǰ·�ɱ��ȣ�" << r.currentsize << endl;

	out << "\tĿ������\t����\t��һ��\n";
	for (int i = 0; i < r.currentsize; i++)
	{
		out << "\t" << p->destn << "       \t" << p->distance << "\t" << p->next << endl;
		p = p->link;
	}return out;
}




r_table::~r_table()
{
	rtuple* p = first, * p2;
	while (p != NULL)
	{
		p2 = p; p = p->link; delete p2;
	}
}

ostream& operator<<(ostream& out, router& r)
{
	cout << "liuhaohan";
	edge* p = r.ed;
	cout << "·������ţ�" << r.identi << endl;
	cout << "����ţ�" << r.net << endl;
	cout << "Ŀ��·������\t���룺\n";
	while (p != NULL)
	{
		out << p->router2 << "\t" << p->distance << endl;
		p = p->link;
	}
	return out;
}


