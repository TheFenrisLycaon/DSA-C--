din = int(eval(input()))

i = 0
lista = [100, 20, 10, 5, 1]

cont = 0
while(din != 0):
    cont += din//lista[i]
    din = din%lista[i]
    i += 1
print(cont)