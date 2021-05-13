#if 0
#include <iostream>
#include <algorithm>
using namespace std;
//��dp[i][j]Ϊ����Ϊi�����λ��j��windy���ĸ���
//���� dp[i][j]=sum(dp[i-1][k]) ���� abs(j-k)>=2 
int p, q, dp[15][15], a[15];
void init()
{
	for (int i = 0; i <= 9; i++)	dp[1][i] = 1;	//0,1,2,3,4...9������windy�� 
	for (int i = 2; i <= 10; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				if (abs(j - k) >= 2)	dp[i][j] += dp[i - 1][k];
			}
		}
	}//�ӵڶ�λ��ʼ ÿ��ö�����λj ���ҵ�k ʹ��j-k>=2 
}
int work(int x)	//����<=x��windy�� 
{
	memset(a, 0, sizeof(a));
	int len = 0, ans = 0;
	while (x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	//��Ϊ������� ����len-1λ��windy�� �ض�������������� 
	for (int i = 1; i <= len - 1; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			ans += dp[i][j];
		}
	}
	//Ȼ����lenλ �����λ<a[len]��windy�� Ҳ������������ 
	for (int i = 1; i < a[len]; i++)
	{
		ans += dp[len][i];
	}
	//������lenλ ���λ��ԭ����ͬ�� ���Ѹ��һ���� 
	for (int i = len - 1; i >= 1; i--)
	{
		//i�����λ��ʼö�� 
		for (int j = 0; j <= a[i] - 1; j++)
		{
			//j��iλ�ϵ��� 
			if (abs(j - a[i + 1]) >= 2)	ans += dp[i][j]; //�жϺ���һλ(i+1)���2����
			   //����� ans���ۼ� 
		}
		if (abs(a[i + 1] - a[i]) < 2)       break;
		//  if(i==1)   ans+=1;
	}
	return ans;
}

typedef long long ll;
ll dp[15][15], ans;//dp[i][j]��ʾ�ѵ���iλ��ǰһλ��j���ģ�limit����totnum��
int a[15], len;
long long L, R;
ll dfs(int pos, int pre, int st, int limit)//pos��ǰλ��,preǰһλ��,st�ж�ǰ���Ƿ�ȫ��0,limit���λ���� 
{
	if (pos > len) return 1;//������ 
	if (!limit && dp[pos][pre] != -1) return dp[pos][pre];//û�����λ���ƣ��Ѿ��ѹ���
	ll ret = 0;
	int res = limit ? a[len - pos + 1] : 9;//��ǰλ������� 
	for (int i = 0; i <= res; i++)//��0ö�ٵ�������� 
	{
		if (abs(i - pre) < 2) continue;//���������⣬���� 
		if (st && i == 0) ret += dfs(pos + 1, -2, 1, limit && i == res);//�����ǰ��0����һλ���� 
		else ret += dfs(pos + 1, i, 0, limit && i == res);//���û��ǰ��0�����������Ͱ���� 
	}
	if (!limit && !st) dp[pos][pre] = ret;//û�����λ������û��ǰ��0ʱ��¼��� 
	return ret;
}
void part(ll x)
{
	len = 0;
	while (x) a[++len] = x % 10, x /= 10;
	memset(dp, -1, sizeof dp);
	ans = dfs(1, -2, 1, 1);
}
int main()
{
	init();
	cin >> p >> q;
	cout << work(q + 1) - work(p) << endl;
	return 0;
}

#endif // 1
