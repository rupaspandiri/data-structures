#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int temp[high-low+1];

    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
        }
        else
        {
            temp[k]=a[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        temp[k]=a[j];
        j++;
        k++;
    }

    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=temp[k];
    }
}

void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int n,i;

    printf("\nEnter n size: ");
    scanf("%d",&n);

    int a[n];

    printf("\nEnter %d elements: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    mergesort(a,0,n-1);

    printf("\nAfter sorting:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
