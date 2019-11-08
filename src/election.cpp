//
// Created by reece on 07/11/2019.
//

#include "election.h"
#include <string>
#include <iostream>
#include <algorithm>

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

int election::count_voters() const {
    return votes.size();
}


// count the number of number 1 preferences for a particular candidate
int election::get_votes_for_candidate(const candidate &c) const {
    int total = 0;
    for(const vote& v : votes){
        if(!v.spent()){
            if(v.first_preference() == c){
                ++total;
            }
        }
    }
    return total;
}


vector<pair<candidate, int>> election::ranked_candidates() const {
    vector<pair<candidate, int>> v;

    // mapping candidate numbers
    for(int i = 1; i < get_candidate_count() + 1; ++i){
        v.emplace_back(pair(i, get_votes_for_candidate(i)));
    }

    // compare vote count of one pair to another pair and use that lambda as a predicate to std::sort
    sort(v.begin(), v.end(), [](auto& candidate, auto& firsts){
        return candidate.second > firsts.second;
    });

    return v;
}

void election::set_candidate_count(const int &count) {
    candidate_count = count;
}

int election::get_candidate_count() const { return candidate_count; }

void election::eliminate(candidate c) {
    for(vote v : votes){
        auto r = remove_if(v.get_prefs().begin(), v.get_prefs().end(), [c](candidate& cand){ return cand == c;});
    }
}

election read_votes(istream& in) {
    election e;
    int highest_candidacy_val = 0;
    string line;
    while(getline(in, line)){
        vector<candidate> preferences;
        for(int c : line) {
            if (c != ' ') {
                // cheeky ascii conversion because simple cast just gives ascii value rather than value
                int pref = c - '0';
                // the highest candidate number seen in the file can be assumed to be the total candidacy turnout
                if(pref > highest_candidacy_val) highest_candidacy_val = pref;
                preferences.push_back(pref);
            }
        }
        e.add_vote(vote(preferences));
    }
    e.set_candidate_count(highest_candidacy_val);
    return e;
}
