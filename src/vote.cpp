//
// Created by reece on 07/11/2019.
//

#include <algorithm>
#include <iostream>
#include "vote.h"


vote::vote(vector <candidate> &prefs) : prefs(prefs){}

candidate vote::first_preference() const {
    return prefs[0];
}

//void vote::discard(candidate c) {
//    remove_if(prefs.cbegin(), prefs.cend(), c);
//}


bool vote::spent() const { return prefs.empty(); }

vector<candidate> vote::get_prefs() const { return prefs; }

void vote::print_prefs() const {
    for(candidate c : prefs){
        cout << c;
    }
    cout << endl;
}