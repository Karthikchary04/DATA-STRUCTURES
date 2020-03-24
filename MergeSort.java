package stringPrograms;

public class MergeSort 
{
    public void sorting(int arr[],int l,int mid,int r)
    {
    	int size1=mid-l+1;
    	int size2=r-mid;
    	int arr1[]=new int[size1];
    	int arr2[]=new int[size2];
    	for(int i=0;i<size1;++i)
    	{
    		arr1[i]=arr[l+i];
    	}
    	for(int j=0;j<size2;++j)
    	{
    		arr2[j]=arr[mid+1+j];
    	}
    	int i=0,j=0,k=l;
    	while(i<size1 && j<size2)
    	{
    		if(arr1[i]<=arr2[j])
    		{
    			arr[k]=arr1[i];
    			i++;
    			k++;
    		}
    		else
    		{
    			arr[k]=arr2[j];
    			j++;
    			k++;
    		}
    	}
    	while(i<size1) 
        { 
            arr[k]=arr1[i]; 
            i++; 
            k++; 
        }
    	while (j<size2) 
        { 
            arr[k] = arr2[j]; 
            j++; 
            k++; 
        } 
    }
    public void partition(int arr[],int l,int r)
    {
    	if(l<r)
    	{
    		int mid=l+(r-l)/2;
    		partition(arr,l,mid);
    		partition(arr,mid+1,r);
    		sorting(arr,l,mid,r);
    	}
    }
	public static void main(String[] args)
	{
        MergeSort ms=new MergeSort();
        int arr[]=new int[] {22,31,10,16,45,9,15,52};
        ms.partition(arr,0,7);
        for(int i=0;i<8;i++)
        {
        	System.out.println(arr[i]);
        }
	}

}
