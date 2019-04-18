# include <iostream>
using namespace std;

//int b[20];
int tsp(int cost[][10],int visited[],int start,int current,int n)
{
	int count=0;
	visited[current]=1;
	
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==1)
			++count;
	}
	
	if(count==n)
	{
		//cout<<"Current "<<current<<"\n"<<cost[current][start]<<"\n";
		return cost[current][start];
	}
	else
	{
		int ans=10000,ans1;
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				//cout<<"\nCurrent vertex is "<<i<<endl<<endl;
				ans1=cost[current][i];
				int b=tsp(cost,visited,start,i,n);
				visited[i]=0;
				//cout<<"cost["<<current<<"]["<<i<<"]: "<<ans1<<endl;
				//cout<<"value returned by tsp is "<<b;
				ans1+=b;
				//cout<<"\nAns1="<<ans1<<endl;
				if(ans1<ans)
				{	
					cout<<"current is "<<current<<endl;
					ans=ans1;
					//b[current]=i;
					//cout<<"\nANS during iteration of "<<current<<" is "<<ans<<endl;			
				}	
			}
			
		}
		visited[current]=0;
		//cout<<"\nFinal ans before returning from "<<current<<" is "<<ans<<endl;
		return ans;
	}
}

int main()
{
	int n;
	cout<<"\nTRAVELLING SALESMAN PROBLEM\n\n";
	cout<<"Enter no of nodes: ";
	
	cin>>n;
	
	int cost[10][10];
	int visited[n+1];
	
	
	/*for(int i=1;i<=20;i++)
	{
		b[i]=0;
	
	}*/
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				cout<<"Enter cost["<<i<<"]["<<j<<"]: ";
				cin>>cost[i][j];
			}
			else
				cost[i][j]=0;
		}
		cout<<"\n\n";
	}	
	
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	visited[1]=1;
	int path_cost=tsp(cost,visited,1,1,n);
	cout<<"\n\nPath cost is "<<path_cost<<endl;
	
	/*cout<<"Path is\n";
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<"-";
	
	}*/
	cout<<"\n";
				
	return 0;
}
