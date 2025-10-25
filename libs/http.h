#pragma once
#include <stdio.h>
void process_urls(int argc, char **argv) {
  unsigned int i = 1;
  for (; i < argc; i++) {
    printf("{\"url\": \"%s\"}\n", argv[i]);
  }
}
