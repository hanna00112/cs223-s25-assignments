#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <unistd.h>

#define N 10

pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
int num_items = 0;
int in = 0;
int out =0;
int buff[N];

int produce_data() {
	return rand() % 10;
}

void* produce_item(void* arg) {
	int item;
	while (1){
		item = produce_data(); // populating item in producer array
		pthread_mutex_lock(&mux);
		while (num_items >= N) { // while needing to populate array
			pthread_cond_wait(&full, &mux);
		}
		buff[in] = item;
		in = (in+1)%N;
		num_items++;
		pthread_cond_signal(&empty);
		pthread_mutex_unlock(&mux);

		sleep(1);

	}
}
void consume_data(int item) {
	printf("Received item: %d\n", item);
}

void* consume_item(void* arg) {
	int item;
	while(1) {
		pthread_mutex_lock(&mux);
		while (num_items == 0) {
			pthread_cond_wait(&empty, &mux);
		}
		item = buff[out];
		out = (out + 1)% N;
		num_items--;
		pthread_cond_signal(&full);
		pthread_mutex_unlock(&mux);
		consume_data(item);
	}
}

int main() {
  // todo
  pthread_t pro_thread, con_thread;

  pthread_create(&pro_thread, NULL, produce_item, NULL);
  pthread_create(&con_thread, NULL, consume_item, NULL);

  pthread_join(pro_thread, NULL);
  pthread_join(con_thread, NULL);

 
  return 0;
}

