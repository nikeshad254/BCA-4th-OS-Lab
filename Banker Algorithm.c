#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    
    int alloc[n][m], max[n][m], avail[m];
    
    printf("Enter the Allocation Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("Enter the Maximum Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    
    printf("Enter the Available Resources:\n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    
    int total[m];
	for(i=0;i<m;i++){
	    total[i] = avail[i];
	    for(j=0;j<n;j++){
	        total[i] += alloc[j][i];
	    }
	}

	printf("\nTotal amount of resource should be:\n");
	for(i=0;i<m;i++){
	    printf("%d ", total[i]);
	}
    
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    
    printf("\n\nthe need matrix is: \n");
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    
    
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++){
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    
    int flag = 1;
    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("\nThe following system is not safe");
            break;
        }
    }
    
    if(flag==1){
        printf("\nFollowing is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++){
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }
    return (0);
}
