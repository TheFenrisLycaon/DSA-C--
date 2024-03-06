def solution(number):
  return sum([x for x in range(number) if x%3 ==0 or x%5==0])