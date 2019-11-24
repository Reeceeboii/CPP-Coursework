//
// Created by reece on 08/11/2019.
//

#include "vote.h"
#include "election.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream infile("votes.txt");

    election e = read_votes(infile);
    bool winner = false;
    int round = 1;
    candidate current_highest_cand = 0;

    while(!winner){
        if(!e.vote_count()){
            cout << "There are no votes left.";
            return 0;
        }
        vector<pair<candidate, int>> ranked = e.ranked_candidates();
        cout << "Round " << round << ": " << e.vote_count() << " votes" << "\n";
        cout << "First preferences:" << "\n";

        current_highest_cand = ranked.front().first;
        for(auto& p : ranked){
            cout << "  Candidate " << p.first << ": " << p.second << "\n";
        }

        if(ranked.front().second > e.vote_count() / 2){
            winner = true;
        }else{
            // eliminate the last ranked candidate
            cout << "Candidate " << ranked.back().first << " is eliminated." << "\n\n";
            e.eliminate(ranked.back().first);
            ++round;
        }
    }
    cout << "Candidate " << current_highest_cand << " is selected.";
    return 0;
}