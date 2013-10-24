bool visx[N],visy[N];
int lx[N],ly[N];
int matchy[N];
int map[N][N];
bool find(int x) {
  visx[x]=true;
  int t;
  for (int y=0; y<ycnt; y++) {
    if (!visy[y]) {
      t=lx[x]+ly[y]-map[x][y];
      if (t==0) {
        visy[y]=true;
        if (matchy[y]==-1 || find(matchy[y])) {
          matchy[y]=x;
          return true;
        }
      } else if (lack>t) lack=t;
    }
  }
  return false;
}
void KM() {
  memset(lx,0,sizeof(lx));
  memset(ly,0,sizeof(ly));
  memset(matchy,-1,sizeof(matchy));
  for (int i=0; i<xcnt; i++)
    for (int j=0; j<ycnt; j++)
      if (map[i][j]>lx[i])
        lx[i]=map[i][j];
  for (int x=0; x<xcnt; x++) {
    while (true) {
      memset(visx,false,sizeof(visx));
      memset(visy,false,sizeof(visy));
      lack=INFI;
      if (find(x)) break;
      for (int i=0; i<xcnt; i++) {
        if (visx[i]) lx[i]-=lack;
        if (visy[i]) ly[i]+=lack;
      }
    }
  }
  int cost=0;
  for (int i=0; i<ycnt; i++)
    cost+=map[matchy[i]][i];
}

