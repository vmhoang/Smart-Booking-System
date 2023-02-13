/*
 * Ticket.h
 *
 *      Author: dongmo
 */

#ifndef TICKET_H_
#define TICKET_H_

class Ticket {
protected:
	int day;
	int fullPrice;
	double discount;
public:
	Ticket(int d, int f) :
			day(d), fullPrice(f) {
		discount;
	}

	int getDay() {
		return day;
	}

	double getTicketPrice() {
		return (1.0-discount) * fullPrice;
	}

	virtual void printTicket() = 0;

	virtual ~Ticket() {
	}
};

#endif /* TICKET_H_ */
