#include<stdio.h>
#include<stdio.h>

void display(int i,int n,int a[]);

typedef struct m1
{
  int max;
  int min;
}m1;


m1 maxmin(int i, int j,int max,int min,int a[])
{
 m1 m;
 int max1, min1, mid;
 if(i==j)
 {
  m.max = m.min = a[i];
  printf("\nmax: %d\t",m.max);
  printf("min: %d\n",m.min);
  return m;
 }

 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
     m.max = a[j];
     m.min = a[i];
     printf("\nmax: %d\t",m.max);
     printf("min: %d\n",m.min);
     return m;
   }
   else
   {
     m.max = a[i];
     m.min = a[j];
     printf("\nmax: %d\t",m.max);
     printf("min: %d\n",m.min);
     return m;
   }
  }
  else
  {
    mid = (i+j)/2;       //breaking the array in two parts ist part up to mid and 2nd up to 
    display(i,mid,a);    //then display the elements up to mid
    m=maxmin(i, mid,m.max,m.min,a); //then recursively we are finding the min and max up to mid and store it to m
    max1=m.max; min1 = m.min;    //now if the display list contain two or one element then we find the max and min out of them and store it in max1 and min1
    display(mid+1,j,a);
    m=maxmin(mid+1, j,m.max, m.min,a);

    if(m.max <max1)
    {
      m.max = max1;
      printf("\n\nmax: %d\t",m.max);
    }
    else
    {
      printf("\n\nmax: %d\t",m.max);
    }

    if(m.min > min1)
    {
      m.min = min1;
      printf("\nmin: %d\n",m.min);
    }
    else
    {
      printf("min: %d\n",m.min);
    }
    return m;
  }
 }
}

void display(int i,int n,int a[])
{
  printf("\n\n{ ");
  for(i;i<=n;i++)
  {
    printf("%d ",a[i]);
  }
   printf("}");
   printf("\n");
}


int main ()
{
 int i, num;
 int a[100],max,min;
 m1 k;
 printf ("\nEnter the no of elements : ");
 scanf ("%d",&num);
 printf ("Enter array elements : \n");
 for (i=1;i<=num;i++)
 scanf ("%d",&a[i]);
 max = 0;
 min = 0;
 k=maxmin(1, num,max,min,a);          //low,high,min,max,array
 printf ("\nMinimum element in an array : %d\n", k.min);
 printf ("\nMaximum element in an array : %d\n", k.max);
 return 0;
}



/*Output:
bash-4.2$ cd DAA

bash-4.2$ gcc ass1_44.c
bash-4.2$ ./a.out
Enter the no of elements : 5
Enter array elements :
40 31 12 2 80
{ 40 31 12 }
{ 40 31 }
max 40 min 31
{ 10 }
max 10 min 10
max 40 min 10
{ 2 80 }
max 80 min 2
max 80 min 2
Minimum element in an array : 2
Maximum element in an array : 80
bash-4.2$
*/

