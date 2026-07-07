#include <stdio.h>
#define MAX 50

int heap[MAX];
int size = 0;

/* --- Utility ------------------------------------------- */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* --- Min Heap: Insert ---------------------------------- */
/*
 * Add value at the end, then "bubble up":
 * keep swapping with parent while parent > current (min rule).
 */
void insertElement(int value) {
    if (size == MAX) {
        printf("Heap overflow\n");
        return;
    }

    heap[size] = value;
    int current = size;
    size++;

    while (current > 0) {
        int parent = (current - 1) / 2;

        if (heap[parent] > heap[current]) {   /* ? '>' for min heap */
            swap(&heap[parent], &heap[current]);
            current = parent;
        } else {
            break;
        }
    }
}

/* --- Min Heap: Delete root ----------------------------- */
/*
 * Replace root with last element, shrink size,
 * then "bubble down": swap with the smaller child.
 */
void deleteElement() {
    if (size == 0) {
        printf("Heap underflow\n");
        return;
    }

    printf("Deleted root (min): %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    int current = 0;
    while (1) {
        int left    = 2 * current + 1;
        int right   = 2 * current + 2;
        int smallest = current;              /* ? 'smallest' for min heap */

        if (left  < size && heap[left]  < heap[smallest])  /* ? '<' */
            smallest = left;
        if (right < size && heap[right] < heap[smallest])  /* ? '<' */
            smallest = right;

        if (smallest != current) {
            swap(&heap[current], &heap[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
}

/* --- Display ------------------------------------------- */

void display() {
	int i;
    printf("\nHeap array: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\nRoot (min element): %d\n", heap[0]);
}

/* --- Main ---------------------------------------------- */

int main() {
    insertElement(50);
    insertElement(30);
    insertElement(40);
    insertElement(10);
    insertElement(20);
    insertElement(60);

    printf("After inserting [50, 30, 40, 10, 20, 60]:");
    display();

    deleteElement();

    printf("After deleting root:");
    display();

    return 0;
}
