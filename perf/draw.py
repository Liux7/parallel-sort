import matplotlib.pyplot as plt
x=[2, 3, 4, 5, 6]

y1=[1.000000,1.000000,1.000000,1.000000,1.000000]
y2=[0.089349,1.037078,0.921321,1.620856,1.816637]
y3=[0.078988,0.904297,2.626881,2.346511,2.196978]
y4=[0.058646,0.711218,3.210093,2.024286,2.152120]

# plt.ylim(1, 10)
# plt.xlim(0, 8192)
# plt.scatter(x1, y1)
# plt.scatter(x2, y2)
# plt.scatter(x3, y3)
plt.title("no AVX performance(use std:sort)")
plt.plot(x,y1,label='thread = 1',)
plt.plot(x,y2,label='thread = 2')
plt.plot(x,y3,label='thread = 3')
plt.plot(x,y4,label='thread = 4')
plt.xlabel('array size 10^x')
plt.ylabel('(time of sort)/(time of thread = 1)')

plt.legend()
plt.show()