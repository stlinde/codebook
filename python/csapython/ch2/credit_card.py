class CreditCard:
    """A consumer credit card."""

    def __init__(self, customer: str, bank: str, acnt: str, limit: int) -> None:
        """Create a new credit card instance.

        The initial balance is zero.

        customer    <str>: the name of the customer.
        bank        <str>: the name of the bank.
        acnt        <str>: the acount identifier.
        limit       <int>: credit limit (dollars)
        """
        self._customer = customer
        self._bank = bank
        self._account = acnt
        self._limit = limit
        self._balance = 0

    def get_customer(self) -> str:
        """Return the name of the customer."""
        return self._customer

    def get_bank(self) -> str:
        """Return the name of the bank."""
        return self._bank

    def get_account(self) -> str:
        """Return the card identifier."""
        return self._account

    def get_limit(self) -> int:
        """Return the current credit limit."""
        return self._limit

    def get_balance(self) -> int:
        """Return current balance."""
        return self._balance

    def charge(self, price: int) -> bool:
        """Charge given price to the card, assuming sufficient credit limit.

        Return True if charge was processed; False if denied.
        """
        if price + self._balance > self._limit:
            return False
        else:
            self._balance += price
            return True

    def make_payment(self, amount: int) -> None:
        """Process customer payment that reduces balance."""
        self._balance -= amount


# Creating a subclass for PredatoryCreditCard, see ch. 2.4

class PredatoryCreditCard(CreditCard):
    """An extension to CreditCard that compounds interests and fees."""
    def __init__(self,
                 customer: str,
                 bank: str,
                 acnt: str,
                 limit: int,
                 apr: float):
        """Create a new predatory credit card instance.

        The initial balance is zero.

        customer    the name of the customer.
        bank        the name of the bank.
        acnt        the account identifier.
        limit       credit limit
        apr         annual percentage rate
        """
        super().__init__(customer, bank, acnt, limit)
        self._apr = apr

    def charge(self, price: int):
        """Charge given price to the card, assuming sufficient credit limit.

        Return True if charge was processed.
        Return False and assess $5 fee if charge is denied.
        """
        success = super().charge(price)
        if not success:
            self._balance += 5
        return success

    def process_month(self):
        """Assess monthly interest on outstanding balance."""
        if self._balance > 0:
            # If positive balance, convert APR to monthly multiplicative factor
            monthly_factor = pow(1 + self._apr, 1/12) 
            self._balance *= monthly_factor

        

# Testing the class
# These tests provide method coverage.
if __name__ == '__main__':
    wallet = []
    wallet.append(CreditCard('John Bowman', 'California Savings',
                  '5391 0375 9387 5309', 2500))
    wallet.append(CreditCard('John Bowman', 'California Federal',
                  '3485 0399 3395 1954', 3500))
    wallet.append(CreditCard('John Bowman', 'California Finance',
                  '5391 0375 9387 5309', 5000))


    for val in range(1, 17):
        wallet[0].charge(val) 
        wallet[1].charge(2 * val) 
        wallet[2].charge(3 * val) 

    for c in range(3):
        print('Customer =', wallet[c].get_customer())
        print('Bank =', wallet[c].get_bank())
        print('Account =', wallet[c].get_account())
        print('Limit =', wallet[c].get_limit())
        print('Balance =', wallet[c].get_balance())
        while wallet[c].get_balance() > 100:
            wallet[c].make_payment(100)
            print('New balance =', wallet[c].get_balance())
        print("----------") 
