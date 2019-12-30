#include"Graph.h"

void g_update()//更新拓扑图
{
	r_graph.outputGraph();
	char option;
	cout << "请选择您想进行的操作：\n";
	cout << "1.删除边\n2.插入路由器、边\n3.删除顶点\n其他：返回主菜单\n";
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