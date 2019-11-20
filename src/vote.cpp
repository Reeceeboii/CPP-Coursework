//
// Created by reece on 07/11/2019.
//

#include "vote.h"
#include <algorithm>

vote::vote(const vector <candidate> &prefs) : prefs(prefs){}

candidate vote::first_preference() const { return prefs[0]; }

void vote::discard(candidate c) {
    prefs.erase(remove_if(prefs.begin(), prefs.end(), [c](const candidate &cand) {
        return c == cand;
    }), prefs.end());
}

bool vote::spent() const { return prefs.empty(); }