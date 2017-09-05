#include<iostream>
#include<cstring>
#include<string> 
#include<stack>

using namespace std;

void read();
void cal(string s);

struct Matrix
{
	int x;
	int y;
	Matrix(){}
};

const int MAXN = 26 + 4;

Matrix m[MAXN];

int main()
{
	memset(m, 0, sizeof(m)); //初始化m
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		read();//读入输入给得n个矩阵
	}
	string s;
	while (cin >> s)
	{
		cal(s);//计算矩阵链乘表达并输出 
	}
	return 0;
}


void cal(string s)
{
	int sum = 0;
	stack<Matrix> st;
	if (s.length() == 1)  //如果只有一个矩阵，则计算次数为0 
	{
		cout << sum << endl;
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			continue;
		else if (s[i] == ')') //遇到')'需要计算栈内最上层的两个矩阵 
		{
			Matrix a, b, t;
			b = st.top(); st.pop();//后入的先出
			a = st.top(); st.pop();
			if (a.y != b.x) 	//无法计算 
			{
				cout << "error" << endl;
				return;
			}
			else     			//计算生成的新矩阵然后放入栈中 
			{
				t.x = a.x;
				t.y = b.y;
				st.push(t);
				sum += a.x * a.y * b.y;
			}
		}
		else
			st.push(m[s[i] - 'A']);
	}
	cout << sum << endl;
}

void read()
{
	string s;
	int a,b;
	cin >> s >> a >> b;
	m[s[0] - 'A'].x = a;
	m[s[0] - 'A'].y = b;
}
