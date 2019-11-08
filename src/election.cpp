//
// Created by reece on 07/11/2019.
//

#include "election.h"
#include <string>
#include <iostream>

using namespace std;

void election::add_vote(const vote &v) {
    votes.push_back(v);
}

int election::vote_count() const {
    int total = 0;
    for(const vote& v : votes){
        total += v.get_prefs().size();
    }
    return total;
}

vector<pair<candidate, int>> election::ranked_candidates() const {

}

candidate election::get_round_winner() const {

}


// count the number of number 1 preferences for a particular candidate
int election::get_votes_for_candidate(const candidate &c) {
    int total = 0;
    for(const vote& v : votes){
        //v.print_prefs();
        if(!v.spent()){
            if(v.first_preference() == c){
                ++total;
            }
        }
    }
    return total;
}

vector<vote> election::get_votes() const { return votes; }

election read_votes(istream& in) {
    election e;
    string line;
    while(getline(in, line)){
        vector<candidate> preferences;
        for(int c : line) {
            if (c != ' ') {
                // cheeky ascii conversion because simple cast just gives ascii value rather than value
                preferences.push_back(c - '0');
            }
        }
        e.add_vote(vote(preferences));
    }
    return e;
}
