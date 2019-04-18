#include<stdio.h>
#define max 25

struct program
{
        int id,len;
};

struct program p[max],b[max];

void merge(int low, int high, int mid)
{
	int i,j,k,h;

	h=low;i=low;j=mid+1;

	while((h<=mid) && (j<=high))
	{
		if(p[h].len<=p[j].len)
		{
			b[i]=p[h];
			h++;
		}
		else
		{
			b[i]=p[j];
			j++;
		}
		i++;
	}

	if(h>mid)
		for(k=j;k<=high;k++)
		{
			b[i]=p[k];i++;
		}
	else
		for(k=h;k<=mid;k++)
		{
			b[i]=p[k];i++;
		}

	for(k=low;k<=high;k++)
		p[k]=b[k];
}

void mergesort(int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,high,mid);
	}
}

int main()
{
        int np,nt,i,j,k,RT,waitingTime,tapelimit;
        float MRT;
        struct program tapes[max][max];
        printf("\n Enter no. of programs and no. of tapes : ");
        scanf("%d%d",&np,&nt);
        
        printf("\n Enter %d program lengths : ",np);
        for(i=0;i<np;i++)
        {
                p[i].id=i+1;
                scanf("%d",&p[i].len);
        }

	//To sort Programs lengthwise
	mergesort(0,np-1);
        
	//To assign programs to their respective tapes
        j=0;k=0;
        for(i=0;i<np;i++)
        {
                tapes[j][k]=p[i];
                j++;
                if(j==nt)
                {
                        j=0;
                        k++;
                }
         }   
         
	//To calculate response time
         printf("\n\n PROGRAMS on TAPES : ");
         RT=0;
         for(i=0;i<nt;i++)
         {
                waitingTime=0;
                printf("\n\n TAPE %d  :   ",i+1);
                
                tapelimit=np/nt;
                if(i<np%nt)
                        tapelimit++;
                for(j=0;j<tapelimit;j++)
                {
                          RT+=(waitingTime+tapes[i][j].len);
                          waitingTime+=tapes[i][j].len;
                          printf("\t%d",tapes[i][j].len);
                }
         }       
         MRT=(float)RT/(float)np;
         
         printf("\n\n Total Retrieval Time : %d", RT);
         printf("\n\n Mean Retrieval Time : %f", MRT);
        
        printf("\n\n");  
}
