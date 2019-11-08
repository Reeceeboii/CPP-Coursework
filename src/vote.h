//
// Created by reece on 07/11/2019.
//

#ifndef CPP_COURSEWORK_VOTE_H
#define CPP_COURSEWORK_VOTE_H

using namespace std;

#include <vector>

typedef unsigned int candidate;

class vote {
    private:
        vector<candidate> prefs;
    public:
        vote(vector<candidate>& prefs);
        bool spent() const;
        candidate first_preference() const;
        void discard(candidate c);
        vector<candidate> get_prefs() const;
        void print_prefs() const;
};

#endif //CPP_COURSEWORK_VOTE_H
