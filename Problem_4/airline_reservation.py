PRICES = {"Economy": 5000, "Business": 10000}


class Booking:
    def __init__(self, name, flight, seat_type):
        self.name = name
        self.flight = flight
        self.seat_type = seat_type
        self.cost = PRICES[seat_type]


class ReservationSystem:
    def __init__(self):
        self.bookings = []

    def add_booking(self, name, flight, seat_type):
        booking = Booking(name, flight, seat_type)
        self.bookings.append(booking)
        return booking

    def flight_bookings(self, flight):
        return [b for b in self.bookings if b.flight.lower() == flight.lower()]

    def total_revenue(self, flight):
        return sum(b.cost for b in self.flight_bookings(flight))

    def print_passenger_list(self, flight):
        rows = self.flight_bookings(flight)
        print(f"\nPassenger List - Flight {flight}")
        print("-" * 52)
        print(f"{'Name':<25}{'Seat Type':<12}{'Cost':>12}")
        print("-" * 52)
        if not rows:
            print("No bookings for this flight.")
        for b in rows:
            print(f"{b.name:<25}{b.seat_type:<12}{'₱' + format(b.cost, ',.2f'):>12}")
        print("-" * 52)
        print(f"{'Total Revenue:':<37}{'₱' + format(self.total_revenue(flight), ',.2f'):>12}\n")


def read_seat_type():
    while True:
        choice = input("Seat type (E = Economy, B = Business): ").strip().upper()
        if choice == "E":
            return "Economy"
        if choice == "B":
            return "Business"
        print("Invalid choice. Enter E or B.")


def main():
    system = ReservationSystem()
    while True:
        print("=== Airline Reservation System ===")
        print("1. Add booking")
        print("2. Print passenger list for a flight")
        print("3. Show total revenue for a flight")
        print("4. Exit")
        choice = input("Choose: ").strip()

        if choice == "1":
            name = input("Passenger name: ").strip()
            flight = input("Flight number: ").strip()
            seat = read_seat_type()
            b = system.add_booking(name, flight, seat)
            print(f"Booked {b.name} on {b.flight} ({b.seat_type}) - ₱{b.cost:,.2f}\n")
        elif choice == "2":
            system.print_passenger_list(input("Flight number: ").strip())
        elif choice == "3":
            flight = input("Flight number: ").strip()
            print(f"Total revenue for {flight}: ₱{system.total_revenue(flight):,.2f}\n")
        elif choice == "4":
            print("Goodbye!")
            break
        else:
            print("Invalid option.\n")


if __name__ == "__main__":
    main()
