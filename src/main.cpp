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


    return 0;
}