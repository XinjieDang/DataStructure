#include <iostream>
#include <queue>
#include <stack>
using namespace std;
//ͼ�ı�ʾ �ڽӾ���
class Graph {
private:
	int** G;  //�ڽӾ���
	int* isvisited;  // ��������
	int Nv;//������
	int Ne;//����
public :
	//���캯��  
	Graph(int nv, int ne) {
		this->Nv = nv;
		this->Ne = ne;
		this->G = new int* [nv + 1];
		this->isvisited = new int[nv + 1];
		memset(isvisited, 0, sizeof(isvisited[0]) * (nv + 1));
		for (int i = 0; i < nv + 1; i++) {
			G[i] = new int[nv + 1];
			memset(G[i], 0, sizeof(G[i][0]) * (nv + 1));
		}
		cout << "������ߣ�" << endl;
		for (int i = 0; i < ne; i++) {
			int a, b;
			cin >> a >> b;
			this->G[a][b] = 1;
			this->G[b][a] = 1;
		}
	}
	void reset() {
		memset(this->isvisited, 0, sizeof(this->isvisited[0]) * (this->Nv + 1));
	}
	void BFS(int vertex) {    //������ȱ���BFS
		queue<int>queue;
		queue.push(vertex);   //��ʼ������
		this->isvisited[vertex] = 1;
		int now;
		while (!queue.empty()) {  //�Ӳ���һֱѭ��
			now = queue.front();  //��ͷԪ�س�ջ
			queue.pop();
			cout << now << " ";      //��ӡ��ǰ���
				int  i = 1;
				while (i <= this->Nv) {// �뵱ǰ��������� δ�����ʹ��Ľ�����
					if (this->G[now][i] == 1 && isvisited[i] == 0) {
						queue.push(i);
						this->isvisited[i] = 1;//����������Ӧ����1
					}
					i++;
				}
		}
	}
	void DFS1(int vertex) {// �ݹ�������ȱ���DFS
		cout << vertex << " ";
		this->isvisited[vertex] = 1; //��Ӧλ�ķ���������1
		for (int i = 1; i <= this->Nv; i++) {
			//���εݹ������ǰ����δ�����ʵ��ڽ��
			if (this->G[vertex][i] == 1 && this->isvisited[i] == 0) {
				this->isvisited[i] = 0;
				this->DFS1(i);
				this->isvisited[i] = 0;
		
			}
			
		}
		this->isvisited[vertex] = 0;

	}
	
	void DFS2(int vertex) {// �ǵݹ�������ȱ��� DFS
		stack<int>stack;
		stack.push(vertex);  //��ǰ�����ջ
		this->isvisited[vertex] = 1; //��Ӧλ�ķ���������1
		int now;
		while (!stack.empty()) { //ջ����ʱһֱѭ��
			now = stack.top();  // ��ǰ����ջ
			stack.pop();
			cout << now << " "; //��ӡ��ǰ���
			//�ѵ�ǰ����δ�����ʹ����ڽӵ�������ջ������Ӧ����������1
			for (int i = 1; i <= this->Nv; i++) {
				if (this->G[now][i] != 0 && this->isvisited[i] == 0) {
					stack.push(i);
					this->isvisited[i] = 1;
					
				}
			}
		}

	}

};

int  main()
{
	cout << "�������������ͱ���!" << endl;
	int nv, ne;
	cin >> nv;
	cin>> ne;
	Graph graph(nv, ne);
	cout << "�������һ�����ʵĽ��" << endl;
	int now;
	cin >> now;
	cout << "������ȱ���BFS ����Ϊ" << endl;
	graph.BFS(now);
	cout << endl;
	return 0;

}