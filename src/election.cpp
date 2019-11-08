//
// Created by reece on 07/11/2019.
//

#include "election.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

void election::add_vote(const vote &v) {
    votes.push_back(v);
}

election read_votes(istream& in) {
    election e;
    string line;
    while(getline(in, line)){
        vector<candidate> preferences;
        for(candidate c : line) {
            if (c != ' ') {
                preferences.push_back(c);
            }
        }
        e.add_vote(vote(preferences));
    }
    return e;
}
