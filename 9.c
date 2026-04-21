#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];      // one semaphore per fork
sem_t room;          // allows max 4 philosophers

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is THINKING\n", id);
        sleep(1);

        // Try to enter room
        sem_wait(&room);

        // Pick forks
        sem_wait(&forks[id]);                // left fork
        sem_wait(&forks[(id + 1) % N]);      // right fork

        // Eating
        printf("Philosopher %d is EATING\n", id);
        printf("Philosopher %d picked forks %d and %d\n",id, id, (id + 1) % N);

        sleep(2);

        // Put forks back
        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);

        printf("Philosopher %d released forks %d and %d\n",
               id, id, (id + 1) % N);

        // Leave room
        sem_post(&room);

        sleep(1);
    }
}

int main() {
    pthread_t ph[N];
    int ids[N];

    // Initialize forks
    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    // Allow max 4 philosophers
    sem_init(&room, 0, N - 1);

    // Create threads
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &ids[i]);
    }

    return 0;
}