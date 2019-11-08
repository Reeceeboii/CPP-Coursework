//
// Created by reece on 07/11/2019.
//

#ifndef CPP_COURSEWORK_ELECTION_H
#define CPP_COURSEWORK_ELECTION_H

#include "vote.h"
#include <istream>

class election {
    private:
        vector<vote> votes;
    public:
        election() = default;
        void add_vote(const vote& v);
        int vote_count() const;
        void eliminate(candidate c);
        vector<pair<candidate, int>>ranked_candidates() const;
        vector<vote> get_votes() const;
        int get_votes_for_candidate(const candidate& c);
        candidate get_round_winner() const;
};

election read_votes(istream& in);

#endif //CPP_COURSEWORK_ELECTION_H
