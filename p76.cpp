#include<stdio.h>
int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int dp[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               dp[i][w] = 0;
           else if (wt[i-1] <= w)
          dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]);
           else
          dp[i][w] = dp[i-1][w];
       }
   }
    for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           printf("%3d",dp[i][w]);
       }
        printf("\n");
   }
   return dp[n][W];
}
int countWays(int x, int y) {
        // write code here
        //int dp[x+1][y+1]={0};
        int dp[13][13]={0};
        dp[0][0]=0;
        for(int i=1;i<y;i++)//第一行初始化，因为只有横着走一种方法。
             dp[0][i]=1;
        for(int i=1;i<x;i++)//第一列初始化，因为只有竖着一种方法。
            dp[i][0]=1;
         for(int i=1;i<x;i++)//dp[i][j]的方法，等于走到上面一格和走到左边一个方法之和。
              for(int j=1;j<y;j++){
                  dp[i][j]=dp[i-1][j]+dp[i][j-1];
              }
               for (int i = 0; i <= x; i++)
   {
       for (int w = 0; w <= y; w++)
       {
           printf("%3d",dp[i][w]);
       }
        printf("\n");
   }
         return dp[x][y];
        if(x==0||y==0) return 0;
        if(x==1||y==1) return 1;
        else return countWays(x-1,y)+countWays(x,y-1);//递归解法
    }

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 60;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", countWays(2,2));
    return 0;
}
