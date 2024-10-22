def is_prime(n):
    if n == 2:
        return True
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def get_q_primes(q):
    primes = []
    n = 2
    while len(primes) < q:
        if is_prime(n):
            primes.append(n)
        n += 1
    return primes


def waiter(number, q):
    primes = get_q_primes(q)
    answers = []
    for i in range(q):
        A_i = []
        B_i = []
        while number:
            plate = number.pop()
            prime = primes[i]
            if plate % prime == 0:
                B_i.append(plate)
            else:
                A_i.append(plate)
        answers += list(reversed(B_i))
        number = A_i
    answers += list(reversed(number))
    return answers
        