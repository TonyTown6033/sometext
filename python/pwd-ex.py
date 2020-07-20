p=dict((['admin','pwd1'],['admin2','pwd2']))
a=dict((['tony','rise'],['flank','ig'],['phonex','fly']))
n=1
while n<4:
    print('you have ',4-n,' times chance to login this system ')
    b=input('please input your name:')
    c=input('please input your password:')
    if (b in p) and c==p[b]:
        print(u'welcome administrator ',b)
        n=4
    elif (b in a) and c==a[b]:
        print (u'welcome ',b)
        n=4
    else:
        print('please input correct name and pwd')
        n=n+1
print('your chance has been consumed')
