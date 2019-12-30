#include"Graph.h"
#include"network topology definition.h"
void f_table()//查找路由表
{
	int id, locate; r_table* t;
	r_graph.n_output();
	cout << "请输入路由器的编号：\n";
	cin >> id;
	t = r_graph.get_t(id); if (t == NULL) { cout << "不存在该路由器\n"; return; }
	cout << *t->get_rid() << endl;
	cout << *t;
}