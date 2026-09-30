"""Problem:
A school library wants to track books borrowed by students. Each transaction includes:

Student ID, book title, borrow date, and return date.
The system should calculate the number of days borrowed and charge a ₱5 fine per day late (after 7 days).
Programming Task:
Write a program that:

Accepts borrowing and returning details.
Calculates fines if applicable.
Displays a transaction report for each student."""

from datetime import datetime, date

def parse_date(date_str):
    date_str = date_str.strip()
    for fmt in ("%m-%d-%Y", "%m/%d/%Y"):
        try:
            return datetime.strptime(date_str, fmt).date()
        except ValueError:
            pass
    raise ValueError("Invalid format")

def format_date_mdy(d):
    return d.strftime("%m-%d-%Y")

def get_valid_student_id():
    while True:
        student_id = input("Enter Student ID (12 digits): ").strip()
        
        if student_id.isdigit() and len(student_id) == 12:
            return student_id
        
        print("Invalid Student ID! Must consist of exactly 12 numbers with no letters or symbols.\n")

def calculate_fine(days_borrowed):
    allowed_days = 7
    fine_per_day = 5.0
    
    if days_borrowed > allowed_days:
        late_days = days_borrowed - allowed_days
        return late_days, late_days * fine_per_day
    return 0, 0.0

def process_transaction():
    print("=== School Library Borrowing System ===")
    
    while True:
        print("\n" + "-" * 40)
        print("NEW TRANSACTION")
        print("-" * 40)
        
        # input details
        student_id = get_valid_student_id()
        book_title = input("Enter Book Title: ").strip()
        
        # borror date imput
        while True:
            borrow_str = input("Enter Borrow Date (MM-DD-YYYY) or type 'now' for today: ").strip().lower()
            if borrow_str in ("now", "today"):
                borrow_date = date.today()
                break
            try:
                borrow_date = parse_date(borrow_str)
                break
            except ValueError:
                print("Invalid date format. Please use MM-DD-YYYY (e.g., 09-30-2026) or type 'now'.")

        while True:
            try:
                return_str = input("Enter Return Date (MM-DD-YYYY): ")
                return_date = parse_date(return_str)
                
                if return_date < borrow_date:
                    print("Return date cannot be earlier than borrow date. Try again.")
                    continue
                break
            except ValueError:
                print("Invalid date format. Please use MM-DD-YYYY (e.g., 10-05-2026).")

        # calc
        days_borrowed = (return_date - borrow_date).days
        late_days, fine_amount = calculate_fine(days_borrowed)

        # report
        print("\n" + "=" * 40)
        print("        TRANSACTION REPORT")
        print("=" * 40)
        print(f"Student ID    : {student_id}")
        print(f"Book Title    : {book_title}")
        print(f"Borrow Date   : {format_date_mdy(borrow_date)}")
        print(f"Return Date   : {format_date_mdy(return_date)}")
        print(f"Days Borrowed : {days_borrowed} day(s)")
        print(f"Late Days     : {late_days} day(s)")
        print(f"Total Fine    : ₱{fine_amount:.2f}")
        print("=" * 40)

        # loop
        while True:
            choice = input("\nDo you want to process another transaction? (y/n): ").strip().lower()
            if choice in ("y", "yes", "n", "no"):
                break
            print("Invalid response. Please enter 'y' for yes or 'n' for no.")

        if choice in ("n", "no"):
            print("\nExiting system. Have a great day!")
            break

#main
if __name__ == "__main__":
    print ("\npython librarymanagement.py\n")
    process_transaction()