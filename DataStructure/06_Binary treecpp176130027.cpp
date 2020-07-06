#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<queue> 
using namespace std;
typedef int ElemType;
struct NodeType       	                    //������ �ṹ��
{
	ElemType   data;
	NodeType* lch, * rch;
};
class BiTree    	                     //���� �������� class
{
public:
	BiTree() { root = NULL; };                    //���캯��
	~BiTree() { destroy(root); }                  //��������
	void inorder()                            //�������
	{
		inorder(root);
	}
	void preordertswap()                       //���������������������������
	{
		preorderswap(root);
	}
	int  tleaf()                             //����Ҷ�ӽڵ�ĸ���
	{
		return leaf(root);
	}
	void creat0();
	void level_traversal()                       //���������������������������
	{
		level_traversal(root);
	}
private:
	NodeType* root;                         //���ݳ�Ա������
	NodeType* creat();                       //�����������ݹ鷽��
	void inorder(NodeType* p);                //�������
	void preorderswap(NodeType* p);           //���������������������������
	int leaf(NodeType* p);	               //���������Ҷ�ӽڵ�ĸ���
	void  destroy(NodeType*& p);             //ɾ�����������н��
	void level_traversal(NodeType* p);     //��α���������
};
void  BiTree::creat0()                         //������������
{
	cout << "�밴�������������˳����֯����" << endl;
	cout << "�������Ϣ��int����ÿ�����Ŀպ�����0����;" << endl;
	cout << "һ�����Ķ�����11�����룺11 0 0;" << endl;
	root = creat();                            //����˽��creat();
}
NodeType* BiTree::creat()                      //�ݹ齨���������㷨
{
	NodeType* p;   ElemType x;
	cout << "\n �������ݣ�";  cin >> x;
	if (x == 0) p = NULL;
	else {
		p = new NodeType;
		p->data = x;
		p->lch = creat();                  //�ݹ��������
		p->rch = creat();
	}
	return p;
}
void BiTree::inorder(NodeType* p)             //�������
{
	if (p != NULL)
	{
		inorder(p->lch);
		cout << p->data << " ";
		inorder(p->rch);

	}
	
}
void BiTree::preorderswap(NodeType* p)         //���������������������������
{
	if (p != NULL)
	{
		NodeType* r; r = p->lch;
		p->lch = p->rch; p->rch = r;
		//���漸����������Ϊ�Խ��ķ��ʣ��������Һ��ӣ�
		//�滻��ԭ���ģ� cout<<p->data<<" ";  ���
		preorderswap(p->lch);
		preorderswap(p->rch);
	}
}
void  BiTree::destroy(NodeType*& p)            //ɾ�����������н��
{
	if (p != NULL)
	{
		destroy(p->lch);
		destroy(p->rch);
		delete p;
		p = NULL;
	}
}
int BiTree::leaf(NodeType* p)                //���������Ҷ�ӽڵ�ĸ���
{
	int nodes = 0;
	if (p == NULL)//����Ϊ��ʱ��Ҷ�ӽ�����Ϊ0
		return 0;
	else if (p->lch == NULL && p->rch == NULL)//��ĳ���ڵ������������Ϊ��ʱ�������ý��ΪҶ�ӽ�㣬����1
		return 1;
	else
		nodes = leaf(p->lch) + leaf(p->rch);
	//��ĳ���ڵ�����������������������ʱ�����߼�������������������ʱ
    //˵���ýڵ㲻��Ҷ�ӽ�㣬���Ҷ������������������Ҷ�ӽ����� ���� ��������Ҷ�ӽ��ĸ���
	return nodes;

}
void BiTree::level_traversal(NodeType* p)
{
	queue< NodeType*> q;
	q.push(p);
	int cnt = 1;
	while (!q.empty())
	{
		if (q.front()->lch != NULL)
		{
			q.push(q.front()->lch);
		}
		if (q.front()->rch != NULL)
		{
			q.push(q.front()->rch);
		}
		cout << q.front()->data << " ";
		q.pop();
	}

}
//---------------------------------------------------------------------------
int main()
{
	int k;     BiTree root0;                     //�����������������󣬵��ù��캯��
	do {
		cout << "\n\n";
		cout << "\n\n     1. ����������";
		cout << "\n\n     2. ������������ ";
		cout << "\n\n     3. ���������Ҷ�ӽڵ�ĸ���  ";
		cout << "\n\n     4. ��������������  ";
		cout << "\n\n     5. ������������";
		cout << "\n======================================";
		cout << "\n     ����������ѡ�� (0,1,2,3,4):"; cin >> k;
		switch (k)
		{
		case 1: {  cout << "\n  s���루0 0��������";
			root0.creat0();
			cout << "\n     ���ȸ����������";  root0.inorder();
		} break;
		case 2: {  cout << "\n     �����������������";
			root0.preordertswap();
			cout << "\n     ���ȸ����������";
			root0.inorder();
		} break;
		case 3: {   int number;
			number = root0.tleaf();
			cout << "\n  Ҷ�ӽڵ�ĸ����ǣ�" << number;
		} break;

		case 4: {
			cout << "\n c��α�������ǣ�" << endl;
			root0.level_traversal();
		} break;

		case 5: exit(0);
		} //  switch
		cout << "\n ----------------";
	} while (k >= 0 && k < 5);
	_getch();   return 0;
}//-----  
