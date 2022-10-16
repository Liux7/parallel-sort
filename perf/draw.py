import matplotlib.pyplot as plt
x=[2, 3, 4, 5, 6, 7]

y1=[1.000000,1.000000,1.000000,1.000000,1.000000,1.000000]
y2=[0.046750,0.691334,1.393793,1.625330,1.599180,1.786264]
y3=[0.022708,0.483072,1.588115,1.882905,1.794725,1.913357]
y4=[0.015883,0.300515,1.537348,2.073525,1.949990,2.486839]

# plt.ylim(1, 10)
# plt.xlim(0, 8192)
# plt.scatter(x1, y1)
# plt.scatter(x2, y2)
# plt.scatter(x3, y3)
plt.plot(x,y1,label='thread = 1',)
plt.plot(x,y2,label='thread = 2')
plt.plot(x,y3,label='thread = 3')
plt.plot(x,y4,label='thread = 4')
plt.xlabel('array size 10^x')
plt.ylabel('(time of sort)/(time of thread = 1)')
plt.title('performance')
plt.legend()
plt.show()