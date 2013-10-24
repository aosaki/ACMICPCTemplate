bool am[100][100];
int ans;
int c[100];
int U[100][100];
int n;
bool dfs(int rest,int num) {
  if (!rest) {
    if (num>=ans)
      return 1;
    else
      return 0;
  }
  int pre=-1;
  for (int i=0; i<rest && rest-i+num>=ans; i++) {
    int idx=U[num][i];
    if (num+c[idx]<ans)
      return 0;
    int nrest=0;
    for (int j=i+1; j<rest; j++)
      if (am[idx][U[num][j]])
        U[num+1][nrest++]=U[num][j];
    if (dfs(nrest,num+1))
      return 1;
  }
  return 0;
}
int main() {
  while (scanf("%d",&n),n) {
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        scanf("%d",&am[i][j]);
    ans=0;
    for (int i=n-1; i>=0; i--) {
      int rest=0;
      for (int j=i+1; j<n; j++)
        if (am[i][j])
          U[0][rest++]=j;
      ans+=dfs(rest,0);
      c[i]=ans;
    }
    printf("%d\n",ans);
  }
  return 0;
}

