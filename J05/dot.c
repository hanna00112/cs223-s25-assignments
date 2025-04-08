#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 100000

// your code here
typedef struct {
  long thread_ids;
  int start_index;
  int end_index;
  int v[100000];
  int u[100000];
  int LocalDotProduct;

} thread_data;

//function dotProduct
void *dotProduct(void *userdata) {
  thread_data *data = (thread_data *)userdata;
  for (int i = data->start_index; i < data->end_index; i++){
    data->LocalDotProduct += data->v[i]*data->u[i];
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  srand(time(0));

  int v[SIZE];
  int u[SIZE];
  int dotproduct = 0;
   
  for (int i = 0; i < SIZE; i++) {
    v[i] = rand() % 1000 - 500; //generating random number for v
    u[i] = rand() % 1000 - 500; //generating random number for u
    dotproduct += u[i] * v[i]; //calculating the dot product
  }
  printf("Ground truth dot product: %d\n", dotproduct);

  // TODO: Implement your thread solution here
  
  pthread_t* threads = malloc(sizeof(pthread_t) * 4);
  thread_data* data = malloc(sizeof(thread_data ) * 4) ;
  int nthreads = 4;
  int subsize = SIZE / nthreads;

   printf("Test with 4 threads\n");
  for (int i =0; i < 4; i++) {
	  data[i].thread_ids = i;
	  data[i].start_index = i * (subsize); 
	  data[i].end_index = (i + 1) * (subsize);
	  for (int j=0; j < SIZE; j++) {
		  data[i].v[j] = v[j];
          	  data[i].u[j] = u[j];
	  }
	  data[i].LocalDotProduct = 0;
	 pthread_create(&threads[i], NULL, dotProduct, &data[i]);
  }
   int thread_dotproduct = 0;
  for (int i = 0; i < 4; i++) {
		pthread_join(threads[i], NULL);
		thread_dotproduct += data[i].LocalDotProduct;
	}


  printf("Answer with threads: %d\n", thread_dotproduct);
  free(threads);
  free(data);
  return 0;
}
