#include"Graph.h"
#include"network topology definition.h"
void f_table()//����·�ɱ�
{
	int id, locate; r_table* t;
	r_graph.n_output();
	cout << "������·�����ı�ţ�\n";
	cin >> id;
	t = r_graph.get_t(id); if (t == NULL) { cout << "�����ڸ�·����\n"; return; }
	cout << *t->get_rid() << endl;
	cout << *t;
}