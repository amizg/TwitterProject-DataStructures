#include <iostream>
#include <string>
#include "TwitterHeader.h"

using namespace std;

struct Profile {
    string userName;
    int age;
    string state;

    bool operator == (Profile p2) {
        if (p2.userName == userName) return true;
        else return false;
    }
};

ostream& operator << (ostream & output, Profile p) {
    output << p.userName;
    return output;
}

int main()
{
    Twitter<string> user1 ("P1");
    user1.AddFollower("P2");
    user1.PrintFollowers();
    user1.AddFollower("P3");
    user1.PrintFollowers();
    user1.AddFollower("P4");
    user1.PrintFollowers();
    user1.RemoveFollower("P2");
    user1.PrintFollowers();

    Profile up; up.userName = "UP1";
    Twitter<Profile> user2 (up);
    up.userName = "UP2";
    user2.AddFollower(up);
    user2.PrintFollowers();
    up.userName = "UP3";
    user2.AddFollower(up);
    user2.PrintFollowers();
    up.userName = "UP4";
    user2.AddFollower(up);
    user2.PrintFollowers();
    up.userName = "UP2";
    user2.RemoveFollower(up);
    user2.PrintFollowers();
    return 0;
}
