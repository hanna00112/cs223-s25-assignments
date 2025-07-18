#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct chunk {
  int size;
  int used;
  struct chunk *next;
};
struct chunk *flist = NULL;

void *malloc (size_t size) {
  // TODO: Implement malloc with a free list (See reading for details)
  if (size == 0) {
	  return NULL;
  }
  struct chunk *ptr = flist;
  struct chunk *prev = NULL;
  while (ptr != NULL) {
	  if (ptr->size >= size) {
		  if (prev != NULL){
		  prev->next = ptr->next;
	  }else {
		  flist = ptr->next;
	  }
	  ptr->used = size;
	  return (void*)(ptr + 1);
  } else {
	  prev = ptr;
	  ptr = ptr->next;
  }
  }

  //requesting memory from system 
  void *memory = sbrk(size + sizeof(struct chunk));
  if (memory == (void *)-1){
	  return NULL;
  } else {
	  struct chunk *cnk = (struct chunk*) memory;
	  cnk->size = size;
	  cnk->next = NULL;
	  cnk->used = size;
	  return (void*)(cnk + 1);
  }
  return NULL;
}

void free(void *memory) {
  // TODO: Implement malloc with a free list (See reading for details)
		if (memory != NULL) {
			struct chunk *cnk = (struct chunk*)((struct chunk*)memory -1);
			cnk->next = flist;
			flist = cnk;
		}
	
  return;
}
