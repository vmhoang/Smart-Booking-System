#ifndef HOTELVOUCHER_H_
#define HOTELVOUCHER_H_
class HotelVoucher: public Ticket{
    private:
    int day, rt, roomPrice;
    int maxreg = hotelQuota[0];
    int maxbronze = hotelQuota[1];
    int maxgold = hotelQuota[2];
    public:
        HotelVoucher(string type, int d, double disc): Ticket(d,roomPrice){
            day = d;
            discount = disc;
            if (type.compare(hotelIndexToTypeMap[0]) == 0){
                rt = 0;
                roomPrice = hotelPriceMap[rt] ;
                maxreg -= 1;
            }
            else if (type.compare(hotelIndexToTypeMap[1]) == 0){
                rt = 1;
                roomPrice = hotelPriceMap[rt] ;
                maxbronze -= 1;
            }
            else if (type.compare(hotelIndexToTypeMap[2]) == 0){
                rt = 2;
                roomPrice = hotelPriceMap[rt] ;
                

            }
            Ticket::fullPrice = roomPrice;
            
        }

        void printTicket(){
            cout <<"Hotel Voucher for a " << hotelIndexToTypeMap[rt] << " on day " 
            << day << " at price " << "$" << getTicketPrice() << endl;
        }
        
};
#endif