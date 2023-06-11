/*
---  SSTF DISK SCHEDULING ALGORITHM ----

Enter the number of disk requests: 7
Enter the disk requests: 82 170 43 140 24 16 190

Enter the current head position: 50

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int find_closest_track(int requests[], int size, int head, int visited[])
{
    int min_distance = INT_MAX;
    int closest_track = -1;

    for (int i = 0; i < size; i++)
    {
        int distance = abs(head - requests[i]);
        if (visited[i] == 0 && distance < min_distance)
        {
            min_distance = distance;
            closest_track = i;
        }
    }

    return closest_track;
}

void sstf_disk_scheduling(int requests[], int size, int head)
{
    int* visited = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    int seek_count = 0;
    int cur_track, distance;

    printf("\nSeek Sequence is:\n%d", head);

    for (int i = 0; i < size; i++)
    {
        int closest_track = find_closest_track(requests, size, head, visited);
        if (closest_track == -1)
            break;

        cur_track = requests[closest_track];
        visited[closest_track] = 1;

        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
        printf(" -> %d", head);
    }

    printf("\nTotal seek time: %d\n", seek_count);

    free(visited);
}

int main()
{
    int size;
     printf(" ---  SSTF DISK SCHEDULING ALGORITHM ---- \n");
     
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

    sstf_disk_scheduling(requests, size, head);

    free(requests);

    return 0;
}
