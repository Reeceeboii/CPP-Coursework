//
// Created by reece on 07/11/2019.
//

#include "election.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

void election::add_vote(const vote &v) { votes.push_back(v); }

int election::vote_count() const { return votes.size(); }

vector<pair<candidate, int>> election::ranked_candidates() const {
    map<candidate, int> map;
    for(auto& v : votes){
        auto it = map.find(v.first_preference());
        it != map.end() ? ++it->second : map[v.first_preference()] = 1;
    }

    vector<pair<candidate, int>> vec(map.cbegin(), map.cend());

    // compare vote count of one pair to another pair and use that lambda as a predicate to std::sort
    sort(vec.begin(), vec.end(), [](auto& pair_a, auto& pair_b){
        return pair_a.second > pair_b.second;
    });
    return vec;
}

void election::eliminate(candidate c) {
    // remove c from votes
    for(auto& v : votes){
        v.discard(c);
    }
    // remove all spent votes from election
    votes.erase(remove_if(votes.begin(), votes.end(), [](const vote& v){
        return v.spent();
    }), votes.end());
}

election read_votes(istream& in) {
    election e;
    string line;

    while(getline(in, line)){
        vector<candidate> preferences;
        stringstream ss(line);
        candidate preference = 0;
        if(line.length()){ // check for blank lines just in case
            while (ss >> preference) {
                preferences.push_back(preference);
            }
            e.add_vote(vote(preferences));
        }
    }
    return e;
}
