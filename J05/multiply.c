#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100

// your code here
typedef struct {
  long thread_ids;
  int start_index;
  int end_index;
  int M[100 * 100];
  int u[100];
  int localResult[100];
} thread_data;

//function dotProduct
void *dotProduct(void *userdata) {
  thread_data *data = (thread_data *)userdata;
  for (int i= data->start_index; i < data->end_index; i++){
	  for (int j = 0; j < 100; j++) {
		  data->localResult[i] += data->M[i*100 + j] * data->u[j];
	  }
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  srand(time(0));

  int M[SIZE*SIZE];
  int u[SIZE];
  int result[SIZE];
  int result_threads[SIZE];
   
  for (int i = 0; i < SIZE; i++) {
    u[i] = rand() % 10 - 5;
    result[i] = 0;
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      int value = rand() % 10 - 5;
      M[i*SIZE + j] = value;
      result[i] += value * u[j];
    }
  }

  pthread_t* threads = malloc(sizeof(pthread_t) * 4);
  thread_data* data = malloc(sizeof(thread_data ) * 4);
  int nthreads = 4;
  int subsize = SIZE / nthreads;

  // TODO: Implement your thread solution here
  for (int i =0; i < 4; i++) {
	  data[i].thread_ids = i;
	  data[i].start_index = i * (subsize);
	  data[i].end_index = (i + 1) * (subsize);
	  for (int j=0; j < SIZE; j++) {
		  for (int k=0; k < SIZE; k++) {
			  data[i].M[j*100 + k] = M[j*100 + k];
		  }
		  data[i].u[j] = u[j];
		  data[i].localResult[i] = 0;
	  }
	  pthread_create(&threads[i], NULL, dotProduct, &data[i]);

  }
  for (int i = 0; i < 4; i++) {
		pthread_join(threads[i], NULL);
		 for (int j = data[i].start_index; j < data[i].end_index; j++) {
			 result_threads[j] += data[i].localResult[j];
		 }
  }

  printf("Test with 4 threads\n");



  int error = 0;
  for (int i = 0; i < SIZE; i++) {
    error += abs(result[i] - result_threads[i]);
  }
  printf("Error between ground truth and multithreaded version: %d\n", error);
  free(threads);
  free(data);
  return 0;
}
