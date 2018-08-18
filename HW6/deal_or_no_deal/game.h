#ifndef GAME_H
#define GAME_H

#include "../util/util.h"
#include "suitcase_array.h"

class game {
public:
	game(bool interactive = true);
	~game();
	void get_user_stc_input(int n = 0);
	void call_banker();
	void do_stuff(int n);
private:
	suitcase_array _suitcases;
	bool _offer_accepted = false;
	char _answer;
	int _total_money_left = 3418416;
	int _offer;
	int _reserved_suitcase;
	int _selected_suitcase;
	int _num_of_stc_to_choose;
	int _round_arr[9] = {6,5,4,3,2,1,1,1,1};
	vector<int> _chosen_suitcases;
};

#endif