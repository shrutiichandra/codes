##def f3(*args): 
### * here indicates unpacking of args to match the positional arguments in sum
##    print "in f3 args=", args, " and sum =",sum(*args)
###sum(iterable, start)
##def f2(a,b):
##    print "f2: two args are ",a,b
### can take variable number of arguments in form of a tuple called args
##def f1(*args): 
##    print "args in f1 is :", args
### * here indicates unpacking of args tuple to corresponding formals a,b of f2
##    f2(*args)  
### f3 is passed a tuple as first postional argument
##    f3(args)   
##f1(1,2)


##def f(a,b,c):
##    print a,b,c
##f(12,22,32)                    
##
##def f(a, b=2, c=3):
##    print a,b,c
##f(10)                          
##

##f(9, **{'b':4, 'c':5})
##
##f(7, 8, **{'c':6})


def double_in(old):
    def wrapper(arg):
        print (2+arg)
        return old(2+arg)
    return wrapper

##@double_in
##def function (arg):
##    return arg % 3
##print function(10)

def double_out(old):
    def wrapper(arg):
        print 2+old(arg)
        return 2 + old(arg)
    return wrapper

@double_out
def function (arg):
    return arg % 3
print function(12)
