/***************************************
 2 Ŀ�ģ�1.����������ַ����뼯����Ȩֵ����
 3 ����շ�������������ַ��ĺշ�������
 4 2.����շ��������У����ԭʼ�ַ�����
 6 ****************************************/
#include<iostream>
#define MAX_MA 1000
#define MAX_ZF 100
using namespace std;
#pragma warning(disable : 4996)

//���������Ĵ����ʾ
typedef struct
{
	int weight;  //����Ȩֵ
	int parent, lchild, rchild;//˫�ף����ӣ��Һ��ӵ��±�
}HTNode, * HuffmanTree;  //��̬����������������������Ľ��
//�����������Ĵ����ʾ
typedef char** HuffmanCode;//��̬��������洢����������

//��������˫����Ϊ0��Ȩֵ��С�ĵ���±�
void Select(HuffmanTree HT, int n, int& s1, int& s2)
{
	/*n����HT����ĳ���
	 */

	 //ǰ����forѭ�������н����Ȩֵ��С�ĵ㣨�ַ���
	for (int i = 1; i <= n; i++)
	{//����forѭ���ҳ�һ��˫��Ϊ0�Ľ��
		if (HT[i].parent == 0)
		{
			s1 = i;//s1��ʼ��Ϊi
			break;//�ҵ�һ���������˳�ѭ��
		}
	}
	for (int i = 1; i <= n; i++)
	{/*����forѭ���ҵ����н�㣨�ַ���Ȩֵ��С��һ��
	  ���ұ�֤�ý���˫��Ϊ0*/
		if (HT[i].weight < HT[s1].weight && HT[i].parent == 0)
			s1 = i;
	}
	//������forѭ�����н����Ȩֵ�ڶ�С�ĵ㣨�ַ���
	for (int i = 1; i <= n; i++)
	{//����forѭ���ҳ�һ��˫��Ϊ0�Ľ�㣬���Ҳ�����s1
		if (HT[i].parent == 0 && i != s1)
		{
			s2 = i;//s2��ʼ��Ϊi
			break;//�ҵ�һ���������˳�ѭ��
		}
	}

	for (int i = 1; i <= n; i++)
	{/*����forѭ���ҵ����н�㣨�ַ���Ȩֵ�ڶ�С��һ����
	 �ý�����㲻����s1��˫����0*/
		if (HT[i].weight < HT[s2].weight && HT[i].parent == 0 && i != s1)
			s2 = i;
	}

}

//�����������
void CreateHuffmanTree(HuffmanTree& HT, int n)
{
	/*-----------��ʼ������-------------------------*/
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; ++i)
	{//��1~m�ŵ�Ԫ�е�˫�ף����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0
		HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> HT[i].weight;//����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
	}
	/*-----------��������---------------------------*/
	int s1, s2;
	for (int i = n + 1; i <= m; ++i)
	{//ͨ��n-1�ε�ѡ��ɾ�����ϲ��������������
		Select(HT, i - 1, s1, s2);
		/*cout << HT[s1].weight << " , " << HT[s2].weight << endl;*/
				 /*��s1,s2��˫������0��Ϊi
				   (�൱�ڰ����������ɾ���ˣ���������㲻�ٲ���Select()����)*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		//s1,��s2�ֱ���Ϊi�����Һ���
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		//���i��ȨֵΪs1,s2Ȩֵ֮��
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�����ڱ����HC��
void CreatHuffmanCode(HuffmanTree HT, HuffmanCode& HC, int n)
{
	HC = new char* [n + 1];//���䴢��n���ַ�����ı����ռ�
	char* cd = new char[n];//������ʱ�洢�ַ�����Ķ�̬�ռ�
	cd[n - 1] = '\0';//���������
	for (int i = 1; i <= n; i++)//������ַ�����
	{
		int start = n - 1;//start ��ʼָ����󣬼����������λ��
		int c = i;
		int f = HT[c].parent;//fָ����c��˫��
		while (f != 0)//��Ҷ�ӽ�㿪ʼ���ݣ�ֱ�������
		{
			--start;//����һ�Σ�start��ǰָ��һ��λ��
			if (HT[f].lchild == c) cd[start] = '0';//���c��f�����ӣ���cd[start] = 0;
			else cd[start] = '1';//����c��f���Һ��ӣ�cd[start] = 1
			c = f;
			f = HT[f].parent;//�������ϻ���
		}
		HC[i] = new char[n - start];//Ϊ��i���ַ��������ռ�
		strcpy(HC[i], &cd[start]);//����ñ�����׵�ַ��cd[start]���Ƶ�HC�ĵ�ǰ����
	}
	delete cd;
}

//����������
void TranCode(HuffmanTree HT, char a[], char zf[], char b[], int n)
{
	/*
125     HT���Ѿ������õĹ�������
126     a[]������������Ʊ���
127     b[]������¼������ַ�
128     zf[]�������������Ҷ�Ӷ�Ӧ���ַ���Ҷ���±����ַ��±��Ӧ��
	*/

	int q = 2 * n - 1;//q��ʼ��Ϊ�������±�
	int k = 0;//��¼�洢����ַ�������±�
	int i = 0;
	for (i = 0; a[i] != '\0'; i++)
	{//forѭ�����������Ƕ�����ַ��ǽ������������Ʊ��룩
		//�˴���������ж϶���Ķ������ַ���0����1
		if (a[i] == '0')
		{/*����0���Ѹ����(HT[q])�����ӵ��±�ֵ����q
		  �´�ѭ����ʱ���HT[q]��������Ϊ�µĸ����*/
			q = HT[q].lchild;
		}
		else if (a[i] == '1')
		{
			q = HT[q].rchild;
		}
		//�˴���������ж�HT[q]�Ƿ�ΪҶ�ӽ��
		if (HT[q].lchild == 0 && HT[q].rchild == 0)
		{/*��Ҷ�ӽ�㣬˵���Ѿ����һ���ַ�
		���ַ����±�����ҵ���Ҷ�ӽ����±�*/
			b[k++] = zf[q];//���±�Ϊq���ַ������ַ�����b[]
			q = 2 * n - 1;//��ʼ��qΪ�������±�
	   //��������һ���ַ���ʱ��ӹ��������ĸ���㿪ʼ
		}
	}
	/*�������֮��������¼����ַ�����������û�н����������
   ʱ��ر����ʽ����Ű�һ���������ӵ��������*/
	b[k] = '\0';
}
//�˵�����
void menu()
{
	cout << endl;
	cout << "       ��������������������������������������������������������������" << endl;
	cout << "       ��      ������������������������������        ��" << endl;
	cout << "       ��                   1.  ������������                       ��" << endl;
	cout << "       ��                   2.  ���й���������                     ��" << endl;
	cout << "       ��                   3.  ���й���������                     ��" << endl;
	cout << "       ��                   4.  �˳�����                           ��" << endl;
	cout << "       ��������������������������������������������������������������" << endl;
	cout << "                       <><ע�⣺�ո��ַ���'- '����><>" << endl;
	cout << endl;
}
void main()
{
	int falg;//��¼Ҫ������ַ�����
	char a[MAX_MA];//��������Ķ������ַ�
	char b[MAX_ZF];//�洢������ַ�
	char zf[MAX_ZF];//����Ҫ������ַ�
	HuffmanTree HT = NULL;//��ʼ����Ϊ����
	HuffmanCode HC = NULL;//��ʼ�������Ϊ�ձ�
	menu();
	while (true)
	{
		int num;
		cout << "<><��ѡ����(1-���� 2-���� 3-���� 4-�˳�)><>: ";
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "<><�������ַ�����><>:";
			cin >> falg;
			//��̬����falg�����ȵ��ַ����飬�����洢Ҫ������ַ�
		   /*char *zf = new char[falg];*/
			cout << "<><����������" << falg << "���ַ�:><>: ";
			for (int i = 1; i <= falg; i++)
				cin >> zf[i];
			cout << "<><����������" << falg << "���ַ���Ȩֵ><>: ";
			CreateHuffmanTree(HT, falg);//���ô������������ĺ���
			cout << endl;
			cout << "<><�����������ɹ���,�����Ǹù��������Ĳ������><>��" << endl;
			cout << endl;
			cout << "���i" << "\t" << "�ַ�" << "\t" << "Ȩֵ" << "\t" << "˫��" << "\t" << "����" << "\t" << "�Һ���" << endl;
			for (int i = 1; i <= falg * 2 - 1; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
			}
			cout << endl;
			break;
		case 2:
			CreatHuffmanCode(HT, HC, falg);//���ô��������������ĺ���
			cout << endl;
			cout << "<><���ɹ����������ɹ���,�����Ǹñ��������><>��" << endl;
			cout << endl;
			cout << "���i" << "\t" << "�ַ�" << "\t" << "Ȩֵ" << "\t" << "����" << endl;
			for (int i = 1; i <= falg; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HC[i] << endl;
			}
			cout << endl;
			break;
		case 3:
			cout << "<><��������Ҫ�����һ�������Ʊ���><>��";
			/*�������Զ�̬��ֱ������һ�������Ʊ��룬
		  ��Ϊ��������ʱ���ϵͳ���Զ���һ��������*/
			cin >> a;
			TranCode(HT, a, zf, b, falg);//��������ĺ�����
			  /*��������ֱ�Ӱ�����b�������Ϊ�����
			������b������ʱ������������������*/
			cout << endl;
			cout << "<><����ɹ���������Ϊ><>��" << b << endl;
			cout << endl;
			break;
		case 4:
			cout << endl;
			cout << "<><�˳��ɹ���><>" << endl;
			exit(0);
		default:
			break;
		}
	}

	//-abcdefghijklmnopqrstuvwxyz
	//186 64 13 22 32 103 21 15 47 57 1 5 32 20 57 63 15 1 48 51 80 23 8 18 1 16 1
  //000101010111101111001111110001100100101011110110

}
