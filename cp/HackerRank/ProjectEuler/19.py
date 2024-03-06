_days_in_month=[31,28,31,30,31,30,31,31,30,31,30,31]

def is_leap(year):
    return (year %4 ==0 and year %100 !=0) or (year % 400 ==0)

def days_in_month(month,year):
    if month==1:
        return _days_in_month[1]+(1 if is_leap(year) else 0)
    else:
        return _days_in_month[month]

def days_from_2000_to_2400():
    day=5
    num_sunday=0
    for year in range(2000,2400):
        day=(day+days_in_month(month,year))%7
        if day==6:
            num_sunday+=1
    return num_sunday 

def calculate_sunday(to_year,to_month):
    if to_year<1900: return 0
    to_month-=1
    result=0
    day_of_week=0
    year=1900
    if to_year>2000:
        while year<2000:
            for month in range(12):
                if day_of_week==6:
                    result+=1
                day_of_week=(day_of_week+days_in_month(month,year))%7
            year+=1
        num_400_rep=int((to_year-2000)/400)
        result +=num_400_rep * 688
        year+=num_400_rep *400
    while(year< to_year):
        for month in range(12):
            if day_of_week==6:
                result+=1
            day_of_week=(day_of_week + days_in_month(month,year))%7
        year+=1
    month=0
    while month<=to_month:
        if day_of_week==6:
            result+=1
        day_of_week=(day_of_week+days_in_month(month,year))%7
        month+=1
    return result

num_sunday_400=688


for i in range(int(input())):
    y1,m1,d1=map(int,input().split())
    y2,m2,d2=map(int,input().split())
    d1-=1
    if d1==0:
        m1-=1
        if m1==0:
            m1=12
            y1-=1
    print(int(calculate_sunday(y2,m2)-calculate_sunday(y1,m1)))
