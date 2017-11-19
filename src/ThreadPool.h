// Author: David Skrenta CS1300 Fall 2017
// Recitation: 210 - Arcadia
// Assignment 8
// ThreadPool.h

#ifndef THEAD_POOL_H
#define THEAD_POOL_H

#include <iostream>
#include <vector>
#include <thread>
#include <deque>
#include <condition_variable>

using namespace std;

class ThreadPool;

class Worker {
    public:
        Worker(ThreadPool &s);
        void operator()();

    private:
        ThreadPool &pool;
}

class ThreadPool {
    public:
        ThreadPool(size_t numThreads);
        ~ThreadPool();

        template <class F>
        void enqueue(F f);

    private:
        friend class Worker;

        vector <thread> workers;
        deque <function<void()>> tasks;
        mutex queue_mutex;
        condition_variable condition;
        bool stop;
};
#endif // THEAD_POOL_H
