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
		if (ch == '#') {   //如果输入# 则代表结束
			T = NULL;
		}
		else {
			T->data = ch;   //构造结点
			T->lchild = Create_BinaryTree();//递归构造左子树
			T->rchild = Create_BinaryTree();//递归构造右子树
		}
		return T;
	}
	void PreTraversal(BinaryTree* T);//递归先序遍历
	void InorderTraversal(BinaryTree* T);//递归中序遍历
	void PostorderTraversal(BinaryTree* T);//递归后序序遍历
	void levelOrderTraversal(BinaryTree* T);//层次遍历
	int getBinaryTreeHeight(BinaryTree* T);//二叉树的高度
};
void BinaryTree::PreTraversal(BinaryTree* T) {//递归先序遍历
	if (T == NULL) {
		return;
	}
	cout << T->data; //访问顺序 根 -左-右
	PreTraversal(T->lchild);
	PreTraversal(T->rchild);
}	

void BinaryTree::InorderTraversal(BinaryTree* T) {//递归中序遍历
	if (T == NULL) {
		return;
	}
	PreTraversal(T->lchild);
	cout << T->data; //访问顺序 左 -根-右
	PreTraversal(T->rchild);
}

void BinaryTree::PostorderTraversal(BinaryTree* T) {//递归后序序遍历
	if (T == NULL) {
		return;
	}
	PreTraversal(T->lchild);
	PreTraversal(T->rchild);
	cout << T->data; //访问顺序 左 -右-根-

}
void  BinaryTree::levelOrderTraversal(BinaryTree* T) {
	queue<BinaryTree*> queue;
	BinaryTree* cur = T;
	//头结点入队
	queue.push(cur);
	//队列为空时，循环结束
	while (!queue.empty()) {
		//队列头元素出队
		cur = queue.front();
		queue.pop();
		cout << cur - data << "";
		//左孩子不为空入队
		if (cur->lchild != NULL) {
			queue.push(cur->lchild);
		}
		//右孩子不为空入队
		if (cur->rchild != NULL) {
			queue.push(cur->rchild);
		}
	}
}
int BinaryTree::getBinaryTreeHeight(BinaryTree* T) {
	if(T){
		//递归求左子树高度
		int lheight = T->getBinaryTreeHeight(T->lchild);
		//递归求右子树高度
		int rheight = T->getBinaryTreeHeight(T->rchild);
		//整棵树的高度等于左右子树最大者加上根的高度
		int height = (lheight > rheight) ? lheight:rheight;
		height++;
	}
	return 0;

}
int main() {
	cout << "初始化一个二插树" << endl;
	BinaryTree* T = new BinaryTree;
	T = T->Create_BinaryTree();
	cout << "先序遍历二叉树顺序为" << endl;
	T->PreTraversal(T);
	return 0;
}
