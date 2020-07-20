a=dict((['tony','001'],['pony','002'],['shiny','003']))
print("you hace 3 chances to login this system")
b=input('please input the name: ')
c=input('please input the pwd:')
n=1
while (b not in a) or c!=a[b]:
    if n<4:
        n=n+1
        print('please input correct name and pwd,you still have ',4-n,' times')
    else :
        print('your chances have been consumed ')
        break
    b=input('please input the name: ')
    c=input('please input the pwd: ')
else:
    print('welcome ',b)
