#if 0
#include <iostream>
#include <algorithm>
using namespace std;
//设dp[i][j]为长度为i中最高位是j的windy数的个数
//方程 dp[i][j]=sum(dp[i-1][k]) 其中 abs(j-k)>=2 
int p, q, dp[15][15], a[15];
void init()
{
	for (int i = 0; i <= 9; i++)	dp[1][i] = 1;	//0,1,2,3,4...9都属于windy数 
	for (int i = 2; i <= 10; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				if (abs(j - k) >= 2)	dp[i][j] += dp[i - 1][k];
			}
		}
	}//从第二位开始 每次枚举最高位j 并找到k 使得j-k>=2 
}
int work(int x)	//计算<=x的windy数 
{
	memset(a, 0, sizeof(a));
	int len = 0, ans = 0;
	while (x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	//分为几个板块 先求len-1位的windy数 必定包含在区间里的 
	for (int i = 1; i <= len - 1; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			ans += dp[i][j];
		}
	}
	//然后是len位 但最高位<a[len]的windy数 也包含在区间里 
	for (int i = 1; i < a[len]; i++)
	{
		ans += dp[len][i];
	}
	//接着是len位 最高位与原数相同的 最难搞的一部分 
	for (int i = len - 1; i >= 1; i--)
	{
		//i从最高位后开始枚举 
		for (int j = 0; j <= a[i] - 1; j++)
		{
			//j是i位上的数 
			if (abs(j - a[i + 1]) >= 2)	ans += dp[i][j]; //判断和上一位(i+1)相差2以上
			   //如果是 ans就累加 
		}
		if (abs(a[i + 1] - a[i]) < 2)       break;
		//  if(i==1)   ans+=1;
	}
	return ans;
}

typedef long long ll;
ll dp[15][15], ans;//dp[i][j]表示搜到第i位，前一位是j，的！limit方案totnum；
int a[15], len;
long long L, R;
ll dfs(int pos, int pre, int st, int limit)//pos当前位置,pre前一位数,st判断前面是否全是0,limit最高位限制 
{
	if (pos > len) return 1;//搜完了 
	if (!limit && dp[pos][pre] != -1) return dp[pos][pre];//没有最高位限制，已经搜过了
	ll ret = 0;
	int res = limit ? a[len - pos + 1] : 9;//当前位最大数字 
	for (int i = 0; i <= res; i++)//从0枚举到最大数字 
	{
		if (abs(i - pre) < 2) continue;//不符合题意，继续 
		if (st && i == 0) ret += dfs(pos + 1, -2, 1, limit && i == res);//如果有前导0，下一位随意 
		else ret += dfs(pos + 1, i, 0, limit && i == res);//如果没有前导0，继续按部就班地搜 
	}
	if (!limit && !st) dp[pos][pre] = ret;//没有最高位限制且没有前导0时记录结果 
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
