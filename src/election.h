//
// Created by reece on 07/11/2019.
//

#ifndef CPP_COURSEWORK_ELECTION_H
#define CPP_COURSEWORK_ELECTION_H

#include "vote.h"
#include <istream>

class election {
    public:
        election() = default;
        void add_vote(const vote& v);
        int vote_count() const;
        void eliminate(candidate c);

};

election read_votes(istream& in);


#endif //CPP_COURSEWORK_ELECTION_H
