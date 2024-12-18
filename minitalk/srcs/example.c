#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t pid;

  pid = getpid();
  printf("The process ID is %d\n", pid);
  printf("Entering pause...\n");
  pause();

  return 0;
}
