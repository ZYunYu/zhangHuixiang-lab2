#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h> /* Provide shared memory functions */
#include <sys/stat.h> /* Provide mode constants */
#include <fcntl.h> /* Provide O_* constants */


/**************************************************************
 *  ipc_create - creates a shared memory object called lab2 and
 *               returns a char pointer to the memory shared
 *               memory object.
 * 
 *  size - is the size of the memory object to create.
 *   
 ***************************************************************/
char* ipc_create(int size){
    /* shared memory file descriptor */
    int fd;
    /* pointer to shared memory obect */
    char* ptr;

    fd = shm_open("lab2", O_CREAT | O_RDWR, 0666);
    // "0666" All users can read and write
    if (fd == -1) {
        printf("shm_open call failed");
        return NULL;
    }
    
    if (ftruncate(fd, size) == -1) {
        return NULL;
    }

    ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }

    return ptr;
}


/**************************************************************
 * ipc_close - closes the ipc communication channel that was
 *             created with ipc_create.
 * 
 **************************************************************/
void ipc_close(){
    shm_unlink("lab2");
}