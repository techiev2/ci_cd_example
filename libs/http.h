#pragma once
#include <stdio.h>
#include <sys/time.h>

int64_t get_current_time_ms() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (int64_t)tv.tv_sec * 1000 + (int64_t)tv.tv_usec / 1000;
}

void process_urls(int argc, char **argv) {
  unsigned int i = 1;
  for (; i < argc; i++) {
    int64_t timestamp = get_current_time_ms();
    printf("{\"message\": \"Procesing %s\", \"timestamp\": %lld}\n", argv[i], timestamp);
  }
}
