#include <iostream>
using namespace std;
class Graph
{
 int v,e;
 int **adjmat;
public:
  Graph(int v,int e)
 {
   this->v=v;
   this->e=e;
   adjmat=new int *[v];
   for(int i=0;i<v;i++)
   {
    adjmat[i]=new int [v];
   }
   for(int i=0;i<v;i++)
   {
      for(int j=0;j<v;j++)
      {
       adjmat[i][j]=0;
      }
       }
  }
  void acceptgraph();
  void display();
  void prims(int);
  void kruskal();
};
void Graph::acceptgraph()
{
 int s,d,wt;
 cout<<"\nEnter source and destination vertex-";
 cin>>s>>d;
  cout<<"Enter weight of edge-";
  cin>>wt;
  adjmat[s][d]=wt;
  adjmat[d][s]=wt;
}
void Graph::display()
{
 for(int i=0;i<v;i++)
 {
  for(int j=0;j<v;j++)
  {
   cout<<" "<<adjmat[i][j]<<" ";
  }
  cout<<endl;
 }
}
void Graph::prims(int v1)
{
  int count1 = 0, count = 0,min = 9999,wt =0,t1,t2,temp1,temp2,cost;
  int root_temp1,root_temp2;
  int adj1[v][v];
  int A[v];
  int father[v];
  int Result[v][v];
  for(int i=0;i<v;i++)
  {
    A[i]=0;
    father[i]=-1;
    for(int j=0;j<v;j++)
    {
     Result[i][j]=0;
      adj1[i][j]=adjmat[i][j];
    }
  }
  A[count1] = v1;
  count1++; 
  while(count<v-1)
  {
    min = 9999;
    for(v1 = 0;v1<count1;v1++)
    {
     for(int v2 = 0;v2<v;v2++)
     {
      if( adj1[A[v1]][v2]!=0 && adj1[A[v1]][v2]<min)
        {
          min = adj1[A[v1]][v2];
          t1 = A[v1];
          t2 = v2;
       }
     }
   }
  temp1 = t1;
  temp2 = t2;
  adj1[t1][t2] = adj1[t2][t1] = 0;
   while(t1>=0)
   {
    root_temp1 = t1;
    t1 = father[t1];
   }
    while(t2>=0)
    {
      root_temp2 = t2;
      t2 = father[t2];
    }
    if(root_temp1!=root_temp2)
    {
      Result[temp1][temp2] = Result[temp2][temp1]= min;
      wt = wt+ Result[temp1][temp2];
      father[root_temp2] = root_temp1;
      count++;
      A[count1] = temp2;
      count1++;
    }
  }
  for(int i=0;i<v;i++)
  {
     for(int j=0;j<v;j++)
     {
       cout<<" "<<Result[i][j]<<" ";
       cost+=Result[i][j];
     }
     cout<<endl;
   }
   cout<<"\nWeight is-"<<cost/2;
}


int main()
{
 int tv,te,s,choice;
 cout<<"\nEnter total no of vertices-";cin>>tv;
 cout<<"Enter total no of edges-";cin>>te;
  Graph g(tv,te);
  while(choice!=4)
  {
    cout<<endl;
    cout<<"\n------------MENU------------\n";
    cout<<"1.Create Graph\n";
    cout<<"2.Display \n";
    cout<<"3.Minimum weight by Prims algorithm \n";
    cout<<"4.Exit\n";
    cout<<"Enter choice-";
    cin>>choice;
       switch(choice)
       {
       case 1:
        for(int i=0;i<te;i++)
        {
         g.acceptgraph();
        }
        break;
        case 2:
         g.display();
         break;
        case 3:
         cout<<"\nEnter seed vertex-";
         cin>>s;
         g.prims(s);
         break;
        case 4:
         cout<<"Program finished!";
         break;
        default:
         cout<<"\nEnter correct choice";
            }
      }
  return 0;
  
}