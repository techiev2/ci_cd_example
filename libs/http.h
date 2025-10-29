#pragma once
#include <stdio.h>
#include <sys/time.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>

void* process_url(void* arg);

int64_t get_current_time_ms() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (int64_t)tv.tv_sec * 1000 + (int64_t)tv.tv_usec / 1000;
}

void process_urls(int argc, char **argv) {
  unsigned int i = 1;
  pthread_t *threads = malloc(sizeof(pthread_t) * (argc - 1));
  for (; i < argc; i++) {
    pthread_create(&threads[i-1], NULL, process_url, (void*) argv[i]);
  }
  for (i = 0; i< argc - 1; i++) {
    pthread_join(threads[i], NULL);
  }
}

void * process_url(void* arg) {
  char* url = arg;
  int64_t timestamp = get_current_time_ms();
  printf("{\"message\": \"Processing %s\", \"timestamp\": %lld}\n", url, (long long)timestamp);
  return NULL;
}
