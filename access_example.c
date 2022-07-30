#include <stdio.h>
#include <unistd.h>

int main(void)
{
  const char* path="/";

  if (access(path, F_OK) != 0)
    printf("'%s' does not exist!\n", path);
  else {
    if (access(path, R_OK) != 0)
      printf("You don't have read access to '%s'\n", path);
    if (access(path, W_OK) != 0)
      printf("You don't have write access to '%s'\n", path);
    if (access(path, X_OK) != 0)
      printf("You don't have search access to '%s'\n", path);
  }


   return 0;
}
