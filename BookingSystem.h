#ifndef BOOKINGSYSTEM_H_
#define BOOKINGSYSTEM_H_

class BookingSystem{
    protected:
        int budget;
        string hotelType;
        int gamenum;
        int customercounter = 0;
        CustomerRequirement *list;
        int startday, endday;
        bool valid;
        int validpackages = 0;
        int gamecounter[NUMBEROFGAMES] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int hotelregular[9] = {0,0,0,0,0,0,0,0,0};
        int hotelbronze[9] = {0,0,0,0,0,0,0,0,0};
        int hotelgold[9] = {0,0,0,0,0,0,0,0,0};
        int flyin[9] ={0,0,0,0,0,0,0,0,0};
        int flyout[9] = {0,0,0,0,0,0,0,0,0};
    public:
        BookingSystem(){
            list = new CustomerRequirement[MAXREQUIREMENTS];

        }
        void readCustomerRequirements();
        void generatePackages();
        void printSuccessfulPackages();
        void savedata();
};
    void BookingSystem::readCustomerRequirements(){
        ifstream file;
        char comma;
        file.open("requirementList.txt");
        
        while (file >> budget >> hotelType>> comma)
        {
            if(comma == '['){
                do{
                    file >> gamenum >> comma;
                    list[customercounter].games[gamenum] = true;
                }while(comma != ']');
            }
            hotelType.erase(hotelType.begin());
            list[customercounter].budget = budget;
            list[customercounter].hotelType = hotelType;
            list[customercounter].cId = customercounter;
            customercounter += 1;
        }
        file.close();
    }
    void BookingSystem::generatePackages(){
        for (int i = 0; i <= customercounter - 1; i++){
            cout << "Cilent: " << list[i].cId + 1  << endl;   
            Package p;
            for (int m = 0; m <= NUMBEROFGAMES; m++){
                if(list[i].games[m] == true){
                    startday = list[i].earliestGameDay();
                    endday = list[i].latestGameDay();
                }
            }
            for (int n = 0; n < 2; n++){
                if (n == 0){
                    p.addFlightTicket(n,startday);
                }
                else if (n == 1){
                    p.addFlightTicket(n,endday);
                }
            }
            for (int n = startday; n < endday; n++ ){
                p.addHotelVoucher(list[i].hotelType,n,0.0);
            }
            for (int n = 0; n <= NUMBEROFGAMES; n++ ){
                if (list[i].games[n] == true){
                    p.addGameTicket(n);
                }
            } 
            p.printPackage();
            
            if ((endday - startday) < 0 || list[i].budget > p.totalcost){
                valid = false;
                cout << "Invalid Packages" << endl;
            }
            else{
                valid  = true;
                cout << "Valid Packages" << endl;
            }
            if (valid == true){
                validpackages += 1;
                flyin[startday] += 1;
                flyout[endday] += 1;
                for (int n = 0; n <= NUMBEROFGAMES; n++ ){
                    if (list[i].games[n] == true){
                        gamecounter[n] ++;
                    }
                }
                for (int n = startday; n < endday; n++ ){
                    if (list[i].hotelType.compare(hotelIndexToTypeMap[0]) == 0){
                        hotelregular[n] += 1;
                    }
                    else if (list[i].hotelType.compare(hotelIndexToTypeMap[1]) == 0){
                        hotelbronze[n] += 1;
                    }
                    else if (list[i].hotelType.compare(hotelIndexToTypeMap[2]) == 0){
                        hotelgold[n] += 1;
                    }
                }
            }
            
        }
    }
    void BookingSystem::printSuccessfulPackages(){
        cout << "Summary of packages"   << endl;
        cout << "Total packages generated: " << validpackages << endl;
        cout << "Total fly-in tickets (to Paris) for each day booked: " << endl;
        for (int i = 0; i < 9; i ++){
            cout << flyin[i] << "   ";
        }
        cout << endl;
        cout << "Total fly-out tickets (from Paris) for each day booked: " << endl;
        for (int i = 0; i < 9; i ++){
            cout << flyout[i] << "   ";
        }
        cout << endl;
        cout <<"Total hotel vouchers for each day sold: " << endl;
        cout << "Regular hotel rooms" << endl;
        for (int i = 0; i < 9; i ++){
            cout << hotelregular[i] << "   ";
        }
        cout << endl;
        cout << "Bronze hotel rooms" << endl;
        for (int i = 0; i < 9; i ++){
            cout << hotelbronze[i] << "   ";
        }
        cout << endl;
        cout << "Gold hotel rooms" << endl;
        for (int i = 0; i < 9; i ++){
            cout << hotelgold[i] << "   ";
        }
        cout << endl;
        cout << "Total event tickets for each events sold: " << endl;
        for (int i = 0; i < 15; i ++){
            cout << gamecounter[i] << "   ";
        }
        cout << endl;
    }
#endif