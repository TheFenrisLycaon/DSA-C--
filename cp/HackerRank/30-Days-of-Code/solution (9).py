num_entries = int(input())

phone_book = {}
for _ in range(num_entries):
    name, number = input().split()
    phone_book[name] = number

query_name = input()
while query_name:
    if query_name in phone_book:
        print(query_name, phone_book[query_name], sep='=')
    else:
        print("Not found")
    query_name = input()
