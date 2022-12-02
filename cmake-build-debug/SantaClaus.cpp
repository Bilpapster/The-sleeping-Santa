#include "SantaClaus.h"

/*
 * santa.cpp : The Santa Claus problem solved with semaphores.
 * This file contains the 'main' function.
 * Program execution begins and ends there.
 * Needs some C++20 features.
 */

#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>
#include <unistd.h>

using namespace std;

static counting_semaphore<10> elfSemaphore(3);
static counting_semaphore<9> reindeerSemaphore(0);
static binary_semaphore santaSemaphore(0);
static binary_semaphore doorSemaphore(1);

static vector<int> elfVector;
static vector<int> reindeerVector;

void elf(int num)
{
    while (true)
    {
        elfSemaphore.acquire();
        doorSemaphore.acquire();
        elfVector.push_back(num);
        cout << "Elf " << num << ": I am waiting in elf's team." << endl;
        if (elfVector.size() == 3)
        {
            santaSemaphore.release();
        }
        doorSemaphore.release();
        usleep(500);
    }
}

void reindeer(int num)
{
    while (true)
    {
        doorSemaphore.acquire();
        reindeerVector.push_back(num);
        cout << "Reindeer " << num << ": I am waiting in reindeer's team." << endl;
        if (reindeerVector.size() == 9)
        {
            santaSemaphore.release();
        }
        doorSemaphore.release();
        reindeerSemaphore.acquire();
        usleep(1000);
    }
}

void santa()
{
    while (true)
    {
        cout << "Santa: I am going to sleep." << endl;
        santaSemaphore.acquire();
        doorSemaphore.acquire();
        cout << "Santa: I am awake." << endl;
        if (reindeerVector.size() == 9)
        {
            cout << "Santa: I am going out with the reindeer's team." << endl;
            usleep(250);
            for (auto& reindeerNum : reindeerVector)
            {
                cout << "Reindeer " << reindeerNum << ": I am free." << endl;
                reindeerVector.pop_back();
                reindeerSemaphore.release();
            }
        }
        else if (elfVector.size() == 3)
        {
            cout << "Santa: The meeting with the elf's team is starting." << endl;
            usleep(125);
            for (auto& elfNum : elfVector)
            {
                cout << "Elf " << elfNum << ": I must go to work." << endl;
                elfVector.pop_back();
                elfSemaphore.release();
            }
        }
        doorSemaphore.release();
    }
}

int main()
{
    vector<thread> elfThreads(10);
    vector<thread> reindeerThreads(9);

    thread santaThread = thread(santa);

    for (int i = 0; i < 10; i++)
    {
        elfThreads[i] = thread(elf, i + 1);
    }

    for (int i = 0; i < 9; i++)
    {
        reindeerThreads[i] = thread(reindeer, i + 1);
    }

    santaThread.join();

    for (auto& elfThread : elfThreads)
    {
        elfThread.join();
    }

    for (auto& reindeerThread : reindeerThreads)
    {
        reindeerThread.join();
    }
}


