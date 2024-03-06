"""
You run an e-commerce website and want to record the last N order ids in a log.
Implement a data structure to accomplish this, with the following API:
record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log.
i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.
"""
from typing import *
from dataclasses import dataclass, field
import random

global orderList


@dataclass
class Product:
    name: str = "Product Name"
    price: float = 0.0


@dataclass
class Order:
    id: int = 0
    buyer: str = "Buyer Name"
    products: List[Product] = field(default_factory=list)
    quantities: List[int] = field(default_factory=list)
    total: float = 0.0


def generateLog(n: int) -> List[int]:
    """Generates a list of last n order ids"""
    global orderList
    return [x.id for x in orderList[-n:]]


def record(order_id: Order) -> None:
    """Records an order in the log"""
    global orderList
    orderList.append(order_id)


def get_last(i: int) -> Order:
    """Gets the ith last element from the log"""
    global orderList
    return orderList[-i]


if __name__ == "__main__":
    orderList = []
    names = ["John", "Jane", "Joe", "Jill", "Jack"]
    for _ in range(10):
        record(
            Order(
                id=random.randint(0, 10000000),
                buyer=random.Random().choice(names),
                products=[
                    Product(name=f"Product {i}", price=random.randint(1, 100))
                    for i in range(random.randint(1, 10))
                ],
                quantities=[1, 2],
            )
        )
    print(generateLog(int(input("Enter the log size (1-10)::\t"))))
    print(get_last(int(input("Enter the desired order index ::\t"))))
