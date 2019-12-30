#include"Graph.h"

ostream& operator<<(ostream& out, r_table& r)
{
	rtuple* p = r.first;
	out << "路由器：" << r.identi << endl;
	out << "当前路由表长度：" << r.currentsize << endl;

	out << "\t目的网络\t距离\t下一跳\n";
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
	cout << "路由器编号：" << r.identi << endl;
	cout << "网络号：" << r.net << endl;
	cout << "目的路由器：\t距离：\n";
	while (p != NULL)
	{
		out << p->router2 << "\t" << p->distance << endl;
		p = p->link;
	}
	return out;
}


