import sys

def mva(k: int, mu: float):
    # k: Number of users to be inserted in the system
    # mu: Base value for service rate mu_m
    if k == 0:
        return print("Error, number of users must be at least 1.")
    i = 1
    # Queue 1
    n_1 = 0
    l_hat_1 = 4
    # Queue 2
    n_2 = 0
    l_hat_2 = 1
    # Queue 3
    n_3 = 0
    l_hat_3 = 3

    while i <= k:
        t_1 = (1/(3*mu))*(1+n_1)
        t_2 = (1/(2*mu))*(1+n_2)
        t_3 = (1/(1*mu))*(1+n_3)

        n_1 = i * (l_hat_1*t_1)/(l_hat_1*t_1 + l_hat_2*t_2 + l_hat_3*t_3)
        n_2 = i * (l_hat_1*t_1)/(l_hat_1*t_1 + l_hat_2*t_2 + l_hat_3*t_3)
        n_3 = i * (l_hat_1*t_1)/(l_hat_1*t_1 + l_hat_2*t_2 + l_hat_3*t_3)

        l_1 = n_1/t_1
        l_2 = n_2/t_2
        l_3 = n_3/t_3

        i += 1

    return print("""For k = {k},\n
l_1 = {l_1}\n
l_2 = {l_2}\n
l_3 = {l_3}""".format(k=k, l_1=l_1, l_2=l_2, l_3=l_3))

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("[E] Need k (number of users) and mu (base value of arrival rate). Please enter the two numbers in sequence, separated by spaces.")
    else:
        try:
            k = int(sys.argv[1])
            mu = float(sys.argv[2])

            print('Entered numbers: k = ' + str(k) + ', mu = ' + str(mu))
            mva(k, mu)
        except:
            print("[E] Incorrect types. k (first number) must be an integer, while mu (second number) must be a floating point number.")