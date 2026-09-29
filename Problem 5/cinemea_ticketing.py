Regular_income=0
Vip_income=0
Name=[]
Tickets=[]
Customer_total=[]
Vip_tickets=0
Regular_tickets=0
total_per_customer=[]

Transaction=int(input("Enter Number of Transaction: "))

def Ticket_type(n):
      global Regular_tickets, Regular_income, Vip_tickets, Vip_income
      if n == "Regular" or n == "regular":
           Customer_total.append(250)
           Regular_tickets+=1 
           Regular_income+=250

      elif n=="Vip" or n=="VIP":
           Customer_total.append(400)
           Vip_income+=400
           Vip_tickets+=1
      else:
           print("Invalid Input") 
print("---------------")
for i in range (1, Transaction+1):
    print(f"Transaction No. {i}")
    C=input("Name: ")
    T=int(input("Enter Number of tickets: "))
    Tick_type= input("Enter Seat Type: Regular, VIP: ")
    for j in range (T):
        Ticket_type(Tick_type)
    print("---------------")
    print(f"Transaction No. {i}")
    print(f"Customer Name: {C}")
    Name.append(C)
    print(f"No. of Tickets: {T}")
    Tickets.append(T)
    print(f"Seat Type: {Tick_type}")
    print(f"Total Amount: {sum(Customer_total)}")
    total_per_customer.append(sum(Customer_total))
    Customer_total.clear()
    if i == Transaction:
         print("-------SUMMARY-------")
    else:
        print("---------------")


print(f"Total No. of Customer: {len(Name)}")
print(f"Total No. of Ticket Sold: {len(Tickets)}")
print(f"Total Income VIP Ticket Sold: {Vip_income}")
print(f"Total Income Regular Ticket Sold: {Regular_income}")
print(f"Total Income Generated: {Vip_income+Regular_income}")
