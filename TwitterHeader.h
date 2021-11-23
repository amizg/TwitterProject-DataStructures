#ifndef TWITTERHEADER_H_INCLUDED
#define TWITTERHEADER_H_INCLUDED

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

template <class T>
class Twitter {
public:
    Twitter(T u);
    void AddFollower(T p);
    void RemoveFollower(T p);
    void PrintFollowers();
private:
    T user;
    LinkedList<T> followers;
};

template <class T>
Twitter<T>::Twitter(T u) {
    user = u;
}

template <class T>
void Twitter<T>::AddFollower(T p) {
    followers.addEl(p);
}

template <class T>
void Twitter<T>::RemoveFollower(T p) {
    followers.removeEl(p);
}

template <class T>
void Twitter<T>::PrintFollowers() {
    cout << followers << endl;
}

#endif // TWITTERHEADER_H_INCLUDED
