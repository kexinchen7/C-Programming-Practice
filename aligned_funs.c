#include <stdio.h>
#include <stdlib.h>


void* aligned_malloc(size_t bytes, size_t alignment) {
	void *p1, *p2; // basic pointer needed for computation.

	// let malloc allocate < bytes+alignment+sizeof(size_t) >
	if((p1 =(void *) malloc(bytes + alignment + sizeof(size_t)))==NULL)
		return NULL;

	// temp addr
	size_t temp_addr=(size_t)p1+alignment+sizeof(size_t);

	// return addr 
	p2=(void *)(temp_addr - (temp_addr%alignment));
	
	// store addr returned by malloc before size_t bytes of p2
	*((size_t *)p2-1)=(size_t)p1;

	return p2;
}

void aligned_free(void *p ) {
/*	Find the address stored by aligned_malloc ,"size_t" bytes above the 
current pointer then free it using normal free routine provided by C.
*/
	free((void *)(*((size_t *) p-1)));
}

void main() {

	// bytes = 50, alignment = 128
	int *p = NULL;

	if((p=aligned_malloc(50, 128)) == NULL) {
		printf("Allocate failed\n");
	} else {
		printf("Aligned address allocated is: %x\n", (size_t)p);
	}

	// test if it is aligned of alignment size
	if((size_t)p % 128 == 0) {
		printf("The address allocated is indeed aligned.\n");
	}

	// test free

	aligned_free(p);

}