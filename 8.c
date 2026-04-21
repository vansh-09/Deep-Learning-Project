#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

// Function to print buffer state
void printBuffer() {
    printf("Buffer: [ ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", buffer[i]);
    }
    printf("]\n");
}

// Producer function
void* producer(void* arg) {
    for (int i = 1; i <= 6; i++) {
        sem_wait(&empty);   // wait if buffer is full
        sem_wait(&mutex);   // lock

        buffer[in] = i;
        printf("Produced: %d at index %d\n", i, in);
        in = (in + 1) % BUFFER_SIZE;

        printBuffer();

        sem_post(&mutex);   // unlock
        sem_post(&full);    // increase full count

        sleep(1);
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    for (int i = 1; i <= 6; i++) {
        sem_wait(&full);    // wait if buffer empty
        sem_wait(&mutex);   // lock

        int item = buffer[out];
        buffer[out] = 0;    // clear slot
        printf("Consumed: %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        printBuffer();

        sem_post(&mutex);   // unlock
        sem_post(&empty);   // increase empty count

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Initialize buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
        buffer[i] = 0;

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}