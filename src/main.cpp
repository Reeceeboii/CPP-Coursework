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

        for(int i = 0; i < ranked.size(); ++i){
            if(ranked[i].second > highest){
                highest = ranked[i].second;
                cand = ranked[i].first;
            }
            cout << "  Candidate " << ranked[i].first << ": " << ranked[i].second << endl;
        }

        if(highest > e.count_voters() / 2){
            winner = true;
        }else{
            cout << "Candidate " << ranked[ranked.size() - 1].first << " is eliminated." << endl;
            //TODO something wrong with this elim function - fix this and you're done :)
            e.eliminate(ranked[ranked.size() - 1].first);
            ++round;
        }
    }
    cout << "Candidate " << cand << " is selected.";




    return 0;
}