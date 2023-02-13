#ifndef GAMETICKET_H_
#define GAMETICKET_H_
class GameTicket: public Ticket{
    private:
    int number, gameday;
    double gameprice;
    string gamename;
    public:
        GameTicket(int num): Ticket(gameDayMap[num],gamePriceMap[num]){
            number = num;
            gamename = nameMap[number];
            gameday = gameDayMap[number]; 
            gameprice = gamePriceMap[number];
        }
        void printTicket(){
            cout <<"Game Ticket for  <" << gamename  << "> on day " 
            << gameday << " at price " << "$" << getTicketPrice() << endl;
        }
        
};
#endif