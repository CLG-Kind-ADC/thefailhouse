def testing(n):
    assert type(n)==int, "argument must be an integer"
    if n<10:
        print("How Sweet!")
    else:
        print("How sour!")

def dont_try(n):
	# DOESN'T WORK FOR BIG THINGS: Recursion overload.
    """Return the nth element of up-down, seven-switch sequence.

    >>> dont_try(7)
    7
    >>> dont_try(8)
    6
    >>> dont_try(15)
    1
    """
    def switch():
        if dont_try(n-1)-dont_try(n-2)==1:
            return -1
        if dont_try(n-1)-dont_try(n-2)==-1:
            return 1
    def no_switch():
        if dont_try(n-1)-dont_try(n-2)==1:
            return 1
        if dont_try(n-1)-dont_try(n-2)==-1:
            return -1
    assert n>0, "Can't do this for non-positive integers"
    assert n%1==0, "Can't do this for non-integers"
    if n==1:
        return 1
    elif n == 2:
        return 2
    elif (n-1) % 7 ==0 or ('7' in str(n-1))==True:
        return dont_try(n-1)+switch()
    else:
        return dont_try(n-1)+no_switch()

def tiesto(hello):
    """ 
    Returns the highest power of two lower than 'hello.'
    """
    import math
    if (math.log(hello)/math.log(2))%1==0:
        return hello
    else:
        for i in range(1,hello):
            if (math.log(i)/math.log(2))%1==0:
                x=i
    return x