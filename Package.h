#ifndef PACKAGE_H_
#define PACKAGE_H_

class Package{
    public:
        double totalcost = 0.0;
        Package(){
            cout << "The Package contain: " << endl;
        }
        void addFlightTicket(int ft, int day){
            FlightTicket fticket(ft,day);
            totalcost += fticket.getTicketPrice();
            fticket.printTicket();
        }
        void addHotelVoucher(string type, int day, double discount){
            HotelVoucher Hvoucher(type, day, discount);
            totalcost += Hvoucher.getTicketPrice();
            Hvoucher.printTicket();
        }
        void addGameTicket(int ticket){
            GameTicket gticket(ticket);
            totalcost += gticket.getTicketPrice();
            gticket.printTicket();
        }
        void printPackage(){
            cout << "Total cost of the package is $" << totalcost << endl;
        }  
        
};
#endif