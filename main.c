//Vani Jain (2021A7PS2062H)
//Yeshika Bharatiya (2021A7PS2779H)

#include <stdio.h>
#include <stdlib.h>


int * degseq(FILE * fp,int n,int e)  
{
    
    int* p=(int*)malloc(n*sizeof(int));
    int deg[n];
    for(int i=0; i<n; i++){
        deg[i]=0;
    }
    for(int i=0; i<e; i++){
        int a, b;
        fscanf(fp,"%d %d",&a,&b);
        deg[a-1]=deg[a-1]+1;
        deg[b-1]=deg[b-1]+1;
    }
    for(int i=0; i<(n-1); i++){
        for(int j=0; j<(n-i-1); j++){
            if(deg[j]<deg[j+1]){
                int temp=deg[j];
                deg[j]=deg[j+1];
                deg[j+1] = temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        *(p+i)=deg[i];
    }
    return p;
}

int distinct(int*a,int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if ((a[i]==a[j])&& (i!=j))
                    return 0;
            }
        }
        return 1;
    }
    

int left(int *arr,int n)
    {
       int p = n - 1;
       while (arr[p] == n-1)
        p--; 
        
        if (p < 0)
        return 0;
        
        arr[p] = arr[p] + 1;
        for(int i = p + 1; i < n; i++)
        arr[i] = 0;
 
    return 1;
    }


int isIsomorphic(FILE*fp1,FILE*fp2,int n,int e)
{
    int am1[n][n];
    int am2[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            am1[i][j]=0;
            am2[i][j]=0;
        }
    }
    for (int i=0;i<e;i++)
    {
        int a,b,c,d;
        fscanf(fp1,"%d %d",&a,&b);
        fscanf(fp2,"%d %d",&c,&d);
        am1[a-1][b-1]=1;
        am1[b-1][a-1]=1;
        am2[c-1][d-1]=1;
        am2[d-1][c-1]=1;
    }
    
    
   int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = 0;
        
    
    while(1)
    {
     int val=1;
        
    if(distinct(arr,n)){
        
        int am2_2[n][n],am2_3[n][n];
        for(int k=0;k<n;k++)
        {
            for(int y=0;y<n;y++)
                am2_3[k][y]=am2[(arr[k])][y];
        }
        for(int k=0;k<n;k++)
        {
            for(int y=0;y<n;y++)
                am2_2[y][k]=am2_3[y][(arr[k])];
        }
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((am1[i][j])!=(am2_2[i][j]))
            val=0;
            
        }
    }
    if(val==1)
        {
        printf("Isomorphic\n");
        for(int k=0;k<n;k++)
        printf("%d %d\n",k+1,arr[k]+1);
        return 1;
        }
    }
    if (left(arr,n)==0){
        return 0;}
    }
}


int main(int argc, char*argv[])
{
    FILE * fp1;
    fp1=fopen(argv[1],"r");
    int n1, e1;
    fscanf(fp1,"%d %d",&n1,&e1);
    FILE * fp2;
    fp2=fopen(argv[2],"r");
    int n2, e2;
    fscanf(fp2,"%d %d",&n2,&e2);
    int val=1;
    if(n1!=n2 || e1!=e2){
        val=0;
        printf("Not Isomorphic\n");
        return 0;
    }
    else{
        int * p1=degseq(fp1,n1,e1);
        int * p2=degseq(fp2,n2,e2);
        for(int i=0;i<n1;i++){
            if(*(p1+i)!=*(p2+i)){
                val=0;
                printf("Not Isomorphic\n");
                return 0;
            }
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    FILE * fp3;
    fp3=fopen(argv[1],"r");
    int n3, e3;
    fscanf(fp3,"%d %d",&n1,&e1);
    FILE * fp4;
    fp4=fopen(argv[2],"r");
    int n4, e4;
    fscanf(fp4,"%d %d",&n2,&e2);
    if(val==1){
        val=isIsomorphic(fp3,fp4,n1,e1);
    }
    if(val==0){
        printf("Not Isomorphic, no bijection found\n");
    }

    return 0;

}