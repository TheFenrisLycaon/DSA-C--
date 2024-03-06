def solve(meal_cost, tip_percent, tax_percent):
    tip_total = meal_cost * tip_percent / 100
    tax_total = meal_cost * tax_percent / 100
    total = meal_cost + tip_total + tax_total
    return round(total)

def main():
    meal_cost = float(input())
    tip_percent = int(input())
    tax_percent = int(input())
    print(solve(meal_cost, tip_percent, tax_percent))

if __name__ == "__main__":
    main()
