#include <iostream>
#include <vector> 
#include <queue> 
#include <stack>
#include <cstring> 
using namespace std;

//�߱��� 
class EdgeList {
private:
    int vertex;
    EdgeList* next;
public:
    EdgeList* Create(int vertex) {
        EdgeList* list = new EdgeList;
        list->vertex = vertex;
        list->next = NULL;
        return list;
    }

    //Ѱ�����һ�����
    EdgeList* getLast(EdgeList* list) {
        EdgeList* cur = list;
        while (cur) {
            if (cur->next == NULL) {
                return cur;
            }
            cur = cur->next;
        }
        return cur;
    }

    //���뺯�� 
    EdgeList* Attach(EdgeList* list, int vertex) {
        EdgeList* last = this->getLast(list);
        EdgeList* insert = insert->Create(vertex);
        last->next = insert;
        return list;
    }

    int getVertex(EdgeList* list) {
        return list->vertex;
    }

    void Print(EdgeList* list) {
        EdgeList* cur = list;
        while (cur) {
            cout << cur->vertex << " ";
            cur = cur->next;
        }
    }

    EdgeList* getNext() {
        return this->next;
    }
};


class Graph {
private:
    vector<EdgeList*> Edgelist;     //�ڽӱ� 
    int* isvisited;                 //�������� 
    int Nv;         //������
    int Ne;         //���� 
public:
    //���캯�� 
    Graph(int nv, int ne) {
        this->Ne = ne;
        this->Nv = nv;
        this->Edgelist.reserve(nv);
        this->isvisited = new int[nv + 1];
        memset(this->isvisited, 0, sizeof(this->isvisited[0]) * (this->Nv + 1));
        cout << "�����붥�㣺" << endl;
        //���ι���ͼ�Ľ�� 
        for (int i = 0; i < this->Nv; i++) {
            int vertex;
            cin >> vertex;
            this->Edgelist[i] = new EdgeList;
            this->Edgelist[i] = this->Edgelist[i]->Create(vertex);
        }
        cout << "������ߣ�" << endl;
        //���ι�������ͼ�ı� 
        for (int i = 0; i < this->Ne; i++) {
            int start, end;
            cin >> start >> end;
            //�ҵ�һ���ߵ��������� 
            EdgeList* s1 = this->Find(start);
            EdgeList* s2 = this->Find(end);
            s1->Attach(s1, end);
            s2->Attach(s2, start);
        }
    }

    //��ָ��������
    EdgeList* Find(int vertex) {
        for (int i = 0; i < this->Nv; i++) {
            if (this->Edgelist[i]->getVertex(this->Edgelist[i]) == vertex) {
                return this->Edgelist[i];
            }
        }
      
    }

    //��ӡ�ڽӱ��� 
    void Print() {
        for (int i = 0; i < this->Nv; i++) {
            EdgeList* list = this->Edgelist[i];
            list->Print(list);
            cout << endl;
        }
    }

    //������ȱ���(BFS)
    void BFS(int vertex) {
        EdgeList* cur = this->Find(vertex);     //�ҵ���ǰ���    
        queue<int> queue;                   //��ʼ������ 
        queue.push(cur->getVertex(cur));            //��ǰ������
        while (!queue.empty()) {
            int index = queue.front();      //��ͷԪ�س���
            queue.pop();
            isvisited[index] = 1;               //���Ϊ�ѷ��� 
            cout << index << " ";
            cur = this->Find(index);
            while (cur) {     //�뵱ǰ���������δ�����ʵĽ����� 
                index = cur->getVertex(cur);
                if (isvisited[index] == 0) {
                    queue.push(index);
                }
                cur = cur->getNext();
            }
        }
    }

    //���÷������� 
    void reset() {
        memset(this->isvisited, 0, sizeof(this->isvisited[0]) * (this->Nv + 1));
    }

    //�ݹ�������ȱ���(DFS)
    void DFS1(int vertex) {
        vector<int> node;
        //�ҵ���ǰ��� 
        EdgeList* cur = this->Find(vertex);
        while (cur) {     //Ѱ�ҵ�ǰ�����ڽӵ� 
            node.push_back(cur->getVertex(cur));
            cur = cur->getNext();
        }
        //��ӡ��ǰ��� 
        cur = this->Find(node[0]);
        int index = cur->getVertex(cur);
        this->isvisited[index] = 1;
        cout << index << " ";
        //һ�ζѵ�ǰ�����ڽӵ����DFS 
        for (int i = 1; i < node.size(); i++) {
            cur = this->Find(node[i]);
            index = cur->getVertex(cur);
            if (this->isvisited[index] == 0) {
                this->isvisited[index] = 1;
                this->DFS1(index);
            }
        }
    }

    //�ǵݹ�������ȱ���(DFS)
    void DFS2(int vertex) {
        stack<int> stack;
        EdgeList* cur = this->Find(vertex);     //���ҵ�ǰԪ�� 
        int index = cur->getVertex(cur);        //��ǰԪ�صĶ��� 
        stack.push(index);                      //������ջ 
        this->isvisited[index] = 1;             //���Ϊ�ѷ��� 
        while (!stack.empty()) {          //ջ����һֱѭ�� 
            index = stack.top();        //ջ���Ķ����ջ 
            stack.pop();
            cout << index << " ";           //��ӡ��ǰ���� 
            cur = this->Find(index);
            while (cur) {         //�ѵ�ǰ������ڽӵ�������ջ 
                index = cur->getVertex(cur);
                if (this->isvisited[index] == 0) {
                    stack.push(index);
                    this->isvisited[index] = 1;
                }
                cur = cur->getNext();
            }
        }
    }
};

int main()
{
    cout << "�����붥���������:" << endl;
    int nv, ne;
    cin >> nv >> ne;
    Graph graph(nv, ne);
    cout << "�ڽӱ�Ϊ��" << endl;
    graph.Print();


    cout << "��������:" << endl;
    int vertex;
    cin >> vertex;

    cout << "������ȱ�����BFS������Ϊ��" << endl;
    graph.BFS(vertex);
    cout << endl;

    cout << "�ݹ�������ȱ�����DFS������Ϊ��" << endl;
    graph.reset();
    graph.DFS1(vertex);
    cout << endl;

    cout << "�ǵݹ�������ȱ�����DFS������Ϊ��" << endl;
    graph.reset();
    graph.DFS2(vertex);
    cout << endl;

    return 0;
}
