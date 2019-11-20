//
// Created by reece on 08/11/2019.
//

#include <iostream>
#include <fstream>
#include "vote.h"
#include "election.h"

using namespace std;

int main(){
    fstream infile("votes.txt");
    election e = read_votes(infile);

    bool winner = false;
    int round = 1;
    int highest = 0, cand = 0;
    while(!winner){
        vector<pair<candidate, int>> ranked = e.ranked_candidates();
        cout << "Round " << round << ": " << e.vote_count() << " votes" << "\n";
        cout << "First preferences:" << "\n";

        // for every candidate, if their preference is the highest, set the flags equal to them
        for(auto& i : ranked){
            if(i.second > highest){
                highest = i.second;
                cand = i.first;
            }
            cout << "  Candidate " << i.first << ": " << i.second << "\n";
        }

        if(highest >= e.vote_count() / 2){
            winner = true;
        }else{
            // eliminate the last ranked candidate
            cout << "Candidate " << ranked[ranked.size() - 1].first << " is eliminated." << "\n\n";
            e.eliminate(ranked[ranked.size() - 1].first);
            ++round;
        }
    }
    cout << "Candidate " << cand << " is selected.";
    return 0;
}