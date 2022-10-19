import matplotlib.pyplot as plt
x=[10, 12, 14, 16, 18]

y1=[3.041062,3.528270,2.822178,4.061632,4.453378]
y2=[1.488200,3.728510,2.223396,3.101196,5.335146]
y3=[1.660198,2.189551,2.720566,3.049943,3.812188]
y4=[0.987527,0.890520,0.958986,0.933661,1.010783]

plt.ylim(1, 6)
# plt.xlim(0, 8192)
# plt.scatter(x1, y1)
# plt.scatter(x2, y2)
# plt.scatter(x3, y3)
plt.title("no AVX vs AVX bitonic sort")
plt.plot(x,y1,label='thread = 1',)
plt.plot(x,y2,label='thread = 2')
plt.plot(x,y3,label='thread = 4')
plt.plot(x,y4,label='thread = 8')
plt.xlabel('array size 2^x')
plt.ylabel('(time of sort)/(no AVX)')

plt.legend()
plt.show()