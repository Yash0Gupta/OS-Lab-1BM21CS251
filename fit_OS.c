#include <stdio.h>
int holes[10],holes1[10];
int holes_free[10];
int request[10];
int completed[10];
int h,n,temp;
void best_fit(int n, int h){
    for(int i=0;i<n;i++){
        completed[i]=0;
    }
    for(int i=0;i<h;i++){
        holes_free[i]=1;
    }
    printf("Best Fit:\n");
    for(int i=0;i<h-1;i++){
        for(int j=0;j<h-i-1;j++){
            if(holes[j+1]<holes[j]){
                temp=holes[j+1];
                holes[j+1]=holes[j];
                holes[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<h;j++){
            if(request[i]<=holes[j] && holes_free[j]==1 && completed[i]==0){
                completed[i]=1;
                holes_free[j]=0;
                printf("%dk in %dk\n",request[i],holes[j]);
            }
        }
    }
}
void worst_fit(int n, int h){
    for(int i=0;i<n;i++){
        completed[i]=0;
    }
    for(int i=0;i<h;i++){
        holes_free[i]=1;
    }
    printf("\nWorst Fit:\n");
    for(int i=0;i<h-1;i++){
        for(int j=0;j<h-i-1;j++){
            if(holes[j+1]>holes[j]){
                temp=holes[j+1];
                holes[j+1]=holes[j];
                holes[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<h;j++){
            if(request[i]<=holes[j] && holes_free[j]==1 && completed[i]==0){
                completed[i]=1;
                holes_free[j]=0;
                printf("%dk in %dk\n",request[i],holes[j]);
            }
        }
    }
}
void first_fit(int n, int h){
    for(int i=0;i<n;i++){
        completed[i]=0;
    }
    for(int i=0;i<h;i++){
        holes_free[i]=1;
    }
    printf("\nFirst Fit:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<h;j++){
            if(request[i]<=holes1[j] && holes_free[j]==1 && completed[i]==0){
                completed[i]=1;
                holes_free[j]=0;
                printf("%dk in %dk\n",request[i],holes1[j]);
            }
        }
    }
}
int main(){
    printf("enter the number of holes:\t");
    scanf("%d",&h);
    printf("Enter the holes sizes:\n");
    for(int i=0;i<h;i++){
        scanf("%d",&holes[i]);
        holes1[i]=holes[i];
    }
    printf("enter the number of requests:\t");
    scanf("%d",&n);
    printf("Enter the request segments:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    best_fit(n,h);
    worst_fit(n,h);
    first_fit(n,h);
    return 0;
}