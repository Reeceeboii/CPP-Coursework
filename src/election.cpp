//
// Created by reece on 07/11/2019.
//

#include "election.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

void election::add_vote(const vote &v) { votes.push_back(v); }

int election::vote_count() const { return votes.size(); }

// count the number of number 1 preferences for a particular candidate
// count if vote is not spent and the first preference is equal to c
int election::get_votes_for_candidate(const candidate &c) const {
    return count_if(votes.begin(), votes.end(), [&c](const vote& v){
        return v.spent() ? false : v.first_preference() == c;
    });
}


vector<pair<candidate, int>> election::ranked_candidates() const {
    vector<pair<candidate, int>> v;

    // mapping candidate numbers
    for(int i = 1; i < get_candidate_count() + 1; ++i){
        int count = get_votes_for_candidate(i);
        if(count > 0) {
            v.emplace_back(pair(i, count));
        }
    }

    // compare vote count of one pair to another pair and use that lambda as a predicate to std::sort
    sort(v.begin(), v.end(), [](auto& candidate, auto& firsts){
        return candidate.second > firsts.second;
    });
    return v;
}

void election::set_candidate_count(const int &count) { candidate_count = count; }

int election::get_candidate_count() const { return candidate_count; }

void election::eliminate(candidate c) {
    // remove c from votes
    for(auto& v : votes){
        v.discard(c);
    }
    // remove all spent votes from election
    votes.erase(remove_if(votes.begin(), votes.end(), [](const vote& v){ return v.spent(); }), votes.end());
}

election read_votes(istream& in) {
    if(!in){
        cerr << "Error reading file: " << strerror(errno) <<endl;
    }

    election e;
    candidate largest_cand = 0;
    string line;

    while(getline(in, line)){
        vector<candidate> preferences;
        stringstream ss(line);
        candidate preference = 0;
        while(ss >> preference){
            if(preference > largest_cand) largest_cand = preference;
            preferences.push_back(preference);
        }
        e.add_vote(vote(preferences));
    }
    e.set_candidate_count(largest_cand);
    return e;
}
