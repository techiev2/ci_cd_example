#include <stdio.h>
#include "libs/http.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    fprintf(stderr, "{\"error\": true, \"message\": \"No URLs provided.\"}\n");
    return 1;
  }
  process_urls(argc, argv);
  return 0;
}
