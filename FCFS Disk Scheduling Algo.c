/*
---  FCFS DISK SCHEDULING ALGORITHM ----

Enter the number of disk requests: 7
Enter the disk requests: 82 170 43 140 24 16 190

Enter the current head position: 50

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fcfs_disk_scheduling(int requests[], int size, int head)
{
    int seek_count = 0;
    int cur_track, distance;
    
    printf("\nSeek Sequence is:\n%d", head);

    for (int i = 0; i < size; i++)
    {
        cur_track = requests[i];
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
        printf(" -> %d", head);
    }

    printf("\nTotal seek time: %d\n", seek_count);
}

int main()
{
    int size;
    printf(" ---  FCFS DISK SCHEDULING ALGORITHM ---- \n");
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &size);

    int* requests = (int*)malloc(size * sizeof(int));

    printf("Enter the disk requests: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &requests[i]);
    }

    int head;
    printf("\nEnter the current head position: ");
    scanf("%d", &head);

    fcfs_disk_scheduling(requests, size, head);

    free(requests);

    return 0;
}
