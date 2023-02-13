#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(){
    int cId;
	string hotelType;
	int budget;
    const int gamenumber = 15;
    string bracket;
    
    bool games[gamenumber];

    for(int i  = 0; i < gamenumber; i++) games[gamenumber] = false;
    ifstream requirementlist;
    requirementlist.open("requirementList.txt");
    while (requirementlist >> budget >> hotelType >> bracket)
    {     
        hotelType.erase(hotelType.begin());
        cout <<  budget << endl;
        cout <<  hotelType << endl;
        // cout << bracket <<endl;

        std::string str = static_cast<std::string>(bracket);
        std::vector<int> vect;
        std::size_t from = 0;

        for(std::size_t i = 0; i < str.size(); ++i) {
            if(str[i] == ',' || str[i] == ']') {
                cout << str.substr(from + 1, i - from - 1) << endl;
                from = i;
            }
        }
    }
    return 0;
}
/*
void readCustomerRequirement(){
		ifstream requirementlist;
		requirementlist.open("requirementList.txt");
		while (requirementlist >> budget >> hotelType>> bracket)
    	{
			hotelType.erase(hotelType.begin());
			cout <<  budget << endl;
			cout <<  hotelType << endl;
			// cout << bracket <<endl;

			std::string str = static_cast<std::string>(bracket);
			std::vector<int> vect;
			std::size_t from = 0;
			
			for(std::size_t i = 0; i < str.size(); ++i) {
				if(str[i] == ',' || str[i] == ']') {
					cout << str.substr(from + 1, i - from - 1) << endl;
					from = i;
				}
			}
    	}
	}
*/