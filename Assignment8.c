#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc dữ liệu Queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Hàm tạo Queue mới với dung lượng cho trước
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Chú ý: rear được khởi tạo là capacity - 1
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Hàm kiểm tra Queue có đầy không
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Hàm kiểm tra Queue có trống không
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Hàm thêm phần tử vào cuối Queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Hàm lấy phần tử ra khỏi đầu Queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int main() {
    struct Queue* queue = createQueue(5);

    // Thêm phần tử vào Queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Lấy phần tử ra khỏi Queue và in ra
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

    // Thêm phần tử mới vào Queue
    enqueue(queue, 50);

    // In ra phần tử ở đầu và cuối Queue
    printf("Front item is %d\n", queue->array[queue->front]);
    printf("Rear item is %d\n", queue->array[queue->rear]);

    // Giải phóng bộ nhớ
    free(queue->array);
    free(queue);

    return 0;
}
