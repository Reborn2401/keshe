#include"Graph.h"

void del_edge()//删除边
{
	int id, n, id2, i, j; router* p; edge* p2;
	cout << "删除哪个路由器的边？\n"; cin >> id;
	n = r_graph.getRouterPos(id); p = r_graph.get_r(n); p2 = p->ed;
	cout << "路由器编号：" << p->identi << endl;
	cout << "网络号：" << p->net << endl;
	cout << "目的路由器：\t距离：\n";
	while (p2 != NULL)
	{
		cout << r_graph.get_r(p2->router2)->identi << "\t" << p2->distance << endl;
		p2 = p2->link;
	}p2 = p->ed;
	cout << "删除的边到达哪个路由器？\n";
	cin >> id2;
	i = r_graph.getRouterPos(id); j = r_graph.getRouterPos(id2);
	while (p2 != NULL) { if (r_graph.get_r(p2->router2)->identi == id2)break; p2 = p2->link; }
	if (p2 != NULL) if (r_graph.removeEdge(i, j))cout << "删除成功！\n"; else cout << "删除失败！\n";
	else cout << "没有到达该路由器的边！\n";
	cout << "shenruijie";
}

void del_rou()//删除路由器顶点
{
	int id, n;
	r_graph.n_output();
	cout << "删除哪个路由器？\n";
	cin >> id;
	n = r_graph.getRouterPos(id);
	if (r_graph.removeRouter(n))cout << "删除成功！\n";
	else cout << "删除失败！\n";
}
