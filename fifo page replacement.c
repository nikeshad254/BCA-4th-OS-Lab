/*

testing data::---

 number of pages: 10
 enter sequence of pages: 4 7 6 1 7 6 1 2 7 2
 give max frame: 3

*/

#include <stdio.h>

// Function to find if a page exists in memory
int findPage(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page)
            return 1; // Page found in memory
    }
    return 0; // Page not found in memory
}

// Function to replace a page using FIFO algorithm
void replacePage(int page, int frames[], int numFrames, int *pointer, int *pageFaults) {
    frames[*pointer] = page;
    *pointer = (*pointer + 1) % numFrames; // Update the pointer to the next frame
    (*pageFaults)++;
}

int main() {
	int maxFrames, numPages, i;
	
	printf("---------- FIFO Page Replacement -----------\n\n");
	
	printf(" number of pages: ");
	scanf("%d", &numPages);
	
	int pages[numPages];
	printf(" enter sequence of pages: ");
	for(i=0; i<numPages; i++){
		scanf("%d", &pages[i]);
	}
	
	printf(" give max frame: ");
	scanf("%d", &maxFrames);
	
    int frames[maxFrames]; // Array to hold the frames in memory
    int numFrames = sizeof(frames) / sizeof(frames[0]);

    int pointer = 0; // Pointer to the current frame to be replaced
    int pageFaults = 0; // Counter for page faults

    // Initialize all frames to -1 (indicating an empty frame)
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    // Simulate page requests
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];

        // Check if the page exists in memory
        if (findPage(page, frames, numFrames) == 0) {
            replacePage(page, frames, numFrames, &pointer, &pageFaults);
        }

        // Print the current state of frames
        printf(" Page %d -> Frames: ", page);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("\n Total Page Faults: %d\n", pageFaults);
	
	printf("\n Hit ratio: %d/%d, Miss ratio: %d/%d", (numPages - pageFaults), numPages, pageFaults, numPages);
    return 0;
}