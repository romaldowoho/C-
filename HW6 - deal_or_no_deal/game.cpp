#include "game.h"

game::game(bool interactive) {
	if(interactive) {
		get_user_stc_input();

		for(int i = 0; i < 9; i++) {
			_num_of_stc_to_choose = _round_arr[i];
			get_user_stc_input(_num_of_stc_to_choose);
			if(_offer_accepted) return;
			if(i == 8) {
				cout << "Your win is " << _suitcases.get_suitcase(_reserved_suitcase).get_val() << endl;
			}
		}
	}
}

game::~game() {

}

void game::get_user_stc_input(int n) {
	if(n && n != 1) {
		cout << "Please select " << n << " suitcases:" << endl;
		do_stuff(n);
		call_banker();
	} else if(n == 1) {
		cout << "Please select " << n << " suitcase:" << endl;
		do_stuff(n);
		call_banker();
	} else {
		_suitcases.print();
		cout << "Please select your suitcase:" << endl;
		cin >> _reserved_suitcase;
		_suitcases.get_suitcase(_reserved_suitcase).reserve();
		_suitcases.print();
	}
}

void game::do_stuff(int n) {
	while(n) {
			if(cin >> _selected_suitcase && _selected_suitcase != _reserved_suitcase) {
				cout << endl;
				_chosen_suitcases.push_back(_selected_suitcase);
				string value = _suitcases.get_suitcase(_selected_suitcase).get_val();
				cout << _selected_suitcase << " suitcase value is: " << value << endl << endl;
				_total_money_left -= stoi(value);
				_suitcases.cross_out_value(value);
				_suitcases.get_suitcase(_selected_suitcase).open();
				_suitcases.print();
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				n--;
				cout << "Your suitcase is " << _reserved_suitcase << endl << endl;
			} else {
				cout << "Please choose available suitcase from the display" << endl << endl;
			}
		}
}

void game::call_banker() {
	cout << endl;
	cout << "It's the banker..." << endl << endl;
	_offer = _total_money_left / (25 - _chosen_suitcases.size());
	cout << "He is making you an offer of $" << _offer << endl;
	cout << "Do you accept this offer? Y/N?" << endl;
	cin >> _answer;
	if(_answer == 'Y') {
		cout << "Your win is $" << _offer << endl;
		_offer_accepted = true;
	}
}




