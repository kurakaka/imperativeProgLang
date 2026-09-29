Regular_income=0
Vip_income=0
Name=[]
Tickets=[]
Customer_total=[]
Vip_tickets=0
Regular_tickets=0
total_per_customer=[]
seat_type_per_customer=[]
tickets_per_customer=[]

print("---------------")
while True:
    try:
        Transaction = int(input("Enter Number of Transaction: "))
        if Transaction > 0:
            break
    except ValueError:
        pass
    print("Invalid Input")
print("---------------")
print()
def Ticket_type(n):
      global Regular_tickets, Regular_income, Vip_tickets, Vip_income
      if n.lower() == "regular":
           Customer_total.append(250)
           Regular_tickets+=1
           Regular_income+=250

      elif n.lower() == "vip":
           Customer_total.append(400)
           Vip_income+=400
           Vip_tickets+=1

print("---------------")
for i in range (1, Transaction+1):
    print(f"Transaction No. {i}")
    C=input("Name: ") #/
    Name.append(C)

    while True:
        try:
            T = int(input("Enter Number of tickets: "))
            if T > 0:
                break
        except ValueError:
            pass
        print("Invalid Input")
    Tickets.append(T)
    tickets_per_customer.append(T)

    while True:
        Tick_type = input("Enter Seat Type: Regular, VIP: ")
        if Tick_type.lower() in ("regular", "vip"):
            break
        print("Invalid Input")
    seat_type_per_customer.append(Tick_type)

    for j in range (T):
        Ticket_type(Tick_type)
    total_per_customer.append(sum(Customer_total))
    Customer_total.clear()
    print("---------------")
print()
for i in range(Transaction):
    print("---------------")
    print(f"Transaction No. {i+1}")
    print(f"Customer Name: {Name[i]}")
    print(f"No. of Tickets: {tickets_per_customer[i]}")
    print(f"Seat Type: {seat_type_per_customer[i]}")
    print(f"Total Amount: {total_per_customer[i]}")
print("---------------")
print()
print("-------SUMMARY-------")
print(f"Total No. of Customer: {len(Name)}")
print(f"Total No. of Ticket Sold: {sum(Tickets)}")
print(f"Total Income VIP Ticket Sold: {Vip_income}")
print(f"Total Income Regular Ticket Sold: {Regular_income}")
print(f"Total Income Generated: {Vip_income+Regular_income}")
print("---------------")