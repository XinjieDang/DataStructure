#include<iostream>
#include<queue>
using namespace std;
class BinaryTree {
private:
	char data;
	BinaryTree* lchild;
	BinaryTree* rchild;
public:
	BinaryTree* Create_BinaryTree() {
		BinaryTree* T = new BinaryTree;
		char ch;
		cin >> ch;
		if (ch == '#') {   //�������# ��������
			T = NULL;
		}
		else {
			T->data = ch;   //������
			T->lchild = Create_BinaryTree();//�ݹ鹹��������
			T->rchild = Create_BinaryTree();//�ݹ鹹��������
		}
		return T;
	}
	void PreTraversal(BinaryTree* T);//�ݹ��������
	void InorderTraversal(BinaryTree* T);//�ݹ��������
	void PostorderTraversal(BinaryTree* T);//�ݹ���������
	void levelOrderTraversal(BinaryTree* T);//��α���
	int getBinaryTreeHeight(BinaryTree* T);//�������ĸ߶�
};
void BinaryTree::PreTraversal(BinaryTree* T) {//�ݹ��������
	if (T == NULL) {
		return;
	}
	cout << T->data; //����˳�� �� -��-��
	PreTraversal(T->lchild);
	PreTraversal(T->rchild);
}	

void BinaryTree::InorderTraversal(BinaryTree* T) {//�ݹ��������
	if (T == NULL) {
		return;
	}
	PreTraversal(T->lchild);
	cout << T->data; //����˳�� �� -��-��
	PreTraversal(T->rchild);
}

void BinaryTree::PostorderTraversal(BinaryTree* T) {//�ݹ���������
	if (T == NULL) {
		return;
	}
	PreTraversal(T->lchild);
	PreTraversal(T->rchild);
	cout << T->data; //����˳�� �� -��-��-

}
void  BinaryTree::levelOrderTraversal(BinaryTree* T) {
	queue<BinaryTree*> queue;
	BinaryTree* cur = T;
	//ͷ������
	queue.push(cur);
	//����Ϊ��ʱ��ѭ������
	while (!queue.empty()) {
		//����ͷԪ�س���
		cur = queue.front();
		queue.pop();
		cout << cur - data << "";
		//���Ӳ�Ϊ�����
		if (cur->lchild != NULL) {
			queue.push(cur->lchild);
		}
		//�Һ��Ӳ�Ϊ�����
		if (cur->rchild != NULL) {
			queue.push(cur->rchild);
		}
	}
}
int BinaryTree::getBinaryTreeHeight(BinaryTree* T) {
	if(T){
		//�ݹ����������߶�
		int lheight = T->getBinaryTreeHeight(T->lchild);
		//�ݹ����������߶�
		int rheight = T->getBinaryTreeHeight(T->rchild);
		//�������ĸ߶ȵ���������������߼��ϸ��ĸ߶�
		int height = (lheight > rheight) ? lheight:rheight;
		height++;
	}
	return 0;

}
int main() {
	cout << "��ʼ��һ��������" << endl;
	BinaryTree* T = new BinaryTree;
	T = T->Create_BinaryTree();
	cout << "�������������˳��Ϊ" << endl;
	T->PreTraversal(T);
	return 0;
}
