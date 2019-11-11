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
        cout << "Round " << round << ": " << e.vote_count() << " votes" << endl;
        cout << "First preferences:" << endl;

        // for every candidate, if their preference is the highest, set the flags equal to them
        for(auto& i : ranked){
            if(i.second > highest){
                highest = i.second;
                cand = i.first;
            }
            cout << "  Candidate " << i.first << ": " << i.second << endl;
        }

        if(highest >= e.count_voters() / 2){
            winner = true;
        }else{
            // eliminate the last ranked candidate
            cout << "Candidate " << ranked[ranked.size() - 1].first << " is eliminated." << endl << endl;
            //TODO something wrong with this elim function - fix this and you're done :)
            e.eliminate(ranked[ranked.size() - 1].first);
            ++round;
        }
    }
    cout << "Candidate " << cand << " is selected.";




    return 0;
}