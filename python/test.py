u=dict((['admin','password'],['admin2','pwd']))
a=dict((['tony','in'],['mike','out'],['susan','close002']))
b=input('please input your name:')
c=input('please input your password:')
if (b in a) and c==a[b]:
    print(u'welcome ',b)
elif (b in u) and c==u[b]:
    print(u'welcome administrator ',b)
else:
    print(u'please input correct name and password')
