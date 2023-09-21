

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int *temp=(int*) calloc(nums1Size+nums2Size, sizeof(int));
    //temp=new int[nums1Size+nums2Size];
    int k=0,i,j;
    for(i=0,j=0;i<nums1Size && j<nums2Size;k++)
    {
        if(nums1[i]>=nums2[j])
        {
           temp[k]= nums2[j];
            j++;
        }
        else if(nums1[i]<nums2[j])
        {
            temp[k]=nums1[i];
            i++;
        }
    }
    if(i!=nums1Size)
    {
        while(i<nums1Size)
        {
            temp[k]=nums1[i];
            i++;    k++;
        }
    }
    else if(j!=nums2Size)
    {
        while(j<nums2Size)
        {
            temp[k]=nums2[j];
            j++;    k++;
        }
    }
    
    int x=(nums1Size+nums2Size)/2;
    if((nums1Size+nums2Size)%2==1)
    {
        return temp[x];

    }
    else {
        double n=temp[x-1]+temp[x];
        return n/2;
    }
}