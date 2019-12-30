#include"Graph.h"
// ���캯��:����һ���յ��ڽӱ�
Graphlnk::Graphlnk(int sz) {
	maxVertices = sz;
	numRouters = 0;
	numEdges = 0;
	nodeTable = new router[maxVertices]; // �������������
	if (nodeTable == NULL) {
		cerr << "�洢�ռ�������" << endl;
		exit(1);
	}
	for (int i = 0; i < maxVertices; i++)
		nodeTable[i].ed = NULL;
}

// ��������
Graphlnk::~Graphlnk() {
	// ɾ�����������еĽ��
	for (int i = 0; i < numRouters; i++) {
		edge* p = nodeTable[i].ed; // �ҵ����Ӧ������׽��
		while (p != NULL) { // ���ϵ�ɾ����һ�����
			nodeTable[i].ed = p->link;
			p->~edge();
			p = nodeTable[i].ed;
			;
		}
	}
	delete[]nodeTable; // ɾ�����������
}

// �����ڽӱ��ʾ��ͼ
void Graphlnk::inputGraph() {
	int n, m; // �洢�������ͱ���
	char net[20];
	int i, j, k;
	int e1, e2; // ����
	int weight; // �ߵ�Ȩֵ

	cout << "�����붥�����ͱ�����" << endl;
	cin >> n >> m;
	cout << "����������㣺(·������ż��������)" << endl;
	for (i = 0; i < n; i++) {
		cin >> e1; cin >> net;
		if (insertRouter(e1))strncpy_s(nodeTable[numRouters - 1].net, net, 20); // ���붥��
	}

	cout << "������ͼ�ĸ��ߵ���Ϣ��(·����1��·����2������)" << endl;
	i = 0;
	while (i < m) {
		cin >> e1 >> e2 >> weight;
		j = getRouterPos(e1);
		k = getRouterPos(e2);
		if (j == -1 || k == -1)
			cout << "�����˵���Ϣ�������������룡" << endl;
		else {
			insertEdge(j, k, weight, 0); // �����
			insertEdge(k, j, weight, 0);
			i++;
		}
	} // while
	t_rebuild();
}

void Graphlnk::br_table(int v)
{
	int i, min, j, k, w, h;  router* r = &nodeTable[v];
	rtuple* p1; p1 = r->table->getfirst();
	int S[DefaultVertices], distance[DefaultVertices], path[DefaultVertices];
	int* c = r->table->get_rid(); *c = nodeTable[v].identi;//��·�ɱ�����·������ֵ
	for (i = 0; i < numRouters; i++)
	{
		S[i] = 0;
		distance[i] = getDistance(v, i);
		if (i != v && distance[i] < maxDistance)path[i] = v;
		else path[i] = -1;
	}
	S[v] = 1; distance[v] = 0;
	for (i = 0; i < numRouters - 1; i++)
	{
		min = maxDistance; int u = v;
		for (j = 0; j < numRouters; j++)
		{
			if (S[j] == 0 && distance[j] < min) { u = j; min = distance[j]; }
		}
		S[u] = 1;
		for (k = 0; k < numRouters; k++)
		{
			w = getDistance(u, k);
			if (S[k] == 0 && w < maxDistance && distance[u] + w < distance[k])
			{
				distance[k] = distance[u] + w;
				path[k] = u;
			}
		}
	}
	for (i = 0; i < numRouters; i++)
	{
		strncpy_s(p1->destn, nodeTable[i].net, 20);
		p1->distance = distance[i]; j = i;
		do
		{
			k = j;
			j = path[k];
		} while (j != v && j >= 0);
		if (i != v)p1->next = nodeTable[k].identi
			; else p1->next = -1;
		if (i < numRouters - 1)
		{
			p1->link = new rtuple; p1 = p1->link;
		} r->table->size_add();

	}
	p1->link = NULL;
}

void Graphlnk::insertGraph(router & r)
{
	if (numRouters == maxVertices) { cout << "ͼ����������ʧ�ܣ�\n"; return; }
	edge* p = r.ed;
	nodeTable[numRouters] = r; numRouters++;
	while (p != NULL)numEdges++;
}

// ���ͼ�е����ж���ͱ���Ϣ
void Graphlnk::outputGraph() {
	int n, m, i, j;
	int e1, e2; // ����
	int weight; // Ȩֵ

	n = numRouters;
	m = numEdges;
	cout << "ͼ�еĶ�����Ϊ" << n << ",����Ϊ" << m << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			weight = getDistance(i, j); // ȡ�ߵ�Ȩֵ
			if (weight > 0 && weight < maxDistance) { // ��Ч
				e1 = getIdenti(i); // ����
				e2 = getIdenti(j);
				cout << "(" << e1 << "," << e2 << "," << weight << ")" << endl;
			}
		} // ��ѭ��for
	} // ��ѭ��for
}

// ȡλ��Ϊi�Ķ����е�ֵ
int Graphlnk::getIdenti(int i) {
	if (i >= 0 && i < numRouters)
		return nodeTable[i].identi;
	return NULL;
}

// ���رߣ�v1�� v2���ϵ�Ȩֵ
int Graphlnk::getDistance(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		edge* p = nodeTable[v1].ed; // v1�ĵ�һ�������ı�
		while (p != NULL && p->router2 != v2) { // Ѱ���ڽӶ���v2
			p = p->link;
		}
		if (p != NULL)
			return p->distance;
	}
	return maxDistance; // ��(v1, v2)������
}

// ���붥��
bool Graphlnk::insertRouter(const int& vertex) {
	if (numRouters == maxVertices) // ������������ܲ���
		return false;
	nodeTable[numRouters].identi = vertex; // �����ڱ�����
	numRouters++;
	return true;
}

// �����
bool Graphlnk::insertEdge(int v1, int v2, int weight, int com) {
	if (v1 >= 0 && v1 < numRouters && v2 >= 0 && v2 < numRouters) {
		edge* q, * p = nodeTable[v1].ed; // v1��Ӧ�ı�����ͷָ��
		while (p != NULL && p->router2 != v2) // Ѱ���ڽӶ���v2
		{
			p = p->link;
		}
		if (p != NULL) // �Ѵ��ڸñߣ�������
			return false;
		p = new edge; // �����½��
		p->router2 = v2;
		p->distance = weight;
		p->link = nodeTable[v1].ed; // ����v1������
		nodeTable[v1].ed = p;
		numEdges++;
		q = new edge;
		q->router2 = v1;
		q->distance = weight;
		q->link = nodeTable[v2].ed; // ����v2������
		nodeTable[v2].ed = q;
		numEdges++;
		if (com == 1)
			t_rebuild();
		return true;
	}
	return false;
}

// ɾ������
bool Graphlnk::removeRouter(int v) {
	if (numRouters == 1 || v < 0 || v > numRouters)
		return false; // ��ջ򶥵�ų�����Χ

	edge * p, *s, *t;
	int k; // �洢�ڽӶ���
	while (nodeTable[v].ed != NULL) {
		p = nodeTable[v].ed;
		k = p->router2; // ȡ�ڽӶ���k
		s = nodeTable[k].ed; // �ҶԳƴ�ŵı߽��
		t = NULL;
		while (s != NULL && s->router2 != v) {
			t = s;
			s = s->link;
		}
		if (s != NULL) { // ɾ���Գƴ�ŵı߽��
			if (t == NULL) // ɾ�����ǵ�һ���ڽӶ���
				nodeTable[k].ed = s->link;
			else
				t->link = s->link;
			delete s;
		}
		nodeTable[v].ed = p->link; // �������v�ı�������
		delete p;
		numEdges--; // �붥��v������ı�����1
	} // while����
	numRouters--; // ͼ�Ķ��������1
	nodeTable[v] = nodeTable[numRouters]; // �
	p = nodeTable[v].ed = nodeTable[numRouters].ed;
	// Ҫ����Ķ����Ӧ��λ�ø�д
	while (p != NULL) {
		s = nodeTable[p->router2].ed; // �ԳƱ�������
		while (s != NULL) {
			if (s->router2 == numRouters) { // �ҵ��ԳƱ�
				s->router2 = v; // �޸�ָ��v
				break;
			}
			s = s->link;
		}
		p = p->link; // ָ����һ���ڽӶ���
	}
	t_rebuild();
	return true;
}

// ɾ����
bool Graphlnk::removeEdge(int v1, int v2) {
	if (v1 != -1 && v2 != -1) {
		edge* p = nodeTable[v1].ed, * q = NULL, * s = p;
		while (p != NULL && p->router2 != v2) { // v1��Ӧ���������ұ�ɾ����
			q = p;
			p = p->link;
		}
		if (p != NULL) { // �ҵ���ɾ���߽��
			if (p == s) // �ý���Ǳ�������׽��
				nodeTable[v1].ed = p->link;
			else
				q->link = p->link; // ���ǣ���������
			delete p;
		}
		else // û�ҵ�
			return false;

		// v2��Ӧ��������ɾ��
		p = nodeTable[v2].ed;
		q = NULL;
		s = p; // �����׽��
		while (p != NULL && p->router2 != v1) { // Ѱ�ұ�������Ҫɾ���Ľ��
			q = p;
			p = p->link;
		}
		if (p == s) // ɾ���ĸý���Ǳ�������׽��
			nodeTable[v2].ed = p->link;
		else
			q->link = p->link; // ���ǣ���������
		p->~edge(); t_rebuild();
		return true;
	}

	return false; // û���ҵ����
}

// ȡ����v�ĵ�һ���ڽӶ���
int Graphlnk::getFirstNeighbor(int v) {
	if (v != -1) {
		edge* p = nodeTable[v].ed; // ��Ӧ�����һ���߽��
		if (p != NULL) // ���ڣ����ص�һ���ڽӶ���
			return p->router2;
	}
	return -1; // ��һ���ڽӶ��㲻����
}

// ȡ����v���ڽӶ���w����һ�ڽӶ���
int Graphlnk::getNextNeighbor(int v, int w) {
	if (v != -1) {
		edge* p = nodeTable[v].ed; // ��Ӧ�����һ���߽��
		while (p != NULL && p->router2 != w) // Ѱ���ڽӶ���w
			p = p->link;
		if (p != NULL && p->link != NULL)
			return p->link->router2;  // ������һ���ڽӶ���
	}
	return -1; // ��һ���ڽӶ��㲻����
}

// ��������vertex��ͼ�е�λ��
int Graphlnk::getRouterPos(const int vertex) {
	for (int i = 0; i < numRouters; i++)
		if (nodeTable[i].identi == vertex)
			return i;
	return -1;
}

// ��ǰ������
int Graphlnk::numberOfRouters() {
	return numRouters;
}

void Graphlnk::t_rebuild()//�ؽ�����·�ɱ�
{
	for (int i = 0; i < numRouters; i++)
	{
		if (nodeTable[i].table == NULL)continue;

		nodeTable[i].apply();
		br_table(i);
	}

}
