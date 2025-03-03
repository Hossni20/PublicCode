import threading
from functools import wraps
import time


class InsufficientFundsError(Exception):
    """Custom exception for handling insufficient funds."""
    pass


def synchronized(lock):
    """Decorator to synchronize method calls in multi-threading."""
    def wrapper(func):
        @wraps(func)
        def synchronized_func(*args, **kwargs):
            with lock:
                return func(*args, **kwargs)
        return synchronized_func
    return wrapper


class BankAccount:
    """A class representing a bank account."""
    def __init__(self, account_id, balance=0.0):
        self.account_id = account_id
        self.balance = balance
        self._lock = threading.Lock()

    @synchronized(lock=threading.Lock())
    def deposit(self, amount):
        """Deposit money into the account."""
        if amount <= 0:
            raise ValueError("Deposit amount must be positive.")
        self.balance += amount
        print(f"Deposited ${amount:.2f} into account {self.account_id}. New balance: ${self.balance:.2f}")

    @synchronized(lock=threading.Lock())
    def withdraw(self, amount):
        """Withdraw money from the account."""
        if amount <= 0:
            raise ValueError("Withdrawal amount must be positive.")
        if self.balance < amount:
            raise InsufficientFundsError(f"Insufficient funds for withdrawal in account {self.account_id}.")
        self.balance -= amount
        print(f"Withdrew ${amount:.2f} from account {self.account_id}. New balance: ${self.balance:.2f}")

    def __str__(self):
        return f"BankAccount(id={self.account_id}, balance=${self.balance:.2f})"


def simulate_transactions(account, transactions):
    """Simulate a series of transactions on the given account."""
    for action, amount in transactions:
        try:
            if action == 'deposit':
                account.deposit(amount)
            elif action == 'withdraw':
                account.withdraw(amount)
            else:
                print(f"Unknown transaction type: {action}")
        except Exception as e:
            print(f"Transaction failed: {e}")
        time.sleep(0.1)  # Simulate processing delay


# Create a shared bank account
shared_account = BankAccount(account_id=1, balance=500.0)

# Define transactions for different users
user1_transactions = [('deposit', 200), ('withdraw', 100), ('withdraw', 300)]
user2_transactions = [('withdraw', 50), ('deposit', 400), ('withdraw', 200)]

# Create threads for multi-threaded transaction simulation
user1_thread = threading.Thread(target=simulate_transactions, args=(shared_account, user1_transactions))
user2_thread = threading.Thread(target=simulate_transactions, args=(shared_account, user2_transactions))

# Start the threads
user1_thread.start()
user2_thread.start()

# Wait for threads to finish
user1_thread.join()
user2_thread.join()

print("\nFinal state of the account:")
print(shared_account)
