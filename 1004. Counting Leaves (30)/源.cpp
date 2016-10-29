#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define Null 0
#define FLAG -1
const int MAXN = 99;
struct Node
{
	int kid;
	int bro;
	Node() { kid = Null; bro = Null; };
};
/*class Queue
{
private:
	int* A;
	int Size;
public:
	Queue(int MAXSize) { A = new int[MAXSize]; Size = 0; }
	bool IsEmpty() { return Size == 0; }
	void InQ(int x) { A[Size] = x; Size++; }
	int OutQ() { int temp = A[Size]; Size--; return temp; }
};
*/
/*
void ShowTree(Node A[], int Size)
{
	for (int i = 1; i <= Size; i++)
	{
		cout <<i<<"�ĺ���"<< A[i].kid << "���ֵ�"<<A[i].bro << endl;
	}
}*/
int main()
{
	int N, M;
	cin >> N >> M;
	int idx1, K, idx2;
	Node* A = new Node[N+1];//�ڵ��±��1��N
	for (int i = 0; i < M; i++)
	{
		cin >> idx1 >> K >> idx2;
		A[idx1].kid = idx2;
		int temp = idx2;
		for (int j = 1; j < K; j++)//��ֻһ���ӽ��ʱ
		{
			cin >> A[temp].bro;
			temp = A[temp].bro;
		}
	}
//	ShowTree(A,N);//
//	Queue q1(N), q2(N);
	queue<int> q1;
	vector<int> ans;
	int Root = 1;
//	q1.InQ(Root);
	q1.push(Root);
	q1.push(FLAG);
	int Count = 0;
	int NODECOUNT = 0;
	while (!q1.empty())//������q1�д洢��һ����ڵ���±����
	{
		int Ele = q1.front();
		q1.pop();
		if (Ele == FLAG)//һ�����
		{
			if (NODECOUNT == 0)
				break;
			ans.push_back(Count);
			q1.push(FLAG);
			Count = 0;
			NODECOUNT = 0;
			continue;
		}
		else if (A[Ele].kid != Null)//�����q2�д���һ����ڵ�
		{
			int NextT = A[Ele].kid;
			q1.push(NextT); //
			int Bro= A[NextT].bro;
			while (Bro != Null)
			{
				q1.push(Bro);//
				Bro = A[Bro].bro;
	//			cout << "Bro " << Bro << endl;
			}
		}
		else Count++;
		NODECOUNT++;
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << " " << ans[i];
	system("pause");
	return 0;
}